#include <bits/stdc++.h>

#define Kmax 100005
#define ll long long

using namespace std;

int K;
int A[Kmax];
ll le, ri, mid;
ll ansmin = -1, ansmax = -1;

ll remain(ll X)
{
    for(int i = 1; i <= K; i++)
        X = X - X % A[i];
    return X;
}

int main()
{
    cin >> K;
    for(int i = 1; i <= K; i++)
        cin >> A[i];
    le = 1, ri = LLONG_MAX;
    while(le <= ri)
    {
        mid = le + (ri - le) / 2;
        if(remain(mid) >= 2)
        {
            ri = mid - 1;
            ansmin = mid;
        }
        else
            le = mid + 1;
    }
    le = 1, ri = LLONG_MAX;
    while(le <= ri)
    {
        mid = le + (ri - le) / 2;
        if(remain(mid) <= 2)
        {
            le = mid + 1;
            ansmax = mid;
        }
        else
            ri = mid - 1;
    }
    if(ansmax != -1 && ansmin <= ansmax)
        cout << ansmin << " " << ansmax << "\n";
    else
        cout << "-1\n";
    return 0;
}
