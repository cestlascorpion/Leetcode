/*
 * n = 2, [10 - 99] [10^2 - 99^2]  ->palindrom
 *
 */
class Solution {
public:
  long findPalindrom(long half)
  {
    string sfront = to_string(half);
    string sback(sfront.rbegin(), sfront.rend());
    return stol(sfront+sback);
  }
  int largestPalindrome(int n)
  {
    if (n == 1) {
      return 9;
    }
    else {
      long upperBound = (long)pow(10, n) - 1;//10^n - 1
      long lowerBound = (long)pow(10, n - 1);//
      long maxNumber = upperBound * upperBound -1;
      long half = maxNumber / (long)(pow(10, n));
      bool found = false;
      long palindrom = 0;
      while (!found)
      {
        palindrom = findPalindrom(half);
        for (long i = upperBound; i >= lowerBound; i--)
        {
          if (i*i < palindrom)
            break;
          if (palindrom % i == 0) {
            found = true;
            break;
          }
        }
        half--;
      }
            return palindrom % 1337;
        }
  }
};