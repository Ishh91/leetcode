//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> adj[V];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ans, indegree(V, 0);
        queue<int> q;
        
        for(int i=0; i<V; i++){
            for(auto u : adj[i])
                indegree[u]++;
        }
        
        for(int i=0; i<V; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(q.empty() == false){
            
            int v = q.front();
            q.pop();
            ans.push_back(v);
            
            for(auto u : adj[v]){
                indegree[u]--;
                if(indegree[u] == 0)
                    q.push(u);
            }
        }
        if(ans.size() != V){ vector<int> temp;
            return temp;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends