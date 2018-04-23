#include "000.config.h"

class Solution
{
  public:
    bool judgeCircle(string moves)
    {
        int len = moves.length();
        if (len < 1 || (len & 1) == 1)
            return false;
        int UPDO = 0;
        int LERI = 0;
        for (int i = 0; i < len; i++)
        {
            switch (moves[i])
            {
            case 'U':
                UPDO++;
                break;
            case 'D':
                UPDO--;
                break;
            case 'L':
                LERI++;
                break;
            case 'R':
                LERI--;
                break;
            default:
                return false;
            }
        }
        return UPDO == 0 && LERI == 0;
    }
};