#include <random>
#include <cassert>
#include "ai.h"
#include <algorithm>
#include "gameboard.h"
#include <limits>
#include <iostream>
#include <map>
#include <vector>
#include <utility> // for std::pair
// 构造函数初始化AI对象
AI::AI(std::shared_ptr<GameBoard> board, bool isRedTurn, int depthLimit)
    : board_(std::move(board)), isRedTurn_(isRedTurn), depthLimit_(depthLimit) {};

MoveResult AI::findBestMove(int piecenum,int airow,int aicol) {
    if (piecenum == 0) {
        // 游戏开始，没有棋子，随机选择一个位置模拟放置一个棋子
        if (board_ == nullptr)
        {
            std::cout << "emptyboard" << std::endl;
        }

        int row = airow;

        int col = aicol;


        // 获取指定位置的所有邻居
        std::vector<std::pair<int, int>> neighbors = board_->getNeighbors(row, col);

        // 定义一个 map，键是 int 类型，值是 std::pair<int, int>
        std::map<int, std::pair<int, int>> canmoves;

        // 初始化键值
        int key = 1;

        // 遍历 vector 并将结果存入 map
        for (const auto& neighbor : neighbors) {
            canmoves[key].first = neighbor.first;
            canmoves[key].second = neighbor.second;
            key++;
        }

        // 从 map 中随机选择一个键
        if (!canmoves.empty()) {
            // 获取 map 的大小
            size_t mapSize = canmoves.size();

            // 创建随机数生成器
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis1(0, mapSize - 1);
            int moveid = dis1(gen);
            std::pair<int, int> value = canmoves[moveid];
            // 更新 row 和 col 为选择的邻居位置
            row = value.first;
            col = value.second;



        } else {
            std::cout << "The map is empty." << std::endl;
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> disId(11, 21); // 棋子ID范围
        int fromId = disId(gen);
        // 返回选择的移动
        return MoveResult{{{row, col}, {-1, -1}}, fromId};

    }
    else {
        // 随机选择下棋或移动
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1); // 生成0或1

        // 如果生成的数字是0，尝试在上一个落子位置的周围下棋
        if (dis(gen) == 0) {
            int row = airow;
            int col = aicol;
            // 获取指定位置的所有邻居
            std::vector<std::pair<int, int>> neighbors = board_->getNeighbors(row, col);

            // 过滤出空位
            std::vector<std::pair<int, int>> emptyNeighbors;
            for (const auto& neighbor : neighbors) {
                if (board_->isCellEmpty(neighbor.first, neighbor.second)) {
                    emptyNeighbors.push_back(neighbor);
                }
            }

            // 从空位中随机选择一个位置
            if (!emptyNeighbors.empty()) {
                std::uniform_int_distribution<> dis1(0, emptyNeighbors.size() - 1);
                int moveid = dis1(gen);
                std::pair<int, int> value = emptyNeighbors[moveid];

                // 更新 row 和 col 为选择的邻居位置
                row = value.first;
                col = value.second;

                std::uniform_int_distribution<> disId(11, 21); // 棋子ID范围
                int fromId = disId(gen);

                // 模拟放置棋子
                return MoveResult{{{row, col}, {-1, -1}}, fromId}; // 正确地构造MoveResult对象
            } else {
                // 如果周围没有空位，可以考虑其他策略，比如随机选择一个位置
                // 这里暂时使用默认的错误返回
                return MoveResult{{{-1, -1}, {-1, -1}}, -1};
            }
        }else {
            // 遍历所有可能的走法
            std::pair<std::pair<int, int>, std::pair<int, int>> bestMove; // 初始化最佳走法为空
            int bestValue = std::numeric_limits<int>::min(); // 初始化最佳评分为最小整数
            auto moves = generateMoves(board_, isRedTurn_); // 获取当前玩家的所有可能走法
            for (const auto& move : moves) {
                int fromRow = move.first.first; // 当前棋子所在行
                int fromCol = move.first.second; // 当前棋子所在列
                int toRow = move.second.first; // 目标位置行
                int toCol = move.second.second; // 目标位置列

                int fromId = board_->getStoneId(fromRow, fromCol); // 获取棋子ID
                if (fromId != -1) { // 棋子存在
                    // 创建当前棋盘的一个副本
                    auto tempBoard = std::make_shared<GameBoard>();
                    tempBoard->setRows(board_->getRows());
                    tempBoard->setCols(board_->getCols());
                    tempBoard->setHexSize(board_->getHexSize());
                    tempBoard->setBoard(board_->getBoard());
                    tempBoard->setRedTurn(board_->isRedTurn());
                    if (tempBoard->trymove(fromId, toRow, toCol)) { // 尝试移动棋子
                        int value = minimax(tempBoard, depthLimit_ - 1, false, !isRedTurn_, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()); // 计算走法的价值

                        // 如果新走法的价值更高，则更新最佳走法
                        if (value > bestValue) {
                            bestValue = value;
                            bestMove = move;
                        }
                    }
                }
            }

            // 执行最佳走法
            if (bestMove.first.first != -1 && bestMove.first.second != -1) {
                int fromRow = bestMove.first.first;
                int fromCol = bestMove.first.second;

                int fromId = board_->getStoneId(fromRow, fromCol); // 获取棋子ID
                if (fromId != -1) { // 棋子存在
                    // 返回最佳走法
                    return MoveResult{bestMove, fromId}; // 正确地构造MoveResult对象
                }
            }
        }
    }

    // 如果没有找到合适的走法，返回一个默认的结果
    return MoveResult{{{-1, -1}, {-1, -1}}, -1}; // 返回默认结果
}
int AI::evaluateBoard(std::shared_ptr<GameBoard> gb) {
    int evaluation = 0; // 初始化评估分数为0

    // 遍历棋盘上的所有位置，根据棋子的颜色和类型调整评估分数
    for (int row = 0; row < gb->getRows(); ++row) {
        for (int col = 0; col < gb->getCols(); ++col) {
            auto piece = gb->getBoard()[row][col]; // 获取当前位置上的棋子
            if (piece) { // 如果有棋子
                evaluation += (piece->_red == gb->isRedTurn() ? 1 : -1) * piece->m_type; // 根据棋子颜色和类型调整评估分数
            }
        }
    }

    // 遍历棋盘上的所有位置，如果棋子没有被包围则加分
    for (int row = 0; row < gb->getRows(); ++row) {
        for (int col = 0; col < gb->getCols(); ++col) {
            if (!gb->isPieceSurrounded(row, col)) {
                evaluation += 10;
            }
        }
    }
    // 如果所有棋子都连通，则加分；否则减分
    evaluation += gb->isAllPiecesConnected() ? 20 : -20;

    return evaluation; // 返回最终评估分数
}

