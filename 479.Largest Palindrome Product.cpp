/*
 * n = 2, [10 - 99] [10^2 - 99^2]  ->palindrom
 *
 */
class Solution {
public:
  void str2long(long &long_temp, const string &string_temp)
  {
    stringstream stream(string_temp);
    stream >> long_temp;
  }
  void long2str(const long &long_temp, string &string_temp)
  {
    stringstream stream;
    stream << long_temp;
    string_temp = stream.str();
  }
  long findPalindrom(long half)
  {
    long ret;
    string sfront;
    long2str(half, sfront);
    string sback(sfront.rbegin(), sfront.rend());
    str2long(ret, sfront + sback);
    return ret;
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
      int ret = palindrom % 1337;
      return ret;
    }
  }
};