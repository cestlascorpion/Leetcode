//
// Created by cestl on 2018/5/3 0003.
//

#ifndef LEETCODE_LEETCODE690_H
#define LEETCODE_LEETCODE690_H

#include "../config.h"

class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Leetcode690 {
public:
    int getImportance(vector<Employee *> employees, int id);

    int getSum2(unordered_map<int, Employee *> &pool, int id);

    int getSum(unordered_map<int, Employee *> &pool, int id);
};


#endif //LEETCODE_LEETCODE690_H
