template <typename T>
class cmp {
public: 
    bool operator()(T a, T b) {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        else {
            return a.second.compare(b.second) > 0;
        }
    }
};

class Solution {
public:    
    vector<string> topKFrequent(vector<string>& words, int k) {
        // Init
        unordered_map<string, int> freq;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp<pair<int, string>>> freq_and_word;
        vector<string> results;
        
        // Count
        for (auto& word: words) {
            ++freq[word];
        }
        
        // Sort
        for (auto& it: freq) {
            freq_and_word.push({it.second, it.first});
        }
        
        for (int i=0; i<k; ++i) {
            string _w = freq_and_word.top().second;
            results.push_back(_w);
            freq_and_word.pop();
        }
        
        return results;
    }
};
