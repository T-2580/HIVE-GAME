#include "gameboard.h"
#include<QFile.h>
#include <QGraphicsPolygonItem>
#include <QBrush>
#include <QtMath>
#include <QTimer>
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include"piece.h"
bool GameBoard::_bRedTurn = true;

GameBoard::GameBoard(QObject* parent)
    : QGraphicsScene(parent), rows(0), cols(0), board(22, std::vector<Piece*>(22, nullptr)) , nowpiece(-1),pieces(),num(-1){
    for (int i = 0; i < 22; ++i) {
        s[i] = nullptr;
    }
}

GameBoard* GameBoard::instance = nullptr;

// 实现静态成员函数
GameBoard* GameBoard::getInstance() {
    if (!instance) {
        instance = new GameBoard();
    }
    return instance;
}

void GameBoard::buildHexGrid(int rows, int cols, qreal hexSize) {
    this->rows = rows;
    this->cols = cols;
    this->hexSize = hexSize;

    qreal xOffset = hexSize * qSqrt(3.0);
    qreal yOffset = hexSize * (1.5);

    // 构建每个六边形格子
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            qreal x = col * xOffset + (row % 2 == 0 ? (hexSize * qSqrt(3.0) / 2) : 0);
            qreal y = row * yOffset;

            QPointF center(x, y);
            QPolygonF hexagon = createHexagon(hexSize);

            // 为每个六边形格子创建 QGraphicsPolygonItem 并添加到场景
            QGraphicsPolygonItem* hexItem = new QGraphicsPolygonItem(hexagon);
            hexItem->setBrush(QBrush(Qt::lightGray));
            hexItem->setPos(center);
            addItem(hexItem);

            hexCells.insert({row, col}, center);
        }
    }
}
GameBoard::~GameBoard() {
    for (int i = 0; i <22; ++i) {
        delete s[i];
    }
}


void GameBoard::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QPointF pos = event->scenePos();
    QPointF clickedCenter;
    int clickedRow, clickedCol;

    // 遍历所有六边形格子，检查点击位置是否在某个六边形内
    for (auto it = hexCells.begin(); it != hexCells.end(); ++it) {
        QPointF center = it.value();
        QPolygonF hexagon = createHexagon(hexSize);
        hexagon.translate(center);

        if (hexagon.containsPoint(pos, Qt::OddEvenFill)) {
            clickedCenter = center;
            clickedRow = it.key().first;
            clickedCol = it.key().second;
            break;
        }
    }

    if (!clickedCenter.isNull()) {
        lastClickedPos = {clickedRow, clickedCol};
    }
}
void GameBoard::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (lastClickedPos.first >= 0 && lastClickedPos.second >= 0) {
        click(lastClickedPos.first, lastClickedPos.second);
        lastClickedPos = {-1, -1}; // 清空记录
    }


}
QPolygonF GameBoard::createHexagon(qreal size) const {
    QPolygonF hexagon;
    for (int i = 0; i < 6; ++i) {
        qreal angle = 2 * M_PI / 6 * i + M_PI / 2; // 起始角度为90度
        qreal x = size * qCos(angle);
        qreal y = size * qSin(angle);
        hexagon << QPointF(x, y);
    }
    return hexagon;
}
QPointF GameBoard::getCellCenter(int row, int col) const {
    return hexCells.value({row, col});
}


int GameBoard::getStoneId(int row, int col) const {
    for(int i = 0; i < 22; ++i) {
        if(s[i] && s[i]->row == row && s[i]->col == col) {
            return i;
        }
    }
    return -1;
}
bool GameBoard::isCellEmpty(int row, int col)  {
    if(getStoneId(row,col)==-1){

        return true;}
    else return false;

}

bool GameBoard::trymove(int id, int tr, int tc) {
    // 获取当前棋子的位置
    Position currPos = {s[id]->row, s[id]->col};

    // 判断是否为合法移动
    if (!isLegalMove(id, tr, tc)) {
        std::cout<<"error logic"<<std::endl;
        return false;
    }

    // 检测移动后是否仍然是完整蜂窝
    if (!isConnectedAfterMove(id, tr, tc)) {
        std::cout<<"is not Connected AfterMove"<<std::endl;
        return false;
    }

    // 检查是否需要放置蜂后
    if (!isQueenPlacedCorrectly(id)) {
        std::cout<<"please place your queen"<<std::endl;
        return false;
    }

    return true;
}

