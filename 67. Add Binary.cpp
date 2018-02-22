class Solution
{
  public:
    string addBinary(string a, string b)
    {
        int size_a = a.size(), size_b = b.size();
        int delta = abs(size_a - size_b);
        if (size_a <= size_b)
            a.insert(0, delta, '0');
        else
            b.insert(0, delta, '0');
        int max = a.size();
        int carry = 0;
        string str;
        if (max == 0)
            return "0";
        else
        {
            for (int i = max - 1; i >= 0; i--)
            {
                switch (carry)
                {
                case 0:
                    if (a[i] == '0' && b[i] == '0')
                    {
                        str = str + '0';
                        carry = 0;
                    }
                    if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1'))
                    {
                        str = str + '1';
                        carry = 0;
                    }
                    if (a[i] == '1' && b[i] == '1')
                    {
                        str = str + '0';
                        carry = 1;
                    }
                    break;
                case 1:
                    if (a[i] == '0' && b[i] == '0')
                    {
                        str = str + '1';
                        carry = 0;
                    }
                    if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1'))
                    {
                        str = str + '0';
                        carry = 1;
                    }
                    if (a[i] == '1' && b[i] == '1')
                    {
                        str = str + '1';
                        carry = 1;
                    }
                    break;
                }
            }
            if (carry == 1)
                str = str + '1';
        }
        return string(str.rbegin(), str.rend());
    }
};