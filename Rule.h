#ifndef RULE_H
#define RULE_H

#include "Board.h"

class Rule {

public:
	int i;
	int j;
	char player;

	void applyRule(Board &mainBoard);

	void undoRule(Board &mainBoard);
};

void Rule::applyRule(Board &mainBoard) {

	mainBoard.board[i][j] = player;
	mainBoard.nodeCount++;
	mainBoard.setCurrentPlayer();

}

void Rule::undoRule(Board &mainBoard) {

	mainBoard.board[i][j] = '_';
	mainBoard.setCurrentPlayer();

}

#endif