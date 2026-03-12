#include<iostream>
#include "gamewindow.h"
#include "gameboard.h"
#include "hexbutton.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QGraphicsView>

class GameWindowPrivate {
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
GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    d_ptr(new GameWindowPrivate())
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


    d_ptr->mainLayout->setContentsMargins(0, 0, 0, 0);


    d_ptr->verticalLayoutForPiecesLeft->setSpacing(1);
    d_ptr->verticalLayoutForPiecesRight->setSpacing(1);
    d_ptr->horizontalLayoutForPieces->addLayout(d_ptr->verticalLayoutForPiecesLeft);
    d_ptr->horizontalLayoutForPieces->addSpacing(20);
    d_ptr->horizontalLayoutForPieces->addLayout(d_ptr->verticalLayoutForPiecesRight);


    QString piecePaths[] = {
        // ... (路径列表)
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
        HexButton *pieceButton = new HexButton(this);
        QPixmap pixmap(piecePaths[i]);
        pieceButton->setIcon(QIcon(pixmap));
        pieceButton->setIconSize(pixmap.size());
        pieceButton->setFixedSize(60, 60);


        QVBoxLayout *layoutToAdd = (i < 11) ? d_ptr->verticalLayoutForPiecesLeft : d_ptr->verticalLayoutForPiecesRight;
        layoutToAdd->addWidget(pieceButton);

        d_ptr->pieceButtons[i] = pieceButton;
        connect(pieceButton, &HexButton::clicked, this, [this, i]() { onPieceClicked(i); });
    }


    d_ptr->mainLayout->addLayout(d_ptr->verticalLayoutForBoardAndStatus);
    d_ptr->mainLayout->addLayout(d_ptr->horizontalLayoutForPieces);


    setLayout(d_ptr->mainLayout);
}
GameWindow::~GameWindow()
{
    delete d_ptr;
}

QSize GameWindow::calculateBoardSize(int rows, int cols, qreal hexSize) {
    qreal width = cols * hexSize * qSqrt(3);
    qreal height = rows * hexSize * 1.5;
    return QSize(width, height);
}
void GameWindow::onPieceClicked(int pieceIndex) {
    if (pieceIndex >= 0 && pieceIndex < 22) {
        Piece *selectedPiece = d_ptr->gameBoard->s[pieceIndex];
        if (selectedPiece != nullptr) {
            d_ptr->gameBoard->setNowPiece(pieceIndex);
            QString insectName = getInsectName(selectedPiece);
            d_ptr->statusLabel->setText(QString("您已选择：%1").arg(insectName));
        } else {
            qDebug() << "Piece at index" << pieceIndex << "is not initialized.";
        }
    } else {
        qDebug() << "Invalid piece index:" << pieceIndex;
    }
}

QString GameWindow::getInsectName(Piece* piece) {
    switch (piece->m_type) {
    case QUEEN: return "QUEEN";
    case ANT: return "ANT";
    case BEETLE: return "BEETLE";
    case GRASSHOPPER: return "GRASSHOPPER";
    case SPIDER: return "SPIDER";
    default: return "UNKNOWN";
    }
}
