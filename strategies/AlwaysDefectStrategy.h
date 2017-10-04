#ifndef TITFORTAT_ALWAYSDEFECTSTRATEGY_H
#define TITFORTAT_ALWAYSDEFECTSTRATEGY_H


#include "../Strategy.h"

class AlwaysDefectStrategy : public Strategy {
public:
    explicit AlwaysDefectStrategy(double score) : Strategy(score) {}

    string getStrategyName() override;

    MoveType nextMove() override;

    void handleResult(MoveType) override;

    Strategy *clone() override;
};


#endif //TITFORTAT_ALWAYSDEFECTSTRATEGY_H
