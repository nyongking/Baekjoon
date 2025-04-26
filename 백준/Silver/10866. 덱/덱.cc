#include <iostream>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    list<int> Deque;
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        string InputString;

        cin >> InputString;

        if ("push_front" == InputString)
        {
            int InputInt;

            cin >> InputInt;
            Deque.push_front(InputInt);
        }

        else if ("push_back" == InputString)
        {
            int InputInt;

            cin >> InputInt;
            Deque.push_back(InputInt);
        }

        else if ("pop_front" == InputString)
        {
            if (Deque.empty())
                cout << -1 << '\n';
            else
            {
                cout << Deque.front() << '\n';
                Deque.pop_front();
            }
        }

        else if ("pop_back" == InputString)
        {
            if (Deque.empty())
                cout << -1 << '\n';
            else
            {
                cout << Deque.back() << '\n';
                Deque.pop_back();
            }
        }

        else if ("size" == InputString)
        {
            cout << Deque.size() << '\n';
        }

        else if ("empty" == InputString)
        {
            if (Deque.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if ("front" == InputString)
        {
            if (Deque.empty())
                cout << -1 << '\n';
            else
                cout << Deque.front() << '\n';
        }
        else if ("back" == InputString)
        {
            if (Deque.empty())
                cout << -1 << '\n';
            else
                cout << Deque.back() << '\n';
        }

    }

    return 0;
}
