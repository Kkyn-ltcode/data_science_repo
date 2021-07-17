#include <iostream>
#include <vector>
using namespace std;

struct position {
    int source;
    int destination;
};

class dictionary {
   public:
    int num_of_word, col, row;
    vector<string> dic;
    vector<vector<char>> a;
    vector<vector<bool>> unused;
    vector<string> result;
    vector<vector<position>> hash;
    position N;
    void print();
    position find_char(int);
    void create_word();
    void input();
    void function();
};

position dictionary::find_char(int char_index) {
    for (int k = 0; k < hash[char_index].size(); k++) {
        position tmp = hash[char_index][k];
        if (!unused[tmp.source][tmp.destination]) {
            unused[tmp.source][tmp.destination] = true;
            return tmp;
        }
    }
    return N;
}

void dictionary::create_word() {
    for (int i = 0; i < num_of_word; i++) {
        string res = "";
        int head_index = dic[i][0];
        position head = find_char(head_index);
        res += dic[i][0];
        
    }
}

void dictionary::input() {
    cin >> num_of_word >> row >> col;
    dic.resize(num_of_word);
    for (int i = 0; i < num_of_word; i++)
        cin >> dic[i];
    a.resize(row);
    hash.resize(26);
    for (int i = 0; i < row; i++) {
        a[i].resize(col);
        for (int j = 0; j < col; j++) {
            cin >> a[i][j];
            position p;
            p.source = i;
            p.destination = j;
            hash[a[i][j] - 'A'].push_back(p);
        }
    }
    unused.resize(row);
    for (int i = 0; i < row; i++) {
        unused[i].resize(col);
        for (int j = 0; j < col; j++)
            unused[i][j] = true;
    }
    N.source = -1;
    N.destination = -1;
}

void dictionary::function() {
    input();
    create_word();
    print();
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        dictionary d;
        d.function();
    }
    return 0;
}