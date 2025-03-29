#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> indices;    // key, vector中位置
public:
    vector<int> getNums(){
        return nums;
    }
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if(indices.count(val)){
            return false;
        }
        int index = nums.size();
        nums.emplace_back(val);
        indices[val] = index;
        return true;
    }
    
    bool remove(int val) {
        if(!indices.count(val)){
            return false;
        }
        int index = indices[val];
        int last = nums.back();
        nums[index] = last;
        indices[last] = index;
        nums.pop_back();
        indices.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};

// Unit tests for RandomizedSet
void testRandomizedSet() {
    RandomizedSet* obj = new RandomizedSet();
    // Test insert
    assert(obj->insert(1) == true);
    assert(obj->insert(2) == true);
    assert(obj->insert(3) == true);
    assert(obj->insert(1) == false); // Duplicate insert should fail
    
    // Test remove
    assert(obj->remove(2) == true);
    assert(obj->remove(4) == false); // Removing non-existing element should fail
    
    // Test getRandom
    // Since getRandom is random, we can't really assert on the value, but we can check if the value is in the set
    int randomValue = obj->getRandom();
    assert(find(obj->getNums().begin(), obj->getNums().end(), randomValue) != obj->getNums().end());
    
    // Clean up
    delete obj;
}

int main()
{
    testRandomizedSet();
    cout << "All tests passed!" << endl;
    system("pause");
    return 0;
}
