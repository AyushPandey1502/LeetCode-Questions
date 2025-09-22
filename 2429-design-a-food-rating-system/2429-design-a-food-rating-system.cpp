class FoodRatings {
public:
    unordered_map<string, int> foodToRating;
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, set<pair<int, string>>> cuisineMap;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++){
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
            cuisineMap[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        cuisineMap[cuisine].erase({-foodToRating[food], food});
        foodToRating[food] = newRating;
        cuisineMap[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return cuisineMap[cuisine].begin()->second;
    }
};
