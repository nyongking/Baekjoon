#include <iostream>
#include <string>
#include <set>
using namespace std;

string ReplaceString(string Input, string FromString, string ToString)
{
    if (string::npos != Input.find(FromString))
        Input.replace(Input.find(FromString), FromString.size(), ToString);

    return Input;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string Croatians[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    string Input;
    cin >> Input;

    for (int i = 0; i < 8; ++i)
    {
        while (string::npos != Input.find(Croatians[i]))
            Input = ReplaceString(Input, Croatians[i], "*");
    }
    
    cout << Input.size();

    return 0;
}
