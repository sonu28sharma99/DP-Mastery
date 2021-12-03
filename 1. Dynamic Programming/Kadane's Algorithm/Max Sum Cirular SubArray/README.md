```c++
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
```

## Example 1:
```
Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
```
## Example 2:
```
Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
```
## Example 3:
```
Input: nums = [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
```
## Example 4:
```
Input: nums = [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
```
## Example 5:
```
Input: nums = [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1
```