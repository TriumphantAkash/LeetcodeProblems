#include<stdio.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* retArr = (int*)malloc(2*sizeof(int));

  for(int i = 0; i< numsSize;i++ )
  {
    if (abs(nums[nums[i]-1]) < 0)
    {
      retArr[0] = nums[i];
    }else
    {
      nums[abs(nums[i])-1] *= -1;
    }
  }
  for(int i =0; i< numsSize; i++)
  {
    if(nums[i] > 0)
    {
      retArr[1] = i+1;
    }
  }
    return retArr;
}

int main()
{
    int nums[4] = {1,2,2,4};
    int numsSize = 4;
    int* returnSize;
    int* ret = findErrorNums(nums, &numsSize, returnSize);
    printf("%d ",ret[0]);
    printf("%d ",ret[1]);
}