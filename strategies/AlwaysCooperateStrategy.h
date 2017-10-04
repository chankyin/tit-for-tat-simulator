#ifndef TITFORTAT_ALWAYSCOOPERATESTRATEGY_H
#define TITFORTAT_ALWAYSCOOPERATESTRATEGY_H


#include "../Strategy.h"

class AlwaysCooperateStrategy : public Strategy {
public:
    explicit AlwaysCooperateStrategy(double score) : Strategy(score) {}

    string getStrategyName() override;

    MoveType nextMove() override;

    void handleResult(MoveType) override;

    Strategy *clone() override;
};


#endif //TITFORTAT_ALWAYSCOOPERATESTRATEGY_H
