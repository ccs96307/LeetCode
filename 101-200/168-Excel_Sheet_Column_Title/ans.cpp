class Solution {
public:
    string convertToTitle(int columnNumber) {
        // Init
        string result;
        int remainder = 0;

        // Combine
        while (columnNumber > 0) {
            --columnNumber;
            remainder = columnNumber % 26;
            columnNumber = columnNumber / 26;

            char currChar = 'A' + remainder;
            result = currChar + result;
        }

        return result;
    }
};

