#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int i;
        int carry_flag = 1;
        int sum = 0;
        for(i = size - 1; i >= 0; i--)
        {
            sum = digits[i] + carry_flag;
            if(10 <= sum)
            {
                carry_flag = 1;
                sum = sum - 10;
            }
            else
            {
                carry_flag = 0;
            }
            digits[i] = sum;
        }

        if(carry_flag)
        {
           
            digits.insert(digits.begin(), 1, carry_flag);
        }

        return digits;
    }
};

int main() {
    vector<int> digits = {9};
    vector<int> expected_digits = {1,0};
    int n = expected_digits.size();
    Solution sol;
    vector<int> res = sol.plusOne(digits);
    for(int i = 0; i < n; i++)
    {
        assert(res[i] == expected_digits[i]);
    }
    cout << "success" << endl;
    return 0;
}