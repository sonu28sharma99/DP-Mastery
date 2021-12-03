```c++
#include<bits/stdc++.h>
using namespace std;

// KADANES ALGO TO FIND MAX SUM SUBARRAY
int maxSumSubArray(vector<int>&arr){
    int curr_sum, max_sum;
    curr_sum = max_sum = arr[0];

    for(int i = 1; i < arr.size(); i++){
        curr_sum = max(curr_sum + arr[i], arr[i]);
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}


// MAIN DRIVER FUNCTION
int main(){
    // num of input
    int n;
    cin >> n;

    vector<int> arr(n);

    // taking input
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << maxSumSubArray(arr);
}
```

## input:
```
9
-2 1 -3 4 -1 2 1 -5 4
```
```
1
1
```
```
5
5 4 -1 7 8
```

## output:
```
6
```
```
1
```
```
23
```
