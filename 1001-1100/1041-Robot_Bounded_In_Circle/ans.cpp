class Solution {
public:
    bool isRobotBounded(string instructions) {
        // Init
        int _x = 0;
        int _y = 1;
        int pos_x = 0;
        int pos_y = 0;
        
        // The first loop
        for (auto s: instructions) {
            if (s == 'G') {
                pos_x += _x;
                pos_y += _y;
            }
            else if (s == 'L') {
                if (_x == 0 && _y == 1) {
                    _x = -1;
                    _y = 0;
                }
                else if (_x == -1 && _y == 0) {
                    _x = 0;
                    _y = -1;
                }
                else if (_x == 0 && _y == -1) {
                    _x = 1;
                    _y = 0;
                }
                else if (_x == 1 && _y == 0) {
                    _x = 0;
                    _y = 1;
                }
            }
            else if (s == 'R') {
                if (_x == 0 && _y == 1) {
                    _x = 1;
                    _y = 0;
                }
                else if (_x == 1 && _y == 0) {
                    _x = 0;
                    _y = -1;
                }
                else if (_x == 0 && _y == -1) {
                    _x = -1;
                    _y = 0;
                }
                else if (_x == -1 && _y == 0) {
                    _x = 0;
                    _y = 1;
                }
            }
        }
        
        // Results
        if (pos_x == 0 && pos_y == 0) return true;
        else if (_x == 0 && _y == 1) return false;
        
        return true;
    }
};

