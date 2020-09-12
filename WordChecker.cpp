

#include <iostream>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool dfs(char** grid, int x, int y, int n, int m, string& word, bool** vis, int len){
    if(word.size()==len){
        return true;
    }
     
     if(x<0 || x>=n || y<0 || y>=m)
     return false;
     
    if(!vis[x][y] && grid[x][y] == word[len]){
        vis[x][y] = true;
        
        bool b = dfs(grid, x+dx[0], y+dy[0], n, m, word, vis, len+1) |
                 dfs(grid, x+dx[1], y+dy[1], n, m, word, vis, len+1) |
                 dfs(grid, x+dx[2], y+dy[2], n, m, word, vis, len+1) |
                 dfs(grid, x+dx[3], y+dy[3], n, m, word, vis, len+1);
                 
        vis[x][y] = false;
        return b;
        
    }
    
    return false;
    
}

bool checkWord(char** grid, int n, int m, string& word){
    int l = word.size();
    if(l>n*m){
        return false;
    }
    
    bool** vis = new bool*[n];
    for(int i=0; i<n; i++){
        vis[i] = new bool[m];
        for(int j=0; j<m; j++){
            vis[i][j] = false;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == word[0]){
                if(dfs(grid, i, j, n, m, word, vis, 0)){
                    return true;
                }
            }
        }
    }
    
    return false;
}

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    char** grid = new char*[n];
    for(int i=0; i<n; i++){
        grid[i] = new char[m];
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    
    string word;
    cin>>word;
    if(checkWord(grid, n, m, word)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }

    return 0;
}
