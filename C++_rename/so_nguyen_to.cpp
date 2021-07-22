#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<int>prime;
vector<int>result;
vector<int>fin;
int c;

bool is_prim(int x){
	if (x == 1)
		return false;
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0)
			return false;
	return true;
}

void push(){
	for (int i = 0; i < result.size(); i++)
		fin.push_back(result[i]);
}

void print(int n) {
	cout << c << endl;
	for (int i = 0; i < fin.size(); i++) {
		if (i % n == 0 && i != 0) {
			cout << endl;
			cout << fin[i] << " ";
		}
		else
			cout << fin[i] << " ";
	}
	cout << endl;
}

void back_track(int sum, int n, int s, int index){
	if (sum == s && result.size() == n) {
		c++;
		push();
		return;
	}
	if (sum > s || index == prime.size())
		return;
	result.push_back(prime[index]);
	back_track(sum + prime[index], n, s, index + 1);
	result.pop_back();
	back_track(sum, n, s, index + 1);
}

int main(){
	int test_case;
	cin >> test_case;
	while (test_case--) {
		int n, s, p;
		c = 0;
		cin >> n >> p >> s;
		for (int i = p + 1; i <= s; i++)
			if (is_prim(i))
				prime.push_back(i);
		back_track(0, n, s, 0);
		print(n);
		prime.clear();
		result.clear();
		fin.clear();
	}
	return 0;
}