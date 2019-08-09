#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARR 5
#define STR_LEN 10
//Using selection sort
void str_sort (char str[][STR_LEN])
{
    char minstr[STR_LEN];
    int minidx;
    char temp[STR_LEN];
    int i, j;

    for (i=0; i<MAX_ARR; i++) {
        minidx = i;
        strcpy(minstr, str[i]);

        for (j=i+1; j<MAX_ARR; j++) {
            if (strcmp(minstr, str[j]) > 0) {
                strcpy(minstr, str[j]);
                minidx = j;
            }
        }

        if (minidx != i) {
            strcpy(temp, str[i]);
            strcpy(str[i], str[minidx]);
            strcpy(str[minidx], temp);
        }
    }

}

void main()
{
    char str[MAX_ARR][STR_LEN];
    int i;

    printf("Enter the input string\n");

    for (i=0; i<MAX_ARR; i++) {
        //scanf("%s", &str[i]);
        fgets(str[i], STR_LEN, stdin);
    }

    for (i=0; i<MAX_ARR; i++) {
        printf("%s", str[i]);
        printf(" ");
    }
    printf("\n");

    str_sort(str);

    for (i=0; i<MAX_ARR; i++) {
        printf("%s ", str[i]);
        printf(" ");
    }
    printf("\n");
}

