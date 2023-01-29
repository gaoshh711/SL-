# author: gaoshh1
class Solution:
    def findingUsersActiveMinutes(self, logs, k: int):
        ans_ = {}
        ans = [0 for i in range(k)]
        logs = list(set([tuple(i) for i in logs]))

        for i in range(len(logs)):
            if (logs[i][0] not in ans_):
                ans_[logs[i][0]] = 1
            else:
                ans_[logs[i][0]] += 1
        for i in ans_.keys():
            ans[ans_[i]-1] += 1
        return ans
