extern int blank;

int checkDraw(char array[6][7]){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            if(array[i][j] == blank) {
                return 0;
            } 
        }
    }
    return 1;
}

int checkWin(char array[6][7], int round){
    if(checkWinHorizontal(array, round)){
        return 1;
    }
    if(checkWinVertical(array, round)){
        return 1;
    }
    if(checkWinDiagonallyLeft(array, round)){
        return 1;
    }
    if(checkWinDiagonallyRight(array, round)){
        return 1;
    }
    return 0;
}

int checkWinHorizontal(char array[6][7], int round){        //sprawdzenie wygranej poziomo
    int length = 0;
    int seek;
    if(round % 2 == 1){
        seek = 99;
    } else {
        seek = 122;
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            if(array[i][j] == seek){
                length++;
            } else {
                length = 0;
            }
            if(length > 3) {
                return 1;
            }
        }
    }
    return 0;
}
int checkWinVertical(char array[6][7], int round){          //sprawdzenie wygranej pionowo
    int length = 0;
    int seek;
    if(round % 2 == 1){
        seek = 99;
    } else {
        seek = 122;
    }
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 6; j++){
            if(array[j][i] == seek){
                length++;
            } else {
                length = 0;
            }
            if(length > 3) {
                return 1;
            }
        }
    }
    return 0;
}
int checkWinDiagonallyLeft(char array[6][7], int round){        //sprawdzenie wygranej ukos "\"
    int length = 0;
    int seek;
    if(round % 2 == 1){
        seek = 99;
    } else {
        seek = 122;
    }
    for(int i = 2; i < 6;){
        for(int j = 0; j <= 3; j++){
            if(array[i][j] == seek){
                length++;
            } else {
                length = 0;
            }
            if(length > 3){
                return 1;
            }
                i++;
        }
    }
    length = 0;

    for(int i = 1; i < 6;){
        for(int j = 0; j <= 4; j++){
            if(array[i][j] == seek){
                length++;
            } else {
                length = 0;
            }
            if(length > 3){
                return 1;
            }
            i++;
        }
    }
    length = 0;

    for(int i = 0; i < 6;){
        for(int j = 0; j <= 5; j++){
            if(array[i][j] == seek){
                length++;
            } else {
                length = 0;
            }
            if(length > 3){
                return 1;
            }
            i++;
        }
    }
    length = 0;

    for(int i = 0; i < 6;){
        for(int j = 1; j <= 6; j++){
            if(array[i][j] == seek){
                length++;
            } else {
                length = 0;
            }
            if(length > 3){
                return 1;
            }
            i++;
        }
    }
    length = 0;

    for(int i = 0; i < 5;){
        for(int j = 2; j <= 6; j++){
            if(array[i][j] == seek){
                length++;
            } else {
                length = 0;
            }
            if(length > 3){
                return 1;
            }
            i++;
        }
    }
    length = 0;

    for(int i = 0; i < 4;){
        for(int j = 3; j <= 6; j++){
            if(array[i][j] == seek){
                length++;
            } else {
                length = 0;
            }
            if(length > 3){
                return 1;
            }
            i++;
        }
    }

    return 0;
}
int checkWinDiagonallyRight(char array[6][7], int round){       //sprawdzenie wygranej ukos "/"
    int length = 0;
    int seek;
    if(round % 2 == 1){
        seek = 99;
    } else {
        seek = 122;
    }
    for(int i = 0; i < 4;){
        for(int j = 3; j >= 0; j--){
            if(array[i][j] == seek){
                length++;
            } else {
                length = 0;
            }
            if(length > 3){
                return 1;
            }
            i++;
        }
    }
    length = 0;

    for(int i = 0; i < 5;){
        for(int j = 4; j >= 0; j--){
            if(array[i][j] == seek){
                length++;
            } else {
                length = 0;
            }
            if(length > 3){
                return 1;
            }
            i++;
        }
    }
    length = 0;

    for(int i = 0; i < 6;) {
        for(int j = 5; j >= 0; j--){
            if(array[i][j] == seek){
                length++;
            } else {
                length = 0;
            }
            if(length > 3){
                return 1;
            }
            i++;
        }
    }
    length = 0;

    for(int i = 0; i < 6;){
        for(int j = 6; j >= 0; j--){
            if(array[i][j] == seek){
                length++;
            } else {
                length = 0;
            }
            if(length > 3){
                return 1;
            }
            i++;
        }
    }
    length = 0;

    for(int i = 1; i < 6;){
        for(int j = 6; j >= 0; j--){
            if(array[i][j] == seek){
                length++;
            } else {
                length = 0;
            }
            if(length > 3){
                return 1;
            }
            i++;
        }
    }
    length = 0;

    for(int i = 2; i < 6;){
        for(int j = 0; j >= 0; j--){
            if(array[i][j] == seek){
                length++;
            } else {
                length = 0;
            }
            if(length > 3){
                return 1;
            }
            i++;
        }
    }

    return 0;
}