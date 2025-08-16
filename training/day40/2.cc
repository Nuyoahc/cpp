// https://www.nowcoder.com/practice/64a4c026b2aa4411984f560deec36323?tpId=196&tqId=40272&ru=/exam/oj
// 拓扑排序

#include <queue>
#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numProject int整型 
     * @param groups int整型vector<vector<>> 
     * @return int整型vector
     */
    vector<int> findOrder(int numProject, vector<vector<int> >& groups) {
        // write code here
        vector<vector<int>> edges(numProject); // 边
        vector<int> in(numProject); // 入度

        // 建图
        for(auto & v : groups)
        {
            int a = v[0], b = v[1];
            edges[b].push_back(a); // b->a
            in[a]++;
        }

        // 入度0加队列
        queue<int> q;
        for(int i = 0; i <numProject; i++)
        {
            if(in[i] == 0) q.push(i);
        }

        // 层序遍历
        vector<int> res;
        while(q.size())
        {
            int t = q.front(); q.pop();
            res.push_back(t);
            for(auto &e : edges[t])
            {
                if(--in[e] == 0) q.push(e);
            }
        }
        if(res.size() == numProject)
            return res;
        else
            return {};
    }
};