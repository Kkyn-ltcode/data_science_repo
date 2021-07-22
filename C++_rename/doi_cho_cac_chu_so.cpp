#include <iostream>
#include <string>
using namespace std;

void max_string(string s, string& result, int k) {
	if (k == 0)
		return;
	int n = s.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (s[j] > s[i]) {
				swap(s[i], s[j]);
				if (s.compare(result) > 0)
					result = s;
				max_string(s, result, k - 1);
				swap(s[i], s[j]);
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		string s, result;
		cin >> s;
		result = s;
		max_string(s, result, k);
		cout << result << endl;
	}
	return 0;
}
