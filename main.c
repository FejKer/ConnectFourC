#include <stdio.h>
#include <time.h>
//#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "checkMove.c"
#include "gameEnd.c"
#include "undoMove.c"

int sec = 0;
int min = 0;

//void *timer(void *threadid){
//    printField();
//    sleep(1);
//    sec++;
//    if(sec % 60 == 0){
//        sec = 0;
//        min++;
//    }
//}

void printField(char array[6][7], char* name1, char* name2, int round, int wrong, int wrongCommand, int failedUndo){
    system("clear");
    system("cls");
    printf("Tura gracza: ");
    if(round % 2 == 1) {
        printf("%s\n", name1);
    } else {
        printf("%s\n", name2);
    }
    printf("Tura numer: %d\n", round);


    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            printf("%c ", array[i][j]);     //wypisanie pola gry
        }
        printf("\n");
    }
    if(wrong){
        printf("\n");
        printf("*************************************\n");
        printf("Podana kolumna jest juz zajeta!!!\n");
        printf("*************************************\n");
    }
    if(wrongCommand){
        printf("\n");
        printf("*************************************\n");
        printf("Podano bledna komende!!!\n");
        printf("*************************************\n");
    }
    if(failedUndo){
        printf("\n");
        printf("*************************************\n");
        printf("Cofniecie bedzie dostepne po\n");
        printf("nastepnym wykonanym ruchu!!!\n");
        printf("*************************************\n");
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
        default: system("clear"); system("cls"); printf("Podano bledna komende.\n"); printMenu();
    }
}

int printMenuInGame(char array[6][7], int column, int round, int undo){
    int choice;
    printf("\n");
    printf("1. Powrot do gry\n");
    printf("2. Cofniecie ruchu\n");
    printf("3. Powrot do menu glownego\n");
    scanf("%d", &choice);
    switch(choice){
        case 1: return 0; break;
        case 2: undoMove(array, column, round, undo); return 1; break;                          //do zrobienia listy
        case 3: return 2; break;
        default: system("clear"); system("cls"); printf("Podano bledna komende.\n"); printMenuInGame(array, column, round, undo);
    }
}

int main() {
    system("cls");
    system("clear");
    int wrongCommand = 0;
    int wrong = 0;
    int round = 1;
    int column = 0;
    char name1[255];
    char name2[255];
//    int sec = 0, min = 0;                     //timer
    FILE *fptr;
    fptr = fopen("data.bin", "ab+");            //plik z danymi o graczach i wynikach
    char array[6][7];                           //tablica charow, zeby byl czytelnieszy output
    for (int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){             //zerowanie tablicy
            array[i][j] = 5;
        }
    }
    printMenu();
    
    printf("Podaj imie gracza 1.\n");
    scanf("%s", name1);
    printf("Podaj imie gracza 2.\n");
    scanf("%s", name2);

    int undo = 0;
    int failedUndo = 0;
    while(1){
        printField(array, name1, name2, round, wrong, wrongCommand, failedUndo);
        wrong = 0;
        wrongCommand = 0;
        printf("\n");
        printf("\n");
        printf("Podaj numer kolumny do ktorej chcesz wrzucic zeton.\n");
        printf("Lub wpisz 0 aby wejsc do menu.\n");
        scanf("%d", &column);
        if(column == 0){
            int ret = printMenuInGame(array, column, round, undo);
            if(ret == 1){
                if(!undo){
                    round--;
                } else {
                    failedUndo = 1;
                }
                undo = 1;       //cofniecie ruchu
                continue;
            } else if(ret == 2){
                main();           //powrot do menu programu
            }
        }
        if(column > 7 || column < 1){
            wrongCommand = 1;
            continue;
        }
        if(checkColumn(array, column)){
            if(round % 2 == 1){
                insertCoin(array, column, 'c');
            } else {
                insertCoin(array, column, 'z');
            }
            undo = 0;
            failedUndo = 0;
        } else {
            wrong = 1;
            round--;
        }

        if(checkDraw(array)){
            printf("Gra zakonczona remisem.\n");
        }
        if(checkWin(array, round)){
            printField(array, name1, name2, round, wrong, wrongCommand, failedUndo);
            printf("\n");
            printf("Gra zakonczona.\n");
            printf("Wygrywa ");                     //sprawdzenie zakonczenia gry
            if(round % 2 == 1){
                printf("%s!\n", name1);
            } else {
                printf("%s!\n", name2);
            }
            sleep(5);
            break;
        }
        round++;
    }




    // pthread_t thread_id; 
    // pthread_create(&thread_id, NULL, timer, NULL);          //rozpoczecie watku z timerem do zrobienia



    return 0;
}