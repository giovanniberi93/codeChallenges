#include <iostream>
#include <map>
#include <vector>

class Solution 
{
public:
    int totalFruit(std::vector<int>& tree)
    {
        if (tree.size() < 3)
            return tree.size();

        int intervalStart = 0;
        int intervalEnd = 0;
        std::map<int, int> fruitCount;
        int maxLength = 0;
        
        while(intervalEnd != tree.size())
        {
            if (fruitCount.size() == 2 && fruitCount.find(tree[intervalEnd]) == fruitCount.end())
            {
                while(fruitCount.size() == 2)
                {
                    fruitCount[tree[intervalStart]]--;
                    if (fruitCount[tree[intervalStart]] == 0) 
                        fruitCount.erase(tree[intervalStart]);
                    intervalStart++;
                }
            }

            if (fruitCount.find(tree[intervalEnd]) == fruitCount.end())
                fruitCount.insert(std::pair<int, int>(tree[intervalEnd], 1));
            else
                fruitCount[tree[intervalEnd]]++;
            maxLength = std::max(maxLength, intervalEnd - intervalStart + 1);
            intervalEnd++;
        }
        return maxLength;
    }
};


int main(int argc, char **argv)
{
    Solution s;
    std::vector<int> input = {3,3,3,1,2,1,1,2,3,3,4};
    int res = s.totalFruit(input);
    std::cout << res << std::endl;
}

