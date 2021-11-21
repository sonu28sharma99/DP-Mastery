#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// FOR DEBUGGING PURPOSE:-
// function to display vector of vector
void displayVector(vector<vector<bool>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}


int targetSumSubet(vector<int>&subset, int target, int n) {
    // creating dp array
    vector<vector<bool>>dp(n + 1, vector<bool>(target + 1, false));

    // making first column true
    for (int i = 0; i < n + 1; i++) dp[i][0] = true;

    // making first row false from idx 1
    for (int j = 1; j < target + 1; j++) dp[0][j] = false;

    // Now real algorithm start here
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < target + 1; j++) {

            // if last element of the subset is less than our target
            // then we may be add or not add
            // Otherwise Don't need to add
            if (subset[i - 1] <= j)
                // or of ADD Karo ya Na karo
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - subset[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    displayVector(dp);

    int mn = INT_MAX;
    for (int j = 0; j < target / 2 + 1; j++) {
        if (dp[n][j] == true) {
            mn = min(mn, (target - 2 * j));
        }
    }

    return mn;
}




// MINIMUM SUBSET SUM DIFF
int minimumSubsetSumDiff(vector<int>&subset, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += subset[i];

    return targetSumSubet(subset, sum, n);
}



int main() {
    // num of elements in subset
    int n; cin >> n;

    // Subset
    vector<int>subset(n);

    // taking input in subset
    for (int i = 0; i < n; i++) cin >> subset[i];


    cout << minimumSubsetSumDiff(subset, n) << endl;

}
