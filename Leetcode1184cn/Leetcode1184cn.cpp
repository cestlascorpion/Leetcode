//
// Created by Wang on 2019/10/10.
//

#include "Leetcode1184cn.h"

int Leetcode1184cn::distanceBetweenBusStops(vector<int> &distance, int start, int destination) {
    if (start == destination)
        return 0;

    int forward = 0;
    int backward = 0;
    int cursor;
    cursor = start;
    while (cursor != destination) {
        forward += distance[cursor];
        cursor = (cursor + 1) % distance.size();
    }
    cursor = destination;
    while (cursor != start) {
        backward += distance[cursor];
        cursor = (cursor + 1) % distance.size();
    }
    return std::min(forward, backward);
}
