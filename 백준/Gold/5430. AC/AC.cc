#include <iostream>
#include <algorithm>
#include <list>
#include <sstream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        bool Reversed = false;
        bool Error = false;
        list<int> Numbers;
        string Commands;
        string strNumbers;

        stringstream SS;
        string Number;

        cin >> Commands;

        int N;
        cin >> N;

        cin >> strNumbers;
        strNumbers = strNumbers.substr(1, strNumbers.size() - 2);

        SS << strNumbers;

        while (getline(SS, Number, ','))
            Numbers.push_back(stoi(Number));

        // Command        
        for (int j = 0; j < Commands.size(); ++j)
        {
            if ('R' == Commands[j])
                Reversed = !Reversed;
            if ('D' == Commands[j])
            {
                if (Numbers.empty())
                {
                    Error = true;
                    break;
                }
                else if (Reversed)
                {
                    Numbers.pop_back();
                }
                else
                {
                    Numbers.pop_front();
                }
            }
        }

        if (Error)
            cout << "error" << '\n';
        else
        {
            if (Reversed)
                Numbers.reverse();

            cout << '[';
            for (auto iter = Numbers.begin(); iter != Numbers.end(); )
            {
                cout << *iter;
                ++iter;
                if (iter != Numbers.end())
                    cout << ',';
                else
                    break;
            }
            cout << ']' << '\n';
        }

    }

    return 0;
}
