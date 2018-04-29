//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode475.h"

int Leetcode475::findRadius(vector<int> &houses, vector<int> &heaters) {
    int ans = 0;
    sort(heaters.begin(), heaters.end());
    for (int i = 0; i < houses.size(); ++i) {
        int index = binarySearch(heaters, houses[i]);
        int dist1 = index - 1 >= 0 ? houses[i] - heaters[index - 1] : INT32_MAX;
        int dist2 = index < heaters.size() ? heaters[index] - houses[i] : INT32_MAX;
        ans = max(ans, min(dist1, dist2));
    }
    return ans;
}

int Leetcode475::binarySearch(vector<int> &heaters, int target) {
    int low = 0, high = heaters.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (heaters[mid] == target)
            return mid;
        else if (heaters[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low < 0 ? ~low : low;
}

int Leetcode475::findRadius2(vector<int> &houses, vector<int> &heaters) {
    int ans = 0;
    if (houses.empty() || heaters.empty())
        return 0;
    sort(heaters.begin(), heaters.end());

    for (int i = 0; i < houses.size(); i++) {
        int left = 0, right = heaters.size() - 1, mid = 0;
        while (left < right - 1) {
            mid = (left + right) >> 1;
            if (heaters[mid] < houses[i])
                left = mid;
            else if (heaters[mid] > houses[i])
                right = mid;
            else break;
        }
        if (heaters[mid] == houses[i] || heaters[left] == houses[i] || heaters[right] == houses[i])
            continue;
        int a = abs(houses[i] - heaters[left]);
        int b = abs(heaters[right] - houses[i]);
        ans = max(a < b ? a : b, ans);
    }
    return ans;
}

void Leetcode475::test475() {
    vector<int> houses = {1, 2, 3};
    vector<int> heaters = {2};
    cout << "radius=" << findRadius2(houses, heaters) << endl;
}
