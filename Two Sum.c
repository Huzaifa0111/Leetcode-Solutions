#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    static int result[2];
    for (int i = 0; i < numsSize; i++){
        for (int j = i + 1; j < numsSize; j++){
            if (nums[i] + nums[j] == target){
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    return NULL;
}

int main(){
    int nums[] = {2, 3, 5, 9};
    int numsSize = 4;
    int target = 11;
    int returnSize;
    int* result = twoSum(&nums[0], numsSize, target, &returnSize);
    if (result == NULL) {
        printf("No solution found\n");
    } else {
        printf("solutions are: [%d, %d]", result[0], result[1]);
    }
    return 0;
}