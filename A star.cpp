#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

struct Node{
    int x, y, g, f;
};

struct cmp {
    bool operator()(Node a, Node b) {
        return a.f > b.f;
    }
};

int h(int x, int y, int gx, int gy){
    return abs(x - gx) + abs(y - gy);
}

void astar(int grid[3][3], int sx, int sy, int gx, int gy){
    priority_queue< Node, vector<Node>, cmp> pq;
    bool visited[3][3] = {false};
    
    pq.push({sx, sy, 0, h(sx, sy, gx, gy)});
    
    while(!pq.empty()){
        Node cur = pq.top();
        pq.pop();
        
        int x = cur.x;
        int y = cur.y;
        
        if(visited[x][y] ) continue;
        visited[x][y] = true;
        
        cout << "(" << x << "," << y << ") ";
        
        if (x == gx && y == gy){
            cout<< "Goal Reached !!!";
            return;
        }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && ny >= 0 && nx < 3 && ny < 3 && grid[nx][ny] == 0){
                int g = cur.g + 1;
                int f = g +  h(nx, ny, gx, gy);
                pq.push({nx, ny, g, f}); 
            }
        }
    }
    
    cout<<"No Path";
}

int main(){
    int grid[3][3]={
        {0,0,0},
        {0,1,1},
        {0,0,0}
    };
    
    astar(grid, 0, 0, 2, 2);
}