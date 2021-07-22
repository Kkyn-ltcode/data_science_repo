#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define huge long long int
using namespace std;

vector<string> total_cubes(huge n) {
	vector<string>tmp;
	for (huge i = 1; (i * i * i) <= n; i++) {
		huge cube = i * i * i;
		string s_cube = to_string(cube);
		tmp.push_back(s_cube);
	}
	return tmp;
}

string find_largest_cube(vector<string>cubes, string num) {
	reverse(cubes.begin(), cubes.end());
	int totalCubes = cubes.size();
	for (int i = 0; i < totalCubes; i++) {
		string current_cube = cubes[i];
		int cube_digits = current_cube.size();
		int num_digits = num.size();
		int index = 0;
		for (int j = 0; j < num_digits; j++) {
			if (current_cube[index] == num[j])
				index++;
			if (index == cube_digits)
				return current_cube;
		}
	}
	return "-1";
}

string driver() {
	huge n;
	cin >> n;
	vector<string>cubes = total_cubes(n);
	string num = to_string(n);
	return find_largest_cube(cubes, num);
	
}

int main() {
	int test_case;
	cin >> test_case;
	while (test_case--) {
		cout << driver() << endl;
	}
	return 0;
}
