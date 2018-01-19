/* 461. Hamming Distance
 * 按位亦或 同零异一
 * 计算一的数量 得到汉明距离
 */ 
class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp = x^y;
        int result = 0;
        if(temp == 0)
        {
            return result;
        }
        while(temp!=0)
        {
            if(temp&1 == 1)
                result++;
            temp=temp>>1;
        }
        return result;
    }
};