class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*initial idea is semi-brute force using the is anagram type of solution,
        I've solved previously, maybe line search and sort into groups if they are the
        same using calls to isAnagram*/
        vector<vector<string>> groups; 
        groups.push_back({strs[0]});
        for (int j = 1; j < strs.size(); j++) { 
            bool flag = false; //if in groups add to that group
            for (int k = 0; k < groups.size(); k++) {
                if (isAnagram(groups[k][0], strs[j])) {
                    flag = true;
                    groups[k].push_back(strs[j]);
                }
            } 
            if (!flag) {
                groups.push_back({strs[j]}); //else new vector to group
            } 
        }

        return groups;
    }

    bool isAnagram(string& s, string& t) { 
        //gives oppurtunity to try array solution 
        if (s.length() != t.length()) {
            return false;
        }

        int occurs[26] = {0};
        for (int i = 0; i < s.length(); i++) { //populate array
            occurs[s[i] - 'a'] += 1;
        }
        for (int i = 0; i < t.length(); i++) {
            occurs[t[i] - 'a'] -= 1;
            if (occurs[t[i] - 'a'] < 0) {
                return false;
            }
        }

        int sum = std::accumulate(std::begin(occurs), std::end(occurs), 0);
        if (sum == 0) {
            return true;
        } else {
            return false;
        }
    }
};
