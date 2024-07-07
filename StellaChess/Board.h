#pragma once
#include <vector>
#include <string>
#include <iostream>

const static unsigned char PAWN = 0b00001;
const static unsigned char BISHOP = 0b00010;
const static unsigned char KNIGHT = 0b00011;
const static unsigned char ROOK = 0b00100;
const static unsigned char C_ROOK = 0b00101; //rook after having castled/moved
const static unsigned char QUEEN = 0b00110;
const static unsigned char KING = 0b00111;

const static unsigned char BLACK = 0b01000;
const static unsigned char WHITE = 0b10000;

const static unsigned char TYPE_MASK = 0b00111;
const static unsigned char COLOR_MASK = 0b11000;

const static char material_scores[24] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 3, 3, 5, 5, 9, 0, //king is 0 cause it doesnt matter for calculating
	0, -1, -3, -3, -5, -5, -9, 0
};

const static unsigned char piece_symbols[24] = {
	' ', '*', '*', '*', '*', '*', '*', '*',
	'*', 'p', 'b', 'n', 'r', 'c', 'q', 'k',
	'*', 'P', 'B', 'N', 'R', 'C', 'Q', 'K'
};

struct Position {
	unsigned char rank;
	unsigned char file;
};

struct Move {
	unsigned char moving_piece;
	struct Position start;
	struct Position end;
};

class Board
{
public:
	Board();
	void from_fen(std::string fen);
	bool move(struct Position start, struct Position end);
	int material(); //returns material advantage, positive for white neg for black
	void print();
protected:
	unsigned char pieces[8][8];
	unsigned int play_count;
	bool white_castle;
	bool black_castle; //if king moves set these to false, to castle must have rook (not c rook)
	unsigned int count_50; //50 move rule counter
	std::vector<struct Move> last_3_moves; //for 3fold repetition

	bool en_passant[2][8]; //first is black en passant possibilites, second is white

};

