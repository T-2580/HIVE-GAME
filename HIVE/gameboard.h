#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsScene>
#include <QMap>
#include <QPair>
#include <QGraphicsPolygonItem>
#include <QBrush>
#include <QTimer>
#include <QGraphicsSceneMouseEvent>
#include <vector>

#include "Piece.h"

class GameBoard : public QGraphicsScene {
    Q_OBJECT

public:
    bool isEmptyBoard() const;
    ~GameBoard();
    GameBoard(QObject* parent = nullptr);
    void buildHexGrid(int rows, int cols, qreal hexSize);
    QPointF getCellCenter(int row, int col) const;
    QPolygonF createHexagon(qreal size) const;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void movePiece(int i, int row, int col, int fr = -1, int fc = -1);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void click(int row, int col);

    Piece *s[25] = {nullptr};
    static bool _bRedTurn;

    bool trymove(int id, int tr, int tc);
    bool isLegalMove(int id, int tr, int tc);
    bool hasNeighborWithRedOrSameColor(int id, int tr, int tc);
    bool isConnectedAfterMove(int id, int tr, int tc);
    bool isQueenPlacedCorrectly(int id);
    bool isCellEmpty(int row, int col);
    int getStoneId(int row, int col) const;
    bool win();
    std::vector<std::pair<int, int>> getNeighbors(int row, int col) const;
    bool isPieceSurrounded(int row, int col) const;
    bool isAllPiecesConnected() const;
    void dfs(int index, std::vector<bool>& visited, int* connectedCount) const;

    static GameBoard* getInstance(); // 获取单例实例


    // Getter methods
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    int getHexSize() const { return hexSize; }
    int getNum() const { return num; }
    const std::vector<std::vector<Piece*>>& getBoard() const { return board; }
    bool isRedTurn() const { return _bRedTurn; }
    int getNowPiece() const { return nowpiece; }

    // Setter methods
    void setRows(int newRows) { rows = newRows; }
    void setCols(int newCols) { cols = newCols; }
    void setHexSize(int newSize) { hexSize = newSize; }
    void setBoard(const std::vector<std::vector<Piece*>>& newBoard) { board = newBoard; }
    void setRedTurn(bool turn) { _bRedTurn = turn; }
    void setNum(int newNum) { num = newNum; }
    void setNowPiece(int newNowPiece) { nowpiece = newNowPiece; }

    std::shared_ptr<GameBoard> clone() const;
    int redpiece = -1;
    int aipieceID = -1;

private:
    int nowpiece=-1;
    int num = -1;
    int rows;
    int cols;
    qreal hexSize;

    std::vector<std::vector<Piece*>> board;
    QVector<QGraphicsPixmapItem*> pieces;
    QMap<QPair<int, int>, QPointF> hexCells;
    QPair<int, int> lastClickedPos;
    QPair<int, int> selectedPiecePos;

    static GameBoard* instance; // 单例实例
};

#endif // GAMEBOARD_H
