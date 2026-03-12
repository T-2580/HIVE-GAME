#ifndef PIECE_H
#define PIECE_H


#include <QGraphicsPolygonItem>
#include <QBrush>
#include <QColor>
#include <QPointF>


enum InsectType {
    QUEEN,  // 蜂后
    ANT,    // 蚂蚁
    SPIDER, // 蜘蛛
    BEETLE, // 甲虫
    GRASSHOPPER, // 蚂蚱
    LADYBUG,    // 瓢虫
    none
};


struct Position {
    int row; // 行号
    int col; // 列号

    Position(int r = 0, int c = 0) : row(r), col(c) {}

    bool operator==(const Position& other) const {
        return row == other.row && col == other.col;
    }
};


class Piece : public QGraphicsPolygonItem {
public:

    QString drawPiece(bool p1, InsectType type);
    Piece();
    int id;
    int row = -1;
    int col = -1;
    int num = -1;
    bool _red;
    InsectType m_type;

    virtual ~Piece() {}

    virtual bool canMoveTo(const std::vector<std::vector<Piece*>>& board, const Position& from, const Position& to) const = 0; // 移动合法性检查

    bool isPressedFlag = 0;

private:

};


class Queen : public Piece {
public:
    Queen() {}
    ~Queen() {}

    bool canMoveTo(const std::vector<std::vector<Piece*>>& board, const Position& from, const Position& to) const override;
};


class Ant : public Piece {
public:
    InsectType m_type = ANT;

    bool canMoveTo(const std::vector<std::vector<Piece*>>& board, const Position& from, const Position& to) const;
private:
    std::vector<Position> getAdjacentPositions(int row, int col) const;
};


class Spider : public Piece {
    InsectType m_type = SPIDER;

    bool canMoveTo(const std::vector<std::vector<Piece*>>& board, const Position& from, const Position& to) const;
private:
    std::vector<Position> getAdjacentPositions(int row, int col) const;
};


class Beetle : public Piece {
    InsectType m_type = BEETLE;

    bool canMoveTo(const std::vector<std::vector<Piece*>>& board, const Position& from, const Position& to) const;
};


class Grasshopper : public Piece {
    InsectType m_type = GRASSHOPPER;

    bool canMoveTo(const std::vector<std::vector<Piece*>>& board, const Position& from, const Position& to) const;
    bool checkAndMove(const std::vector<std::vector<Piece*>>& board, int& currentRow, int& currentCol, bool& foundPiece) const;
};


class Ladybug : public Piece {
    InsectType m_type = LADYBUG;

    bool canMoveTo(const std::vector<std::vector<Piece*>>& board, const Position& from, const Position& to) const;
private:
    std::vector<Position> getAdjacentPositions(int row, int col) const;
};

#endif // PIECE_H
