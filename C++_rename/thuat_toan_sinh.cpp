#include <iostream>
using namespace std;
int n, a[100];

void init() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		a[i] = 0;
}

void result() {
	int l = 1, r = n;
	while (l < r) {
		if (a[l] != a[r])
			return;
		l++;
		r--;
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void back_track(int i) {
	for (int j = 0; j <= 1; j++) {
		a[i] = j;
		if (i == n)
			result();
		else
			back_track(i + 1);
	}
}

int main() {
	init();
	back_track(1);
	return 0;
}