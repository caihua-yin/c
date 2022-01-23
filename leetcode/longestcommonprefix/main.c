#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 200

char* longestCommonPrefix(char **strs, int strsSize)
{
	int i,j;
	char *commonStr = malloc(MAXLEN * sizeof(char));
	char *p = &commonStr[0];
	for (j = 0; j < MAXLEN; j++)
	{
		commonStr[j] = '\0';
		for (i = 0; i < strsSize; i++)
		{
			// It reaches to end of a string
			if (strs[i][j] == '\0')
				break;

			if (commonStr[j] == '\0')
				// Initialize commonChar from the first string
				commonStr[j] = strs[i][j];
			else if (commonStr[j] != strs[i][j])
			{
				commonStr[j] = '\0';
				break;
			}
		}
		if(commonStr[j] == '\0')
			break;
	}
	return p;
}
int main()
{
	char *test1[3] = {"flower","flow","flight"};
	char *test2[3] = {"dog","racecar","car"};
	char *result;

	result = longestCommonPrefix(test1, 3);
	printf("Result of test1 is: %s\n", result);
	free(result);

	result = longestCommonPrefix(test2, 3);
	printf("Result of test2 is: %s\n", result);
	free(result);
	return 0;
}
