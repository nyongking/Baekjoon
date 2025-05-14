#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

/*
10 20 10 30 20 50
10 20 5 9 15 30
10 20 25 30 5 9 24 40
10 20 25 30 5 9 24 25 40
f(0) = 1
f(1) = 2
f(2) = 3



*/


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> Numbers;
    vector<int> Sequence;
    int N;
    
    cin >> N;
    Numbers.resize(N, 0);
    Sequence.resize(N, 1);

    for (int i = 0; i < N; ++i)
    {
        cin >> Numbers[i];

        for (int j = 0; j < i; ++j)
        {
            if (Numbers[i] > Numbers[j] && Sequence[i] <= Sequence[j])
                Sequence[i] = Sequence[j] + 1;
        }
    }
    
    auto iter = max_element(Sequence.begin(), Sequence.end());

    cout << *iter;

    return 0;

}