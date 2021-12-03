#include<bits/stdc++.h>
using namespace std;

// FUNCTION TO CALCULATE THE MAX SUM CIRCULAR SUBARRAY
int maxSumCircularSubArray(vector<int>&arr){
    int currSum, maxSum,
    currSum = maxSum = arr[0];

    int currMin, maxMin;
    currMin = maxMin = arr[0];

    int arraySum = arr[0];

    for(int i = 1; i < arr.size(); i++){
        // max sum subarray
        currSum = max(currSum + arr[i], arr[i]);
        maxSum = max(maxSum, currSum);

        // min sum subarray
        currMin = min(currMin + arr[i], arr[i]);
        maxMin = min(maxMin, currMin);

        // maintain array sum
        arraySum += arr[i];
    }

    if(maxSum > 0)
        return max(maxSum, arraySum-maxMin);
    return maxSum;
}




// MAIN DRIVER FUNCTION
int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    // taking input 
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    maxSumCircularSubArray(arr);
}