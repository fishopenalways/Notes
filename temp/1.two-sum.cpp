#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i;
        int j;
        bool flag = false;
        int size = nums.size();

        vector<int> res;
        for(i = 0; i < size; i++)
        {
            for(j = i + 1; j < size; j++)
            {
                if(target == nums[i] + nums[j])
                {
                    flag = true;
                    break;
                }
            }

            if (flag) break;
        }

        res.push_back(i);
        res.push_back(j);
        return res;
    }

    vector<int> hashedTwoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> res;
        int i;
        int size = nums.size();
        for(i = 0; i < size; i++)
        {
            if(map.end() != map.find(nums[i])) break;
            map.insert({target - nums[i], i});
        }
        res.push_back(map.at(nums[i]));
        res.push_back(i);
        return res;
    }
};

int main()
{
    vector<int> test = {3,2,4};
    int target = 6;
    vector<int> res(2);
    Solution sol;
    res = sol.hashedTwoSum(test, target);
    cout << res[0] << endl;
    cout << res[1] << endl;
    return 0;
}