#ifndef TECH_FLOW_SOLUTION_H
#define TECH_FLOW_SOLUTION_H

// c++ headers
#include <random>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>


namespace Print{
    void printVector(const std::vector<int>& v);

    void printMap(const std::map<int, int>& m);
}

namespace RandSolution{
    int random(const int a, const int b);

    // Part 1
    void randVector(std::vector<int>& vec);
    void randMap(std::map<int, int>& map, const int cap);

    // Part 2
    void delRandVec(std::vector<int>& vec);
    void delRandMap(std::map<int, int>& map);

    // Part 3
    void checkSim(std::vector<int>& vec, std::map<int, int>& map);
}
#endif //TECH_FLOW_SOLUTION_H
