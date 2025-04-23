#include <iostream>

using namespace std;

int main()
{
	int num1, num2 = 0;
	cin >> num1 >> num2;
	int digit = 3;
	int temp1 = 0;
	int temp2 = 0;

	while (digit != 0)
	{
		temp1 = temp1 * 10 + num1 % 10;
		temp2 = temp2 * 10 + num2 % 10;

		num1 /= 10;
		num2 /= 10;
		digit--;
	}
	cout << max(temp1, temp2) << endl;
}