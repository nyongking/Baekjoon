#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*

N <= 1515,
O(2^1515)

15의 배수 = 3, 5의 배수
3의 배수 -> 각 자릿수 합 = 3의 배수
5의 배수 -> 끝자리 = (5, 0) -> 끝자리 5

x(끝자리 5를 제외한 자릿수 합) + 5 = 3의 배수 

N = 2 -> 1 (15)
N = 3 -> 1 (555)
N = 4 -> (1155, 1515, 5115)
...

*/
long long factorial(long long n, long long m)
{
    long long ret = 1;
    for (long long i = 1; i <= n; ++i)
        ret = (ret * i) % m;
    return ret;
}

long long power(long long a, long long b, long long m)
{
    long long answer = 1;
    long long prev = a;
    for (int i = 0; i <= 62; ++i)
    {
        if (b & (1ll << i))
            answer = (answer * prev) % m;
        prev = (prev * prev) % m;
    }
    return answer;
}



long long Comb(long long n, long long r, long long m)
{
    long long numerator = factorial(n, m);

    long long denominator1 = factorial(r, m);
    long long denominator2 = factorial(n - r, m);
    long long denominator = (denominator1 * denominator2) % m;

    long long newdenominator = power(denominator, m - 2, m);

    return (numerator * newdenominator) % m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int answer = 0;
    // N - 1개중 i개를 1, N - i - 1개를 5로 선택
    for (int i = 0; i <= N - 1; ++i)
    {
        int NumAdd = i * 1 + (N - i - 1) * 5 + 5;
        if (0 != NumAdd % 3)
            continue;

        answer = (answer + Comb(N - 1, i, 1'000'000'007)) % 1'000'000'007;
        
    }

    cout << answer;


    return 0;
}