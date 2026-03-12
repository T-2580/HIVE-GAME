#include "piece.h"
#include <QPainter>
#include <QtMath>
#include<qfile.h>
#include <queue>
#include<iostream>
Piece::Piece()

{

}

QString Piece::drawPiece(bool p1, InsectType type)
{


    QString imagePath;
    if(p1==1)
    {

        switch (type) {
        case QUEEN:
            imagePath = "D:/images/pieces/player1/1.png";
            break;
        case ANT:
            imagePath = "D:/images/pieces/player1/2.png";
            break;
        case SPIDER:
            imagePath = "D:/images/pieces/player1/3.png";
            break;
        case BEETLE:
            imagePath = "D:/images/pieces/player1/4.png";
            break;
        case GRASSHOPPER:
            imagePath = "D:/images/pieces/player1/5.png";
            break;
        case LADYBUG:
            imagePath = "D:/images/pieces/player1/12.png";
            break;
        default:
            break;
        }
    }
    else{
        switch (type) {
        case QUEEN:
            imagePath = "D:/images/pieces/player2/6.png";
            break;
        case ANT:
            imagePath = "D:/images/pieces/player2/7.png";
            break;
        case SPIDER:
            imagePath = "D:/images/pieces/player2/8.png";
            break;
        case BEETLE:
            imagePath = "D:/images/pieces/player2/9.png";
            break;
        case GRASSHOPPER:
            imagePath = "D:/images/pieces/player2/11.png";
            break;
        case LADYBUG:
            imagePath = "D:/images/pieces/player2/13.png";
            break;
        default:
            break;
        }
    }



    if (!QFile::exists(imagePath)) {
        qDebug() << "Image file does not exist:" << imagePath;

    }
    return imagePath;


}



QString drawPiece(bool p1, InsectType type);


bool Queen::canMoveTo(const std::vector<std::vector<Piece*>>& board, const Position& from, const Position& to) const {
    if (isPressedFlag) {
        std::cout<<"error1"<<isPressedFlag<<"\n";
        return false;
    }

    int rowDiff = abs(from.row - to.row);
    int colDiff = abs(from.col - to.col);

    // 相邻六边形的可能位置差
    if (!(rowDiff == 1 && colDiff == 0) ||
        (rowDiff == 0 && colDiff == 1) ||
        (rowDiff == 1 && colDiff == 1) ||
        (rowDiff == 1 && colDiff == 1)) {
        std::cout<<"error2";
        return false;
    }
    // 检查目标位置是否被阻挡
    if (board[to.row][to.col] != nullptr) {
        std::cout<<"error3";
        return false; // 目标位置被阻挡
    }
    return true;
}

// Ant


std::vector<Position> Ant::getAdjacentPositions(int row, int col) const {
    std::vector<Position> adjacentPositions;
    const int dr[] = {0, 1, 1, 0, -1, -1};
    const int dc_even[] = {1, 0, -1, -1, -1, 0}; // 偶数行的方向调整
    const int dc_odd[] = {1, 1, 0, -1, 0, 1}; // 奇数行的方向调整

    const int* dc = (row % 2 == 0) ? dc_even : dc_odd;

    for (int i = 0; i < 6; ++i) {
        int nextRow = row + dr[i];
        int nextCol = col + dc[i];
        adjacentPositions.push_back(Position(nextRow, nextCol));
    }

    return adjacentPositions;
}

bool Ant::canMoveTo(const std::vector<std::vector<Piece*>>& board, const Position& from, const Position& to) const {
    if ( isPressedFlag) {

        return false;
    }


    auto adjacentPositions = getAdjacentPositions(to.row, to.col);


    if (board[to.row][to.col] != nullptr) {
        return false;
    }


    for (const auto& pos : adjacentPositions) {
        if (board[pos.row][pos.col] != nullptr) {
            return true;
        }
    }

    return false;
}


// Spider


std::vector<Position> Spider::getAdjacentPositions(int row, int col) const {
    std::vector<Position> adjacentPositions;
    const int dr[] = {0, 1, 1, 0, -1, -1};
    const int dc_even[] = {1, 0, -1, -1, -1, 0};
    const int dc_odd[] = {1, 1, 0, -1, 0, 1};

    const int* dc = (row % 2 == 0) ? dc_even : dc_odd;

    for (int i = 0; i < 6; ++i) {
        int nextRow = row + dr[i];
        int nextCol = col + dc[i];
        adjacentPositions.push_back(Position(nextRow, nextCol));
    }

    return adjacentPositions;
}

