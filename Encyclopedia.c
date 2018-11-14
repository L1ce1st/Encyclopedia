#include <stdio.h>
#include <stdlib.h>
#include <sys\stat.h>
#include <string.h>

int CountStrings(FILE *f1);
//int Compare(const void * x1, const void * x2);

int main() {
    FILE *Hamlet = NULL;
    //FILE *sort = NULL;
    int nStrings = CountStrings(Hamlet);
    //sort = fopen("sort.txt","w");

    struct stat buff;
    if ((Hamlet = fopen("Hamlet 1.txt", "r")) == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }
    stat("Hamlet 1.txt", &buff);
    printf("Size of the file is: %ld\n", buff.st_size);
    char *hamlet = calloc(buff.st_size, sizeof(char));
    fread(hamlet, sizeof(char), buff.st_size, Hamlet);
    int ptrnum = 1;
    int nSymbol = 0;
    char **ptr = (char **) calloc(nStrings, sizeof(int));
    ptr[0] = &hamlet[0];
    for (int i = 0; hamlet[i] != '\0'; i++) {
        if (hamlet[i] == '\n') {
            hamlet[i] = '\0';
            ptr[ptrnum] = &hamlet[0] + i + 1;
            ptrnum++;
        }
       // printf("%c", hamlet[i]);
        nSymbol = i;
    }
    char *ptrparttime = 0;
    for (int i = 0; i <= nStrings; i++)
        for (int j = 0; j <= nStrings; j++) {
            [. , ! ? ; :    ]
            if (strcmp(ptr[i], ptr[j]) < 0) {
                ptrparttime = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = ptrparttime;
            }
        }

    for (int i = 0; i <= nStrings; i++)
        for (int j = 0; j <= nSymbol; j++) {
            if (ptr[i][j] == '\0') {
                printf("\n");
                break;
            }
            printf("%c", ptr[i][j]);
        }
       // fclose(sort);
return 0;
}

int CountStrings(FILE *f1) {

    f1 = fopen("Hamlet 1.txt", "r");
    int sum = 0;
    int letter;
    for (;;) {
        letter = getc(f1);
        if (letter == EOF) {
            sum = sum - 1;
            break;
        }
        if (letter == '\n') {
            sum++;
        }
    }
    printf("%d\n", sum);
    fclose(f1);

    return sum;
}

