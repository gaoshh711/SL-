// author: gaoshh1
// pass
// time: 96ms 36.14%
// capacity: 68.8mb 5.86%
#include <vector>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = nums[0];
        vector<int> opt;
        opt.resize(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                opt[i] = nums[i];
            }
            else
            {
                opt[i] = max(opt[i - 1] + nums[i], nums[i]);
                ans = max(opt[i], ans);
            }
        }
        return ans;
    }
};