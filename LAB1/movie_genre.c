/*Problem:-
---You are asked to conduct a survey at a movie theatre to find the most watched movie genre.Write a C program to store the collected data using structures.The program should contain a function that allows users to input their names,movie watched and genre of the movie.Use this collected data to find out the most watched movie genre and print it. If there are multiple such movie genres,then print all of them.
*/

#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 100
#define MAX_GENRE 100

typedef struct {
    char name[50];
    char movie[50];
    char genre[20];
} Survey;

void inputSurveyData(Survey surveys[], int n) {
    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", surveys[i].name);
        scanf(" %[^\n]", surveys[i].movie);
        scanf(" %[^\n]", surveys[i].genre);
    }
}

void findMostWatchedGenres(Survey surveys[], int n) {
    int genreCount[MAX_GENRE] = {0};
    char genres[MAX_GENRE][20];
    int genreIndex = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < genreIndex; j++) {
            if (strcmp(surveys[i].genre, genres[j]) == 0) {
                genreCount[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(genres[genreIndex], surveys[i].genre);
            genreCount[genreIndex]++;
            genreIndex++;
        }
    }

    int maxCount = 0;
    for (int i = 0; i < genreIndex; i++) {
        if (genreCount[i] > maxCount) {
            maxCount = genreCount[i];
        }
    }

    int first = 1;
    for (int i = 0; i < genreIndex; i++) {
        if (genreCount[i] == maxCount) {
            if (!first) {
                printf(" ");
            }
            printf("%s", genres[i]);
            first = 0;
        }
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    Survey surveys[MAX_PEOPLE];

    if (n > 0) {
        inputSurveyData(surveys, n);
        findMostWatchedGenres(surveys, n);
    } else {
        printf("\n");
    }

    return 0;
}