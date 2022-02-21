#include <bits/stdc++.h>

using namespace std;

#define int     long long
#define endl    "\n"
int N = 100005;

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    int n, m, sum1, sum2, result, i, j;
    int nums1[N], nums2[N];

    while(t--)
    {
        cin >> n >> m;

        for(int i = 0; i < n; i++)
            cin >> nums1[i];

        for(int i = 0; i < m; i++)
            cin >> nums2[i];
        
        sum1 = 0, sum2 = 0, result = 0;
        i = 0, j = 0;

        while(i < n && j < m)
        {
            if(nums1[i] < nums2[j])
                sum1 += nums1[i++];
            
            else if(nums2[j] < nums1[i])
                sum2 += nums2[j++];

            else
            {
                result += max(sum1, sum2) + nums1[i];
                sum1 = 0, sum2 = 0;
                i++;
                j++;
            }
        }

        while(i < n)
            sum1 += nums1[i++];
        
        while(j < m)
            sum2 += nums2[j++];

        result += max(sum1, sum2);
        
        cout << result << endl;
    }

    return 0;
}
