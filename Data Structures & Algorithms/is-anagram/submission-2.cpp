class Solution {
public:
    bool isAnagram(string s, string t) {
        //Populate a hashmap with <key (char), occurances <int>
        std::unordered_map<char, int> stored;
        for (const char& c : s) {
            if (stored.find(c) == stored.end()) {
                stored[c] = 1;
            } else {
                stored[c] += 1;
            }
        }

        //Now clear the hashmap
        for (const char& c : t) {
            if (stored.find(c) == stored.end()) {
                return false;
            } else if (stored[c] <= 0 ) {
                return false;
            }
            else {
                stored[c] -= 1;
            }
        }
        
        //check clearance
        for (const auto& [character, occurs] : stored) {
            if (occurs >= 1) {
                return false;
            }
        }

        return true;
    }
};
/*After using the hashmap I found that I could change to an
array of 26 and use the ascii value to index occurances, potential
implementation later, would save mem, but same mem and time order*/
