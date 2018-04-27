//
// Created by hans on 4/27/18.
//

#include "Leetcode412.h"

vector<string> Leetcode412::fizzBuzz(int n) {
    vector<string> ans;
    for (int i = 1; i <= n; i++) {
        bool Fizz = i % 3 == 0;
        bool Buzz = i % 5 == 0;
        if (!Fizz && !Buzz)
            ans.push_back(to_string(i));
        else if (Fizz && !Buzz)
            ans.push_back("Fizz");
        else if (!Fizz && Buzz)
            ans.push_back("Buzz");
        else
            ans.push_back("FizzBuzz");
    }
    return ans;
}

void Leetcode412::test412() {
    int n = 15;
    vector<string> str = fizzBuzz(15);
    for (auto item:str)
        cout << item << endl;
    cout << endl;
}
