#include <stdio.h>

int maxArea(int* height, int heightSize){
    int left = 0, right = heightSize - 1;
    int result = 0, tmp, high;
    while (left < right)
    {
        high = height[left] < height[right]? height[left] : height[right];
        tmp = high * (right - left);
        result = tmp > result ? tmp : result;

        if (height[left] == high)
            left++;
        if(height[right] == high)
            right--;
    }
    return result;
}

int main()
{
    int height[] = {1,8,6,2,5,4,8,3,7};
    int heightSize = sizeof(height) / sizeof(height[0]);
    printf("heightSize: %d\n", heightSize);
    printf("Output: %d\n", maxArea(height, heightSize));

    return 0;
}
