#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <set>
#include <map>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) 
    {
        std::map<int, std::vector<int>> fanout;

        for (int i = 0; i < numCourses; ++i)
        {
            fanout.insert(std::pair<int, std::vector<int>>(i, std::vector<int>()));
        }
        for (int i = 0; i < prerequisites.size(); ++i)
            fanout.at(prerequisites[i][0]).push_back(prerequisites[i][1]);

        for (int i = 0; i < numCourses; ++i)
        {
            if(hasCycle(i, fanout))
                return false;
        }
        return true;
    }

    bool hasCycle(int const rootNode, std::map<int, std::vector<int>> const fanout)
    {
        std::vector<bool> hasBeenVisited(fanout.size(), false);
        std::vector<bool> alreadyInQueue(fanout.size(), false);
        std::queue<int> toBeVisited;
        
        toBeVisited.push(rootNode);
        while(!toBeVisited.empty())
        {
            int currentNode = toBeVisited.front();
            toBeVisited.pop();

            alreadyInQueue[currentNode] = false;
            if (hasBeenVisited[currentNode])
                return true;
            else
                hasBeenVisited[currentNode] = true;

            for (int i = 0; i < fanout.at(currentNode).size(); ++i)
            {
                int consideredNode = fanout.at(currentNode)[i];
                if (!alreadyInQueue[consideredNode])
                {
                    alreadyInQueue[consideredNode] = true;
                    toBeVisited.push(fanout.at(currentNode)[i]);
                }
            }

        }
        return false;
    }
};

int main(int argc, char **argv) 
{ 
    std::vector<std::vector<int>> edges;
    Solution s;
    edges.push_back({1,0});
    edges.push_back({2,6});
    edges.push_back({1,7});
    edges.push_back({6,4});
    edges.push_back({7,0});
    edges.push_back({0,5});
    bool res = s.canFinish(8, edges);

    std::cout << res << std::endl;
}

