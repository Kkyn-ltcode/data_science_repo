#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct data {
    string father_name;
    string child_name;
    int father_age;
};

class births_info {
   public:
    int num_of_people;
    map<data, int> m;
    vector<int> age;
    void function();
    void input();
    void sort();
    int calculate();
};

void births_info::sort() {
    for (int i = 0; i < age.size(); i++) {
        if (age[i] == 0) {
            age[i] = calculate();
        }
    }
}

void births_info::input() {
    cin >> num_of_people;
    for (int i = 0; i < num_of_people; i++) {
        data tmp;
        cin >> tmp.father_name >> tmp.child_name >> tmp.father_age;
        if (tmp.father_name == "Ted")
            m[tmp] = 100 - tmp.father_age;
        else
            m[tmp] = 0;
        age.push_back(m[tmp]);
    }
}

void births_info::function() {
    input();
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        births_info g;
        g.function();
    }
    return 0;
}