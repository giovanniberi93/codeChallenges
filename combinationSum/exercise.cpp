#include <iostream>
#include <algorithm>
#include <vector>

class Solution 
{
public:	
	std::vector<std::vector<int>> combinationSum(std::vector<int> candidates,
												 int target)
	{
		_target = target;
		std::sort(candidates.begin(), candidates.end());
		_candidates = candidates;

		std::vector<int> emptySequence;
		recursiveSolution(_target, emptySequence, _candidates.cbegin());

		return _result;
	}

	void recursiveSolution(int remainingSum, std::vector<int> partialSequence, std::vector<int>::const_iterator listStart)
	{
		if (remainingSum <= 0 ||
			*listStart > _target ||
			listStart == _candidates.cend())
		{
			return;
		}
		else
		{
			partialSequence.push_back(*listStart);
			
			if (remainingSum - *listStart > 0)
			{
				recursiveSolution(remainingSum - *listStart, partialSequence, listStart);
				recursiveSolution(remainingSum - *listStart, partialSequence, listStart+1);
			}
			else if (remainingSum - *listStart == 0)
			{
				_result.push_back(partialSequence);
				// printVectorOfVectors(_result);
			}

			std::vector<int> emptySequence;
			// always start a new attempt from the next element 
			recursiveSolution(_target, emptySequence, listStart+1);
		}

	}

	void printVectorOfVectors(std::vector<std::vector<int>> vec)
	{
		std::cout << "****" << std::endl;
		for (auto r : vec)
		{
			for (auto el : r)
			{
				std::cout << el << " ";
			}
			std::cout << std::endl;
		}
		std::cout << "****" << std::endl;
	}

private:
	int _target;
	std::vector<std::vector<int>> _result;
	std::vector<int> _candidates;
};



int main(int argc, char const *argv[])
{
	std::vector<int> candidates = {2, 3, 6, 7};
	int target = 7;
	std::vector<std::vector<int>> res;
	Solution sol;

	res = sol.combinationSum(candidates, target);
	std::cout << "----------------" << std::endl;
	sol.printVectorOfVectors(res);

	return 0;
}