#include "000.config.h"

class Solution
{
  public:
    bool rotateString(string A, string B)
    {
        if (A.length() < 1 && B.length() < 1)
            return true;
        if (A.length() < 1 || B.length() < 1 || A.length() != B.length())
            return false;
        int len = A.length();
        for (int i = 0; i < len; i++)
        {
            if (A[i] == B[0])
            {
                if (isSame(A, B, i, len))
                    return true;
            }
        }
        return false;
    }
    bool isSame(string &A, string &B, int index, int length)
    {
        for (int i = 0; i < length; i++)
        {
            if (A[(index + i) % length] != B[i])
                return false;
        }
        return true;
    }
};