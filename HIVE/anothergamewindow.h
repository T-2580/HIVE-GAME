#ifndef ANOTHERGAMEWINDOW_H
#define ANOTHERGAMEWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QGraphicsView>
#include "gameboard.h"
#include "hexbutton.h"

class AnotherGameWindowPrivate;

class AnotherGameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AnotherGameWindow(QWidget *parent = nullptr);
    ~AnotherGameWindow();



private:
    void handleHexagonClick(int row, int col);
    GameBoard *gameBoard;
    QHBoxLayout *mainLayout; // 主布局改为水平布局
    QVBoxLayout *verticalLayoutForBoardAndStatus; // 棋盘及其状态标签的垂直布局
    QHBoxLayout *horizontalLayoutForPieces; // 棋子按钮的水平布局
    QVBoxLayout *verticalLayoutForPiecesLeft; // 左侧棋子按钮的垂直布局
    QVBoxLayout *verticalLayoutForPiecesLeftMiddle; // 左中间棋子按钮的垂直布局
    QVBoxLayout *verticalLayoutForPiecesRightMiddle; // 中间棋子按钮的垂直布局
    QVBoxLayout *verticalLayoutForPiecesRight; // 右侧棋子按钮的垂直布局
    QString getInsectName(Piece* piece) ;
    QLabel *statusLabel;
    QGraphicsView *graphicsView;
    HexButton *pieceButtons[10];

    AnotherGameWindowPrivate *d_ptr;

    QSize calculateBoardSize(int rows, int cols, qreal hexSize);

private slots:

    void onPieceClicked(int pieceIndex);


};
#endif // ANOTHERGAMEWINDOW_H
