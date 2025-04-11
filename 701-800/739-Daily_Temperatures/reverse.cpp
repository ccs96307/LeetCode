class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Init
        vector<int> results(temperatures.size(), 0);

        // Find the larger point at the left side
        for (int i=temperatures.size()-2; i>=0; --i) {
            int j = i + 1;
            int steps = 1;
            bool isFound = false;

            // If `j` not out of boundary that we can explore
            while (j < temperatures.size()) {
                if (temperatures[i] >= temperatures[j]) {
                    if (results[j]) {
                        steps += results[j];
                        j += results[j];
                    }
                    else {
                        break;
                    }
                }
                else {
                    isFound = true;
                    break;
                }
            }

            if (isFound) {
                results[i] = steps;
            }
        }
        
        return results;
    }
};

