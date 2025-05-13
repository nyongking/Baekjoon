#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;


/*



*/

int Tiling(vector<int>& Tiles, int N)
{
    if (0 == Tiles[N])
    {
        Tiles[N] = (Tiling(Tiles, N - 1) + 2 * Tiling(Tiles, N - 2)) % 10007;
    }

    return Tiles[N];
}


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> Tiles;
    int N;

    cin >> N;

    if (N > 2)
        Tiles.resize(N + 1, 0);
    else
        Tiles.resize(3, 0);

    Tiles[1] = 1;
    Tiles[2] = 3;

    cout << Tiling(Tiles, N);

    return 0;

}