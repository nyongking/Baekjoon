#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

/*

(0) 1 2 3 1 2
(0) 1 3 6 7 9
(0) 1 0 0 1 0
--------------
      +1+2+1+3
      = 7


*/



int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> Mods;
    int N, M;
    int TotalMod = 0;
    int64_t Answer = 0;

    cin >> N >> M;
    
    Mods.resize(M, 0);
    Mods[0] = 1;

    for (int i = 0; i < N; ++i)
    {
        int Input;
        cin >> Input;

        TotalMod = (TotalMod + Input) % M;

        Answer += (int64_t)Mods[TotalMod];
        ++Mods[TotalMod];
    }

    cout << Answer;


    return 0;

}