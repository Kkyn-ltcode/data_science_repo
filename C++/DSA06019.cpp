#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool comp(pair<int, int>p1, pair<int, int>p2) {
	if (p1.second == p2.second)
		return p1.first < p2.first;
	return p1.second > p2.second;
}

void sorting(){
	int n;
	cin >> n;
	map<int, int>m;
	vector<int>a(n, 0);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		m[a[i]]++;
	}
	vector<pair<int, int>>p;
	for (auto i = m.begin(); i != m.end(); i++)
		p.push_back(make_pair(i->first, i->second));
	sort(p.begin(), p.end(), comp);
	for (int i = 0; i < p.size(); i++)
		while (p[i].second--)
			cout << p[i].first << " ";
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		sorting();
	}
	return 0;
}