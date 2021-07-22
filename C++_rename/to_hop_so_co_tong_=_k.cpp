#include <iostream>
#include <vector>
using namespace std;
bool printed;

void print(vector<int>result) {
	for (int i = 0; i < result.size(); i++) {
		if (i == 0)
			cout << "[";
		if (i == result.size() - 1)
			cout << result[i] << "]";
		else
			cout << result[i] << " ";
	}
	printed = true;
}

void back_track(vector<int>a, vector<int> result,
	int i, int k, int n) {
	if (k == 0)
		print(result);
	while (i <= n - 1 && k >= a[i]) {
		result.push_back(a[i]);
		back_track(a, result, i, k - a[i], n);
		i++;
		result.pop_back();
	}
}

void drive() {
	int n, k;
	cin >> n >> k;
	vector<int>a(n, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<int>result;
	back_track(a, result, 0, k, a.size());
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		printed = false;
		drive();
		if (!printed)
			cout << -1;
		cout << endl;
	}
	return 0;
}