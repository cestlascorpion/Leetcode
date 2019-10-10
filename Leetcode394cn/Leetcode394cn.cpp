//
// Created by Wang on 2019/10/14.
//

#include "Leetcode394cn.h"

string Leetcode394cn::decodeString(string s) {
    if (s.empty()) {
        return "";
    }

    stack<string> stack;
    for (int i = 0; i < s.size();) {
        if (is_digit(s[i])) { // 'x['入栈
            int j = i + 1;
            while (s[j] != '[') ++j;
            stack.push(move(s.substr(i, j - i + 1)));
            i = j + 1; // j 指向 '['  i 移动到 j+1
        } else if (is_alpha(s[i])) { // 纯字符串入栈
            int j = i + 1;
            while (is_alpha(s[j])) ++j;
            stack.push(move(s.substr(i, j - i)));
            i = j; // j 指向 ']' 或者 'x['  i 移动到 j
        } else { // i 指向 ']'
            string str; // 取出所有的str并按照顺序连接
            while (is_alpha(stack.top()[0])) {
                str = stack.top() + move(str);
                stack.pop();
            }
            // 取出最近的 'x[' 解析出重复的次数->count
            string num = stack.top();
            stack.pop();
            num.pop_back();

            string tmp;
            int count = to_integer(num);
            while (count != 0) {
                tmp += str;
                --count;
            }
            stack.push(move(tmp)); // 串好之后再次压栈
            ++i;
        }
    }

    string res;
    while (!stack.empty()) {
        res = stack.top() + move(res);
        stack.pop();
    }
    return res;
}

bool Leetcode394cn::is_digit(char ch) {
    return ch >= '0' && ch <= '9';
}

int Leetcode394cn::to_integer(string s) {
    int res = 0;
    for (const char ch : s) {
        res = res * 10 + (ch - '0');
    }
    return res;
}

bool Leetcode394cn::is_alpha(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
