#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

/*
R G B G B G..
R B R G B..

*/

#define RED 0
#define GREEN 1
#define BLUE 2
#define END 3

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<int>> MinCosts;
    int N;

    cin >> N;
    MinCosts.resize(N + 1, vector<int>(END, INT32_MAX));

    MinCosts[0][RED] = 0;
    MinCosts[0][GREEN] = 0;
    MinCosts[0][BLUE] = 0;

    for (int i = 1; i <= N; ++i)
    {
        int Red, Green, Blue;

        cin >> Red >> Green >> Blue;

        MinCosts[i][RED] = min(min(MinCosts[i][RED], MinCosts[i - 1][GREEN] + Red), MinCosts[i - 1][BLUE] + Red);
        MinCosts[i][GREEN] = min(min(MinCosts[i][GREEN], MinCosts[i - 1][RED] + Green), MinCosts[i - 1][BLUE] + Green);
        MinCosts[i][BLUE] = min(min(MinCosts[i][BLUE], MinCosts[i - 1][GREEN] + Blue), MinCosts[i - 1][RED] + Blue);
    }

    cout << min(min(MinCosts[N][RED], MinCosts[N][BLUE]), MinCosts[N][GREEN]);

    return 0;

}