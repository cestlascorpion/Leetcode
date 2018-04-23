#include "000.config.h"

class Solution
{
  public:
    int romanToInt(std::string s)
    {
        int sum = 0;
        int start = 0;

        char char_arr[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int int_arr[] = {1, 5, 10, 50, 100, 500, 1000};
        map<char, int> roman_map;
        int map_len = sizeof(char_arr) / sizeof(char);
        for (int i = 0; i < map_len; ++i)
            roman_map[char_arr[i]] = int_arr[i];
        for (int i = 0; i < s.length() - 1; ++i)
        {
            if (roman_map[s[i]] >= roman_map[s[i + 1]])
                sum += roman_map[s[i]];
            else
                sum -= roman_map[s[i]];
        }
        sum += roman_map[s[s.length() - 1]];
        return sum;
    }
};