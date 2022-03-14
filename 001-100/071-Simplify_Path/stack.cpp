class Solution {
public:
    string simplifyPath(string path) {
        // Init
        string newPath;
        stack<string> st;
        
        // Check the raw path
        for (int i=0; i<path.size(); ++i) {
            string temp = "";
            
            while (i<path.size() && path[i]!='/') {
                temp.push_back(path[i]);
                ++i;
            }
                        
            if (temp == "..") { 
                if (!st.empty()) st.pop();
            }
            else if (!temp.empty() && temp != ".") {
                st.push(temp);
            }            
        }        
        
        // Recombination
        while (!st.empty()) {
            newPath = '/' + st.top() + newPath;            
            st.pop();
        }
                
        if (newPath.empty()) return "/";
        else return newPath;
    }
};

