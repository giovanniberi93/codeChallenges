#include <vector>
#include <iostream>
#include <set>

class Solution {
public: 
    int nextRoot(std::vector<bool> visited)
    {
        for(int i = 0; i < visited.size(); ++i)
            if (!visited[i] && outgoingArcs[i].size() > 0)
                return i;
        return -1;
    }

    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) 
    {
        outgoingArcs = std::vector<std::set<int>>(numCourses, std::set<int>());
        isNodeInSameRecursion = std::vector<bool>(numCourses, false);
        isNodeVisited = std::vector<bool>(numCourses, false);

        for (auto edge : prerequisites)
            outgoingArcs[edge[0]].insert(edge[1]);

        int nonVisitedNode = nextRoot(isNodeVisited);
        while(nonVisitedNode >= 0) 
        {
            bool loopFound = dfs(nonVisitedNode);
            if (loopFound)
                return false;
            nonVisitedNode = nextRoot(isNodeVisited);
        }

        return true;
    }

    bool dfs(int const rootNode)
    {
        isNodeVisited[rootNode] = true;
        isNodeInSameRecursion[rootNode] = true;
        bool subtreeResult = false;
        for (auto reachableNode : outgoingArcs[rootNode])
        {
            if (isNodeInSameRecursion[reachableNode])
                return true;
            if (!isNodeVisited[reachableNode])
            {
                subtreeResult = dfs(reachableNode);
                if (subtreeResult)
                    break;
            }
        }
        isNodeInSameRecursion[rootNode] = false;
        return subtreeResult;
    }

    std::vector<bool> isNodeVisited;
    std::vector<std::set<int>> outgoingArcs;
    std::vector<bool> isNodeInSameRecursion;
};

int main(int argc, char **argv) 
{ 
    std::vector<std::vector<int>> edges;
    Solution s;
    edges.push_back({1, 0});
    edges.push_back({0, 2});

    bool res = s.canFinish(2, edges);

    std::cout << res << std::endl;
}