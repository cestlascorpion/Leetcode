#include "000.config.h"

class Solution
{
  public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int length = bits.size();
        if (length <= 0)
            return false;
        int index = 0;
        while (index < length)
        {
            if (bits[index] == '0' && index == length - 1)
                return true;
            if (bits[index] == '1')
                index++;
            index++;
        }
        return false;
    }
};