std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> AI::generateMoves(std::shared_ptr<GameBoard> gb, bool isRedTurn) {
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> moves;
    for (int row = 0; row < gb->getRows(); ++row) {
        for (int col = 0; col < gb->getCols(); ++col) {
            auto piece = gb->getBoard()[row][col];
            if (piece && piece->_red == isRedTurn) {
                for (const auto& neighbor : gb->getNeighbors(row, col)) {
                    int toRow = neighbor.first;
                    int toCol = neighbor.second;
                    int fromId = gb->getStoneId(row, col);

                    if (gb->trymove(fromId, toRow, toCol)) {
                        moves.emplace_back(std::make_pair(row, col), std::make_pair(toRow, toCol)); // 添加到可能的移动列表
                    }
                }
            }
        }
    }
    return moves; // 返回所有可能的移动
}

int AI::minimax(std::shared_ptr<GameBoard> gb, int depth, bool isMaximizingPlayer, bool isRedTurn, int alpha, int beta) {
    if (depth == 0 || gb->win()) { // 达到搜索深度或游戏结束
        return evaluateBoard(gb); // 返回当前棋盘的评估分数
    }

    auto moves = generateMoves(gb, isRedTurn); // 生成当前玩家的所有可能走法

    if (isMaximizingPlayer) { // 最大化玩家
        int value = std::numeric_limits<int>::min(); // 初始化价值为最小整数
        for (const auto& move : moves) {
            int fromRow = move.first.first;
            int fromCol = move.first.second;
            int toRow = move.second.first;
            int toCol = move.second.second;

            int fromId = gb->getStoneId(fromRow, fromCol);
            if (fromId != -1) {
                // 创建当前棋盘的一个副本
                auto tempBoard = std::make_shared<GameBoard>();
                tempBoard->setRows(board_->getRows());
                tempBoard->setCols(board_->getCols());
                tempBoard->setHexSize(board_->getHexSize());
                tempBoard->setBoard(board_->getBoard());
                tempBoard->setRedTurn(board_->isRedTurn());

                if (tempBoard->trymove(fromId, toRow, toCol)) {
                    value = std::max(value, minimax(tempBoard, depth - 1, false, !isRedTurn, alpha, beta)); // 递归调用minimax
                    alpha = std::max(alpha, value); // 更新alpha值

                    if (beta <= alpha) break; // 如果beta小于等于alpha，剪枝
                }
            }
        }
        return value; // 返回最大化玩家的最大价值
    } else { // 最小化玩家
        int value = std::numeric_limits<int>::max(); // 初始化价值为最大整数
        for (const auto& move : moves) { // 遍历所有可能的走法
            int fromRow = move.first.first;
            int fromCol = move.first.second;
            int toRow = move.second.first;
            int toCol = move.second.second;

            int fromId = gb->getStoneId(fromRow, fromCol);
            if (fromId != -1) {
                // 创建当前棋盘的一个副本
                auto tempBoard = std::make_shared<GameBoard>();
                tempBoard->setRows(board_->getRows());
                tempBoard->setCols(board_->getCols());
                tempBoard->setHexSize(board_->getHexSize());
                tempBoard->setBoard(board_->getBoard());
                tempBoard->setRedTurn(board_->isRedTurn());

                if (tempBoard->trymove(fromId, toRow, toCol)) { // 尝试移动棋子
                    value = std::min(value, minimax(tempBoard, depth - 1, true, !isRedTurn, alpha, beta)); // 递归调用minimax
                    beta = std::min(beta, value); // 更新beta值

                    if (beta <= alpha) break; // 如果beta小于等于alpha，剪枝
                }
            }
        }
        return value; // 返回最小化玩家的最小价值
    }
}
