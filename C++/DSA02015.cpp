#include <iostream>
#include <set>
#include <string>
#include <queue>
using namespace std;
bool printed;

bool is_parentheses(char c) {
	if (c == '(' || c == ')')
		return true;
	return false;
}

bool is_valid_string(string s) {
	if (s.size() == 1 || s.size() == 0)
		return false;
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			count++;
		if (s[i] == ')')
			count--;
		if (count < 0)
			return false;
	}
	return (count == 0);
}

void remove_parentheses(string s) {
	if (s.size() == 1 || s.size() == 0)
		return;
	set<string>used;
	queue<string>q;
	bool found = false;
	q.push(s);
	used.insert(s);
	while (!q.empty()) {
		string tmp = q.front();
		q.pop();
		if (is_valid_string(tmp)) {
			cout << tmp << " ";
			found = true;
			printed = true;
		}
		if (found)
			continue;
		for (int i = 0; i < tmp.size(); i++) {
			if (!is_parentheses(tmp[i]))
				continue;
			string sub_string = tmp.substr(0, i) + tmp.substr(i + 1);
			if (used.find(sub_string) == used.end()) {
				q.push(sub_string);
				used.insert(sub_string);
			}
		}
	}
}

void drive() {
	string s;
	getline(cin, s);
	remove_parentheses(s);
}

int main()
{
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		printed = false;
		drive();
		if (!printed)
			cout << -1;
		cout << endl;
	}
	return 0;
}