class Solution {
    bool solve(int i, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &path)
    {
        vis[i] = true;
        path[i] = true;

        for (auto val : adj[i])
        {
            if (!vis[val])
            {
                if (solve(val, adj, vis, path))
                {
                    return true;
                }
            }
            else if (path[val])
            {
                return true;
            }
        }

        path[i] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, false);
        vector<bool> path(numCourses, false);

        vector<vector<int>> adj(numCourses);

        for (auto &i : prerequisites)
        {
            adj[i[1]].push_back(i[0]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                if (solve(i, adj, vis, path))
                {
                    return false;
                }
            }
        }

        return true;
    }
};