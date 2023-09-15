/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize){
    int* result = (int*)malloc(2 * numsSize * sizeof(int));
    for(int i = 0; i < 2 * numsSize; i++){
        if(i < numsSize){
            result[i] = nums[i];
        }else{
            result[i] = nums[i - numsSize];
        }
    }
    
    *returnSize = 2 * numsSize; 
    return result;
}
