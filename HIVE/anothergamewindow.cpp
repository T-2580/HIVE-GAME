#include "anothergamewindow.h"
#include "gameboard.h"
#include "hexbutton.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QGraphicsView>

class AnotherGameWindowPrivate {
public:
    GameBoard *gameBoard;
    QHBoxLayout *mainLayout; // 主布局改为水平布局
    QVBoxLayout *verticalLayoutForBoardAndStatus; // 棋盘及其状态标签的垂直布局
    QHBoxLayout *horizontalLayoutForPieces; // 棋子按钮的水平布局
    QVBoxLayout *verticalLayoutForPiecesLeft; // 左侧棋子按钮的垂直布局
    QVBoxLayout *verticalLayoutForPiecesLeftMiddle; // 中侧棋子按钮的垂直布局
    QVBoxLayout *verticalLayoutForPiecesRightMiddle;
    QVBoxLayout *verticalLayoutForPiecesRight; // 右侧棋子按钮的垂直布局
    QLabel *statusLabel;
    QGraphicsView *graphicsView;
    HexButton *pieceButtons[22];
};

AnotherGameWindow::AnotherGameWindow(QWidget *parent) :
    QWidget(parent),
    d_ptr(new AnotherGameWindowPrivate())
{
    d_ptr->gameBoard = new GameBoard(this);
    d_ptr->mainLayout = new QHBoxLayout(this); // 主布局改为水平布局
    d_ptr->verticalLayoutForBoardAndStatus = new QVBoxLayout(); // 棋盘及其状态标签的垂直布局
    d_ptr->horizontalLayoutForPieces = new QHBoxLayout(); // 棋子按钮的水平布局
    d_ptr->verticalLayoutForPiecesLeft = new QVBoxLayout(); // 左侧棋子按钮的垂直布局
    d_ptr->verticalLayoutForPiecesLeftMiddle = new QVBoxLayout(); // 中侧棋子按钮的垂直布局
    d_ptr->verticalLayoutForPiecesRightMiddle = new QVBoxLayout();
    d_ptr->verticalLayoutForPiecesRight = new QVBoxLayout(); // 右侧棋子按钮的垂直布局
    d_ptr->statusLabel = new QLabel("您已选择：", this);
    d_ptr->graphicsView = new QGraphicsView(this);

    setFixedSize(1200, 800); // 调整窗口大小


    // 设置棋盘大小
    QSize boardSize = calculateBoardSize(10, 10, 40); // 棋盘大小不变
    d_ptr->graphicsView->setMinimumSize(boardSize);
    d_ptr->graphicsView->setMaximumSize(boardSize);

    // 设置棋盘视图
    d_ptr->gameBoard->buildHexGrid(10, 10, 40); // 棋盘大小不变
    d_ptr->graphicsView->setScene(d_ptr->gameBoard);
    d_ptr->graphicsView->setRenderHint(QPainter::Antialiasing);

    // 设置棋盘及其状态标签的垂直布局
    d_ptr->verticalLayoutForBoardAndStatus->addWidget(d_ptr->graphicsView);
    d_ptr->verticalLayoutForBoardAndStatus->addWidget(d_ptr->statusLabel); // 将状态标签放在棋盘下方
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
            d_ptr->gameBoard->s[i] = new Ladybug();
            d_ptr->gameBoard->s[i]->_red = 1;
            d_ptr->gameBoard->s[i]->m_type=LADYBUG;

            break;
        case 12:
            d_ptr->gameBoard->s[i] = new Queen();
            d_ptr->gameBoard->s[i]->_red = 0;
            d_ptr->gameBoard->s[i]->m_type=QUEEN;

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
            d_ptr->gameBoard->s[i] = new Ant();
            d_ptr->gameBoard->s[i]->_red = 0;
            d_ptr->gameBoard->s[i]->m_type=ANT;

            break;
        case 16:
            d_ptr->gameBoard->s[i] = new Beetle();
            d_ptr->gameBoard->s[i]->_red = 0;

            d_ptr->gameBoard->s[i]->m_type=BEETLE;
            break;
        case 17:
            d_ptr->gameBoard->s[i] = new Beetle();
            d_ptr->gameBoard->s[i]->_red = 0;

            d_ptr->gameBoard->s[i]->m_type=BEETLE;
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
            d_ptr->gameBoard->s[i] = new Grasshopper();
            d_ptr->gameBoard->s[i]->_red = 0;

            d_ptr->gameBoard->s[i]->m_type=GRASSHOPPER;
            break;
        case 21:
            d_ptr->gameBoard->s[i] = new Spider();
            d_ptr->gameBoard->s[i]->_red = 0;

            d_ptr->gameBoard->s[i]->m_type=SPIDER;
            break;
        case 22:
            d_ptr->gameBoard->s[i] = new Spider();
            d_ptr->gameBoard->s[i]->_red = 0;

            d_ptr->gameBoard->s[i]->m_type=SPIDER;
            break;
        case 23:
            d_ptr->gameBoard->s[i] = new Ladybug();
            d_ptr->gameBoard->s[i]->_red = 0;

            d_ptr->gameBoard->s[i]->m_type=LADYBUG;
            break;
        default:

            break;}
    }




    // 设置主布局
    d_ptr->mainLayout->setContentsMargins(0, 0, 0, 0);

    // 设置棋子选择栏
    d_ptr->verticalLayoutForPiecesLeft->setSpacing(0); // 设置棋子按钮的间距
    d_ptr->verticalLayoutForPiecesLeftMiddle->setSpacing(0); // 设置棋子按钮的间距
    d_ptr->verticalLayoutForPiecesRightMiddle->setSpacing(0);
    d_ptr->verticalLayoutForPiecesRight->setSpacing(0); // 设置棋子按钮的间距
    d_ptr->horizontalLayoutForPieces->addLayout(d_ptr->verticalLayoutForPiecesLeft);
    d_ptr->horizontalLayoutForPieces->addSpacing(20); // 添加一些间距
    d_ptr->horizontalLayoutForPieces->addLayout(d_ptr->verticalLayoutForPiecesLeftMiddle);
    d_ptr->horizontalLayoutForPieces->addSpacing(20); // 添加一些间距
    d_ptr->horizontalLayoutForPieces->addLayout(d_ptr->verticalLayoutForPiecesRightMiddle);
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
        "D:/images/pieces/player1/12.png",
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
        "D:/images/pieces/player2/13.png",
    };

    // 循环创建棋子按钮并将它们添加到相应的布局中
    for (int i = 0; i < 24; ++i) {
        HexButton *pieceButton = new HexButton(this);
        QPixmap pixmap(piecePaths[i]);
        pieceButton->setIcon(QIcon(pixmap));
        pieceButton->setIconSize(pixmap.size());
        pieceButton->setFixedSize(60, 60); // 使棋子按钮大小与棋盘六边形大小一致

        // 根据 i 的值选择合适的布局
        QVBoxLayout *layoutToAdd;
        int columnIndex = i / 6; // 计算出当前棋子应该放置在哪一列

        switch (columnIndex) {
        case 0:
            layoutToAdd = d_ptr->verticalLayoutForPiecesLeft;
            break;
        case 1:
            layoutToAdd = d_ptr->verticalLayoutForPiecesLeftMiddle;
            break;
        case 2:
            layoutToAdd = d_ptr->verticalLayoutForPiecesRightMiddle;
            break;
        case 3:
            layoutToAdd = d_ptr->verticalLayoutForPiecesRight;
            break;
        default:
            // 这里不应该到达
            Q_ASSERT(false);
            break;
        }

        layoutToAdd->addWidget(pieceButton);

        d_ptr->pieceButtons[i] = pieceButton;
        connect(pieceButton, &HexButton::clicked, this, [this, i]() { onPieceClicked(i); });
    }

    // 将棋子按钮的水平布局添加到主布局
    d_ptr->mainLayout->addLayout(d_ptr->verticalLayoutForBoardAndStatus);
    d_ptr->mainLayout->addLayout(d_ptr->horizontalLayoutForPieces);

}

AnotherGameWindow::~AnotherGameWindow()
{
    delete d_ptr;
}

QSize AnotherGameWindow::calculateBoardSize(int rows, int cols, qreal hexSize) {
    qreal width = cols * hexSize * qSqrt(3); // 最大宽度
    qreal height = rows * hexSize * 1.5; // 高度
    return QSize(width, height);
}
void AnotherGameWindow::onPieceClicked(int pieceIndex) {


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
    QString AnotherGameWindow::getInsectName(Piece* piece) {
        switch (piece->m_type) {
        case QUEEN: return "QUEEN";
        case ANT: return "ANT";
        case BEETLE: return "BEETLE";
        case GRASSHOPPER: return "GRASSHOPPER";
        case SPIDER: return "SPIDER";
        default: return "UNKNOWN";
        }
    }
