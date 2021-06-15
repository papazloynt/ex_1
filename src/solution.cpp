// private headers
#include "solution.h"

// c++ headers
#include <iostream>

// The output(std::cout) should be in main, I left it in the main library
// for ease of checking. But mostly I leave it in the main

// Optional
void Print::printVector(const std::vector<int>& v){
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Optional
void Print::printMap(const std::map<int, int>& m){
    for (auto i : m) {
        std::cout << i.second << " ";
    }
    std::cout << std::endl;
}

// I don't use rand ()% n as it is not thread safe.
int RandSolution::random(const int a, const int b) {
    if (a >= b) throw std::logic_error("Invalid argument");
    std::random_device rd;
    std::mt19937_64 rng(rd());
    std::uniform_int_distribution<int> rand(a, b);
    return rand(rng);
}

void RandSolution::randVector(std::vector<int>& vec){
    for ( auto& v : vec ) {
        v = random(1, 9);
    }
    Print::printVector(vec);
}

void RandSolution::randMap(std::map<int, int>& map, const int cap){
    for ( int i = 0; i < cap; ++i ) {
        map.insert(std::make_pair(i, random(1, 9)));
    }
    Print::printMap(map);
}

void RandSolution::delRandVec(std::vector<int>& vec){
    int del_num = random(1, 15);
    while ( del_num > 0 && !vec.empty() ) {
        vec.pop_back();
        --del_num;
    }
    Print::printVector(vec);
}

void RandSolution::delRandMap(std::map<int, int>& map){
    int del_num = random(1, 15);
    while( del_num > 0 && !map.empty() ) {
        map.erase(--map.end());
        --del_num;
    }
    Print::printMap(map);
}

// std::map sorted by keys, so no iteration
// it is impossible to check for each element of std::map

void RandSolution::checkSim(std::vector<int>& vec, std::map<int, int>& map){
    // Remove vec elements that are not in map
    auto it_vec = vec.begin();
    while ( it_vec != vec.end() ){
        auto it_map = std::find_if(map.begin(),
                                   map.end(),
                                   [&it_vec](const auto& kv_pair) {
                                       return kv_pair.second == *it_vec;
                                   });
        if ( it_map == map.end() ) {
            it_vec = vec.erase(it_vec);
            --it_vec;
        }
        ++it_vec;
    }

    // Create a new_map and insert the elements that are present in the vec
    std::map<int, int> new_map;
    int count = 0;
    for ( const auto& m : map )
    {
        for ( const auto& v : vec ) {
            if ( m.second == v ) {
                new_map.insert(std::make_pair(count, v));
                ++count;
                break;
            }
        }
    }
    map.swap(new_map);
    Print::printVector(vec);
    Print::printMap(map);
}
