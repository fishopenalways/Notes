#include <iostream>
#include <vector>
#include <cassert>
#include <set>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        set<int> set(nums.begin(), nums.end());
        set.erase(val);
        nums.assign(set.begin(), set.end());
        return set.size();
    }
};

int main() {
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    vector<int> expectedNums = {0,1,4,0,3};
    Solution sol;
    int k = sol.removeElement(nums, val);
    assert(k == expectedNums.size());
    sort(expectedNums, 0, k);
    sort(nums, 0, k);
    for(int i = 0; i < k; i++)
    {
        assert(nums[i] == expectedNums[i]);
    }

    cout << "success" << endl;
    return 0;
}