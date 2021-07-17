#include <iostream>
using namespace std;

string add() {
	int base;
	string s1, s2, result = "", s = "";
	cin >> base;
	cin >> s1 >> s2;
	int len1 = s1.size(), len2 = s2.size();
	int dif = abs(len1 - len2);
	for (int i = 1; i <= dif; i++)
		s += "0";
	if (len1 < len2)
		s1 = s + s1;
	else
		s2 = s + s2;
	int tmp, carry = 0;
	for (int i = max(len1, len2) - 1; i >= 0; i--) {
		tmp = carry + (s1[i] - '0') + (s2[i] - '0');
		carry = tmp / base;
		tmp = tmp % base;
		result = (char)(tmp + '0') + result;
	}
	if (carry > 0)
		result = (char)(tmp + '0') + result;
	return result;
}

int main() {
	cout << add() << endl;
	return 0;
}
