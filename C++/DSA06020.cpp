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
		cin.ignore();
		string s, k;
		getline(cin, k);
		getline(cin, s);
		if (s.find(k) != -1)
			cout << "1" << endl;
		else
			cout << "-1" << endl;
	}
	return 0;
}