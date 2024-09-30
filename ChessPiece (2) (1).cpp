#include "ChessPiece.h"
#include <algorithm>
#include <vector>

std::vector<std::pair<int, int>> King::getPossibleMoves(int x, int y, const std::vector<std::vector<std::shared_ptr<ChessPiece>>>& board) const {
    std::vector<std::pair<int, int>> moves = {
        {x+1, y}, {x-1, y}, {x, y+1}, {x, y-1},
        {x+1, y+1}, {x+1, y-1}, {x-1, y+1}, {x-1, y-1}
    };
    moves.erase(std::remove_if(moves.begin(), moves.end(),
        [](const std::pair<int, int>& move) {
            return move.first < 0 || move.first >= 8 || move.second < 0 || move.second >= 8;
        }), moves.end());
    return moves;
}

std::vector<std::pair<int, int>> Queen::getPossibleMoves(int x, int y, const std::vector<std::vector<std::shared_ptr<ChessPiece>>>& board) const {
    std::vector<std::pair<int, int>> moves;
    for (int i = 1; i < 8; ++i) {
        if (x + i < 8 && !board[x + i][y]) moves.push_back({x + i, y});
        else break;
    }
    for (int i = 1; i < 8; ++i) {
        if (x - i >= 0 && !board[x - i][y]) moves.push_back({x - i, y});
        else break;
    }
    for (int i = 1; i < 8; ++i) {
        if (y + i < 8 && !board[x][y + i]) moves.push_back({x, y + i});
        else break;
    }
    for (int i = 1; i < 8; ++i) {
        if (y - i >= 0 && !board[x][y - i]) moves.push_back({x, y - i});
        else break;
    }
    for (int i = 1; i < 8; ++i) {
        if (x + i < 8 && y + i < 8 && !board[x + i][y + i]) moves.push_back({x + i, y + i});
        else break;
    }
    for (int i = 1; i < 8; ++i) {
        if (x - i >= 0 && y - i >= 0 && !board[x - i][y - i]) moves.push_back({x - i, y - i});
        else break;
    }
    for (int i = 1; i < 8; ++i) {
        if (x + i < 8 && y - i >= 0 && !board[x + i][y - i]) moves.push_back({x + i, y - i});
        else break;
    }
    for (int i = 1; i < 8; ++i) {
        if (x - i >= 0 && y + i < 8 && !board[x - i][y + i]) moves.push_back({x - i, y + i});
        else break;
    }
    return moves;
}

std::vector<std::pair<int, int>> Bishop::getPossibleMoves(int x, int y, const std::vector<std::vector<std::shared_ptr<ChessPiece>>>& board) const {
    std::vector<std::pair<int, int>> moves;
    for (int i = 1; i < 8; ++i) {
        if (x + i < 8 && y + i < 8 && !board[x + i][y + i]) moves.push_back({x + i, y + i});
        else break;
    }
    for (int i = 1; i < 8; ++i) {
        if (x - i >= 0 && y - i >= 0 && !board[x - i][y - i]) moves.push_back({x - i, y - i});
        else break;
    }
    for (int i = 1; i < 8; ++i) {
        if (x + i < 8 && y - i >= 0 && !board[x + i][y - i]) moves.push_back({x + i, y - i});
        else break;
    }
    for (int i = 1; i < 8; ++i) {
        if (x - i >= 0 && y + i < 8 && !board[x - i][y + i]) moves.push_back({x - i, y + i});
        else break;
    }
    return moves;
}

std::vector<std::pair<int, int>> Knight::getPossibleMoves(int x, int y, const std::vector<std::vector<std::shared_ptr<ChessPiece>>>& board) const {
    std::vector<std::pair<int, int>> moves = {
        {x+2, y+1}, {x+2, y-1}, {x-2, y+1}, {x-2, y-1},
        {x+1, y+2}, {x+1, y-2}, {x-1, y+2}, {x-1, y-2}
    };
    moves.erase(std::remove_if(moves.begin(), moves.end(),
        [](const std::pair<int, int>& move) {
            return move.first < 0 || move.first >= 8 || move.second < 0 || move.second >= 8;
        }), moves.end());
    return moves;
}

std::vector<std::pair<int, int>> Rook::getPossibleMoves(int x, int y, const std::vector<std::vector<std::shared_ptr<ChessPiece>>>& board) const {
    std::vector<std::pair<int, int>> moves;
    for (int i = 1; i < 8; ++i) {
        if (x + i < 8 && !board[x + i][y]) moves.push_back({x + i, y});
        else break;
    }
    for (int i = 1; i < 8; ++i) {
        if (x - i >= 0 && !board[x - i][y]) moves.push_back({x - i, y});
        else break;
    }
    for (int i = 1; i < 8; ++i) {
        if (y + i < 8 && !board[x][y + i]) moves.push_back({x, y + i});
        else break;
    }
    for (int i = 1; i < 8; ++i) {
        if (y - i >= 0 && !board[x][y - i]) moves.push_back({x, y - i});
        else break;
    }
    return moves;
}

std::vector<std::pair<int, int>> Pawn::getPossibleMoves(int x, int y, const std::vector<std::vector<std::shared_ptr<ChessPiece>>>& board) const {
    std::vector<std::pair<int, int>> moves;
    if (x + 1 < 8 && !board[x + 1][y]) {
        moves.push_back({x + 1, y});
        if (x == 1 && x + 2 < 8 && !board[x + 2][y]) {
            moves.push_back({x + 2, y});
        }
    }
    // Add diagonal capture moves for pawns
    if (x + 1 < 8 && y + 1 < 8 && board[x + 1][y + 1] && board[x + 1][y + 1]->getType() != getType()) {
        moves.push_back({x + 1, y + 1});
    }
    if (x + 1 < 8 && y - 1 >= 0 && board[x + 1][y - 1] && board[x + 1][y - 1]->getType() != getType()) {
        moves.push_back({x + 1, y - 1});
    }
    return moves;
}

