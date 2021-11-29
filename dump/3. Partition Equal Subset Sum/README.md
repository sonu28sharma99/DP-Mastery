
# 0-1 Knapsack:-

<!-- USING RECURSION -->
<details>
<summary>Using Recursion:</summary>
<br>

```c++
coming soon
```
</details>



<details>
<summary>Using Memoization (Bottom-Up Approach):</summary>
<br>

```c++
coming soon
```
</details>






<details>
<summary>Using Tabulation (Top-Down Approach):</summary>
<br>

```c++
// USING TABULATION (TOP DOWN APPROACH)
// TIME COMPLEXITY :- O(N * W) (SAME AS SUBSET SUM PROBLEM)

// same function of previous problem
bool targetSumSubet(vector<int>&subset, int target, int n) {
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
    // displayVector(dp);
    // return the last cell
    return dp[n][target];
}

bool partitionEqualSubsetSum(vector<int>&subset) {
    // No of element in subset
    int n = subset.size();

    // calculating sum of all elements in the subset
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += subset[i];

    // if sum is odd then we can't make equal partition
    if (sum % 2 != 0) return false;

    int target = sum / 2;

    bool ans = targetSumSubet(subset, target, n);

    return ans;
}
```
</details>





<!-- FULL SOURCE CODE -->
<details open="true">
<summary>Full Source Code:</summary>
<br>

```c++
#include<iostream>
#include<vector>
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


bool targetSumSubet(vector<int>&subset, int target, int n) {
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
    // displayVector(dp);
    // return the last cell
    return dp[n][target];
}

// TIME COMPLEXITY :- O(N * W) (SAME AS SUBSET SUM PROBLEM)
bool partitionEqualSubsetSum(vector<int>&subset) {
    // No of element in subset
    int n = subset.size();

    // calculating sum of all elements in the subset
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += subset[i];

    // if sum is odd then we can't make equal partition
    if (sum % 2 != 0) return false;

    int target = sum / 2;

    bool ans = targetSumSubet(subset, target, n);

    return ans;
}


int main() {
    // num of elements in subset
    int n; cin >> n;

    // Subset
    vector<int>subset(n);

    // taking input in subset
    for (int i = 0; i < n; i++) cin >> subset[i];


    cout << partitionEqualSubsetSum(subset) << endl;

}
```
</details>



## Example 1:-

```
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
```

## Example 2:-
```
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
```


