class FoodRatings {
private:
    struct Compare {
        bool operator()(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) const {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            
            return a.second < b.second;
        }
    };

    std::unordered_map<std::string, int> food2rating;
    std::unordered_map<std::string, std::string> food2cuisine;
    std::unordered_map<std::string, std::set<std::pair<int, std::string>, Compare>> cuisine2foods;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i=0; i<foods.size(); ++i) {
            food2rating[foods[i]] = ratings[i];
            food2cuisine[foods[i]] = cuisines[i];
            cuisine2foods[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        // Update highest food by cuisines
        const std::string& cuisine = food2cuisine[food];
        cuisine2foods[cuisine].erase({food2rating[food], food});
        cuisine2foods[cuisine].insert({newRating, food});

        // Update rating
        food2rating[food] = newRating;
    }
    
    std::string highestRated(string cuisine) {
        return cuisine2foods[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
