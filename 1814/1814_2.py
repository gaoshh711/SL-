# author: gaoshh1
# pass
# time: 1036ms 5.67%
# capacity: 22.7mb 90.91%
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

    def countNicePairs(self, nums):
        ans = {}
        for i in nums:
            ind = i-self.reverse(i)
            if (ans.get(ind)):
                ans[ind] += 1
            else:
                ans[ind] = 1
        ans_ = 0
        for i in ans:
            ans_ += ans[i]*(ans[i]-1)/2
        return int(ans_) % (1000000007)
