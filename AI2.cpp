
	
#include<string>
#include<iostream>
#include "Rule.h"	
#include "Board.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2) {
		cout << "Invalid arguments" << endl;
		return -1;
	}

	string sizer = argv[1];

	if (sizer.length()!=9){
		cout << "Invalid board position!" << endl;
		return -1;
	}

	Board mainBoard;

	
	mainBoard.buildBoard(argv[1]);
	mainBoard.printBoard();
        
	char player = mainBoard.checkWin();

    if (player != '_') {
        cout << player << " wins!";
    }
    else {
        cout << "no winner";
    }
	return 0;

}

