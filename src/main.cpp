// private headers
#include "solution.h"

// c++ headers
#include <iostream>

int main() {
    std::cout << "Enter the number of elements of the vector:" << std::endl;
    int size_vector;
    std::cin >> size_vector;

    std::cout << "Enter the number of elements of the map:" << std::endl;
    int size_map;
    std::cin >> size_map;

    if ( size_vector <= 0 || size_map <= 0 ) {
        throw std::invalid_argument("Wrong numbers!");
    }

    // Part 1
    std::vector<int> vec_rand(size_vector);
    RandSolution::randVector(vec_rand);

    std::map<int, int> map_rand;
    RandSolution::randMap(map_rand, size_map);

    // Part 2
    RandSolution::delRandVec(vec_rand);
    RandSolution::delRandMap(map_rand);

    // Part 3
    RandSolution::checkSim(vec_rand, map_rand);

    return 0;
}
