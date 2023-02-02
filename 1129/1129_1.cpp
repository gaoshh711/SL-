// author: gaoshh1
// 基于di 最短路算法， 交错push
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<list<int>> red_Edge;
        red_Edge.resize(n);

        for (int i = 0; i < redEdges.size(); i++)
        {
            red_Edge[redEdges[i][0]].push_back(redEdges[i][1]);
        }

        vector<list<int>> blue_Edge;
        blue_Edge.resize(n);
        for (int i = 0; i < blueEdges.size(); i++)
        {
            blue_Edge[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }

        int flag = 0;
        vector<int> bool_r(n, 0);
        vector<int> bool_b(n, 0);
        vector<int> cur_r(n, __INT_MAX__);
        cur_r[0] = 0;
        vector<int> cur_b(n, __INT_MAX__);
        cur_b[0] = 0;

        std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> ms_r;
        std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> ms_b;
        ms_r.push(pair(0, 0));
        ms_b.push(pair(0, 0));
        while (!ms_r.empty() || !ms_b.empty())
        {
            if (!ms_r.empty())
            {
                pair<int, int> med = ms_r.top();
                ms_r.pop();
                if (bool_r[med.second] == 1)
                {
                    continue;
                }
                bool_r[med.second] = 1;
                for (auto iter = blue_Edge[med.second].begin(); iter != blue_Edge[med.second].end(); ++iter)
                {
                    if (bool_b[*iter] == 1)
                    {
                        continue;
                    }
                    if (cur_b[*iter] > cur_r[med.second] + 1)
                    {
                        cur_b[*iter] = cur_r[med.second] + 1;
                        ms_b.push(pair(cur_b[*iter], *iter));
                    }
                }
            }

            if (!ms_b.empty())
            {
                pair<int, int> med = ms_b.top();
                ms_b.pop();
                if (bool_b[med.second] == 1)
                {
                    continue;
                }
                bool_b[med.second] = 1;
                for (auto iter = red_Edge[med.second].begin(); iter != red_Edge[med.second].end(); ++iter)
                {
                    if (bool_r[*iter] == 1)
                    {
                        continue;
                    }
                    if (cur_r[*iter] > cur_b[med.second] + 1)
                    {
                        cur_r[*iter] = cur_b[med.second] + 1;
                        ms_r.push(pair(cur_r[*iter], *iter));
                    }
                }
            }
        }
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++)
        {
            int p_ans = min(cur_r[i], cur_b[i]);
            if (p_ans < __INT_MAX__)
            {
                ans[i] = p_ans;
            }
        }
        return ans;
    }
};