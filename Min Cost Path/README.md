# `MIN COST PATH`

<p align="center">
<img src="./code.png"/>
</p>

---
## `Other Method:-`
```c++
// function to find the min cost to reach destination
int minPathSum(vector<vector<int>> &grid){
    // row and col 
    int row = grid.size(); int col = grid[0].size();
    
    // creating dp vector
    vector<vector<int>>dp(row, vector<int>(col, 0));
    

    
    for(int i = row-1; i >=0; i--){
        for(int j = col-1; j >= 0; j--){
            
            if(i==row-1 and j == col-1)
                dp[row-1][col-1] = grid[row-1][col-1];
            
            else if(i==row-1)
                dp[i][j] = grid[i][j] + dp[i][j+1];
                
            else if(j==col-1)
                dp[i][j] = grid[i][j] + dp[i+1][j];
            
            else
                dp[i][j] = grid[i][j] + min(dp[i][j+1], dp[i+1][j]);
        }
    }
    return dp[0][0];
}
}
```