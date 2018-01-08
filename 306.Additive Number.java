class Solution {
    public boolean isAdditiveNumber(String num)
    {
      if(num.length() < 3)
      {
        return false;
      }
      else
      {
        for(int i = 1; i <= num.length()/2; i ++)
        {
          if(num.charAt(0) == '0' && i > 1)
          {
            return false;
          }
          Long first = Long.valueOf(num.substring(0, i));
          for(int j = 1; num.length() - i - j >= Math.max(i, j); j ++)
          {
            if(num.charAt(i) == '0' && j > 1)
              break;
            else
            {
              Long second = Long.valueOf(num.substring(i, i + j));
              if(isValid(first, second, i + j, num))
                return true;
            }
          }
        }
        return false;
      }
    }
    public boolean isValid(Long first, Long second, int start, String num)
    {
      if(start == num.length())
        return true;
      else
      {
        second = second + first;
        first = second - first;
        return (num.startsWith(second.toString()) && isValid(first, second, start + second.toString().length(), num));
      }
    }
}
