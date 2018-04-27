//
// Created by hans on 4/27/18.
//

#include "Leetcode204.h"

int Leetcode204::countPrimes(int n) {
    if (n < 2)
        return 0;
    vector<int> array(n - 1, 1);//1-(n-1)
    //2->n-1
    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (array[i] == 1) {
            ans++;
            for (int j = 2; j * (i + 1) < n; ++j) {
                array[j * (i + 1) - 1] = 0;
            }
        }
    }
    return ans;
}

void Leetcode204::test204() {
    int n = 10;//4
    cout << "Primes number (1~" << n << ") = " << countPrimes(n) << endl;

}
