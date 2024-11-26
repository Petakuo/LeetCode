/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char** rotateTheBox(char** box, int boxSize, int* boxColSize, int* returnSize, int** returnColumnSizes){
    for(int i = 0; i < boxSize; i++){
        for(int j = (*boxColSize)-2; j >= 0; j--){
            for(int k = j+1; k < (*boxColSize); k++){
                if(box[i][k-1] == '#' && box[i][k] == '.'){
                    box[i][k-1] = '.';
                    box[i][k] = '#';
                }
                if(box[i][k] == '*') break;
            }
        }
    }
    char** ans = (char**)malloc((*boxColSize)*sizeof(char*));
    for(int i = 0; i < (*boxColSize); i++){
        ans[i] = malloc(boxSize*sizeof(char));
    }
    for(int i = 0; i < (*boxColSize); i++){
        for(int j = 0; j < boxSize; j++){
            ans[i][j] = box[boxSize-1-j][i];
        }
    }
    *returnSize = (*boxColSize);
    (*returnColumnSizes) = malloc((*boxColSize)*sizeof(int));
    for(int i = 0; i < (*boxColSize); i++){
        (*returnColumnSizes)[i] = boxSize;
    }
    return ans;
}
