// TIME : O(N)
// SPACE : O(N)
// ------------------------------------------------------
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // array size
        int n = nums.size();
        // store the left prefix product except self
        vector<int> L(n, 1);
        // store the right prefix product except self
        vector<int> R(n, 1);
        
        // store our result
        vector<int> result(n,1);
        
        // fill the left prefix product array
        for(int i = 1; i < n; i++)
            L[i] = L[i-1] * nums[i-1];
        
        // fill the right prefix product array
        for(int i = n-2; i >= 0; i--)
            R[i] = R[i+1] * nums[i+1];
    
        // At the end fill the result array
        // which is a multiple of left prefix * right prefix
        for(int i = 0; i < n; i++)
            result[i] = L[i] * R[i];
        
        // all done bro
        // just return the result array
        return result;
    }
};

// TIME : O(N)
// SPACE : O(1) as it is given outupt array is not considered as a space space
// ------------------------------------------------------
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // array size
        int n = nums.size();

        // our answer store here
        vector<int> ans(n,1);
        
        // calculate the prefix left product
        for(int i = 1; i < n; i++)
            ans[i] = ans[i-1] * nums[i-1];

        // calculate the prefix right product
        int product_right = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            ans[i] *= product_right;
            product_right*=nums[i];
        }
    return ans;
    }
};


