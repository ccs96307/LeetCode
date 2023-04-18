class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // Init
        int size1 = word1.size();
        int size2 = word2.size();
        std::string mergeWord;

        // Reserve space for the merged word
        mergeWord.reserve(size1 + size2);

        // Merge
        int i = 0, j = 0;
        while (i < size1 && j < size2) {
            mergeWord.push_back(word1[i++]);
            mergeWord.push_back(word2[j++]);
        }

        // Append the remaining characters
        if (i < size1) {
            mergeWord.append(word1.substr(i));
        } 
        else {
            mergeWord.append(word2.substr(j));
        }

        return mergeWord;
    }
};


