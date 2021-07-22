#include <iostream>
using namespace std;
int n, k, a[100], b[100], c = 0;

void init() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = 0;
	}
}

void result() {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (b[i] == 1)
			sum += b[i] * a[i];
	}
	if (sum == k) {
		for (int i = 1; i <= n; i++) {
			if (b[i] == 1)
				cout << a[i] << " ";
		}
		c++;
		cout << endl;
	}

}

void back_track(int i) {
	for (int j = 0; j <= 1; j++) {
		b[i] = j;
		if (i == n)
			result();
		else
			back_track(i + 1);
	}
}

int main() {
	init();
	back_track(1);
	cout << c << endl;
	return 0;
}