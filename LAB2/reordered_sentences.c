/*Problem:- 
---Write a C program that contains an ‘input’ function that inputs a sentence and stores the words in it as an array of structures.Then sort these words lexicographically(order in which they appear in the dictionary) and generate a sentence from them.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct stud {
    char word[200];
} node;

node* input(int *senlen) {
    char sentence[10000];
    node *words = (node*)malloc(1000 * sizeof(node));
    *senlen = 0;

    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';

    char *token = strtok(sentence, " ");
    while (token != NULL) {
        strcpy(words[*senlen].word, token);
        (*senlen)++;
        token = strtok(NULL, " ");
    }

    return words;
}

int compare(const void *a, const void *b) {
    return strcmp(((node*)a)->word, ((node*)b)->word);
}

void generateSentence(node *words, int senlen) {
    for (int i = 0; i < senlen; i++) {
        printf("%s", words[i].word);
        if (i < senlen - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int senlen;
    node *words = input(&senlen);

    qsort(words, senlen, sizeof(node), compare);
    generateSentence(words, senlen);

    free(words);
    return 0;
}
