#include<iostream>
#include<vector>
using namespace std;

// Reaturn no. of permutation of coins equals to the amount value 
int coinChangePermutation(vector<int>&coins, int amount) {
    // creating dp array
    vector<int> dp(amount + 1, 0);

    dp[0] = 1;

    for (int amt = 1; amt <= amount; amt++) {
        for (int coin : coins) {
            if (coin <= amt) {
                int remainingAmt = amt - coin;
                dp[amt] += dp[remainingAmt];
            }
        }
    }
    return dp[amount];
}

// Main driver function
int main() {
    int n; cin >> n; // array size

    vector<int> coins(n);

    // taking input in the array
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    int amount; cin >> amount;

    cout << coinChangePermutation(coins, amount) << endl;
}