通过断掉相关联系 寻找孤立物体 
=========================================================================================================
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

		vector<vector<int>> simpleG;

		for (int i = 0; i < numCourses; i++) {
			vector<int> a;
			simpleG.push_back(a);
		}

		for (int i = 0; i < prerequisites.size(); i++) {
			vector<int>& b = prerequisites[i];
			int from = b[0];
			int end = b[1];

			simpleG[from].push_back(end);
		}

		vector<bool> visted(numCourses, false);

		for (int i = 0; i < numCourses; i++) {
			set<int> b;
			if (!visted[i] && hasCycle(i,b,simpleG,visted)) {
				return false;
			}
		}

		return true;
	}

	bool hasCycle(int index,set<int>& his, vector<vector<int>>& simpleG,vector<bool> & vec) {

		vec[index] = true;
		his.insert(index);

		vector<int>& nodes = simpleG[index];
		for (int i = 0; i < nodes.size(); i++) {
			int node = nodes[i];
			if (his.count(node) || hasCycle(node, his,simpleG,vec)) {
				return true;
			}
		}
	
		his.erase(index);
		return false;
	}
};


========================================================================================
	
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> degrees = computeIndegrees(g);
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (!degrees[j]) {
                    break;
                }
            }
            if (j == numCourses) {
                return false;
            }
            degrees[j]--;
            for (int v : g[j]) {
                degrees[v]--;
            }
        }
        return true;
    }
private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) {
            g[p.second].push_back(p.first);
        }
        return g;
    }
    
    vector<int> computeIndegrees(graph& g) {
        vector<int> degrees(g.size(), 0);
        for (auto adj : g) {
            for (int v : adj) {
                degrees[v]++;
            }
        }
        return degrees;
    }
};
	
========================================================================================
	
bool canFinish(int n, vector<pair<int, int>>& pre) {
    vector<vector<int>> adj(n, vector<int>());
    vector<int> degree(n, 0);
    for (auto &p: pre) {
        adj[p.second].push_back(p.first);
        degree[p.first]++;
    }
    queue<int> q;
	
    for (int i = 0; i < n; i++)
        if (degree[i] == 0) q.push(i);
	
    while (!q.empty()) {
        int curr = q.front(); q.pop(); n--;
        for (auto next: adj[curr])
            if (--degree[next] == 0) q.push(next);
    }
    return n == 0;
}
