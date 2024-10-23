#include <iostream>
#include <vector>
#include <cassert>
#include <set>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> setVec(nums.begin(), nums.end());
        nums.assign(setVec.begin(), setVec.end());
        return setVec.size();
    }
};

int main() {
    vector<int> nums = {1, 1, 2};
    vector<int> expectedNums = {1, 2};
    Solution sol;
    int k = sol.removeDuplicates(nums);

    assert(k == expectedNums.size());
    for(int i = 0; i < k; i++)
    {
        assert(nums[i] == expectedNums[i]);
    }

    cout << "success" << endl;
    return 0;
}