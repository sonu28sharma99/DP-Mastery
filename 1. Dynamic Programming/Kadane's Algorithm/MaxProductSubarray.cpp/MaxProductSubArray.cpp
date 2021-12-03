#include<bits/stdc++.h>
using namespace std;
    // FUNCTION TO COMPUTER MAX PRODUCT SUBARRAY
    int maxProduct(vector<int>& nums) 
    {
    	// Guys, dont forget the corner case
    	if(nums.size()==0) return 0;
    
    	// Guys, Now we maintan three variables, initilized with first element of array 
    	int maxSub = nums[0]; // store the maximum product so far
    	int minSub = nums[0]; // store the minimum product so far
    	int ans = nums[0];	  // Store our desired output guys 
    
    
    	// Guys, Now we run a loop from index-1 to nums.size()-1
    	for(int i = 1; i < nums.size(); i++){
    
        // This is tricky case guy's 
        // if we found negative value
        // Then we simply swap the value
    
        // suppose we found -5 
        // and next eleent is -8 
        // then the product of two negative value is bigger positive value 
        // so that's why we swap, i hope you understand
    
    		if(nums[i] < 0)
    			swap(maxSub, minSub);
    
    		// next step is simple guys
    		// simply maintain the maxsub and minsub
    		maxSub = max(nums[i]*maxSub, nums[i]);
    		minSub = min(nums[i]*minSub, nums[i]);
    
    
    		// At the end
    		// if we found value greater than ans 
    		// simply update the ans
    		if(maxSub > ans)
    			ans = maxSub;
    	}
    	// All work complete guys 
    	// simply return the ans
    	return ans;
    } 


// MAIN DRIVER FUNCTION
int main(){
    // num of elements in array
    int n; cin >> n;

    vector<int> arr(n);

    // taking input in array
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxProduct(arr);

}