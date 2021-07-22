#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

class word_ladder {
   public:
    int n;
    string source, destination;
    unordered_set<string> my_set;
    void function();
    void input();
    int solve();
};

int word_ladder::solve() {
    queue<string> q;
    q.push(source);
    int level = 0;
    while (!q.empty()) {
        level++;
        int l_size = q.size();
        while (l_size--) {
            string tmp = q.front();
            q.pop();
            for (int i = 0; i < tmp.size(); i++) {
                string word = tmp;
                for (char j = 'A'; j <= 'Z'; j++) {
                    word[i] = j;
                    if (tmp.compare(word) == 0)
                        continue;
                    if (word.compare(destination) == 0)
                        return level + 1;
                    if (my_set.find(word) != my_set.end()) {
                        q.push(word);
                        my_set.erase(word);
                    }
                }
            }
        }
    }
    return -1;
}

void word_ladder::input() {
    cin >> n >> source >> destination;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        my_set.insert(tmp);
    }
}

void word_ladder::function() {
    input();
    cout << solve() << endl;
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        word_ladder w;
        w.function();
    }
}