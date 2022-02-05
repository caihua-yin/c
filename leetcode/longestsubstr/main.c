#include<stdio.h>

int lengthOfLongestSubstring(char * s)
{
    int len = 0, i = 0, start = 0, end = 0;

    if (s == NULL)
        return 0;

    while (s[end] != '\0')
    {
        for (i = start; i < end; i++)
        {
            if (s[i] == s[end])
            {
                if (end - start > len)
                    len = end - start;
                start = i + 1;
                break;
            }
        }
        end++;
    }

    if (end - start > len)
        len = end - start;

    return len;
}

int main()
{
    printf("The length of longest substr of 'abcabcbb' is: %d\n", lengthOfLongestSubstring("abcabcbb"));
    printf("The length of longest substr of 'abcbcbb' is: %d\n", lengthOfLongestSubstring("abcbcbb"));
    return 0;
}
