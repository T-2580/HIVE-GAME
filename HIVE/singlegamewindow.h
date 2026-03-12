#ifndef SINGLEGAMEWINDOW_H
#define SINGLEGAMEWINDOW_H

#include <QDialog>
#include <QTimer>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QGraphicsView>
#include "gameboard.h"
#include "hexbutton.h"
#include <QDebug>
#include <memory>
#include "ai.h"
#include "gameboard.h"

class SingleGameWindowPrivate;

class SingleGameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SingleGameWindow(QWidget *parent = nullptr);
    ~SingleGameWindow();

    void startAI();
    int airow = -1;
    int aicol = -1;

    // 存储搜索深度
    static constexpr int DEPTH_LIMIT = 3; // AI 搜索深度限制，默认值可调整

private:
    int lastAIRow;
    int lastAICol;

    QTimer *timer; // 用于定期检查是否轮到AI
    GameBoard *gameBoard; // 游戏棋盘实例
    QHBoxLayout *mainLayout; // 主布局
    QVBoxLayout *verticalLayoutForBoardAndStatus; // 棋盘及其状态标签的垂直布局
    QHBoxLayout *horizontalLayoutForPieces; // 棋子按钮的水平布局
    QVBoxLayout *verticalLayoutForPiecesLeft; // 左侧棋子按钮的垂直布局
    QVBoxLayout *verticalLayoutForPiecesRight; // 右侧棋子按钮的垂直布局
    QLabel *statusLabel; // 显示状态的标签
    QGraphicsView *graphicsView; // 显示棋盘的图形视图
    HexButton *pieceButtons[22]; // 存储棋子按钮数组
    SingleGameWindowPrivate *d_ptr; // 指向私有数据结构的指针


    QSize calculateBoardSize(int rows, int cols, qreal hexSize);
    QString getInsectName(Piece* piece);


    void handleHexagonClick(int row, int col);

private slots:
    // 当棋子按钮被点击时触发
    void onPieceClicked(int pieceIndex);

    // 每次计时器触发时检查是否轮到AI
    void onGameTick();
};

#endif // SINGLEGAMEWINDOW_H
