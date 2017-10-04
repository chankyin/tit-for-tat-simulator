#ifndef TITFORTAT_TITFORTAT_H
#define TITFORTAT_TITFORTAT_H


#include "../Strategy.h"

class TitForTatStrategy : public Strategy {
public:
    explicit TitForTatStrategy(double score) : Strategy(score) {}

    string getStrategyName() override;

    MoveType nextMove() override;

    void handleResult(MoveType) override;

    Strategy *clone() override;
};


#endif //TITFORTAT_TITFORTAT_H
