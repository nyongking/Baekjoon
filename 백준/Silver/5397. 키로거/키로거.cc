#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        string Commands;
        cin >> Commands;

        list<char> Passwords;
        auto Cursor = Passwords.begin();
                
        for (int j = 0; j < Commands.size(); ++j)
        {
            if ('<' == Commands[j] && false == Passwords.empty() && Passwords.begin() != Cursor)
                --Cursor;
            else if ('>' == Commands[j] && false == Passwords.empty() && Passwords.end() != Cursor)
                ++Cursor;
            else if ('-' == Commands[j] && false == Passwords.empty() && Passwords.begin() != Cursor)
            {
                auto DeleteCursor = Cursor;
                --DeleteCursor;

                Cursor = Passwords.erase(DeleteCursor);
            }
            else if ('<' != Commands[j] && '>' != Commands[j] && '-' != Commands[j])
            {             
                Cursor = Passwords.insert(Cursor, Commands[j]);
                ++Cursor;               

            }
        }

        for (auto& Character : Passwords)
        {
            cout << Character;
        }
        cout << '\n';
    }

    return 0;
}
