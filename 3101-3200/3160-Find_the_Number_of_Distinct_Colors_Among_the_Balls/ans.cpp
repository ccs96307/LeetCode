class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        // Init
        int colorNum = 0;
        vector<int> results;
        unordered_map<int, int> ball2color;
        unordered_map<int, int> color2num;

        // Color
        for (int i=0; i<queries.size(); ++i) {
            int ball = queries[i][0];
            int color = queries[i][1];
            int currBallColor = ball2color[ball];

            if (currBallColor != 0) { 
                --color2num[currBallColor];

                if (color2num[currBallColor] == 0) {
                    --colorNum;
                }
            }

            ball2color[ball] = color;
            ++color2num[color];

            if (color2num[color] == 1) {
                ++colorNum;
            }

            results.emplace_back(colorNum);
        }

        return results;
    }
};