bool GameBoard::isLegalMove(int id, int tr, int tc) {
    if (num < 0) {
        return true;
    }

    if (num == 0 || s[id]->row == -1) {
        return hasNeighborWithRedOrSameColor(id, tr, tc);
    }

    if (s[id]->row != -1 && s[id]->canMoveTo(board, {s[id]->row, s[id]->col}, {tr, tc})) {
        return true;
    }

    return false;
}

bool GameBoard::hasNeighborWithRedOrSameColor(int id, int tr, int tc) {
    std::vector<std::pair<int, int>> neighbors = getNeighbors(tr, tc);

    for (const auto& neighbor : neighbors) {
        int nr = neighbor.first;
        int nc = neighbor.second;

        if (nr >= 0 && nr < 20 && nc >= 0 && nc < 20) {
            if (board[nr][nc] != nullptr && (num == 0 || board[nr][nc]->_red == s[id]->_red)) {
                return true;
            }
        }
    }

    return false;
}

bool GameBoard::isConnectedAfterMove(int id, int tr, int tc) {
    if (s[id]->col <= 0) {
        return true;
    }

    int fr = s[id]->row;
    int fc = s[id]->col;

    // 尝试移动棋子
    s[id]->row = tr;
    s[id]->col = tc;
    board[tr][tc] = s[id];
    board[fr][fc] = nullptr;

    // 检查移动后是否所有棋子仍连在一起
    if (isAllPiecesConnected()) {
        return true;
    } else {
        // 如果棋子不连在一起，则恢复原始状态
        s[id]->row = fr;
        s[id]->col = fc;
        board[fr][fc] = s[id];
        board[tr][tc] = nullptr;
        std::cout << "Move does not comply with the rules." << std::endl;
        return false;
    }
}

bool GameBoard::isQueenPlacedCorrectly(int id) {
    if (num < 6) {
        return true;
    }

    if (s[id]->_red == 1 && s[0] == nullptr) {
        std::cout << "please place your queen" << std::endl;
        return false;
    }

    if (s[id]->_red == 0 && s[12] == nullptr) {
        std::cout << "please place your queen" << std::endl;
        return false;
    }

    return true;
}
void moveStone(int id, int row, int col);

void GameBoard::click(int row, int col) {

    redpiece = nowpiece;

    if(isRedTurn()==false)
    {
        aipieceID = redpiece;
    }

    if (nowpiece != -1) {

        if (_bRedTurn == s[nowpiece]->_red) {

            bool moveSuccess = trymove(nowpiece, row, col);

            if (moveSuccess) {
                movePiece(nowpiece, row, col, s[nowpiece]->row, s[nowpiece]->col);
                nowpiece = -1;

                if (num > 5) {
                    if (win()) {
                        qDebug() << "Gameover!";
                    }
                }
                _bRedTurn = !_bRedTurn;
            } else {
                qDebug() << "Move failed due to logic error";
            }
        } else {
            qDebug() << "It is not your turn.";
            nowpiece = -1;
        }
    } else {

        if (isCellEmpty(row, col)) {
            qDebug() << "Cell is empty, no action needed.";
        } else {
            nowpiece = getStoneId(row, col);

            if (_bRedTurn != s[nowpiece]->_red) {
                nowpiece = -1;
                qDebug() << "It is not your turn.";
            }
        }
    }
}
void GameBoard::movePiece(int i, int row, int col, int fr, int fc) {
    QPointF center = getCellCenter(row, col);
    // 如果是从负数开始，则分配一个新的索引
    if (fr < 0) {
        num++;
        s[i]->num = static_cast<int>(pieces.size());
    }

    s[i]->row = row;
    s[i]->col = col;

    QString imagePath = s[i]->drawPiece(s[i]->_red, s[i]->m_type);



    QPixmap pixmap(imagePath);
    if (pixmap.isNull()) {
        qDebug() << "Failed to load image:" << imagePath;
        return;
    }
    if (fr >= 0  && fc >= 0 ) {
        board[fr][fc] = nullptr;
    }
    if (row >= 0 && col >= 0 ) {
        board[row][col] = s[i];
    }
    auto pixmapItem = std::make_unique<QGraphicsPixmapItem>(pixmap);
    pixmapItem->setPos(center - QPointF(pixmap.width() / 2, pixmap.height() / 2));


    if (static_cast<size_t>(s[i]->num) < pieces.size()) {

        if (pieces[s[i]->num] != nullptr) {

            pieces[s[i]->num]->setPixmap(pixmap);
            pieces[s[i]->num]->setPos(center - QPointF(pixmap.width() / 2, pixmap.height() / 2));
        } else {

            this->addItem(pixmapItem.get());
            pieces[s[i]->num] = pixmapItem.release();
        }
    } else {

        this->addItem(pixmapItem.get());
        pieces.emplace_back(pixmapItem.release());
    }

}

