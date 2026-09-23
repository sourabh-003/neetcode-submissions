class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(grid[0][i]==1) break;
            ans[0][i] = 1;
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1) break;
            ans[i][0] = 1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j]) continue;
                ans[i][j] = ans[i-1][j]+ans[i][j-1];
            }
        }
        return ans[n-1][m-1];
    }
};