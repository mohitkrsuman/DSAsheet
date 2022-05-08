/*
381. Insert Delete GetRandom O(1) - Duplicates allowed
Hard

1616

118

Add to List

Share
RandomizedCollection is a data structure that contains a collection of numbers, possibly duplicates (i.e., a multiset). It should support inserting and removing specific elements and also removing a random element.

Implement the RandomizedCollection class:

RandomizedCollection() Initializes the empty RandomizedCollection object.
bool insert(int val) Inserts an item val into the multiset, even if the item is already present. Returns true if the item is not present, false otherwise.
bool remove(int val) Removes an item val from the multiset if present. Returns true if the item is present, false otherwise. Note that if val has multiple occurrences in the multiset, we only remove one of them.
int getRandom() Returns a random element from the current multiset of elements. The probability of each element being returned is linearly related to the number of same values the multiset contains.
You must implement the functions of the class such that each function works on average O(1) time complexity.

Note: The test cases are generated such that getRandom will only be called if there is at least one item in the RandomizedCollection.

 

Example 1:

Input
["RandomizedCollection", "insert", "insert", "insert", "getRandom", "remove", "getRandom"]
[[], [1], [1], [2], [], [1], []]
Output
[null, true, false, true, 2, true, 1]

Explanation
RandomizedCollection randomizedCollection = new RandomizedCollection();
randomizedCollection.insert(1);   // return true since the collection does not contain 1.
                                  // Inserts 1 into the collection.
randomizedCollection.insert(1);   // return false since the collection contains 1.
                                  // Inserts another 1 into the collection. Collection now contains [1,1].
randomizedCollection.insert(2);   // return true since the collection does not contain 2.
                                  // Inserts 2 into the collection. Collection now contains [1,1,2].
randomizedCollection.getRandom(); // getRandom should:
                                  // - return 1 with probability 2/3, or
                                  // - return 2 with probability 1/3.
randomizedCollection.remove(1);   // return true since the collection contains 1.
                                  // Removes 1 from the collection. Collection now contains [1,2].
randomizedCollection.getRandom(); // getRandom should return 1 or 2, both equally likely.
*/

// Appriach-> 1
class RandomizedCollection {
private:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> map;
public:
    RandomizedCollection() {
    }
    
    bool insert(int val) {
       auto result = map.find(val) == map.end();   // Returns true if item is not present
        
        map[val].push_back(nums.size());
        nums.push_back(pair<int, int>(val, map[val].size()-1));
        return result;
    }
    
    bool remove(int val) {
        auto result = map.find(val) != map.end(); // Return if item is present
        if(result){
            auto last = nums.back();
            map[last.first][last.second] = map[val].back();
            nums[map[val].back()] = last;
            map[val].pop_back();
            if(map[val].empty()){
                map.erase(val);
            }
            nums.pop_back();
        }
        return result;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
};


// Approach-2
class RandomizedCollection{
private:
    vector<int> nums;
    unordered_map<int, int> map;
public:
    RandomizedCollection(){
        
    }
    
    bool insert(int val){
        if(map.find(val) != map.end()){
            return false;
        }
        
        nums.push_back(val);
        map[val] = nums.size()-1;
        
        return true;
    }
    
    bool remove(int val){
        if(map.find(val) == map.end()){
            return false;
        }
        auto it = map.find(val);
        nums[it->second] = nums.back();
        nums.pop_back();
        map[nums[it->second]] = it->second;
        map.erase(val);
        return true;
    }
    
    int getRandom(){
        return nums[rand()%nums.size()];
    }
};
/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
