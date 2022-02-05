#include <bits/stdc++.h>

using namespace std;

int bitonicPoint(vector<int> &a)
{
    int n = a.size();
    int left, right, mid;
    left = 0, right = n - 1;
    while (left <= right)
    {
        mid = (left + right) >> 1;
        if (a[mid] > a[mid + 1] && a[mid] > a[mid - 1])
            return mid;

        else if (a[mid] < a[mid + 1])
            left = mid + 1;

        else
            right = mid - 1;
    }
}

int leftBinarySearch(vector<int> &a, int b, int bp)
{
    int left, right, mid;
    left = 0, right = bp;
    while (left <= right)
    {
        mid = (left + right) >> 1;
        if (a[mid] == b)
            return mid;
        else if (a[mid] < b)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int rightBinarySearch(vector<int> &a, int b, int bp)
{
    int n = a.size();
    int left, right, mid;
    left = bp, right = n - 1;
    while (left <= right)
    {
        mid = (left + right) >> 1;
        if (a[mid] == b)
            return mid;
        else if (a[mid] < b)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> a{1, 20, 50, 40, 10};
    int b = 5;
    int bp = bitonicPoint(a);
    // cout << bp << endl;
    if (a[bp] < b)
        cout << "-1" << endl;
    else
    {
        int left = leftBinarySearch(a, b, bp);
        int right = rightBinarySearch(a, b, bp);
        if (left != -1)
            cout << left << endl;
        else if (right != -1)
            cout << right << endl;
        else
            cout << "-1" << endl;
    }

    return 0;
}
