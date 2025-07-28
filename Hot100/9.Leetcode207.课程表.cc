class Solution 
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        // 1. 初始化
        unordered_map<int, vector<int>> edges;
        vector<int> in(numCourses);

        // 2. 建图
        for(auto& e : prerequisites)
        {
            int a = e[0], b = e[1];
            edges[b].push_back(a);
            in[a]++;
        }

        // 3.拓扑排序
        queue<int> q;
        // 入度为 0 的点进队
        for(int i = 0; i < numCourses; i++)
        {
            if(in[i] == 0) q.push(i);
        }
        // BFS
        while(!q.empty())
        {
            auto t = q.front(); q.pop();
            for(auto e : edges[t])
            {
                in[e]--;
                if(in[e] == 0) q.push(e);
            }
        }

        for(auto e : in)
        {
            if(e) return false;
        }
        return true;
    }
};