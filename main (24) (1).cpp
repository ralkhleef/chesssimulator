#include "ChessBoard.h"
#include <iostream>
#include <cctype>

int main() {
    ChessBoard board;
    int startX, startY, moveIndex;
    char continuePlaying = 'y';

    while (tolower(continuePlaying) == 'y') {
        board.printBoard();
        std::cout << "\nEnter the position of the piece to move (row [1-8] col [1-8]): ";
        std::cin >> startX >> startY;
        startX--; // Adjust for 0-indexed internal representation
        startY--;

        board.printPossibleMoves(startX, startY);

        std::cout << "\nEnter the move number to move the piece, or -1 to choose another piece: ";
        std::cin >> moveIndex;

        if (moveIndex == -1) continue;

        auto moves = board.getPossibleMoves(startX, startY);
        if (moveIndex >= 0 && moveIndex < moves.size()) {
            if (board.movePiece(startX, startY, moves[moveIndex].first, moves[moveIndex].second)) {
                std::cout << "Move successful.\n";
            } else {
                std::cout << "Move failed.\n";
            }
        } else {
            std::cout << "Invalid move number. Try again.\n";
        }

        std::cout << "Continue playing? (y/n): ";
        std::cin >> continuePlaying;
    }

    return 0;
}


