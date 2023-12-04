class RandomizedSet {
    unordered_set<int> set;
    int rand_index;
    unordered_set<int>::iterator itr;
public:
    RandomizedSet() {
        rand_index = 0;
    }
    
    bool insert(int val) {
        if(set.find(val) == set.end())
        {
            set.insert(val);
            return true;
        }else
        {return false;}
    }
    
    bool remove(int val) {
        if(set.find(val) == set.end())
        {
            return false;
        }
        else
        {
            set.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        rand_index = rand()%set.size();
        itr = set.begin();
        std::advance(itr, rand_index);
        return *itr;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */