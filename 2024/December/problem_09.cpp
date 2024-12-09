/*An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that 
subarray
 nums[fromi..toi] is special or not.

Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.
*/

// #Approach - 01

class Solution {
public:
    // Function to check if subarrays are special for given queries
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(); // Get the size of the input array nums
        vector<int> cs(n, 0); // Create a prefix sum array to store parity consistency

        // Step 1: Preprocess the array to fill the 'cs' array
        // cs[i] will store how many adjacent pairs from nums[0] to nums[i] have the same parity
        for (int i = 1; i < n; i++) {
            // If the current number and the previous number have the same parity
            // (both even or both odd), increment the count in cs[i]
            if (nums[i] % 2 == nums[i - 1] % 2) {
                cs[i] = 1 + cs[i - 1]; // Same parity, continue the count
            } else {
                cs[i] = cs[i - 1]; // Different parity, no need to increment
            }
        }

        // Step 2: Answer the queries
        int q = queries.size(); // Get the number of queries
        vector<bool> result(q, false); // Vector to store the results for each query

        // For each query, check if the subarray is special
        for (int i = 0; i < q; i++) {
            int x = queries[i][0]; // Starting index of the query
            int y = queries[i][1]; // Ending index of the query

            // Check if the subarray nums[fromi..toi] is special
            // A subarray is special if there are no adjacent elements with the same parity
            // This can be checked by ensuring the difference between cs[y] and cs[x] is 0
            if (cs[y] - cs[x] == 0) {
                result[i] = true; // Subarray is special, so set result[i] to true
            } else {
                result[i] = false; // Subarray is not special, so set result[i] to false
            }
        }

        return result; // Return the result array with true/false for each query
    }
};


//#Approach - 02

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();  // Get the size of the input array nums
        vector<int> tillRight(n);  // Create a vector to store the farthest index where each subarray starting at index i is special
        
        int i = 0, j = 0;  // Two pointers: i for the starting index of the subarray, j for the farthest index where parity alternates

        // Step 1: Preprocess the array to fill the tillRight array
        while(i < n) {
            // Ensure j is always ahead or equal to i (if j is behind i, move it forward)
            if(j < i) {
                j = i;
            }

            // Step 1.1: Extend the subarray to the right as long as the parities alternate
            while(j + 1 < n && nums[j] % 2 != nums[j + 1] % 2) {
                j++;  // Move j to the right, continuing the alternating parity sequence
            }

            // Step 1.2: Store the farthest index where the subarray starting at i is special
            tillRight[i] = j;
            i++;  // Move to the next starting index
        }

        // Step 2: Process each query
        int q = queries.size();  // Number of queries
        vector<bool> result(q, false);  // Result array to store the answers for each query

        // Step 2.1: For each query, check if the subarray nums[fromi..toi] is special
        for(int i = 0; i < q; i++) {
            int x = queries[i][0];  // Starting index of the query
            int y = queries[i][1];  // Ending index of the query

            // If the ending index y is within the range of the farthest special subarray starting at x,
            // then the subarray nums[fromi..toi] is special
            if(y <= tillRight[x]) {
                result[i] = true;  // The subarray is special
            }
        }

        return result;  // Return the result array with true/false for each query
    }
};
