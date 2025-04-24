#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;    
    // key, count 
    map<int64_t, int> CardCounts;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int64_t Input;
        cin >> Input;

        if (CardCounts.find(Input) == CardCounts.end())
            CardCounts.emplace(Input, 1);
        else
            ++CardCounts[Input];
    }

    int Count = 0;
    int64_t Answer = INT64_MAX;
    for (auto iter = CardCounts.begin(); iter != CardCounts.end(); ++iter)
    {
        // 더 많은 카드
        if (Count < iter->second)
        {
            Count = iter->second;
            Answer = iter->first;
        }
        else if (Count == iter->second && Answer > iter->first)
        {
            Answer = iter->first;
        }
    }

    cout << Answer;

    return 0;
}
