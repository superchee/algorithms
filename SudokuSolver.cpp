#include <stdlib.h>
#include <string.h>

int Backtrack(char** board, int row, int col, int* rowBit, int* colBit, int* blockBit){
    if (row == 9)
        return true;
    if (col == 9)
        return Backtrack(board, row+1, 0, rowBit, colBit, blockBit);
    if (board[row][col] != '.') return Backtrack(board, row, col+1, rowBit, colBit, blockBit);
    for (int i = 1; i < 10; i++){

        if ((rowBit[row] & (1 << i)) || (colBit[col] & (1 << i)) || (blockBit[(row/3)*3 + col/3] & (1 << i))) continue;
        rowBit[row] = rowBit[row] + (1<<i);
        colBit[col] = colBit[col] + (1<<i);
        blockBit[(row/3)*3 + col/3] += (1<<i);     

        board[row][col] = '0' + i;
        if (Backtrack(board, row, col+1, rowBit, colBit, blockBit)){
            return true;
        }else{
            board[row][col] = '.';
            rowBit[row] = rowBit[row] - (1<<i);
            colBit[col] = colBit[col] - (1<<i);
            blockBit[(row/3)*3 + col/3] -=  (1<<i);  
        }
    }

    return false;
}

void solveSudoku(char** board, int boardSize, int* boardColSize){
    int rowBit[9]={0}, colBit[9]={0}, blockBit[9]={0};

    int temp = 0;

    //init
    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < boardSize; j++){
            if (board[i][j] == '.') continue;
            temp = board[i][j] - '0';
            rowBit[i] = rowBit[i] + (1<<temp);
            colBit[j] = colBit[j] + (1<<temp);
            blockBit[(i/3)*3 + j/3] += (1<<temp);
        }
    }

    Backtrack(board, 0, 0, rowBit, colBit, blockBit);
}
/****
#define MSIZE 9

int check(char** board, int row, int col, char value){
    for(int i = 0; i < 9; i++){
        if(board[row][i] == value) return true;
    }
    for (int i = 0; i < 9; i++){
        if (board[i][col] == value) return true;
    }
    for (int i = 0; i < 9; i++){
        int r = (row/3)*3 + i/3;
        int c = (col/3)*3 + i%3;
        if (board[r][c] == value) return true;
    }
    return false;
}


int Backtrack(char** board, int row, int col, int* rowBit, int* colBit, int* blockBit){
    if (row == MSIZE)
        return true;
    if (col == MSIZE)
        return Backtrack(board, row+1, 0, rowBit, colBit, blockBit);
    if (board[row][col] != '.') return Backtrack(board, row, col+1, rowBit, colBit, blockBit);
    for (int i = 1; i <= MSIZE; i++){

        if (check(board, row, col, '0'+i)) continue;  

        board[row][col] = '0' + i;
        if (Backtrack(board, row, col+1, rowBit, colBit, blockBit)){
            return true;
        }else{
            board[row][col] = '.';
        }
    }

    return false;
}

void solveSudoku(char** board, int boardSize, int* boardColSize){
    int rowBit[MSIZE] = {0}, colBit[MSIZE] = {0}, blockBit[MSIZE] = {0};

    int temp = 0;

    //init
    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < boardSize; j++){
            if (board[i][j] == '.') continue;
            temp = board[i][j] - '0';
            rowBit[i] = rowBit[i] + (1<<temp);
            colBit[j] = colBit[j] + (1<<temp);
            blockBit[(i/3)*3 + j/3] = blockBit[(i/3)*3 + j/3] + (1<<temp);
        }
    }

    Backtrack(board, 0, 0, rowBit, colBit, blockBit);
}

***/

