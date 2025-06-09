class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> counter;
        priority_queue<pair<int, char>> maxHeap;

        for (char &c: s) {
            ++counter[c];
        }

        for (auto& [c, n]: counter) {
            maxHeap.push({n, c});
        }

        int idx = 0;
        while (maxHeap.size() >= 2) {
            auto [num1, c1] = maxHeap.top();
            maxHeap.pop();

            auto [num2, c2] = maxHeap.top();
            maxHeap.pop();

            s[idx] = c1;
            --num1;

            ++idx;

            s[idx] = c2;
            --num2;

            ++idx;

            if (num1 > 0) {
                maxHeap.push({num1, c1});
            }

            if (num2 > 0) {
                maxHeap.push({num2, c2});
            }
        }

        if (!maxHeap.empty()) {
            auto [num, c] = maxHeap.top();

            if (num > 1) {
                return "";
            }

            s[idx] = c;
        }

        return s;
    }
};

