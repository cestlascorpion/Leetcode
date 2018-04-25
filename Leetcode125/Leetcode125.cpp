//
// Created by hans on 4/25/18.
//

#include "Leetcode125.h"

bool Leetcode125::isPalindrome(string s) {
    if (s.empty())
        return true;
    int low = 0;
    int high = s.length() - 1;

    while (low < high) {
        while (low < high && !isVaild(s[low]))
            ++low;
        while (high > low && !isVaild(s[high]))
            --high;
        if (low < high) {
            if (s[low] != s[high])
                return false;
        } else
            break;
        ++low;
        --high;
    }
    return true;
}

void Leetcode125::test125() {
    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s) << "==true?" << endl;
}

bool Leetcode125::isVaild(char &ch) {
    if (ch >= '0' && ch <= '9')
        return true;
    if (ch >= 'a' && ch <= 'z')
        return true;
    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;
        return true;
    } else
        return false;
}