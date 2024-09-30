#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "ChessPiece.h"
#include <vector>
#include <memory>
#include <utility>

class ChessBoard {
private:
    std::vector<std::vector<std::shared_ptr<ChessPiece>>> board;

public:
    ChessBoard();
    void setupInitialPositions();
    void printBoard(int highlightX = -1, int highlightY = -1);
    void printPossibleMoves(int x, int y);
    bool movePiece(int startX, int startY, int endX, int endY);
    std::vector<std::pair<int, int>> getPossibleMoves(int x, int y);
};

#endif

