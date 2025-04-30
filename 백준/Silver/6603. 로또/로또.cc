#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void Lotto(vector<int>& Numbers, vector<bool>& Visited, int Now, int Count)
{
    Visited[Now] = true;
    ++Count;

    // 출력
    if (6 == Count)
    {
        for (int i = 0; i < Numbers.size(); ++i)
        {
            if (true == Visited[i])
                cout << Numbers[i] << ' ';
        }
        cout << '\n';
        Visited[Now] = false;
        return;
    }

    for (int i = Now + 1; i < Numbers.size(); ++i)
    {
        if (false == Visited[i])
        {
            Lotto(Numbers, Visited, i, Count);
        }
    }

    Visited[Now] = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true)
    {
        int K;
        cin >> K;

        if (0 == K)
            return 0;

        vector<int> Numbers;
        vector<bool> Visited(K, false);

        for (int i = 0; i < K; ++i)
        {
            int Input;
            cin >> Input;

            Numbers.push_back(Input);
        }

        for (int i = 0; i < K; ++i)
        {
            Lotto(Numbers, Visited, i, 0);
        }

        cout << '\n';
    }




    return 0;
}
