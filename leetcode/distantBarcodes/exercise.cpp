#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> rearrangeBarcodes(std::vector<int>& barcodes) 
    {
        std::vector<int> result;
        std::vector<std::pair<int, int>> occurrences;
        std::map<int, int> nrBarcodes;

        for (auto code : barcodes)
        {
            auto targetCodePosition = nrBarcodes.find(code);
            if (targetCodePosition == nrBarcodes.end())
                nrBarcodes.insert(std::pair<int, int>(code, 1));
            else
                nrBarcodes[code]++;
        }

        for (auto it = nrBarcodes.begin(); it != nrBarcodes.end(); ++it)
        {
            occurrences.push_back(std::pair<int, int>(it->first, it->second));
        }
        std::sort(occurrences.begin(), occurrences.end(), [](std::pair<int, int> el1, std::pair<int, int> el2){
                return el1.second > el2.second;});
        
        for (int currentMainValueIndex = 0; currentMainValueIndex < occurrences.size(); ++currentMainValueIndex)
        {
            int mainValue = occurrences[currentMainValueIndex].first;
            int mainValueOccurences = occurrences[currentMainValueIndex].second;

            for(int valuesInserted = 0; valuesInserted < mainValueOccurences; ++valuesInserted)
            {
                int interposedValue;
                if (result.size() == barcodes.size())
                    return result;
                if (result.size() == barcodes.size() - 1)
                {
                    result.push_back(mainValue);
                    return result;
                }

                int valueToInterponeIndex;
                for (valueToInterponeIndex = currentMainValueIndex + 1;
                     valueToInterponeIndex < occurrences.size();
                     valueToInterponeIndex++)    
                {
                    if (valueToInterponeIndex == occurrences.size() - 1)
                        break;
                    if (occurrences[valueToInterponeIndex + 1].second < occurrences[valueToInterponeIndex].second) 
                        break;
                }
                occurrences[valueToInterponeIndex].second--;

                interposedValue = occurrences[valueToInterponeIndex].first;
                if (result.size() > 0 && result[result.size() - 1] == mainValue)
                {
                    result.push_back(interposedValue);
                    result.push_back(mainValue);
                }
                else
                {
                    result.push_back(mainValue);
                    result.push_back(interposedValue);
                }
            }
        }
        return result;
    }
};

template <typename T>
void printVector(std::vector<T> v)
{
    for (auto el : v)
        std::cout << el << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv) 
{ 
    Solution s;

    // std::vector<int> input = {1,1,1,2,2,2};
    // std::vector<int> input = {7,7,7,8,5,7,5,5,5,8};
    std::vector<int> input = {1};
    std::vector<int> result = s.rearrangeBarcodes(input);

    printVector(result);
}
