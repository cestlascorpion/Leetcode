/* 136. Single Number
 * 亦或操作 同零异一 
 * 亦或满足 交换律 和 自反性
 * A XOR B XOR B = A XOR 0 = A
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            result ^= nums[i];
        }
        return result;
        /*
        map<int,int> mapDog;
        map<int,int>::iterator it = mapDog.begin();
        for(int i = 0; i != nums.size(); i++)
        {
            it = mapDog.find(nums.at(i));
            if( it == mapDog.end())
                mapDog[nums.at(i)] = 1;  
            else
                mapDog.erase(it);
        }
        it = mapDog.begin();
        return it->first;
        */
    }
};