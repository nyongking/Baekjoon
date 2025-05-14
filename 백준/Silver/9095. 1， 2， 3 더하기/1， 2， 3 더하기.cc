#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

/*
1 = 1 (1)
2 = 2 (11, 2)
3 = 4 (111, 21, 12, 3)
4 = 7 (1111, 211, 121, 31, 112, 22, 13)
5 = 13 (11111, 2111, 1211, 311, 1121, 221, 131, 1112, 212, 122, 32, 113, 23)
6 = 24
7 = 44 ?

*/


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> OTTs(12, 0);
    int T;

    OTTs[1] = 1;
    OTTs[2] = 2;
    OTTs[3] = 4;

    for (int i = 4; i <= 11; ++i)
        OTTs[i] = OTTs[i - 1] + OTTs[i - 2] + OTTs[i - 3];

    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int N;
        cin >> N;     

        cout << OTTs[N] << '\n';
    }
  

    return 0;

}