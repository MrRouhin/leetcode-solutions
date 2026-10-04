class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map to store the number and its corresponding index
        unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // If the complement is already in the map, we found our pair
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            
            // Otherwise, add the current number and its index to the map
            numMap[nums[i]] = i;
        }
        
        return {}; // Return empty vector if no solution is found
    }
};