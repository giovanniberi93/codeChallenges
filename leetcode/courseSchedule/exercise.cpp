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
        std::map<int, std::set<int>> outgoingArcs;
        std::map<int, std::set<int>> ingoingArcs;
        std::set<int> nodesWithNoIngoingArcs;

        for (auto edge : prerequisites)
        {
            outgoingArcs.insert(std::pair<int, std::set<int>>(edge[0], std::set<int>()));
            ingoingArcs.insert(std::pair<int, std::set<int>>(edge[1], std::set<int>()));
            nodesWithNoIngoingArcs.insert(edge[0]);
        }
        for (auto edge : prerequisites)
        {
            outgoingArcs[edge[0]].insert(edge[1]);
            ingoingArcs[edge[1]].insert(edge[0]);
            nodesWithNoIngoingArcs.erase(edge[1]);
        }

        std::queue<int> nodesToVisit;
        for (auto node : nodesWithNoIngoingArcs)
            nodesToVisit.push(node);
        while(!nodesToVisit.empty())
        {
            int const currentNode = nodesToVisit.front();
            nodesToVisit.pop();
            // delete outgoing arcs
            for (auto pointedNode : outgoingArcs[currentNode])
            {
                ingoingArcs[pointedNode].erase(currentNode);
                if (ingoingArcs[pointedNode].size() == 0)
                    nodesToVisit.push(pointedNode);
            }
            // delete node
            outgoingArcs.erase(currentNode);
        }

        // if there are nodes left, there was a loop
        return outgoingArcs.size() == 0;
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

