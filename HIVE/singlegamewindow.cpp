#include "singlegamewindow.h"
#include "gameboard.h"
#include "hexbutton.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QGraphicsView>
#include <QDialog>
#include <ai.h>
#include <QDebug>
#include<iostream>
class SingleGameWindowPrivate
{
public:
    GameBoard *gameBoard;
    QHBoxLayout *mainLayout;
    QVBoxLayout *verticalLayoutForBoardAndStatus;
    QHBoxLayout *horizontalLayoutForPieces;
    QVBoxLayout *verticalLayoutForPiecesLeft;
    QVBoxLayout *verticalLayoutForPiecesRight;
    QLabel *statusLabel;
    QGraphicsView *graphicsView;
    HexButton *pieceButtons[22];
};

SingleGameWindow::SingleGameWindow(QWidget *parent) :
    QDialog(parent),
    timer(new QTimer(this)),
    d_ptr(new SingleGameWindowPrivate())
{
    d_ptr->gameBoard = new GameBoard(this);
    d_ptr->mainLayout = new QHBoxLayout(this);
    d_ptr->verticalLayoutForBoardAndStatus = new QVBoxLayout();
    d_ptr->horizontalLayoutForPieces = new QHBoxLayout();
    d_ptr->verticalLayoutForPiecesLeft = new QVBoxLayout();
    d_ptr->verticalLayoutForPiecesRight = new QVBoxLayout();
    d_ptr->statusLabel = new QLabel("您已选择：", this);
    d_ptr->graphicsView = new QGraphicsView(this);

    setFixedSize(1200, 800);

    QSize boardSize = calculateBoardSize(10, 10, 40);
    d_ptr->graphicsView->setMinimumSize(boardSize);
    d_ptr->graphicsView->setMaximumSize(boardSize);

    d_ptr->gameBoard->buildHexGrid(10, 10, 40);
    d_ptr->graphicsView->setScene(d_ptr->gameBoard);
    d_ptr->graphicsView->setRenderHint(QPainter::Antialiasing);


    d_ptr->verticalLayoutForBoardAndStatus->addWidget(d_ptr->graphicsView);
    d_ptr->verticalLayoutForBoardAndStatus->addWidget(d_ptr->statusLabel);

    for (int i = 0; i < 22; ++i) {
        switch (i) {
        case 0:
            d_ptr->gameBoard->s[i] = new Queen();
            d_ptr->gameBoard->s[i]->_red = 1;
            d_ptr->gameBoard->s[i]->m_type=QUEEN;

            break;
        case 1:
            d_ptr->gameBoard->s[i] = new Ant();
            d_ptr->gameBoard->s[i]->_red = 1;
            d_ptr->gameBoard->s[i]->m_type=ANT;

            break;
        case 2:
            d_ptr->gameBoard->s[i] = new Ant();
            d_ptr->gameBoard->s[i]->_red = 1;
            d_ptr->gameBoard->s[i]->m_type=ANT;

            break;
        case 3:
            d_ptr->gameBoard->s[i] = new Ant();
            d_ptr->gameBoard->s[i]->_red = 1;
            d_ptr->gameBoard->s[i]->m_type=ANT;

            break;
        case 4:
            d_ptr->gameBoard->s[i] = new Beetle();
            d_ptr->gameBoard->s[i]->_red = 1;
            d_ptr->gameBoard->s[i]->m_type=BEETLE;

            break;
        case 5:
            d_ptr->gameBoard->s[i] = new Beetle();
            d_ptr->gameBoard->s[i]->_red = 1;
            d_ptr->gameBoard->s[i]->m_type=BEETLE;

            break;
        case 6:
            d_ptr->gameBoard->s[i] = new Grasshopper();
            d_ptr->gameBoard->s[i]->_red = 1;
            d_ptr->gameBoard->s[i]->m_type=GRASSHOPPER;

            break;
        case 7:
            d_ptr->gameBoard->s[i] = new Grasshopper();
            d_ptr->gameBoard->s[i]->_red = 1;
            d_ptr->gameBoard->s[i]->m_type=GRASSHOPPER;

            break;
        case 8:
            d_ptr->gameBoard->s[i] = new Grasshopper();
            d_ptr->gameBoard->s[i]->_red = 1;
            d_ptr->gameBoard->s[i]->m_type=GRASSHOPPER;

            break;
        case 9:
            d_ptr->gameBoard->s[i] = new Spider();
            d_ptr->gameBoard->s[i]->_red = 1;
            d_ptr->gameBoard->s[i]->m_type=SPIDER;

            break;
        case 10:
            d_ptr->gameBoard->s[i] = new Spider();
            d_ptr->gameBoard->s[i]->_red = 1;
            d_ptr->gameBoard->s[i]->m_type=SPIDER;

            break;
        case 11:
            d_ptr->gameBoard->s[i] = new Queen();
            d_ptr->gameBoard->s[i]->_red = 0;
            d_ptr->gameBoard->s[i]->m_type=QUEEN;

            break;
        case 12:
            d_ptr->gameBoard->s[i] = new Ant();
            d_ptr->gameBoard->s[i]->_red = 0;
            d_ptr->gameBoard->s[i]->m_type=ANT;

            break;
        case 13:
            d_ptr->gameBoard->s[i] = new Ant();
            d_ptr->gameBoard->s[i]->_red = 0;
            d_ptr->gameBoard->s[i]->m_type=ANT;

            break;
        case 14:
            d_ptr->gameBoard->s[i] = new Ant();
            d_ptr->gameBoard->s[i]->_red = 0;
            d_ptr->gameBoard->s[i]->m_type=ANT;

            break;
        case 15:
            d_ptr->gameBoard->s[i] = new Beetle();
            d_ptr->gameBoard->s[i]->_red = 0;

            d_ptr->gameBoard->s[i]->m_type=BEETLE;
            break;
        case 16:
            d_ptr->gameBoard->s[i] = new Beetle();
            d_ptr->gameBoard->s[i]->_red = 0;

            d_ptr->gameBoard->s[i]->m_type=BEETLE;
            break;
        case 17:
            d_ptr->gameBoard->s[i] = new Grasshopper();
            d_ptr->gameBoard->s[i]->_red = 0;

            d_ptr->gameBoard->s[i]->m_type=GRASSHOPPER;
            break;
        case 18:
            d_ptr->gameBoard->s[i] = new Grasshopper();
            d_ptr->gameBoard->s[i]->_red = 0;

            d_ptr->gameBoard->s[i]->m_type=GRASSHOPPER;
            break;
        case 19:
            d_ptr->gameBoard->s[i] = new Grasshopper();
            d_ptr->gameBoard->s[i]->_red = 0;

            d_ptr->gameBoard->s[i]->m_type=GRASSHOPPER;
            break;
        case 20:
            d_ptr->gameBoard->s[i] = new Spider();
            d_ptr->gameBoard->s[i]->_red = 0;

            d_ptr->gameBoard->s[i]->m_type=SPIDER;
            break;
        case 21:
            d_ptr->gameBoard->s[i] = new Spider();
            d_ptr->gameBoard->s[i]->_red = 0;

            d_ptr->gameBoard->s[i]->m_type=SPIDER;
            break;
        default:

            break;}
    }



    // 设置主布局
    d_ptr->mainLayout->setContentsMargins(0, 0, 0, 0);

    // 设置棋子选择栏
    d_ptr->verticalLayoutForPiecesLeft->setSpacing(1); // 设置棋子按钮的间距
    d_ptr->verticalLayoutForPiecesRight->setSpacing(1); // 设置棋子按钮的间距
    d_ptr->horizontalLayoutForPieces->addLayout(d_ptr->verticalLayoutForPiecesLeft);
    d_ptr->horizontalLayoutForPieces->addSpacing(20); // 添加一些间距
    d_ptr->horizontalLayoutForPieces->addLayout(d_ptr->verticalLayoutForPiecesRight);



    // 添加棋子按钮
    QString piecePaths[] = {
        "D:/images/pieces/player1/1.png",
        "D:/images/pieces/player1/2.png",
        "D:/images/pieces/player1/2.png",
        "D:/images/pieces/player1/2.png",
        "D:/images/pieces/player1/4.png",
        "D:/images/pieces/player1/4.png",
        "D:/images/pieces/player1/5.png",
        "D:/images/pieces/player1/5.png",
        "D:/images/pieces/player1/5.png",
        "D:/images/pieces/player1/3.png",
        "D:/images/pieces/player1/3.png",
        "D:/images/pieces/player2/6.png",
        "D:/images/pieces/player2/7.png",
        "D:/images/pieces/player2/7.png",
        "D:/images/pieces/player2/7.png",
        "D:/images/pieces/player2/9.png",
        "D:/images/pieces/player2/9.png",
        "D:/images/pieces/player2/11.png",
        "D:/images/pieces/player2/11.png",
        "D:/images/pieces/player2/11.png",
        "D:/images/pieces/player2/8.png",
        "D:/images/pieces/player2/8.png",
    };

    for (int i = 0; i < 22; ++i) {
        // 创建一个新的HexButton实例，并将其父窗口设置为当前对象(this)
        HexButton *pieceButton = new HexButton(this);

        // 使用给定的路径加载一个图像文件
        QPixmap pixmap(piecePaths[i]);

        // 设置按钮的图标为加载的图像，并使用QIcon类
        pieceButton->setIcon(QIcon(pixmap));

        // 设置按钮的图标大小为图像的大小
        pieceButton->setIconSize(pixmap.size());

        // 设置按钮的固定尺寸为60x60像素，使其与棋盘上的六边形大小一致
        pieceButton->setFixedSize(60, 60);

        // 根据循环索引值决定将按钮添加到左侧还是右侧的垂直布局中
        QVBoxLayout *layoutToAdd = (i < 11) ? d_ptr->verticalLayoutForPiecesLeft : d_ptr->verticalLayoutForPiecesRight;

        // 将按钮添加到选定的垂直布局中
        layoutToAdd->addWidget(pieceButton);

        // 在成员变量pieceButtons数组中的相应位置存储创建的按钮对象
        d_ptr->pieceButtons[i] = pieceButton;

        // 连接按钮的点击信号到槽函数onPieceClicked，并传递当前循环索引值
        connect(pieceButton, &HexButton::clicked, this, [this, i]() { onPieceClicked(i); });
    }

    // 将棋子按钮的水平布局添加到主布局
    d_ptr->mainLayout->addLayout(d_ptr->verticalLayoutForBoardAndStatus);
    d_ptr->mainLayout->addLayout(d_ptr->horizontalLayoutForPieces);

    // 初始化界面和其他成员变量
    connect(timer, &QTimer::timeout, this, &SingleGameWindow::onGameTick);
    timer->start(10000); // 每秒检查一次
}

