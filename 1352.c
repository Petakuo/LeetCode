Sol1: 
typedef struct {
    int* arr;
    int capacity;
    int size;
} ProductOfNumbers;


ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers* obj = (ProductOfNumbers*)malloc(sizeof(ProductOfNumbers));
    obj->capacity = 100;
    obj->arr = (int*)malloc((obj->capacity)*sizeof(int));
    obj->size = 0;
    return obj;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    if((obj->capacity) == (obj->size)){
        obj->capacity *= 2;
        obj->arr = (int*)realloc(obj->arr, (obj->capacity)*sizeof(int));
    }
    obj->arr[obj->size++] = num;
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    int ans = 1;
    for(int i = obj->size-1; i >= obj->size-k; i--){
        ans *= obj->arr[i];
    }
    return ans;
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your ProductOfNumbers struct will be instantiated and called as such:
 * ProductOfNumbers* obj = productOfNumbersCreate();
 * productOfNumbersAdd(obj, num);
 
 * int param_2 = productOfNumbersGetProduct(obj, k);
 
 * productOfNumbersFree(obj);
*/

Sol2: 
typedef struct {
    int* prefix;
    int capacity;
    int size;
} ProductOfNumbers;


ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers* obj = (ProductOfNumbers*)malloc(sizeof(ProductOfNumbers));
    obj->capacity = 4;
    obj->prefix = (int*)malloc(obj->capacity*sizeof(int));
    obj->size = 1;
    obj->prefix[0] = 1;
    return obj;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    if(num == 0){
        obj->size = 1;
        obj->prefix[0] = 1;
        return;
    }
    if(obj->size == obj->capacity){
        obj->capacity *= 2;
        obj->prefix = (int*)realloc(obj->prefix, obj->capacity*sizeof(int));
    }
    obj->prefix[obj->size++] = obj->prefix[obj->size-1]*num;
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    if(k >= obj->size) return 0;
    else return obj->prefix[obj->size-1]/obj->prefix[obj->size-1-k];
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    free(obj->prefix);
    free(obj);
}

/**
 * Your ProductOfNumbers struct will be instantiated and called as such:
 * ProductOfNumbers* obj = productOfNumbersCreate();
 * productOfNumbersAdd(obj, num);
 
 * int param_2 = productOfNumbersGetProduct(obj, k);
 
 * productOfNumbersFree(obj);
*/
