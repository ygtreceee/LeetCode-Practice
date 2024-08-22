#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<pair<double, int>>> a(14, vector<pair<double, int>>(7));
    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cin >> a[i][j].first;
            a[i][j].second = j;            
        }
    }
    for (int i = 0; i < 14; i++)
    {
        sort(a[i].begin(), a[i].end());
    }
    vector<double> rank(7);
    cout << endl;
    for (int i = 0; i < 14; i++)
        for (int j = 0; j < 7; j++)
            cout << a[i][j].first << " \n"[j == 6];
    cout << endl;
    for (int i = 0; i < 14; i++)
    {
        int f = 1;
        for (int j = 6; j >= 0; j--)
        {
            if (j != 6 && a[i][j].first == a[i][j + 1].first)
                f = f;
            else f = 6 - j + 1;
            rank[a[i][j].second] += f;
        }
    }
    for (int j = 0; j < 7; j++)
    {
        rank[j] /= 14;
        cout << j + 1 << ": " << rank[j] << "  ";
    }
    return 0;
}