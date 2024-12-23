#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxProd = nums[0]; // Initialize the maximum product
        int minProd = nums[0]; // Initialize the minimum product (to account for negatives)
        int result = nums[0];  // Result stores the maximum product found so far

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                swap(maxProd, minProd); // Swap max and min because a negative number reverses their roles
            }

            maxProd = max(nums[i], maxProd * nums[i]); // Update max product ending at current index
            minProd = min(nums[i], minProd * nums[i]); // Update min product ending at current index

            result = max(result, maxProd); // Update the global maximum
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {2, 3, -2, 4};
    cout << "Input: nums = [2, 3, -2, 4]" << endl;
    cout << "Output: " << solution.maxProduct(nums1) << endl;

    // Example 2
    vector<int> nums2 = {-2, 0, -1};
    cout << "Input: nums = [-2, 0, -1]" << endl;
    cout << "Output: " << solution.maxProduct(nums2) << endl;

    return 0;
}
