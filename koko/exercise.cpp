#include <vector>
#include <array>
#include <iostream>
#include <cmath>
#include <algorithm>
//#include <unistd.h>

class Solution {
public:

    int minEatingSpeed(std::vector<int> & piles, int H)
    {
        int upperBoundSpeed = *std::max_element(piles.begin(), piles.end());
        int lowerBoundSpeed = static_cast<int>(std::ceil(static_cast<float>(upperBoundSpeed) / H));
        int candidateSpeed;

        while (lowerBoundSpeed <= upperBoundSpeed)
        {
            candidateSpeed = (lowerBoundSpeed + upperBoundSpeed) / 2;
            int const timeWithCurrentSpeed = getEatingTime(piles, candidateSpeed, H); 
            int const timeWithDecreasedSpeed = getEatingTime(piles, candidateSpeed - 1, H);

            if (timeWithCurrentSpeed <= H && timeWithDecreasedSpeed > H)
            {
                return candidateSpeed;
            } 
            else if (timeWithCurrentSpeed > H)
            {
                lowerBoundSpeed = candidateSpeed + 1;
            }
            else
            {
                upperBoundSpeed = candidateSpeed - 1;
            }

        }
        return candidateSpeed;
    }

    int getEatingTime(std::vector<int> const & piles, int currentSpeed, int timeAvailable)
    {
        int overallTime = 0;

        for (auto it = piles.begin(); it != piles.end(); ++it)
        {
            overallTime += std::ceil(*it / static_cast<float>(currentSpeed));
            if (overallTime > timeAvailable)
            {
                return overallTime;
            }
        }
        return overallTime;
    }

};

int main(int argc, char const *argv[])
{
	Solution sol;

	std::vector<int>piles = {332484035,
                             524908576,
                             855865114,
                             632922376,
                             222257295,
                             690155293,
                             112677673,
                             679580077,
                             337406589,
                             290818316,
                             877337160,
                             901728858,
                             679284947,
                             688210097,
                             692137887,
                             718203285,
                             629455728,
                             941802184};

	int H = 823855818;

	int result = sol.minEatingSpeed(piles, H);
	std::cout << result << std::endl;
	return 0;
}