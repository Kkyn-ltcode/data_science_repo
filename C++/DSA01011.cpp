#include <iostream>
#include <algorithm>
using namespace std;

//void reverse_string(string& s, int left, int right) {
//	while (left < right) {
//		swap(s[left], s[right]);
//		left++;
//		right--;
//	}
//}
//
//int binary_search(string s, int left, int right, int key) {
//	int n = s.size();
//	int index = -1;
//	while (left <= right) {
//		int mid = (left + right) / 2;
//		if (s[mid] <= key)
//			right = mid - 1;
//		else {
//			left = mid + 1;
//			if (index == -1 || s[index] >= s[mid])
//				index = mid;
//		}
//	}
//	return index;
//}
//
//bool next_permutation(string& s) {
//	int n = s.size();
//	int i = n - 2;
//	while (i >= 0 && s[i] >= s[i + 1])
//		i--;
//	if (i < 0)
//		return false;
//	else {
//		int index = binary_search(s, i + 1, n - 1, s[i]);
//		swap(s[index], s[i]);
//		reverse_string(s, i + 1, n - 1);
//		return true;
//	}
//}
//
//int main() {
//	int test_case;
//	cin >> test_case;
//	while (test_case--) {
//		string s;
//		int num;
//		cin >> num >> s;
//		bool result = next_permutation(s);
//		if (result == true)
//			cout << num << " " << s;
//		else
//			cout << num << " " << "BIGGEST";
//		cout << endl;
//	}
//	return 0;
//}

int main() {
	int test_case;
	cin >> test_case;
	while (test_case--) {
		string s;
		int num;
		cin >> num >> s;
		bool result = next_permutation(s.begin(), s.end());
		if (result == true)
			cout << num << " " << s;
		else
			cout << num << " " << "BIGGEST";
		cout << endl;
	}
	return 0;
}
