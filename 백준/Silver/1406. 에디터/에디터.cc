#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    list<char> Characters;
    string strInput;
    int Count;
    
    cin >> strInput;
    cin >> Count;

    for (int i = 0; i < strInput.size(); ++i)
        Characters.push_back(strInput[i]);

    list<char>::iterator Cursor = Characters.end();

    for (int i = 0; i < Count; ++i)
    {
        char Command;
        cin >> Command;

        if ('L' == Command)
        {
            if (Characters.begin() != Cursor)
                --Cursor;
        }
        else if ('D' == Command)
        {
            if (Characters.end() != Cursor)
                ++Cursor;
        }
        else if ('B' == Command)
        {
            if (Characters.begin() != Cursor)
            {
                list<char>::iterator DeleteCursor = Cursor;
                --DeleteCursor;

                Cursor = Characters.erase(DeleteCursor);
            }
        }
        else if ('P' == Command)
        {
            char Add;
            cin >> Add;

            Cursor = Characters.insert(Cursor, Add);
            ++Cursor;
        }

    }

    for (auto& Character : Characters)
        cout << Character;

    return 0;
}
