//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   private:
    bool DFS(vector<int> adj[], int currNode, vector<bool> &visited, vector<bool> &currRecurr){
        visited[currNode] = true;
        currRecurr[currNode] = true;
        
        for(int &v : adj[currNode]){
            if(visited[v] && currRecurr[v]){
                return true;
            }
            else if(!visited[v]){
                if(DFS(adj, v, visited, currRecurr)) return true;   
            }
        }
        
        currRecurr[currNode] = false;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V, false), currRecurr(V, false);
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(DFS(adj, i, visited, currRecurr)) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends