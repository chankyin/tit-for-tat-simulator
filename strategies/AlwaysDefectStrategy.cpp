#include "AlwaysDefectStrategy.h"

string AlwaysDefectStrategy::getStrategyName() {
    return "AlwaysDefect";
}

MoveType AlwaysDefectStrategy::nextMove() {
    return DEFECT;
}

void AlwaysDefectStrategy::handleResult(bool) {
    // nothing to do
}

Strategy *AlwaysDefectStrategy::clone() {
    return new AlwaysDefectStrategy(score);
}
