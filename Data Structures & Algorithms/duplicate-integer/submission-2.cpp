class Solution {
public:
    /* Brute force solution: O(n^2)
    bool hasDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }

        return false;
    } */

    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, bool> record;
        for (int i = 0; i < nums.size(); i++) {
            if (record[nums[i]]) {
                return true;
            } else {
                record[nums[i]] = true;
            }
        }
        return false;
    }
    /*
    Uses hashmap as a way to reduce time complexity
    while increasing the space complexity of the brute 
    force solution from O(1) to O(n), hashmap look-up speed
    */
};