SingleGameWindow::~SingleGameWindow()
{
    delete d_ptr;
}

QSize SingleGameWindow::calculateBoardSize(int rows, int cols, qreal hexSize) {
    qreal width = cols * hexSize * qSqrt(3);
    qreal height = rows * hexSize * 1.5;
    return QSize(width, height);
}

void SingleGameWindow::onGameTick()
{
    startAI(); // 每次计时器触发时检查是否轮到 AI
}
void SingleGameWindow::onPieceClicked(int pieceIndex) {
    if (pieceIndex >= 0 && pieceIndex < 22) {
        Piece *selectedPiece = d_ptr->gameBoard->s[pieceIndex];
        if (selectedPiece != nullptr) {
            d_ptr->gameBoard->setNowPiece(pieceIndex);
            // 更新状态标签
            QString insectName = getInsectName(selectedPiece);
            d_ptr->statusLabel->setText(QString("您已选择：%1").arg(insectName));
        } else {
            qDebug() << "Piece at index" << pieceIndex << "is not initialized.";
        }
    } else {
        qDebug() << "Invalid piece index:" << pieceIndex;
    }
}

// 辅助函数用来获取棋子的名字
QString SingleGameWindow::getInsectName(Piece* piece) {
    switch (piece->m_type) {
    case QUEEN: return "QUEEN";
    case ANT: return "ANT";
    case BEETLE: return "BEETLE";
    case GRASSHOPPER: return "GRASSHOPPER";
    case SPIDER: return "SPIDER";
    default: return "UNKNOWN";
    }
}

