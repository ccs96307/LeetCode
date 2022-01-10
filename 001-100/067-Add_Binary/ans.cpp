class Solution {
public:
    string addBinary(string a, string b) {
        // Init
        string sum;
        int carry = 0;
        int ai = a.size()-1;
        int bi = b.size()-1;
        int temp = 0;
        
        // a + b
        while (ai >= 0 || bi >= 0 || carry) {
            // Compute temp value
            temp = carry;
            if (ai >= 0 && a[ai] == '1') ++temp;
            if (bi >= 0 && b[bi] == '1') ++temp;
            
            // Carry
            carry = temp / 2;
            
            // Add to "sum"
            temp = temp % 2;
            if (temp == 1) sum =  "1" + sum;
            else sum = "0" + sum;            
            
            // Step
            --ai;
            --bi;
        }
        
        // Answer
        return sum;
    }
};

