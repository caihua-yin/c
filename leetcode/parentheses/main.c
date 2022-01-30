#include <stdio.h>
#include "list.h" 

int validate_parentheses(char *str)
{
    unsigned int i;
    list_node_t *node;
    int result = 0;
    list_t *list = list_new();


    for (i = 0; str[i] != '\0'; i++)
    {
        switch(str[i])
        {
            case '(':
            case '[':
            case '{':
                list_rpush(list, list_node_new(&str[i]));
                break;
            case ')':
                node = list_rpop(list);
                if('(' == *(char*)node->val)
                    break;
                else
                {
                    result = 1;
                    break;
                }
            case ']':
                node = list_rpop(list);
                if('[' == *(char*)node->val)
                    break;
                else
                {
                    result = 1;
                    break;
                }
            case '}':
                node = list_rpop(list);
                if('{' == *(char*)node->val)
                    break;
                else
                {
                    result = 1;
                    break;
                }
            default:
                result = -1;
        }
    }
    list_destroy(list);
    return result;
}

int main()
{
    printf("() valid? : %d\n", validate_parentheses("()"));
    printf("()[]{} valid? : %d\n", validate_parentheses("()[]{}"));
    printf("(] valid? : %d\n", validate_parentheses("(]"));
    printf("(1+2) valid? : %d\n", validate_parentheses("(1+2)"));
    return 0;
}
