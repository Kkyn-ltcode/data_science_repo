#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

void I_D_expression(string s) {
    queue<string> ex;
    unordered_map<string, string> um;
    ex.push("I");
    um["I"] = "12";
    ex.push("D");
    um["D"] = "21";
    int digit = 3;
    while (ex.front() != s) {
        string tmp = ex.front();
        string tmp1, tmp2;
        ex.pop();
        if (tmp[tmp.size() - 1] == 'I') {
            tmp1 = tmp + "I";
            um[tmp1] = um[tmp] + to_string(digit);
            tmp2 = tmp + "D";
            um[tmp2] = um[tmp].insert(um[tmp].size() - 1, to_string(digit));
        } else {
            tmp1 = tmp + "I";
            um[tmp1] = um[tmp] + to_string(digit);
            tmp2 = tmp + "D";
            int index = tmp2.size() - 1;
            while (index >= 0 && tmp2[index] == 'D')
                index--;
            um[tmp2] = um[tmp].insert(index + 1, to_string(digit));
        }
        ex.push(tmp1);
        ex.push(tmp2);
        if (ex.front().size() > tmp.size())
            digit++;
    }
    cout << um[ex.front()] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        I_D_expression(s);
    }
    return 0;
}