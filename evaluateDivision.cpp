class Solution {

unordered_map<string, unordered_map<string, double>> adjList;
unordered_set<string> visited;
    
public:
    
    double DFS(string startNode, string endNode)
    {
        // if the start node is not present in the graph
        if(adjList.find(startNode) == adjList.end())
            return -1;
        
        // return the value of start node * end node
        if(adjList[startNode].find(endNode) != adjList[startNode].end())
            return adjList[startNode][endNode];
        
        for(auto &neighbor : adjList[startNode])
        {
            // if this neighbor node is already visited, then skip it
            if(find(visited.begin(), visited.end(), neighbor.first) != visited.end())
                continue;
            
            visited.insert(neighbor.first);
            
            // see if the end node is reachable from this neighbor
            double res = DFS(neighbor.first, endNode);
            
            // if this node is indeed reachable, return the product of start node and neighbor with neighbor and end node
            if(res != -1)
                return res * adjList[startNode][neighbor.first];
        }
        
        return -1;
    }
        
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n = equations.size(), m = queries.size();
        
        for(int i = 0; i < n; i++)
        {
            adjList[equations[i][0]][equations[i][1]] = values[i];
            adjList[equations[i][1]][equations[i][0]] = 1.0 / values[i];
            adjList[equations[i][0]][equations[i][0]] = 1.0;
            adjList[equations[i][1]][equations[i][1]] = 1.0;
        }
        
        vector<double> ans;
        
        for(auto &query : queries)
        {
            const string &num = query[0];
            const string &den = query[1];
            
            visited = {num};
            
            ans.push_back(DFS(num, den));
        }
        
        return ans;
    }
};
