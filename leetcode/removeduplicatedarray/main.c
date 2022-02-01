#include<stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
    int i,j;

    if (numsSize == 0 || numsSize == 1)
        return numsSize;

    for (i = j = 1; i < numsSize; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            if (i != j)
                nums[j] = nums[i];
            j++;
        }
    }

    return j;
}

void printArray(int* nums, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d", nums[i]);
        if (i+1 < size)
            printf(" ");
    }
    printf("\n");
}

int main()
{
    int nums[] = {1,1,2,3,4,4,5,5,5,6,7,8};
    int size = 12;

    printf("Input array is:");
    printArray(nums, size);

    size = removeDuplicates(nums, 12);
    printf("Output array is:");
    printArray(nums, size);
    return 0;
}
