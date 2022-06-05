#include <bits/stdc++.h>

using namespace std;

#define MOD 10000003

int minimumJumpsRequired(string A) {
    
    vector<int> indices;
    for(int i = 0; i < A.length(); i++) {
        if(A[i] == 'x') {
            indices.push_back(i);
        }
    }

    int n = indices.size();
    int median = n/2;
    int ans = 0;
    
    int dec = 1;
    
    for(int i = 0; i < median; i++) {
        ans = (ans + indices[median] - indices[i] - dec) % MOD;
        dec++;
    }

    int inc = 1;

    for(int i = median + 1; i < n; i++) {
        ans = (ans + indices[i] - (indices[median] + inc)) % MOD;
        inc++;
    }

    return ans % MOD;
}

int main() {

    string s = "....x..xx...x..";
    cout << minimumJumpsRequired(s) << endl;
    
    return 0;
}