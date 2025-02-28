#include<iostream>
#include<vector>
using namespace std;
// function to display vector of vector
void displayVector(vector<vector<int>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

int findCount(vector<int>&subset, int target, int n) {
    // creating a dp array to store subproblem
    vector<vector<int>>dp(n + 1, vector<int>(target + 1, 0));

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;

    for (int j = 1; j < target + 1; j++)
        dp[0][j] = 0;

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < target + 1; j++) {
            if (subset[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - subset[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    displayVector(dp);
    return dp[n][target];
}

int main() {
    int n; cin >> n;

    vector<int> subset(n);

    for (int i = 0; i < n; i++) cin >> subset[i];

    int sum; cin >> sum;

    cout << findCount(subset, sum, n) << endl;
}