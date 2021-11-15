#include<iostream>
#include<vector>
using namespace std;

// function to find the min cost to reach destination
int minPathSum(vector<vector<int>> &grid){
    // row and col
    int row = grid.size(); int col = grid[0].size();
    
    // creating a dp array to store min cost to reach right-most bottom-most cell
    vector<vector<int>>dp(row, vector<int>(col, 0));
    
    // fill the right-most bottom-most cell
    dp[row-1][col-1] = grid[row-1][col-1];
    
    // fill the all bottom-most cells 
    for(int i = row-2; i >= 0; i--)
        dp[i][col-1] = grid[i][col-1]+dp[i+1][col-1];
        
    // fill the all bottom-most cells 
    for(int i = col-2; i >= 0; i--)
        dp[row-1][i] = grid[row-1][i]+dp[row-1][i+1];
        
    // fil all the left mid cells
    for(int i = row-2; i >= 0; i--){
        for(int j = col-2; j >=0; j--)
            dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
    }
    
    // first cell of dp contains the min Cost
    return dp[0][0];
}


// MAIN DRIVER FUNCTION
int main(){
    // row and col
    int row, col;
    cin >> row >> col;
    
    // declaring 2-d vector
    vector<vector<int>> arr(row, vector<int>(col, 0));
    
    // taking input in the arr
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            cin >> arr[i][j];
    }
    
    // printing the answer 
    cout << minPathSum(arr) << endl;
}