#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void remove_bracket() {
    string s;
    cin >> s;
    stack<int> st;
    st.push(0);
    vector<char> result;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') {
            if (st.top() == 1)
                result.push_back('-');
            else if (st.top() == 0)
                result.push_back('+');
        } else if (s[i] == '-') {
            if (st.top() == 1)
                result.push_back('+');
            else if (st.top() == 0)
                result.push_back('-');
        } else if (s[i] == '(' && i >= 0) {
            if (s[i - 1] == '-') {
                if (st.top() == 1)
                    st.push(0);
                else
                    st.push(1);
            }
            else if (s[i - 1] == '+')
                st.push(st.top());
        } else if (s[i] == ')')
            st.pop();
        else
            result.push_back(s[i]);
    }
    for (int i = 0; i < result.size(); i++)
        cout << result[i];
    cout << endl;
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        remove_bracket();
    }
    return 0;
}