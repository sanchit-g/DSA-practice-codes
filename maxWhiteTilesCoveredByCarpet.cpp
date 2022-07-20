class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        
        int n = tiles.size();
        
        // sort the tiles according to starting position
        sort(tiles.begin(), tiles.end());
        
        // create a prefix sum array storing the total number
        // of white tiles at the end of each tile block
        vector<int> prefix(n + 1, 0);
        for(int i = 1; i <= n; i++)
            prefix[i] += prefix[i-1] + (tiles[i-1][1] - tiles[i-1][0] + 1);
        
        // create an array storing the staring positions of each tile block
        // this will be used later when we apply the binary search
        vector<int> starts(n);
        for(int i = 0; i < n; i++)
            starts[i] = tiles[i][0];
        
        int res = INT_MIN;
        
        for(int i = 0; i < n; i++)
        {
            int s = tiles[i][0], e = tiles[i][1];
            int lastTile = s + carpetLen - 1;
            
            if(e >= lastTile)
                return carpetLen;
            
            // now we will binary search for the start of the block which is just greater than the lastTile
            int endIndex = upper_bound(starts.begin(), starts.end(), lastTile) - starts.begin();
            endIndex -= 1;
            
            // cout << endIndex << endl;
            
            // find the length of the end tile that the carpet cannot cover
            int compensate = 0;
            if(tiles[endIndex][1] > lastTile)
                compensate = tiles[endIndex][1] - lastTile;
            
            res = max(res, prefix[endIndex+1] - prefix[i] - compensate);
        }
        
        return res;
    }
};
