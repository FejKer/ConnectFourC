#include <stdio.h>
#include <time.h>
//#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int sec = 0;
int min = 0;

void *timer(void *threadid){
    printField();
    sleep(1);
    sec++;
    if(sec % 60 == 0){
        sec = 0;
        min++;
    }
}

void printField(char array[6][7], char* name1, char* name2, int round){
    system("clear");
    printf("Tura gracza: ");
    if(round % 2 == 1) {
        printf("%s\n", name1);
    } else {
        printf("%s\n", name2);
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
}

void printMenu(){
    int choice;
    printf("1. Rozpoczecie gry\n");
    printf("2. Wyswietlenie tabeli wynikow\n");
    printf("3. Wyswietlanie danych gracza\n");
    scanf("%d", &choice);
    switch(choice){
        case 1: return;
        case 2: break;                          //do zrobienia listy
        case 3: break;
        default: printf("Podano bledna komende.\n"); printMenu();
    }
}

int main() {
    int round = 1;
    int column;
    char name1[255];
    char name2[255];
    int sec = 0, min = 0;
    FILE *fptr;
    fptr = fopen("data.bin", "ab+");            //plik z danymi o graczach i wynikach
    char array[6][7];                           //tablica charow, zeby byl czytelnieszy output
    for (int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){             //zerowanie tablicy
            array[i][j] = 0;
        }
    }
    printMenu();
    
    printf("Podaj imie gracza 1.\n");
    scanf("%s", name1);
    printf("Podaj imie gracza 2.\n");
    scanf("%s", name2);
    
    while(1){
        printField(array, name1, name2, round);
        printf("\n");
        printf("\n");
        printf("Podaj numer kolumny do ktorej chcesz wrzucic zeton.\n");
        scanf("%d", column);
        round++;
    }
    // pthread_t thread_id; 
    // pthread_create(&thread_id, NULL, timer, NULL);          //rozpoczecie watku z timerem do zrobienia



    return 0;
}