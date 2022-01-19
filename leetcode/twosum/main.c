#include <stdio.h>
#include "hashmap.h" 

#define UNUSED(x) (void)(x)

int n2_solution(int* arr, unsigned int arrlen, int sum)
{
    unsigned int left,right;
    unsigned int i,j;

    printf("The length of input array is: %u\n", arrlen);

    for (i = 0; i < arrlen; i++)
    {
        for (j = i; j < arrlen; j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                left = i;
                right = j;
                printf("The result is arr[%u]=%d and arr[%u]=%d\n", left, arr[left], right, arr[right]);
                return 0;
            }
        }
    }
    printf("No answer!\n");
    return 1;
}

typedef struct Entry
{
    int key;
    int value;
} Entry;

int user_compare(const void *a, const void *b, void *udata) {
    const Entry *ea = a;
    const Entry *eb = b;
    UNUSED(udata);
    return ea->key > eb->key ? 1 : (ea->key < eb->key ? -1 : 0);
}

bool user_iter(const void *item, void *udata) {
    const Entry *e = item;
    UNUSED(udata);
    printf("(key: %d, value: %d)\n", e->key, e->value);
    return true;
}

uint64_t user_hash(const void *item, uint64_t seed0, uint64_t seed1) {
    const Entry *e = item;
    return hashmap_sip(&e->key, sizeof(int), seed0, seed1);
}

int n_solution(int* arr, unsigned int arrlen, int sum)
{
    unsigned int left, right;
    unsigned int i;
    Entry *e;

    // create a new hash map where each item is a `struct entry`. The second
    // argument is the initial capacity. The third and fourth arguments are
    // optional seeds that are passed to the following hash function.
    struct hashmap *map = hashmap_new(sizeof(Entry), 0, 0, 0,
                                     user_hash, user_compare, NULL, NULL);

    for (i = 0; i < arrlen; i++)
    {
        e = hashmap_get(map, &(struct Entry) { .key = sum - arr[i] });
        if (e)
        {
            left = e->value;
            right = i; 
            break;
        }
        else
        {
            hashmap_set(map, &(struct Entry) { .key=arr[i], .value=i });
        }
    }

    hashmap_free(map);
    
    if(i < arrlen)
    {
        printf("The result is arr[%u]=%d and arr[%u]=%d\n", left, arr[left], right, arr[right]);
        return 0;
    }
    else
    {
        printf("No answer!\n");
        return 1;
    }

}

int main()
{
    int sum;
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int arrlen = sizeof(arr)/sizeof(int);
    printf("Type the sum:");
    scanf("%d", &sum);

    return n_solution(arr, arrlen, sum);
    //return n2_solution(arr, arrlen, sum);
}