bool GameBoard::win(){
    if(s[0]->row>0&&s[11]->row>0)
        if(isPieceSurrounded(s[0]->row, s[0]->col) || isPieceSurrounded(s[11]->row, s[11]->col))
        {
            std::cout << "Winner is: " << (_bRedTurn ? "bleu" : "Red") << std::endl;
            return true;
        }
        else {
            std::cout << "No winner yet." << std::endl;
            return false;
        }
    else return false;
}

std::vector<std::pair<int, int>> GameBoard::getNeighbors(int row, int col) const{
    std::vector<std::pair<int, int>> neighbors;
    if (col % 2 == 0) {
        neighbors = {
            {row , col-1},
            {row - 1, col +1},
            {row+1, col + 1},
            {row , col+1},
            {row + 1, col },
            {row-1, col }
        };


    } else {
        neighbors = {
            {row - 1, col + 1},
            {row - 1, col},
            {row, col + 1},
            {row + 1, col},
            {row + 1, col +1},
            {row, col - 1}
        };
    }
    return neighbors;
}
bool GameBoard::isPieceSurrounded(int row,int col) const {
    std::vector<std::pair<int, int>> neighbors = getNeighbors(row,col);


    for (const auto& neighbor : neighbors) {

        if (board[neighbor.first][ neighbor.second]==nullptr) {
            return false;
        }
    }
    return true;
}
bool GameBoard::isAllPiecesConnected() const {
    std::cout << "Checking if all pieces are connected..." << std::endl;
    std::vector<bool> visited(32, false);
    int connectedCount = 0;


    int startIndex = -1;
    for (int i = 0; i < 21 && startIndex == -1; ++i) {
        if (s[i] && s[i]->row >= 0 && s[i]->col >= 0) {
            startIndex = i;
            break;
        }
    }

    if (startIndex == -1) {
        std::cout << "No placed pieces found." << std::endl;
        return false; // 没有找到任何放置的棋子
    }

    // 从找到的第一个棋子开始进行DFS
    dfs(startIndex, visited, &connectedCount);

    // 统计棋盘上放置的棋子总数
    int totalPlacedPieces = 0;
    for (int i = 0; i < 21; ++i) {
        if (s[i] && s[i]->row >= 0 && s[i]->col >= 0) {
            ++totalPlacedPieces;
        }
    }

    std::cout << "Connected count: " << connectedCount << ", Total placed pieces: " << totalPlacedPieces << std::endl;

    // 如果连接的棋子数量等于总放置的棋子数量，则表示所有棋子都连在一起
    if(connectedCount == totalPlacedPieces) return true;
    else return false;
}
void GameBoard::dfs(int index, std::vector<bool>& visited, int* connectedCount) const {
    if (index < 0 || index >= 32 || visited[index]) {
        return;
    }

    if (s[index] && s[index]->row >= 0 && s[index]->col >= 0) {
        visited[index] = true;
        (*connectedCount)++;
        int row = s[index]->row;
        int col = s[index]->col;

        // 获取邻居并递归访问
        for (const auto& neighbor : getNeighbors(row, col)) {
            int neighborIndex = getStoneId(neighbor.first, neighbor.second);
            if (neighborIndex != -1) {
                dfs(neighborIndex, visited, connectedCount);
            }
        }
    }
}

std::shared_ptr<GameBoard> GameBoard::clone() const
{
    auto clonedBoard = std::make_shared<GameBoard>();
    clonedBoard->rows = rows;
    clonedBoard->cols = cols;
    clonedBoard->hexSize = hexSize;
    clonedBoard->board = board;
    clonedBoard->_bRedTurn = _bRedTurn;
    return clonedBoard;
}

bool GameBoard::isEmptyBoard() const {
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (board[row][col]) {
                return false;
            }
        }
    }
    return true;
}
