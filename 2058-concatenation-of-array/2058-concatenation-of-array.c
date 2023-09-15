/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize){
    int* result = (int*)malloc(2 * numsSize * sizeof(int));
    for(int i = 0; i < numsSize; i++){
    result[i] = result[numsSize + i] = nums[i];}
    *returnSize = 2 * numsSize; 
    return result;
}


