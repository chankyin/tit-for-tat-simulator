#ifndef TITFORTAT_GAMEPAIR_H
#define TITFORTAT_GAMEPAIR_H


#include "Strategy.h"
#include "PayoffMatrix.h"

class GamePair {
private:
    Strategy *a, *b;
    Strategy *aClone, *bClone;
    PayoffMatrix *matrix;
public:
    GamePair(PayoffMatrix *matrix, Strategy *a, Strategy *b);

    double calculateScoreProduct();

    void compete(double weight);

    ~GamePair();
};


#endif //TITFORTAT_GAMEPAIR_H
