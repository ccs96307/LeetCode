class Solution {
public:
    bool notDuplicatedInt[1000] = {};

    void DFS(std::vector<int>& digits, std::vector<bool>& isUsed, std::string& temp) {
        // Base case:
        if (temp.size() == 3) {
            int num = std::stoi(temp);
            if (num % 2 == 0) {
                notDuplicatedInt[num] = true;
            }
            return;
        }

        for (int i=0; i<digits.size(); ++i) {
            if (isUsed[i] || (temp.empty() && digits[i] == 0)) {
                continue;
            }

            isUsed[i] = true;
            temp.push_back('0' + digits[i]);

            DFS(digits, isUsed, temp);

            isUsed[i] = false;
            temp.pop_back();
        }
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        // Init
        std::vector<int> results;
        std::vector<bool> isUsed(digits.size(), false);
        std::string temp;

        DFS(digits, isUsed, temp);

        // Construct `results`
        for (int i=0; i<sizeof(notDuplicatedInt) / sizeof(notDuplicatedInt[0]); ++i) {
            if (notDuplicatedInt[i]) {
                results.emplace_back(i);
            }
        }

        return results;
    }
};
