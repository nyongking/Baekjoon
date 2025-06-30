#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;


void Print(vector<int>& ArrayA, vector<int>& ArrayB)
{
    int IdxA = 0;
    int IdxB = 0;

    while (IdxA < ArrayA.size() && IdxB < ArrayB.size())
    {
        if (ArrayA[IdxA] >= ArrayB[IdxB])
        {
            cout << ArrayB[IdxB++] << " ";
        }
        else
        {
            cout << ArrayA[IdxA++] << " ";
        }
    }

    while (IdxA < ArrayA.size())
    {
        cout << ArrayA[IdxA++] << " ";
    }

    while (IdxB < ArrayB.size())
    {
        cout << ArrayB[IdxB++] << " ";
    }
}


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> ArrayA(N);
    vector<int> ArrayB(M);

    for (int i = 0; i < N; ++i)
    {
        cin >> ArrayA[i];
    }

    sort(ArrayA.begin(), ArrayA.end());

    for (int i = 0; i < M; ++i)
    {
        cin >> ArrayB[i];
    }

    sort(ArrayB.begin(), ArrayB.end());

    Print(ArrayA, ArrayB);
    
    return 0;
}