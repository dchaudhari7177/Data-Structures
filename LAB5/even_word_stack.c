#include <stdio.h>
#include <string.h>

#define MAX_WORDS 30
#define MAX_LENGTH 30

char stack[MAX_WORDS][MAX_LENGTH];
int top = -1;

void push(char word[]) {
    if (top == MAX_WORDS - 1) {
        printf("stack is full\n");
    } else {
        strcpy(stack[++top], word);
    }
}

char* pop() {
    if (top == -1) {
        printf("");
        return NULL;
    } else {
        return stack[top--];
    }
}

void processSentence(char sentence[]) {
    char result[1000] = "";
    char word[MAX_LENGTH];
    int wordIndex = 0;
    int wordCount = 0;
    int len = strlen(sentence);

    for (int i = 0; i <= len; i++) {
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            word[wordIndex] = '\0';
            wordCount++;

            if (wordCount % 2 == 0) {
                push(word);
            } else {
                strcat(result, word);
                strcat(result, " ");
            }

            wordIndex = 0;
        } else {
            word[wordIndex++] = sentence[i];
        }
    }

    char* poppedWord;
    while ((poppedWord = pop()) != NULL) {
        strcat(result, poppedWord);
        strcat(result, " ");
    }

    result[strlen(result) - 1] = '\0';

    printf("%s\n", result);
}

int main() {
    char sentence[1000];

    printf("");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';

    processSentence(sentence);

    return 0;
}