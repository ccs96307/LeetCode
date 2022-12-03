class Solution {
public:
    string frequencySort(string s) {
        // Init
        unordered_map<char, int> freq;
        unordered_map<int, vector<char>> freq2chars;
        set<int, std::greater<int>> set;
        
        // Count
        for (char& c: s) {
            ++freq[c];
        }
        
        // Create the frequence-to-character mapping
        for (auto& it: freq) {
            freq2chars[it.second].emplace_back(it.first);
            set.insert(it.second);            
        }
        
        // Create new string
        string results;
        for (const int& f: set) {            
            for (auto c: freq2chars[f]) {
                results.append(f, c);
            }            
        }
        
        return results;
    }
};

