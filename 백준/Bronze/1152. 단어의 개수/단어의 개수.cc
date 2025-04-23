#include <iostream>
#include <string>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string Input;
    int WordCount = 0;
    bool IsWord = false;

    getline(std::cin, Input);  // 공백 포함해서 한 줄 전체를 입력받음


    for (int i = 0; i < Input.size(); ++i)
    {
        if (' ' == Input[i])
        {
            if (IsWord)
                ++WordCount;
            IsWord = false;
        }
        else
        {
            IsWord = true;
        }
    }

    if (IsWord)
        ++WordCount;

    cout << WordCount;

    return 0;
}
