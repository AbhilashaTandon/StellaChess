#include "Board.h"

//bool piece_move(unsigned char piece, struct Position start, struct Position end) {
//
//}

Board::Board()
{
	for (unsigned char i = 0; i < 8; i++) {
		pieces[1][i] = WHITE | PAWN;
		pieces[6][i] = BLACK | PAWN;
	}
	pieces[0][0] = WHITE | ROOK;
	pieces[0][1] = WHITE | KNIGHT;
	pieces[0][2] = WHITE | BISHOP;
	pieces[0][3] = WHITE | QUEEN;
	pieces[0][4] = WHITE | KING;
	pieces[0][5] = WHITE | BISHOP;
	pieces[0][6] = WHITE | KNIGHT;
	pieces[0][7] = WHITE | ROOK;
	pieces[7][0] = BLACK | ROOK;
	pieces[7][1] = BLACK | KNIGHT;
	pieces[7][2] = BLACK | BISHOP;
	pieces[7][3] = BLACK | QUEEN;
	pieces[7][4] = BLACK | KING;
	pieces[7][5] = BLACK | BISHOP;
	pieces[7][6] = BLACK | KNIGHT;
	pieces[7][7] = BLACK | ROOK;

	play_count = 0;
	white_castle = true;
	black_castle = true;
	count_50 = 0;

	for (unsigned char i = 0; i < 8; i++) {
		en_passant[0][i] = false;
		en_passant[1][i] = false;
	}
}



void Board::from_fen(std::string fen)
{

}

bool Board::move(Position start, Position end)
{
	return false;
}

int Board::material()
{
	int material_score = 0;
	for (unsigned char i = 0; i < 8; i++) {
		for (unsigned char j = 0; j < 8; j++) {
			material_score += material_scores[pieces[i][j]];
		}
	}
	return material_score;
}

void Board::print()
{
	std::cout << "###################\n";
	for (int i = 7; i >= 0; i--) {

		std::cout << "# ";
		for (int j = 0; j < 8; j++) {
			std::cout << piece_symbols[pieces[i][j]] << " ";

		}
		std::cout << "#\n";
	}
	std::cout << "###################\n";
}
