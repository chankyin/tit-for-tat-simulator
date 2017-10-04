
#include "GamePair.h"

void GamePair::compete(double weight) {
    MoveType aMove = aClone->nextMove(), bMove = bClone->nextMove();
    if (aMove == COOPERATE) {
        if (bMove == COOPERATE) {
            a->score += matrix->bothCooperate * weight;
            b->score += matrix->bothCooperate * weight;
        } else {
            a->score += matrix->onlyCooperator * weight;
            b->score += matrix->onlyDefector * weight;
        }
    } else {
        if (bMove == COOPERATE) {
            a->score += matrix->onlyDefector * weight;
            b->score += matrix->onlyCooperator * weight;
        } else {
            a->score += matrix->bothDefect * weight;
            b->score += matrix->bothDefect * weight;
        }
    }
    aClone->myHistory.push_back(aMove);
    aClone->otherHistory.push_back(bMove);
    bClone->myHistory.push_back(bMove);
    bClone->otherHistory.push_back(aMove);
    aClone->handleResult(bMove);
    bClone->handleResult(aMove);
}

GamePair::~GamePair() {
    delete this->aClone, this->bClone;
}

GamePair::GamePair(PayoffMatrix *matrix, Strategy *a, Strategy *b) : matrix(matrix), a(a), b(b) {
    this->aClone = a->clone();
    this->bClone = b->clone();
}

double GamePair::calculateScoreProduct() {
    return a->score * b->score;
}
