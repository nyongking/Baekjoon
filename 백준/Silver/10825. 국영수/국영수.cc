#include <iostream>
#include <list>
#include <string>
using namespace std;

typedef struct tagStudentInfo
{
    string Name;
    int Kor, Eng, Math;
}STUDENTINFO;


bool Cmp(const STUDENTINFO& A, const STUDENTINFO& B)
{
    
    if (A.Kor == B.Kor)
    {        
        if (A.Eng == B.Eng)
        {
            if (A.Math == B.Math)
            {
                int Length = min(A.Name.length(), B.Name.length());
                for (int i = 0; i < Length; ++i)
                {
                    if (A.Name[i] == B.Name[i])
                        continue;
                    else
                        return A.Name[i] < B.Name[i];
                }
            }
            else // 3. 수학 점수 감소 순서
                return A.Math > B.Math;
        }
        else // 2. 영어 점수 증가 순서
            return A.Eng < B.Eng;
    }
    else // 1. 국어 점수 감소 순서
        return A.Kor > B.Kor;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    list<STUDENTINFO> Students;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        STUDENTINFO NewInfo;
        cin >> NewInfo.Name;
        cin >> NewInfo.Kor;
        cin >> NewInfo.Eng;
        cin >> NewInfo.Math;

        Students.push_back(NewInfo);
    }

    Students.sort(Cmp);

    for (auto& iter : Students)
        cout << iter.Name << '\n';

    return 0;
}
