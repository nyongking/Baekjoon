#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>


using namespace std;

int LowerBoundary(vector<int>& Cards, int Number, int Left, int Right)
{
    if (Left >= Right)
        return Left;

    int Mid = Left + (Right - Left) / 2;
    if (Cards[Mid] < Number)
        return LowerBoundary(Cards, Number, Mid + 1, Right);
    else
        return LowerBoundary(Cards, Number, Left, Mid);
}

int UpperBoundary(vector<int>& Cards, int Number, int Left, int Right)
{
    if (Left >= Right)
        return Right;

    int Mid = Left + (Right - Left) / 2;
    if (Cards[Mid] > Number)
        return UpperBoundary(Cards, Number, Left, Mid);
    else
        return UpperBoundary(Cards, Number, Mid + 1, Right);
}


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> Cards(N);

    for (int i = 0; i < N; ++i)
        cin >> Cards[i];

    sort(Cards.begin(), Cards.end());

    int M;
    cin >> M;
    
    for (int i = 0; i < M; ++i)
    {
        int Input;
        cin >> Input;

        cout << UpperBoundary(Cards, Input, 0, N) -  LowerBoundary(Cards, Input, 0, N) << ' ';
    }

    return 0;

}