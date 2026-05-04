#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> adj[100];
bool visited[100];

void dfs(int node){
    visited[node] = true;
    cout << node << " ";
    
    for(int neighboour : adj[node]){
        if (!visited[neighboour]){
            dfs(neighboour);
        }
    }
}

void bfs(int node){
    queue<int> q;
    visited[node] = true;
    q.push(node);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        cout << node << " ";
        
        for (int neighboour : adj[node]){
            if (!visited[neighboour]){
                visited[neighboour] = true;
                q.push(neighboour);
            }
        }
    }
    
    
}

int main(){
    int n, e;
    cout << "Enter number of nodes and edges : ";
    cin >> n >> e;
    
    for (int i = 0; i < e; i++){
        int u, v;
        cout << "Enter the node :";
        cin >> u;
        cout << "Enter the connected edges :";
        cin >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cout<<"DFS :";
    dfs(1);
    
    for(int i = 0; i <= n; i++){
        visited[i] = false;
    }
    
    cout<<"\nBFS :";
    bfs(1);
}