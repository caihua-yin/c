#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *number2Roman(int n)
{
    switch(n)
    {
        case 1:
            return "I";
        case 2:
            return "II";
        case 3:
            return "III";
        case 4:
            return "IV";
        case 5:
            return "V";
        case 6:
            return "VI";
        case 7:
            return "VII";
        case 8:
            return "VIII";
        case 9:
            return "IX";
        case 10:
            return "X";
        case 20:
            return "XX";
        case 30:
            return "XXX";
        case 40:
            return "XL";
        case 50:
            return "L";
        case 60:
            return "LX";
        case 70:
            return "LXX";
        case 80:
            return "LXXX";
        case 90:
            return "XC";
        case 100:
            return "C";
        case 200:
            return "CC";
        case 300:
            return "CCC";
        case 400:
            return "CD";
        case 500:
            return "D";
        case 600:
            return "DC";
        case 700:
            return "DCC";
        case 800:
            return "DCCC";
        case 900:
            return "CM";
        case 1000:
            return "M";
        case 2000:
            return "MM";
        case 3000:
            return "MMM";
    }
    return NULL;
}

char * intToRoman(int num)
{
    char *result = NULL;
    char *tmp;
    char **tmps = malloc(sizeof(char*) * 4);
    int tmpIndex = 0;
    unsigned long size = 0;
    int n = 0, m = 1;

    // Check whether num is in valid range
    if (num < 1 || num > 3999)
        return NULL;

    while (num)
    {
        n = num % 10;
        if (n != 0)
        {
            tmp = number2Roman(n * m);
            tmps[tmpIndex++] = tmp;
            size += strlen(tmp);
        }
        num /= 10;
        m *= 10;
    }

    result = malloc(size + 1);
    result[0] = '\0';
    while (--tmpIndex >= 0)
    {
        strcat(result, tmps[tmpIndex]);
    }
    free(tmps);

    return result;
}

int main()
{
    char *result = NULL;
    result = intToRoman(3);
    printf("3 is %s\n", result);
    free(result);

    result = intToRoman(58);
    printf("58 is %s\n", result);
    free(result);

    result = intToRoman(1994);
    printf("1994 is %s\n", intToRoman(1994));
    free(result);

    result = intToRoman(2000);
    printf("2000 is %s\n", intToRoman(2000));
    free(result);
    return 0;
}
