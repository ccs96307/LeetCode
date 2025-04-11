class Solution {
public:
    string multiply(string num1, string num2) {
        // Exception
        if (num1 == "0" || num2 == "0") return "0";
        
        // Init
        int carry = 0;
        string sum = "";
        vector<string> part_sum;
        
        // Multiply        
        for (int i=num1.size()-1; i>=0; --i) {
            for (int j=num2.size()-1; j>=0; --j) {
                int temp_sum = (int(num1[i]-48)) * (int(num2[j]-48)) + carry;
                carry = temp_sum / 10;
                sum = char(temp_sum%10+48) + sum;
            }
            
            // Carry
            if (carry > 0) {
                sum = char(carry+48) + sum;
                carry = 0;
            }
            
            // Clear
            for (int k=i; k<num1.size()-1; ++k) sum += "0";
            part_sum.push_back(sum);
            sum.clear();
        }
        
        for (string s: part_sum) cout << s << endl;
        
        // Padding
        int max_len = 0;
        for (int i=0; i<part_sum.size(); ++i) {
            if (part_sum[i].size() > max_len) max_len = part_sum[i].size();
        }
        
        for (int i=0; i<part_sum.size(); ++i) {
            while (part_sum[i].size() < max_len) part_sum[i] = "0" + part_sum[i];
        }
        
        for (string s: part_sum) cout << s << endl;

        // Summing
        carry = 0;
        for (int i=max_len-1; i>=0; --i) {
            int temp_sum = carry;
            
            for (int j=0; j<part_sum.size(); ++j) {
                temp_sum += int(part_sum[j][i])-48;
            }
            
            carry = temp_sum / 10;
            sum = char(temp_sum%10+48) + sum;
        }
        
        // Carry
        if (carry > 0) {
            sum = char(carry+48) + sum;
            carry = 0;
        }
        
        return sum;
    }
};
