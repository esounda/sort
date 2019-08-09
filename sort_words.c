#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct ht_s {
    char ch;
    int count;
} ht_t;

void main ()
{
    ht_t *ht;
    char word[MAX];
    int i, j;

    printf("Enter the input string\n");
    fgets(word, MAX, stdin);

    ht = malloc (sizeof(ht_t) * 26);

    for (i=0; i<26; i++) {
        memset(&ht[i], 0, sizeof(ht_t));
    }

    printf("string len %d\n", strlen(word));

    for (i=0; i< (strlen(word)-1); i++) {
        j = word[i] - 'a';
        ht[j].ch = word[i];
        ht[j].count++;
    }

    for (i=0; i<26; i++) {
        if (ht[i].count != 0) {
            printf("%c : %d\n", ht[i].ch, ht[i].count);
        }
    }

    for (i=0; i< 26; i++) {
        while(ht[i].count > 0) {
            printf("%c", ht[i].ch);
            ht[i].count--;
        }
    }

    printf("\n");
}

