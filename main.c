#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

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

void printField(char array[6][7]){

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

int gameEnd() {                                 //funkcja sprawdzajaca stan gry po kazdym ruchu


    return 0;
}

int main() {
    int sec = 0, min = 0;
    pthread_t thread_id;                        //deklaracja id wątku
    FILE *fptr;
    fptr = fopen("data.bin", "ab+");            //plik z danymi o graczach i wynikach
    char array[6][7];                           //tablica charow, zeby byl czytelnieszy output
    for (int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){             //zerowanie tablicy
            array[i][j] = 177;
        }
    }
    printMenu();
    pthread_create(&thread_id, NULL, timer, NULL);          //rozpoczecie watku z timerem


    return 0;
}