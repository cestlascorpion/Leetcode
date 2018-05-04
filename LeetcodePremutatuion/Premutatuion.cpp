//
// Created by cestl on 2018/4/27 0027.
//

#include "Premutatuion.h"

vector<vector<int>> Premutatuion::premutatuion(vector<int> &nums) {
    vector<vector<int>> ans;
    if (nums.empty())
        return ans;
    int low = 0;
    int high = nums.size() - 1;
    premutatuionhelper(nums, low, high, ans);
    return ans;
}

void Premutatuion::premutatuionhelper(vector<int> nums, int low, int high,
                                      vector<vector<int>> &ans) {
    if (low == high) {
        ans.push_back(nums);
        return;
    }
    for (int i = low; i <= high; ++i) {
        swap(nums[low], nums[i]);
        premutatuionhelper(nums, low + 1, high, ans);
        swap(nums[low], nums[i]);
    }
}

void Premutatuion::testPremutatuion() {
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> ans = premutatuion(nums);
    for (auto item:ans) {
        for (auto jtem:item) {
            cout << jtem << " ";
        }
        cout << endl;
    }
    cout << endl;

}
