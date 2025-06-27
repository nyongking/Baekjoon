#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

string QuadTree(vector<vector<char>>& Image, int Size, int Top, int Left)
{
    if (1 == Size)
    {
        if ('1' == Image[Top][Left])
        {
            return to_string(1);
        }
        else
        {
            return to_string(0);
        }
    }
    else
    {
        int HalfSize = Size / 2;
        string LT = QuadTree(Image, HalfSize, Top, Left);
        string RT = QuadTree(Image, HalfSize, Top, Left + HalfSize);
        string LB = QuadTree(Image, HalfSize, Top + HalfSize, Left);
        string RB = QuadTree(Image, HalfSize, Top + HalfSize, Left + HalfSize);

        if (1 == LT.size() && 1 == RT.size() && 1 == LB.size() && 1 == RB.size())
        {
            if (LT == RT && RT == LB && LB == RB)
                return LT;
            else
                return string('(' + LT + RT + LB + RB + ')');
        }
        else
        {
            return string('(' + LT + RT + LB + RB + ')');
        }
    }


}

void PrintQuadTree(vector<vector<char>>& Image, int Size)
{
    cout << QuadTree(Image, Size, 0, 0);
}


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    
    vector<vector<char>> Image(N, vector<char>(N));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> Image[i][j];

    PrintQuadTree(Image, N);


    return 0;

}