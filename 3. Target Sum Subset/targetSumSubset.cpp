#include<iostream>
#include<vector>
using namespace std;

// function to display vector of vector
void displayVector(vector<vector<bool>> v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[0].size(); j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
}


// function that return
// any subset sum present that is equal to the target
int targetSumSubset(vector<int>&arr, int target) {
	// array size
	int n = arr.size();

	// creating 2D dp array
	// that store subset is present or not
	vector<vector<bool>>dp(n + 1, vector<bool>(target + 1, false));

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j <= target; j++) {

			// first cell makes subset of zero
			if (i == 0 and j == 0)
				dp[i][j] = true;

			// uppermost row
			// can't make any subset b/c no element is present in first
			else if (i == 0) {
				dp[i][j] = false;
			}

			// left-most column
			// can easily make the subset of 0
			else if (j == 0) {
				dp[i][j] = true;
			}

			// for rest of the cells
			// that are in the mid
			else {
				// if upper cell is true than true
				if (dp[i - 1][j] == true)
					dp[i][j] = true;

				// Otherwise
				else {
					// getting/extracting the value of array of that index
					int value = arr[i - 1];
					// checking otherwise array idx out of bound error occur
					if (j >= value ) {
						if (dp[i - 1][j - value] == true)
							dp[i][j] = true;
					}
				}
			}
		}
	}
	// displayVector(dp);	for dubugging
	return dp[n][target];
}


// MIN DRIVER FUNCTION
int main() {
	// array size
	int n;
	cin >> n;

	// vector
	vector<int> arr(n, 0);

	// input elements in vector
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	// target
	int target; cin >> target;

	// print the answer
	cout << targetSumSubset(arr, target) << endl;
}