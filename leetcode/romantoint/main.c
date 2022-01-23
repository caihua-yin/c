#include<stdio.h>

typedef enum
{
    // Q stands for invalid roman number
    Q = -1,

    // Valid roman number starts here
    I = 1,
    V = 5,
    X = 10,
    L = 50,
    C = 100,
    D = 500,
    M = 1000
} Roman;

Roman char2Roman(char c)
{
    switch(c)
    {
        case 'I':
            return I;
        case 'V':
            return V;
        case 'X':
            return X;
        case 'L':
            return L;
        case 'C':
            return C;
        case 'D':
            return D;
        case 'M':
            return M;
        default:
            return Q;
    }
}

int roman2int(const char *c)
{
    // The intermediate result can be negative, e.g. IV
    short result = 0;
    short n = 0 ;
    short next = 0;
    while (*c != '\0')
    {
        n = char2Roman(*c);

        // Handle invalid case
        if (n < 0)
           return n;

        if (*(c+1) != '\0')
        {
            next = char2Roman(*(c+1));
            if (n >= next)
                result += n;
			else
				result -= n;
        }
		else
		{
			result += n;
		}

        // Advance c
        c++;
    }

    return result;
}

int main()
{
    printf("III[3] is %d\n", roman2int("III"));
    printf("LVIII[58] is %d\n", roman2int("LVIII"));
    printf("MCMXCIV[1994] is %d\n", roman2int("MCMXCIV"));
    return 0;
}
