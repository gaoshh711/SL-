# author: gaoshh1
# TLE
class Solution:
    def reverse(self, num):
        string_num = str(num)
        string_num = string_num[::-1]
        i = len(string_num)-1
        ind = 0
        ans = 0
        while (i >= 0):
            ans += int(string_num[i])*(10**ind)
            ind += 1
            i -= 1
        return ans

    def countNicePairs(self, nums) -> int:
        ans = 0
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if (nums[i]+self.reverse(nums[j]) == nums[j]+self.reverse(nums[i])):
                    ans += 1
        return int(ans % (10e9+7))
