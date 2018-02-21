class Solution
{
  public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> pv(256, 0), sv(256, 0), res;
        if (s.size() < p.size())
            return res;

        for (int i = 0; i < p.size(); ++i)
        {
            ++pv[p[i]];
            ++sv[s[i]];
        }

        if (pv == sv) //如果相同说明[0,p.size-1]匹配成功
            res.push_back(0);

        for (int i = p.size(); i < s.size(); ++i)
        {
            ++sv[s[i]];            //维护长度为p.size-1的滑动窗口。把新写入的元素加入匹配容器sv
            --sv[s[i - p.size()]]; //把移动窗口后，待剔除元素的计数减掉
            if (pv == sv)          //比较是否相同
                res.push_back(i - p.size() + 1);
        }
        return res;
    }
};
//ASCII码使用指定的7 位或8 位二进制数组合来表示128或256种可能的字符。所以选择了长度为256的vector
//先将p序列长度的s/p写入vector, Index为ASCII对应的数值, value为出现的次数