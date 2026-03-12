#ifndef AI_H
#define AI_H

#include <memory>
#include <utility>
#include <vector>
#include "gameboard.h"
#include <cassert>

struct MoveResult {
    std::pair<std::pair<int, int>, std::pair<int, int>> move;
    int fromId;

    // 显式构造函数
    MoveResult(const std::pair<std::pair<int, int>, std::pair<int, int>>& move, int fromId)
        : move(move), fromId(fromId) {}
};

class AI {
public:
    AI(std::shared_ptr<GameBoard> board, bool isRedTurn, int depthLimit);
    MoveResult findBestMove(int piecenum,int airow,int aicol);

    std::vector<std::pair<int, int>> neighbors;

    int piecenum = -1;

private:

    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> generateMoves(std::shared_ptr<GameBoard> gb, bool isRedTurn);
    int evaluateBoard(std::shared_ptr<GameBoard> gb);
    int minimax(std::shared_ptr<GameBoard> gb, int depth, bool isMaximizingPlayer, bool isRedTurn, int alpha, int beta);

    std::shared_ptr<GameBoard> board_;
    bool isRedTurn_;
    int depthLimit_;// 搜索深度限制
};

#endif // AI_H
