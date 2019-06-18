#include <vector>
#include <map>
#include <algorithm>
#include <iostream>


class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
    	// <aggregatedSumValue, startingIndex>
    	std::map<int, int> intervals;
    	int aggregatedSum;
    	int maxLength;

    	maxLength = 0;
    	aggregatedSum = 0;
    	intervals[0] = 0;

    	for (int i = 0; i < nums.size(); ++i)
    	{
    		if (nums.at(i) == 0)
    		{
    			--aggregatedSum;
    		}
    		else
    		{
    			++aggregatedSum;
    		}
    		
    		auto intervalStart = intervals.find(aggregatedSum);
    		if (intervalStart == intervals.end())
    		{
    			intervals[aggregatedSum] = i + 1;
    		}
    		else
    		{
    			int intervalLength = i + 1 - intervalStart->second;
    			if (intervalLength > maxLength)
    			{
    				maxLength = intervalLength;
    			}
    		}
    	}
    	return maxLength;
    }
};

int main(int argc, char const *argv[])
{
	// std::vector<int> input = {0,0,0,0,0,0,0,1,1,0,1,1,0,0};
	// std::vector<int> input = {0,1};
	// std::vector<int> input = {0,1,0};
	std::vector<int> input = {};
	Solution s;

	int res = s.findMaxLength(input);
	std::cout << res << std::endl;
	return 0;
}