#include <iostream>
#include <vector>
#include <list>
#include <set>


class FruitInBucket 
{
public:

    FruitInBucket()
        : sum(0)
    {
    }

    int sum;
    std::set<int> fruitTypes;
};

using FruitIterator = std::vector<FruitInBucket>::iterator;

class Solution {
public:
    int totalFruit(std::vector<int>& tree) {
        std::vector<FruitInBucket> buckets;
        int max;
        if (tree.empty())
            return 0;

        max = 0;
        for (auto it = tree.cbegin(); it != tree.cend(); ++it)
        {
            std::vector<FruitIterator> indexToDelete;

            FruitInBucket bucketStartingFromCurrentTree;
            // insert from the beginning to make it easier
            // to delete later
            if (it == tree.cbegin() ||  *(it-1) != *it)
                buckets.insert(buckets.begin(), bucketStartingFromCurrentTree);
 
            for (auto itBucket = buckets.begin(); itBucket != buckets.end(); ++itBucket)
            {
                 itBucket->fruitTypes.insert(*it);
                 if (itBucket->fruitTypes.size() > 2)
                 {
                     indexToDelete.push_back(itBucket);
                 }
                 else
                 {
                     itBucket->sum++;
                     if (itBucket->sum > max)
                         max = itBucket->sum;
                 }
            }
            // delete buckets with >= 3 
            for (auto el : indexToDelete)
               buckets.erase(el);
        }
        return max;
    }
};


int main(int argc, char **argv)
{
    Solution s;
    std::vector<int> input = {1,0,1,4,1,4,1,2,3};
    int res = s.totalFruit(input);
    std::cout << res << std::endl;
}

