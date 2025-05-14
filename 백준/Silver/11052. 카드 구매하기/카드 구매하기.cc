#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

/*

N 0
N-1 1
N-2 2...

1 0

3 0
2 1

4 0
3 1
2 2

*/

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> MaxCosts;
    int N;

    cin >> N;
    MaxCosts.resize(N + 1, 0);

    for (int i = 1; i <= N; ++i)
    {
        cin >> MaxCosts[i];

        for (int j = 0; j <= i / 2; ++j)
        {
            MaxCosts[i] = max(MaxCosts[i], MaxCosts[j] + MaxCosts[i - j]);
        }
    }

    cout << MaxCosts[N];

    return 0;

}