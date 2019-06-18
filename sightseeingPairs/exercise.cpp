#include <vector>
#include <iostream>


class Solution {
public:
    int maxScoreSightseeingPair(std::vector<int>& A)
    {
    	std::pair<int, int> indexesCurrentBestCouple;
    	indexesCurrentBestCouple = std::make_pair(0,1);
    	int currentBestCoupleValue = A.at(0) + A.at(1) - 1;
		int indexNextBestCandidate = (A.at(0) - 2 > A.at(1) - 1) ? 0 : 1; 

		if (A.size() >= 2)
		{
			for (int i = 2; i < A.size(); ++i)
			{
				int valueOfPossiblePair = A.at(i) +
				                          A.at(indexNextBestCandidate) -
				                          std::abs(i - indexNextBestCandidate);
				if (valueOfPossiblePair > currentBestCoupleValue)
				{
					indexesCurrentBestCouple = std::make_pair(indexNextBestCandidate, i);
	    			currentBestCoupleValue = A.at(indexesCurrentBestCouple.first) +
	    			                         A.at(indexesCurrentBestCouple.second) -
	    			                         std::abs(indexesCurrentBestCouple.first -indexesCurrentBestCouple.second);
				}
				if (A.at(i) > A.at(indexNextBestCandidate) - (i - indexNextBestCandidate))
				{
					indexNextBestCandidate = i;
				}
				// std::cout << "index: " << i << std::endl;
				// std::cout << "best indexes: " << indexesCurrentBestCouple.first << ", " << indexesCurrentBestCouple.second << std::endl;
				// std::cout << "currentBestCoupleValue: " << currentBestCoupleValue << std::endl;
				// std::cout << "indexNextBestCandidate: " << indexNextBestCandidate << std::endl << std::endl;
			}
		}

		return currentBestCoupleValue;
    }

};

int main(int argc, char const *argv[])
{
	Solution s;
	// std::vector<int> input = {8,1,5,2,6};
	std::vector<int> input = {7,1,10,6,3,5,10,2};

	int sol = s.maxScoreSightseeingPair(input);
	std::cout << sol << std::endl;

	return 0;
}