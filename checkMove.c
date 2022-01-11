extern int blank;

int checkColumn(char array[6][7], int column) {                 //sprawdzenie czy kolumna jest juz pelna
    if(array[0][column - 1] != blank) {
        return 0;
    }
    return 1;
}

void insertCoin(char array[6][7], int column, char sign){                  //wrzucenie zetonu
    column--;                                                               //wyrownanie indeksowania tablic od 0
    for(int i = 5; i >= 0; i--){
        if(array[i][column] == blank){
            array[i][column] = sign;
            return;
        }
    }
}