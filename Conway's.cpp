// Created by: Talon Jones
// Purpose: Simple exercise to practice C++
// Name: Conway's Game of Life

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

typedef vector< vector<int> > myVector;

class board {
    myVector myBoard;
    int generation = 0;
    public:
        board(const myVector& x) : myBoard(x) {};
        void updateLife();
        void printBoard();
};

void board::updateLife() {
    myVector tempBoard = myBoard;
    int count;

    for(int i = 1; i < myBoard.size()-1; i++) {
        for(int j = 1; j < myBoard[i].size()-1; j++) {
            count = 0;
            count = myBoard[i-1][j-1] + myBoard[i-1][j] + myBoard[i-1][j+1] +
                    myBoard[i][j-1] + myBoard[i][j] + myBoard[i][j+1] +
                    myBoard[i+1][j-1] + myBoard[i+1][j] + myBoard[i+1][j+1];
            if(count < 2 || count > 3) {
                tempBoard[i][j] = 0;
            } else if(count == 2) {
                tempBoard[i][j] = myBoard[i][j];
            } else if(count == 3) {
                tempBoard[i][j] = 1;
            } else {
                cout << "Error" << endl;
            }
        }
    }
    myBoard = tempBoard;
    generation++;
}

void board::printBoard() {
    cout << "Generation: " << generation << endl;
    for(int i = 1; i < myBoard.size()-1; i++) {
        for(int j = 1; j < myBoard[i].size()-1; j++) {
            cout << myBoard[i][j] << " ";
        }
        cout << endl;
    }
}

myVector genBoard(int width, int height) {
    myVector newBoard(height+2, vector<int>(width+2));
    for(int i = 0; i < newBoard.size(); i++) {
        for(int j = 0; j < newBoard[i].size(); j++) {
            newBoard[i][j] = rand() % 2;
        }
    }
    return newBoard;
}

int main(int argc, char* argv[]) {
    int x, y;
    char cont = 'y';
    cout << "Enter board width and height (x y): ";
    cin >> x >> y;
    board gameBoard(genBoard(x,y));
    while(cont == 'y' || cont == 'Y') {
        gameBoard.printBoard();
        gameBoard.updateLife();
        cout << "Continue? (y/n): ";
        cin >> cont;
    }
}