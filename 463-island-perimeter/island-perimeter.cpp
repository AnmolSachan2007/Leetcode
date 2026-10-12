class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>&visi ){
        if(i<0 || j<0 || j>=n || i>=m) return 1;
        if(visi[i][j]) return 0;
        if(grid[i][j]==0) return 1;
        visi[i][j]=1;

        return dfs(i+1,j,m,n,grid,visi) + dfs(i,j+1,m,n,grid,visi) + dfs(i-1,j,m,n,grid,visi)+dfs(i,j-1,m,n,grid,visi);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visi(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return dfs(i,j,m,n,grid,visi);
                }
            }
        }
        return 0;
    }
};