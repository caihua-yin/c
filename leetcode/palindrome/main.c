#include<stdio.h>

#define MAX_INT_LEN 10

// Return 0 if false, 1 if true
int isPalindrome(int d)
{
    int i = 0;
    int j;
    char numbers[MAX_INT_LEN];
    if (d < 0)
        return 0;

    do
    {
        numbers[i++] = d % 10;
        d = d / 10;
    } while (d != 0);

    // 1 digit integer will not go into this loop, so always return 1
    for (j = 0; j < i/2; j++)
    {
        if (numbers[j] != numbers[i-1-j])
            return 0;
    }

    return 1;
}

// Return 0 if false, 1 if true
int isPalindrome2(int d)
{
    int high = d;
    int low = 0;

    if (high < 0)
        return 0;

    // For the case a positive number ending with 0
    if(high > 0 && high % 10 == 0)
        return 0;

    while (high > low)
    {
        low = low * 10 + high % 10;

        // For the case d has even number of digits
        if (high == low)
            break;

        high = high / 10;
    }

    if(high == low)
        return 1;
    else
        return 0;
}

int main()
{
    printf("%d - %d : %d\n", 0, isPalindrome(-10), isPalindrome2(-10));
    printf("%d - %d : %d\n", 0, isPalindrome(0), isPalindrome2(0));
    printf("%d - %d : %d\n", 1, isPalindrome(1), isPalindrome2(1));
    printf("%d - %d : %d\n", 10, isPalindrome(10), isPalindrome2(10));
    printf("%d - %d : %d\n", 101, isPalindrome(101), isPalindrome2(101));
    printf("%d - %d : %d\n", 11223, isPalindrome(11223), isPalindrome2(11223));
    printf("%d - %d : %d\n", 112233, isPalindrome(112233), isPalindrome2(112233));
    printf("%d - %d : %d\n", 112211, isPalindrome(112211), isPalindrome2(112211));
    return 0;
}
