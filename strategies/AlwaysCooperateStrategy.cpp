#include "AlwaysCooperateStrategy.h"

string AlwaysCooperateStrategy::getStrategyName() {
    return "AlwaysCooperate";
}

MoveType AlwaysCooperateStrategy::nextMove() {
    return COOPERATE;
}

void AlwaysCooperateStrategy::handleResult(bool) {
    // nothing to do
}

Strategy *AlwaysCooperateStrategy::clone() {
    return new AlwaysCooperateStrategy(score);
}