void SingleGameWindow::startAI()
{
    // 检查 d_ptr->gameBoard 是否为空
    if (!d_ptr->gameBoard) {
        qDebug() << "d_ptr->gameBoard is null.";
        return;
    }

    if (d_ptr->gameBoard->_bRedTurn == 0) {

        // 创建AI实例
        auto clonedBoard = d_ptr->gameBoard->clone();
        auto ai = std::make_shared<AI>(clonedBoard, false, DEPTH_LIMIT);

        // 检查是否是游戏刚开始（棋盘上还没有棋子）
        if (d_ptr->gameBoard->getNum() == 0) {

            airow = d_ptr->gameBoard->s[d_ptr->gameBoard->redpiece]->row;
            aicol = d_ptr->gameBoard->s[d_ptr->gameBoard->redpiece]->col;

            MoveResult result = ai->findBestMove(d_ptr->gameBoard->getNum(),airow,aicol);

            d_ptr->gameBoard->setNowPiece(result.fromId);
            d_ptr->gameBoard->click(result.move.first.first, result.move.first.second);
        }
        else {
            airow = d_ptr->gameBoard->s[d_ptr->gameBoard->aipieceID]->row;
            aicol = d_ptr->gameBoard->s[d_ptr->gameBoard->aipieceID]->col;

            MoveResult result = ai->findBestMove(d_ptr->gameBoard->getNum(),airow,aicol);

            if (d_ptr->gameBoard) {
                d_ptr->gameBoard->setNowPiece(result.fromId);
            } else {
                qDebug() << "d_ptr->gameBoard is null during setting nowpiece.";
            }
            // 执行最佳走法
            if (d_ptr->gameBoard) {
                d_ptr->gameBoard->click(result.move.first.first, result.move.first.second);
            } else {
                qDebug() << "d_ptr->gameBoard is null during click execution.";
            }
        }
    }
}
