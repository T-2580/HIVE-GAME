#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QGraphicsView>
#include "gameboard.h"
#include "hexbutton.h"

class GameWindowPrivate;

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private:
    void handleHexagonClick(int row, int col);

    GameBoard *gameBoard;
    QHBoxLayout *mainLayout; // 主布局改为水平布局
    QVBoxLayout *verticalLayoutForBoardAndStatus; // 棋盘及其状态标签的垂直布局

    QString getInsectName(Piece* piece);

    QHBoxLayout *horizontalLayoutForPieces; // 棋子按钮的水平布;局
    QVBoxLayout *verticalLayoutForPiecesLeft; // 左侧棋子按钮的垂直布局
    QVBoxLayout *verticalLayoutForPiecesRight; // 右侧棋子按钮的垂直布局

    QLabel *statusLabel;
    QGraphicsView *graphicsView;
    HexButton *pieceButtons[20];
    GameWindowPrivate *d_ptr;
    QSize calculateBoardSize(int rows, int cols, qreal hexSize);

private slots:
    void onPieceClicked(int pieceIndex);
};

#endif // GAMEWINDOW_H
