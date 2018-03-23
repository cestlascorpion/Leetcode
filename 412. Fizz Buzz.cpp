class Solution
{
  public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> ans;
        for (int i = 1; i <= n; i++)
        {
            bool Fizz = i % 3 == 0;
            bool Buzz = i % 5 == 0;
            if (!Fizz && !Buzz)
                ans.push_back(to_string(i));
            else if (Fizz && !Buzz)
                ans.push_back("Fizz");
            else if (!Fizz && Buzz)
                ans.push_back("Buzz");
            else
                ans.push_back("FizzBuzz");
        }
        return ans;
    }
};