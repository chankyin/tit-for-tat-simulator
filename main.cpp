#include <iostream>
#include "Strategy.h"
#include "PayoffMatrix.h"
#include "strategies/AlwaysCooperateStrategy.h"
#include "strategies/AlwaysDefectStrategy.h"
#include "strategies/TitForTatStrategy.h"
#include "GamePair.h"

using namespace std;

template<typename T>
void query(const string &query, T &);

template<typename T>
T query(const string &query);

int main() {
    PayoffMatrix matrix{};
    query("Both cooperate", matrix.bothCooperate);
    query("Both defect", matrix.bothDefect);
    query("If one cooperates and one defects, for the cooperator", matrix.onlyCooperator);
    query("And for the defector", matrix.onlyDefector);

    cout << "PAYOFF MATRIX" << endl;
    cout << "| Me \\ Opponent | Cooperate | Defect |" << endl;
    cout << "| Cooperate | " << matrix.bothCooperate << " | " << matrix.onlyCooperator << " |" << endl;
    cout << "| Defect | " << matrix.onlyDefector << " | " << matrix.bothDefect << " |" << endl;

    vector<Strategy *> strategies = {};
    strategies.push_back(new AlwaysCooperateStrategy(query<double>("AlwaysCooperate population")));
    strategies.push_back(new AlwaysDefectStrategy(query<double>("AlwaysDefect population")));
    strategies.push_back(new TitForTatStrategy(query<double>("TitForTat population")));

    unsigned long size = strategies.size();
    vector<GamePair *> gamePairs;
    for (int j = 0; j < size; ++j) {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wfor-loop-analysis"
        for (int k = j + 1; k < size; ++k) {
            gamePairs.push_back(new GamePair(&matrix, strategies[j], strategies[k]));
        }
#pragma clang diagnostic pop
    }

    auto turns = query<int>("Turns to test");

    for (int i = 0; i < turns; ++i) {
        double scoreProductSum = 0;
        for (GamePair *pair:gamePairs) {
            scoreProductSum += pair->calculateScoreProduct();
        }
        for (GamePair *pair:gamePairs) {
            pair->compete(pair->calculateScoreProduct() / scoreProductSum);
        }
        cout << "Results (#" << i << ")" << endl;
        cout << "=======" << endl;
        for (Strategy *strategy : strategies) {
            cout << strategy->getStrategyName() << ": " << strategy->score << endl;
        }
        cout << "=======" << endl;
    }


    return 0;
}

template<typename T>
void query(const string &query, T &store) {
    cout << query << ": ";
    cin >> store;
}

template<typename T>
T query(const string &query) {
    cout << query << ": ";
    T t;
    cin >> t;
    return t;
}
