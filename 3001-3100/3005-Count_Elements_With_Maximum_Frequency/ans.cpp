class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> num2freq(101, 0);
        vector<int> freq2times(101, 0);
        int maxFreq = 0;

        for (auto num: nums) {
            ++num2freq[num];
            int freq = num2freq[num];

            maxFreq = max(maxFreq, freq);

            ++freq2times[freq];
            --freq2times[freq-1];
        }

        return freq2times[maxFreq] * maxFreq;
    }
};

