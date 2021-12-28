int checkDraw(char array[6][7]){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            if(array[i][j] == 5) {
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

int checkWinHorizontal(char array[6][7], int round){
    int length = 0;
    if(round % 2 == 1){
        int seek = 99;
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

    } else {
        int seek = 122;
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
    }
    return 0;
}
int checkWinVertical(char array[6][7], int round){
    int length = 0;
    if(round % 2 == 1){
        int seek = 99;
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 7; j++){
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

    } else {
        int seek = 122;
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 7; j++){
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
    }
    return 0;
}
int checkWinDiagonallyLeft(char array[6][7], int round){
    int length = 0;
    return 0;
}
int checkWinDiagonallyRight(char array[6][7], int round){
    int length = 0;
    return 0;
}