bool Spider::canMoveTo(const std::vector<std::vector<Piece*>>& board, const Position& from, const Position& to) const {
    if (isPressedFlag) {
        return false;
    }

    // 使用广度优先搜索 (BFS) 来查找从from到to的路径，限制步数为3
    std::queue<std::pair<Position, int>> q;
    std::vector<std::pair<int, int>> visited;

    q.push({from, 0});
    visited.push_back({from.row, from.col});

    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();

        if (current == to && steps == 3) {
            return true;
        }

        if (steps < 3) {
            auto adjacentPositions = getAdjacentPositions(current.row, current.col);
            for (const auto& pos : adjacentPositions) {
                if (board[pos.row][pos.col] != nullptr) {
                    bool alreadyVisited = false;
                    for (const auto& v : visited) {
                        if (v.first == pos.row && v.second == pos.col) {
                            alreadyVisited = true;
                            break;
                        }
                    }
                    if (!alreadyVisited) {
                        q.push({pos, steps + 1});
                        visited.push_back({pos.row, pos.col});
                    }
                }
            }
        }
    }

    return false;
}




bool Beetle::canMoveTo(const std::vector<std::vector<Piece*>>& board, const Position& from, const Position& to) const {
    if (isPressedFlag) {
        return false;
    }
    int rowDiff = abs(from.row - to.row);
    int colDiff = abs(from.col - to.col);
    if (!(rowDiff == 1 && colDiff == 0) ||
        (rowDiff == 0 && colDiff == 1) ||
        (rowDiff == 1 && colDiff == 1) ||
        (rowDiff == 1 && colDiff == -1)) {
        return false;
    }
    else {

        if (board[to.row][to.col] == nullptr) {
            return true;
        }


        (board[to.row][to.col])->isPressedFlag=1;
        return true;}
}


// Grasshopper
bool Grasshopper::checkAndMove(const std::vector<std::vector<Piece*>>& board, int& currentRow, int& currentCol, bool& foundPiece) const
{
    if (currentRow < 0 || currentRow >= board.size() || currentCol < 0 || currentCol >= board[0].size()) {
        return false;
    }

    if (board[currentRow][currentCol] != nullptr) {
        foundPiece = true;
        return true;
    }

    return true;
}


bool Grasshopper::canMoveTo(const std::vector<std::vector<Piece*>>& board, const Position& from, const Position& to) const {
    if (!isPressedFlag) {
        return false;
    }
    int dr = to.row - from.row;
    int dc = to.col - from.col;


    if (from.row % 2 != 0) {

        if (dr == 1 && dc == -1) dc = 0;
        else if (dr == -1 && dc == -1) dc = 0;
    }


    if ((dr == 0 && abs(dc) == 1) || (abs(dr) == 1 && (dc == 0 || (from.row % 2 == 0 ? dc == -1 : dc == 0)))) {

        int currentRow = from.row + dr;
        int currentCol = from.col + dc;
        bool foundPiece = false;

        while (true) {
            if (!checkAndMove(board, currentRow, currentCol, foundPiece)) {
                return false;
            }

            if (currentRow == to.row && currentCol == to.col) {

                return true;
            }

            currentRow += dr;
            currentCol += dc;
        }
    }

    return false;
}


std::vector<Position> Ladybug::getAdjacentPositions(int row, int col) const {
    std::vector<Position> adjacentPositions;
    const int dr[] = {0, 1, 1, 0, -1, -1};
    const int dc_even[] = {1, 0, -1, -1, -1, 0};
    const int dc_odd[] = {1, 1, 0, -1, 0, 1};

    const int* dc = (row % 2 == 0) ? dc_even : dc_odd;

    for (int i = 0; i < 6; ++i) {
        int nextRow = row + dr[i];
        int nextCol = col + dc[i];
        adjacentPositions.push_back(Position(nextRow, nextCol));
    }

    return adjacentPositions;
}

bool Ladybug::canMoveTo(const std::vector<std::vector<Piece*>>& board, const Position& from, const Position& to) const {
    if (!isPressedFlag) {
        return false;
    }

    auto adjacentPositions = getAdjacentPositions(from.row, from.col);


    if (std::find(adjacentPositions.begin(), adjacentPositions.end(), to) == adjacentPositions.end()) {
        return false;
    }


    if (board[to.row][to.col] != nullptr) {
        return false;
    }


    for (const auto& firstStep : adjacentPositions) {
        if (board[firstStep.row][firstStep.col] != nullptr) {
            for (const auto& secondStep : getAdjacentPositions(firstStep.row, firstStep.col)) {
                if (board[secondStep.row][secondStep.col] == nullptr) {

                    auto thirdStepPositions = getAdjacentPositions(secondStep.row, secondStep.col);
                    if (std::find(thirdStepPositions.begin(), thirdStepPositions.end(), to) != thirdStepPositions.end()) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}
