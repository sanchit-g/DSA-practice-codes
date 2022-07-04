// BFS solution
// This should be a HARD category problem

class Solution {
    typedef pair<int, int> pii;
    typedef tuple<int, int, int> tiii;
public:
    const int inf = 1e9;
    vector<pii> adj[110];

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        for (auto &e: flights)
            adj[e[0]].emplace_back(make_pair(e[1], e[2]));

        return bfs(src, dst, k, n);
    }

    int bfs(int src, int dest, int k, int n) {
        
        queue<tiii> q;
        vector<int> costs(n, inf); // stores minimum costs to travel to any node from souce using at mosts k+2 nodes
        costs[src] = 0; // source to source travel cost is 0
        q.push({src, 0, 1}); // {node, cost, stops}

        while (!q.empty()) {
            auto [currNode, currCost, currTotalNodes] = q.front();
            q.pop();

            // Having k stops between source and destination equals to total of k + 2 nodes in the path including source and destination
            // So, if path to currNode already has total k+2 nodes, there is no point to go any further
            if (currTotalNodes == k + 2)
                continue;

            for (auto &[nextNode, cost]: adj[currNode]) { //iterate over all the neighbors of currNode
                int nextCost = currCost + cost;
                int nextTotalNodes = currTotalNodes + 1;

                if (nextCost < costs[nextNode]) {
                    costs[nextNode] = nextCost; //update costs to reach nextNode
                    q.push({nextNode, nextCost, nextTotalNodes});
                }
            }
        }

        if (costs[dest] == inf)
            return -1;
        
        else return costs[dest];
    }
};
