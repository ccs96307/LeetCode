class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        // Init
        int index = 0;
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> results;
        
        // Find        
        for (auto& path: paths) {
            int i = 0;
            bool isFilepath = true;
            string _path;
            string filepath;
            string content;
            
            // Combine path
            while (path[i] != ' ') {
                _path.push_back(path[i]);
                ++i;
            }
            _path.push_back('/');
             
            // Combine filepath and content <FILE_PATH>(<CONTENT>)
            for (int j=i+1; j<path.size(); ++j) {
                char c = path[j];
                if (c == ' ') {
                    continue;
                }
                
                // File path
                if (isFilepath) {
                    if (c != '(') {
                        filepath.push_back(c);
                    }
                    else {
                        isFilepath = false;
                    }
                }
                
                // Content
                else {
                    if (c != ')') {
                        content.push_back(c);
                    }
                    else {
                        if (!mp.count(content)) {
                            mp[content] = vector<string>();
                        }
                        mp[content].push_back(_path+filepath);
                        
                        isFilepath = true;
                        filepath.clear();
                        content.clear();
                    }
                }
            }
        }
        
        // Combined results
        for (auto& it: mp) {
            if (it.second.size() > 1) {
                results.push_back(it.second);
            }
        }
        
        return results;
    }
};
