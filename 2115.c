/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct{
    char* key;
    UT_hash_handle hh;
} Supply;

typedef struct{
    char* recipe;
    bool canMake;
    UT_hash_handle hh;
} Recipe;

bool canMakeRecipe(Supply* supplyHash, Recipe* recipeHash, char** ingredients, int ingredientCount){
    for(int i = 0; i < ingredientCount; i++){
        char* ingredient = ingredients[i];
        Supply* s = NULL;
        HASH_FIND_STR(supplyHash, ingredient, s);
        if(s == NULL){
            Recipe* r = NULL;
            HASH_FIND_STR(recipeHash, ingredient, r);
            if(r == NULL || r->canMake == 0) return 0;
        }
    }
    return 1;
}

void Check(Supply* supplyHash, Recipe* recipeHash, char** recipes, int recipesSize, char*** ingredients, int* ingredientsColSize, char*** ans, int* returnSize){
    for(int i = 0; i < recipesSize; i++){
        Recipe* find = NULL;
        HASH_FIND_STR(recipeHash, recipes[i], find);
        if(find != NULL && find->canMake == 0){
            find->canMake = canMakeRecipe(supplyHash, recipeHash, ingredients[i], ingredientsColSize[i]);
            if(find->canMake == 1){
                (*ans)[(*returnSize)++] = find->recipe;
                Check(supplyHash, recipeHash, recipes, recipesSize, ingredients, ingredientsColSize, ans, returnSize);
            }
        }
    }
}

char** findAllRecipes(char** recipes, int recipesSize, char*** ingredients, int ingredientsSize, int* ingredientsColSize, char** supplies, int suppliesSize, int* returnSize) {
    Supply* supplyHash = NULL;
    for(int i = 0; i < suppliesSize; i++){
        Supply* s = (Supply*)malloc(sizeof(Supply));
        s->key = supplies[i];
        HASH_ADD_KEYPTR(hh, supplyHash, s->key, strlen(s->key), s);
    }
    Recipe* recipeHash = NULL;
    for(int i = 0; i < recipesSize; i++){
        Recipe* r = (Recipe*)malloc(sizeof(Recipe));
        r->recipe = recipes[i];
        r->canMake = 0;
        HASH_ADD_KEYPTR(hh, recipeHash, r->recipe, strlen(r->recipe), r);
    }
    char** ans = (char**)malloc(recipesSize*sizeof(char*));
    *returnSize = 0;
    Check(supplyHash, recipeHash, recipes, recipesSize, ingredients, ingredientsColSize, &ans, returnSize);
    return ans;
}
