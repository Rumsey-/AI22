#include<iostream>
using namespace std;

class Board {
public:
	char board[3][3];
	int nodeCount;

	void buildBoard(char* input);

	void printBoard();

	char checkWin();

};

void Board::printBoard() {

	cout << board[0][0] << " | ";
	cout << board[0][1] << " | ";
	cout << board[0][2] << endl;

	cout << "__|___|___" << endl;

	cout << board[1][0] << " | ";
	cout << board[1][1] << " | ";
	cout << board[1][2] << endl;

	cout << "__|___|___" << endl;

	cout << board[2][0] << " | ";
	cout << board[2][1] << " | ";
	cout << board[2][2] << endl;

}

void Board::buildBoard(char* input) {
	board[0][0] = input[0];
	board[0][1] = input[1];
	board[0][2] = input[2];
	board[1][0] = input[3];
	board[1][1] = input[4];
	board[1][2] = input[5];
	board[2][0] = input[6];
	board[2][1] = input[7];
	board[2][2] = input[8];
	return;
}

char Board::checkWin() {

	int i, j;
	char player = '_';
	//horizontal
	for (i = 0; i<3; i++) {
		for (j = 0; j<3; j++) {
			if (j == 0) player = board[i][j];
			if (board[i][j] != player) player = '_';
		}
		if (player != '_') {
			return player;
		}
	}
	//vertical
	for (i = 0; i<3; i++) {
		for (j = 0; j<3; j++) {
			if (j == 0) player = board[j][i];
			if (board[j][i] != player) player = '_';
			if (player != '_') {
				return player;
			}
		}
	}
	//diagonal 1
	if (board[0][0] != '_') {
		player = board[0][0];
		if (player != board[1][1] || player != board[2][2]) {
			player = '_';
		}
		if (player != '_') {
			return player;
		}
	}

	if (board[0][2] != '_') {
		player = board[0][2];
		if (player != board[1][1] || player != board[2][0]) {
			player = '_';
		}
		if (player != '_') {
			return player;
		}
	}
	return player;
}