```c++
#include<bits/stdc++.h>
using namespace std;

// KADANES ALGO TO FIND MAX SUM SUBARRAY
int maxSumSubArray(vector<int>&arr){
    
    // Guy's we have to maintin two variables 
    int current_sum = arr[0];   // for comparing the current sum 
    int max_sum = arr[0];       // store the max sum so far

    for(int i = 1; i < arr.size(); i++){
        // Agar sum positive aa raha hai 
        // then we contribute
        if(current_sum >= 0)
            current_sum += arr[i];
        
        else 
            current_sum = arr[i]; 
        
        // At the end 
        // find max of current sum
        if(current_sum > max_sum)
            max_sum = current_sum;
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
