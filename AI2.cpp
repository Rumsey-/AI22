
	
#include<string>
#include<iostream>
#include <list>
#include "Rule.h"	
#include "Board.h"

//http://blog.circuitsofimagination.com/2014/06/29/MiniMax-and-Tic-Tac-Toe.html
//http://www.ocf.berkeley.edu/~yosenl/extras/alphabeta/alphabeta.html

using namespace std;

char backTrack(Board &mainBoard, Rule ruleCurrent) {
	

	ruleCurrent.applyRule(mainBoard);
	mainBoard.printBoard();
	char player = mainBoard.checkWin();
	if (player != '_') return player;
	char winner = '_';
	int i, j;
	player = mainBoard.currentPlayer;

	list<Rule> rulesList;
	for (i = 0; i<3; i++) {
		for (j = 0; j<3; j++) {
			if (mainBoard.board[i][j] == '_') {
				Rule newRule;
				newRule.i = i;
				newRule.j = j;
				newRule.player = player;
				rulesList.push_back(newRule);
			}
		}
	}
	while (rulesList.size() != 0) {
		Rule currentRule = rulesList.front();
		winner = backTrack(mainBoard, currentRule);
		if (winner != '_')
		currentRule.undoRule(mainBoard);
		rulesList.pop_front();
	}
	return winner;

}
char backTrackStart(Board &mainBoard) {

	list<Rule> rulesList;
	char player = mainBoard.currentPlayer;
	char winner = '_';
	int i, j;
	for (i = 0; i<3; i++) {
		for (j = 0; j<3; j++) {
			if (mainBoard.board[i][j] == '_') {
				Rule newRule;
				newRule.i = i;
				newRule.j = j;
				newRule.player = player;
				rulesList.push_back(newRule);
			}
		}
	}
 	while (rulesList.size() != 0) {
		Rule currentRule = rulesList.front();
		winner = backTrack(mainBoard, currentRule);
		if (winner!='_')
		currentRule.undoRule(mainBoard);
		rulesList.pop_front();
	}
	return winner;

}

int score(char player) {
	if (player == 'X') return 1;
	
	if (player == 'O') return -1;
	
	if (player == 'D') return 0;
}
int minimax(Board &mainBoard) {

	char player = mainBoard.checkWin();
	if (player != '_') return score(player);
	
	int score, bestScore;
	int i, j;
	list<Rule> rulesList;
	for (i = 0; i<3; i++) {
		for (j = 0; j<3; j++) {
			if (mainBoard.board[i][j] == '_') {
				Rule newRule;
				newRule.i = i;
				newRule.j = j;
				newRule.player = mainBoard.currentPlayer;
				rulesList.push_back(newRule);
			}
		}
	}

	if (mainBoard.currentPlayer == 'X') {
		while (rulesList.size() != 0) {
			bestScore = -2; //-2 is even worse than O winning, so must find a better score than this
			Rule currentRule = rulesList.front();
			currentRule.applyRule(mainBoard);
			score = minimax(mainBoard);
			if (score>bestScore) bestScore = score;
			currentRule.undoRule(mainBoard);
			rulesList.pop_front();
		}
		return bestScore;
	}

	else if (mainBoard.currentPlayer == 'O') {
		while (rulesList.size() != 0){
			bestScore = 2; //2 is worse than X winning, so O can find a better move than this
			Rule currentRule = rulesList.front();
			currentRule.applyRule(mainBoard);
			score = minimax(mainBoard);
			if (score < bestScore) bestScore = score;
			currentRule.undoRule(mainBoard);
			rulesList.pop_front();
		}
		return bestScore;
	}


}

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
	mainBoard.setCurrentPlayer();

	if (mainBoard.currentPlayer == 'E') {
		cout << "Invalid board position" << endl;
	}

	char player = mainBoard.checkWin();

    if (player != '_') {
		cout << "Winning position input: " << player << " wins!" << endl;
    }

	int score = minimax(mainBoard);
	cout << "Game Result: " << score << endl;
	cout << "Moves considered without alpha-beta pruning: " << mainBoard.nodeCount << endl;

	return 0;

}

