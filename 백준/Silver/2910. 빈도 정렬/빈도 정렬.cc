#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<int> Numbers;
map<int, int> Counts;
map<int, int> Orders;

bool Compare(int Src, int Dest)
{
    if (Counts[Src] == Counts[Dest])
    {
        return Orders[Src] < Orders[Dest];
    }
    else
        return Counts[Src] > Counts[Dest];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int N, C;
    cin >> N >> C;

    for (int i = 0; i < N; ++i)
    {
        int Input;
        cin >> Input;

        // Array
        Numbers.push_back(Input);

        // Count
        auto iter = Counts.find(Input);

        if (Counts.end() != iter)
        {
            ++iter->second;
        }
        else
        {
            Orders.emplace(Input, i);
            Counts.emplace(Input, 1);
        }
    }

    sort(Numbers.begin(), Numbers.end(), Compare);

    for (auto& Number : Numbers)
        cout << Number << " ";


    return 0;
}
