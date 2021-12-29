void undoMove(char array[6][7], int column, int round, int undo){
    if(round == 1 || undo == 1) return;
    for(int i = 0; i < 6; i++){
        if(array[i][column] != 5){
            array[i][column] = 5;
        }
    }
}