class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> setMap;
    
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        // Is existed
        if (setMap.find(val) != setMap.end()) {
            return false;
        }
        
        // Store the position of `nums`
        setMap[val] = nums.size();
        nums.emplace_back(val);
        return true;
    }
    
    bool remove(int val) {
        // Is not existed
        if (setMap.find(val) == setMap.end()) {
            return false;
        }
        
        // Swap the last number and the remove number
        int lastNum = nums.back();
        setMap[lastNum] = setMap[val];
        swap(nums[nums.size()-1], nums[setMap[val]]);
        
        // Remove the target number of `nums` and `setMap`
        nums.pop_back();
        setMap.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
 
