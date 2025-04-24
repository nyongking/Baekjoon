#include <iostream>
#include <list>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    list<int> Peoples;
    list<int> Josephus;

    cin >> N >> K;

    for (int i = 1; i <= N; ++i)
        Peoples.push_back(i);

    int Count = 1;
    auto iter = Peoples.begin();
    while (false == Peoples.empty())
    {
        // 요세푸스에 투입, 사람 제거, iter 바꾸기
        if (K == Count)
        {
            Josephus.push_back(*iter);
            iter = Peoples.erase(iter);
            if (Peoples.empty())
                break;
            if (iter == Peoples.end())
                iter = Peoples.begin();

            Count = 1;
        }
        else
        {
            ++Count;
            ++iter;
            if (iter == Peoples.end())
                iter = Peoples.begin();
        }

    }

    cout << '<';
    for (auto it = Josephus.begin(); it != Josephus.end(); )
    {
        cout << *it;
        ++it;
        if (it != Josephus.end())
            cout << ", ";
    }

    cout << '>';

    return 0;
}
