#include<iostream>
#include<vector>
using namespace std;

// function to display vector of vector
void displayVector(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

// Unbounded Knapsack function
int unboundedKnapsack(vector<int>&value, vector<int>&weight, int capacity) {
    
    // creating dp array
    vector<int>dp(capacity+1, 0);

    // first cell must be zero
    dp[0] = 0;

    for(int bagCap = 1; bagCap < capacity+1; bagCap++){
        for(int j = 0; j < value.size(); j++){
            
            int max = 0;
            if(weight[i] <= bagCap){
                int remBagCap= bagCap - weight[i];
                int remBagVal = dp[remBagCap];
                int total
            }
        }
    }



}


// Main driver function
int main() {
    // No of items
    int n; cin >> n;

    // value and weight array
    vector<int>value(n);
    vector<int>weight(n);

    // taking input in value
    for (int i = 0; i < n; i++)
        cin >> value[i];

    // taking input in weight
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    // capacity of the bag
    int capacity; cin >> capacity;

    cout << unboundedKnapsack(value, weight, capacity) << endl;
}