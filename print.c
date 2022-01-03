void empty_stdin (void) //funkcja oczyszczajaca bufor w przypadku podania zmiennej innej niz int
{
    int c = getchar();

    while (c != '\n')
        c = getchar();
}

int printMenuInGame(char array[6][7], int column, int round, int undo){
    system("clear");
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
        default: system("clear"); system("cls"); printf("Podano bledna komende.\n"); empty_stdin(); printMenuInGame(array, column, round, undo);
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
        default: system("clear"); system("cls"); printf("Podano bledna komende.\n"); empty_stdin(); printMenu();
    }
}

void printField(char array[6][7], char* name1, char* name2, int round, int wrong, int wrongCommand, int failedUndo){
    system("clear");
    printf("Tura gracza: ");
    if(round % 2 == 1) {
        printf("%s\n", name1);
    } else {
        printf("%s\n", name2);
    }
    printf("Tura numer: %d\n", round);
    printf("%d:%d", min, sec);


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