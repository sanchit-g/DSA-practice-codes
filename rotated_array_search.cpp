#include <bits/stdc++.h>

using namespace std;

int search(vector<int> &a, int b)
{
    int low, high, mid, ans;
    low = 0, high = a.size() - 1, ans = -1;
    while (low <= high)
    {
        mid = (low + high) >> 1;
        if (a[mid] == b)
        {
            ans = mid;
            break;
        }

        else if (a[low] <= a[mid])
        {
            if (b >= a[low] and b < a[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        else
        {
            if (b > a[mid] and b <= a[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> a{3, 1};
    int b = 1;

    cout << search(a, b) << endl;

    return 0;
}
