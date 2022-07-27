class Solution {
public:
    vector<int> NLE(vector<int>& A) {
        
        int n = A.size();
        stack<pair<int, int>> st;
        vector<int> right(n, n);
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() and st.top().first > A[i]) {
                auto x = st.top();
                st.pop();
                
                right[x.second] = i;
            }
            
            st.push({A[i], i});
        }
        
        return right;
    }
    
    vector<int> PLE(vector<int>& A) {
        
        int n = A.size();
        stack<pair<int, int>> st;
        vector<int> left(n);
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() and st.top().first > A[i])
                st.pop();
            left[i] = st.empty() ? -1 : st.top().second;   
            st.push({A[i], i});
        }
        
        return left;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        vector<int> left = PLE(heights);
        vector<int> right = NLE(heights);
        
        vector<int> width(n);
        for(int i = 0; i < n; i++)
            width[i] = right[i] - left[i] - 1;
        
        vector<int> area(n);
        for(int i = 0; i < n; i++)
            area[i] = heights[i] * width[i];
        
        return *max_element(area.begin(), area.end());
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> v;
        for(int j = 0; j < m; j++) {
            if(matrix[0][j] == '0')
                v.push_back(0);
            else
                v.push_back(1);
        }
            
        int mx = largestRectangleArea(v);
            
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '0')
                    v[j] = 0;
                else
                    v[j] += 1;
            }
            mx = max(mx, largestRectangleArea(v));
        }
        
        return mx;
    }
};
