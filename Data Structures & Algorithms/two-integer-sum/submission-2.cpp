class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        std::unordered_map<int, int> diffs; //target diff, index
        
        for (int i = 0; i < nums.size(); i++) {
            int temp_diff = target - nums[i]; 
            if (diffs.find(temp_diff) == diffs.end()){ //see if this was a previous target diff
                diffs[nums[i]] = i; //if not add this target diff
            } else {
                return std::vector<int> ({diffs[temp_diff], i}); //when found return idx
            }
        }

        return {}; //err
    }
};
