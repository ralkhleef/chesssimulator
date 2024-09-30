#include "ChessBoard.h"
#include <iomanip>
#include <iostream>

ChessBoard::ChessBoard() : board(8, std::vector<std::shared_ptr<ChessPiece>>(8, nullptr)) {
    setupInitialPositions();
}

void ChessBoard::setupInitialPositions() {
    for (int i = 0; i < 8; i++) {
        board[1][i] = std::make_shared<Pawn>();
        board[6][i] = std::make_shared<Pawn>();
    }
    board[0][0] = std::make_shared<Rook>(); board[0][7] = std::make_shared<Rook>();
    board[7][0] = std::make_shared<Rook>(); board[7][7] = std::make_shared<Rook>();
    board[0][1] = std::make_shared<Knight>(); board[0][6] = std::make_shared<Knight>();
    board[7][1] = std::make_shared<Knight>(); board[7][6] = std::make_shared<Knight>();
    board[0][2] = std::make_shared<Bishop>(); board[0][5] = std::make_shared<Bishop>();
    board[7][2] = std::make_shared<Bishop>(); board[7][5] = std::make_shared<Bishop>();
    board[0][3] = std::make_shared<Queen>();
    board[7][3] = std::make_shared<Queen>();
    board[0][4] = std::make_shared<King>();
    board[7][4] = std::make_shared<King>();
}

void ChessBoard::printBoard(int highlightX, int highlightY) {
    std::vector<std::pair<int, int>> highlightMoves;
    if (highlightX >= 0 && highlightX < 8 && highlightY >= 0 && highlightY < 8 && board[highlightX][highlightY]) {
        highlightMoves = board[highlightX][highlightY]->getPossibleMoves(highlightX, highlightY, board);
    }

    std::cout << "    1  2  3  4  5  6  7  8\n";
    std::cout << "  -------------------------\n";
    for (int i = 0; i < 8; ++i) {
        std::cout << i + 1 << "|";
        for (int j = 0; j < 8; ++j) {
            bool isHighlighted = false;
            for (const auto& move : highlightMoves) {
                if (move.first == i && move.second == j) {
                    std::cout << " * "; // Highlight possible move
                    isHighlighted = true;
                    break;
                }
            }
            if (!isHighlighted) {
                if (board[i][j]) {
                    std::cout << " " << board[i][j]->getSymbol() << " ";
                } else {
                    std::cout << " . ";
                }
            }
        }
        std::cout << "|\n";
    }
    std::cout << "  -------------------------\n";
}

std::vector<std::pair<int, int>> ChessBoard::getPossibleMoves(int x, int y) {
    if (x < 0 || x >= 8 || y < 0 || y >= 8 || !board[x][y]) {
        return {};
    }
    return board[x][y]->getPossibleMoves(x, y, board);
}

void ChessBoard::printPossibleMoves(int x, int y) {
    if (x < 0 || x >= 8 || y < 0 || y >= 8 || !board[x][y]) {
        std::cout << "No piece at position (" << x + 1 << ", " << y + 1 << ")\n"; // Adjust output for user-friendly display
        return;
    }

    auto moves = getPossibleMoves(x, y);
    std::cout << "Possible moves for " << board[x][y]->getSymbol() << " at (" << x + 1 << ", " << y + 1 << "):\n";
    for (size_t i = 0; i < moves.size(); ++i) {
        std::cout << i << ": (" << moves[i].first + 1 << ", " << moves[i].second + 1 << ")\n"; // Adjust output for user-friendly display
    }
    printBoard(x, y);
}

bool ChessBoard::movePiece(int startX, int startY, int endX, int endY) {
    if (startX < 0 || startX >= 8 || startY < 0 || startY >= 8 || !board[startX][startY]) {
        std::cout << "No piece at start position (" << startX + 1 << ", " << startY + 1 << ")\n"; // Adjust output for user-friendly display
        return false;
    }

    auto possibleMoves = getPossibleMoves(startX, startY);
    for (const auto& move : possibleMoves) {
        if (move.first == endX && move.second == endY) {
            board[endX][endY] = board[startX][startY];
            board[startX][startY] = nullptr;
            return true;
        }
    }

    std::cout << "Invalid move\n";
    return false;
}

