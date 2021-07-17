#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int x = 0; x < t; x++)
	{
		long long n;
		cin >> n;
		string s;
		cin.ignore();
		getline(cin, s);
		for (char i = '0'; i <= '9'; i++)
			if (s.find(i) != -1)
				cout << i << " ";
		cout << endl;
	}
	return 0;
}