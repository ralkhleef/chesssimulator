#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <iostream>
#include <vector>
#include <memory>

enum class PieceType { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN };

class ChessPiece {
public:
    virtual ~ChessPiece() {}
    virtual PieceType getType() const = 0;
    virtual char getSymbol() const = 0;
    virtual std::vector<std::pair<int, int>> getPossibleMoves(int x, int y, const std::vector<std::vector<std::shared_ptr<ChessPiece>>>& board) const = 0;
};

class King : public ChessPiece {
public:
    PieceType getType() const override { return PieceType::KING; }
    char getSymbol() const override { return 'K'; }
    std::vector<std::pair<int, int>> getPossibleMoves(int x, int y, const std::vector<std::vector<std::shared_ptr<ChessPiece>>>& board) const override;
};

class Queen : public ChessPiece {
public:
    PieceType getType() const override { return PieceType::QUEEN; }
    char getSymbol() const override { return 'Q'; }
    std::vector<std::pair<int, int>> getPossibleMoves(int x, int y, const std::vector<std::vector<std::shared_ptr<ChessPiece>>>& board) const override;
};

class Bishop : public ChessPiece {
public:
    PieceType getType() const override { return PieceType::BISHOP; }
    char getSymbol() const override { return 'B'; }
    std::vector<std::pair<int, int>> getPossibleMoves(int x, int y, const std::vector<std::vector<std::shared_ptr<ChessPiece>>>& board) const override;
};

class Knight : public ChessPiece {
public:
    PieceType getType() const override { return PieceType::KNIGHT; }
    char getSymbol() const override { return 'N'; }
    std::vector<std::pair<int, int>> getPossibleMoves(int x, int y, const std::vector<std::vector<std::shared_ptr<ChessPiece>>>& board) const override;
};

class Rook : public ChessPiece {
public:
    PieceType getType() const override { return PieceType::ROOK; }
    char getSymbol() const override { return 'R'; }
    std::vector<std::pair<int, int>> getPossibleMoves(int x, int y, const std::vector<std::vector<std::shared_ptr<ChessPiece>>>& board) const override;
};

class Pawn : public ChessPiece {
public:
    PieceType getType() const override { return PieceType::PAWN; }
    char getSymbol() const override { return 'P'; }
    std::vector<std::pair<int, int>> getPossibleMoves(int x, int y, const std::vector<std::vector<std::shared_ptr<ChessPiece>>>& board) const override;
};

#endif
