#ifndef TITFORTAT_STRATEGY_H
#define TITFORTAT_STRATEGY_H

#define COOPERATE true
#define DEFECT false
#define MoveType bool

#include <vector>
#include <string>

using namespace std;

class Strategy {
public:
    double score = 0;
    vector<MoveType> myHistory, otherHistory;

    explicit Strategy(double score) : score(score) {}

    virtual string getStrategyName() = 0;

    virtual MoveType nextMove() = 0;

    virtual void handleResult(MoveType) = 0;

    virtual Strategy *clone() = 0;
};


#endif //TITFORTAT_STRATEGY_H
