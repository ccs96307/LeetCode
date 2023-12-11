class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        // Init
        unordered_map<int, int> n2times;

        // Count
        for (int& n: arr) {
            ++n2times[n];
        }

        // Get the maximum number
        int _max = 0;
        int _num = 0;
        for (auto& it: n2times) {
            if (_max < it.second) {
                _max = it.second;
                _num = it.first;
            }
        }

        return _num;
    }
};

