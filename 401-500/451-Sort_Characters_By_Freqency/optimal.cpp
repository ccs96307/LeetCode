class Solution {
public:
    string frequencySort(string s) {
        // Create a map to store the frequency of each character in the string
        std::unordered_map<char, int> freq;
        for (const auto& c : s) {
            freq[c]++;
        }

        // Create a max-heap to store the characters in the string, sorted by their frequency
        std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>, std::less<std::pair<int, char>>> heap;
        for (const auto& [c, f] : freq) {
            heap.push({f, c});
        }

        // Build the result string by popping the characters from the max-heap
        std::string result;
        while (!heap.empty()) {
            const auto& [f, c] = heap.top();
            result.append(f, c);
            heap.pop();
        }

        return result;
    }
};

