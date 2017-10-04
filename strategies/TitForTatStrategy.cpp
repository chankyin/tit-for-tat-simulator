#include "TitForTatStrategy.h"

string TitForTatStrategy::getStrategyName() {
    return "TitForTat";
}

MoveType TitForTatStrategy::nextMove() {
    if (0 == this->otherHistory.size()) {
        return COOPERATE;
    }
    return this->otherHistory.back();
}

void TitForTatStrategy::handleResult(bool) {

}

Strategy *TitForTatStrategy::clone() {
    return new TitForTatStrategy(score);
}
