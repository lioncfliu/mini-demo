ass Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> top_order_v;
        vector<int> indegree_v(numCourses);
        vector<vector<int> > adj_v(numCourses);
        deque<int> q;
        for (int i = 0; i < numCourses; ++i) indegree_v[i] = 0;

        for (int i = 0; i < prerequisites.size(); ++i) {
            ++indegree_v[prerequisites[i][0]];
            adj_v[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (! indegree_v[i]) q.push_back(i);
        }

        while(! q.empty()) {
            int n = q.front();
            q.pop_front();
            top_order_v.push_back(n);
            for (auto &e : adj_v[n]) {
                --indegree_v[e];
                if (! indegree_v[e]) q.push_back(e);
            }
        }

        if (top_order_v.size() < numCourses) return vector<int>(0);
        return top_order_v;
    }
};

int main(int argch ,char* argv[]) 
{
    return 0;
}
