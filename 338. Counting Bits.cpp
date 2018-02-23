class Solution
{
  public:
    /*
	vector<int> countBits(int num) 
    {
		vector<int> res;
		int cnt = 0;
		for (int i = 0; i <= num; i++)
		{
			int j = i;
			while (j)
			{
				if(j&1==1)
					cnt++;
				j = j>> 1;
			}
			res.push_back(cnt);
			cnt = 0;
		}
		return res;
	}
    
	vector<int> countBits(int num)
	{
		vector<int> res;
		int cnt = 0;
		for (int i = 0; i <= num; i++)
		{
			if (i % 2 == 0)
			{
				int j = i;
				while (j)
				{
					if (j & 1 == 1)
						cnt++;
					j = j >> 1;
				}
				res.push_back(cnt);

			}
			else
			{
				res.push_back(cnt + 1);
				cnt = 0;
			}
		}
		return res;
	}
    */
    vector<int> countBits(int num)
    {
        vector<int> dp(num + 1, 0);

        for (int i = 1; i <= num; i++)
        {
            dp[i] = dp[i >> 1] + (i % 2);
        }
        return dp;
    }
};