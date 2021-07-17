#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct objects {
    int weight;
    int value;
    double ratio;
};

class knapsack {
   public:
    int num_of_ob;
    int max_weight;
    vector<objects> o;
    void function();
    void input();
    void solve();
};

void knapsack::solve() {
    double res = 0.0;
    for (int i = 0; i < num_of_ob; i++) {
        if (o[i].weight <= max_weight) {
            res += o[i].value;
            max_weight -= o[i].weight;
        } else {
            res += ((double)max_weight / (double)o[i].weight) * o[i].value;
            max_weight = 0;
            break;
        }
    }
    cout << fixed << setprecision(2) << res << endl;
}

bool compare(objects a, objects b) {
    return a.ratio > b.ratio;
}

void knapsack::input() {
    cin >> num_of_ob >> max_weight;
    o.resize(num_of_ob);
    for (int i = 0; i < num_of_ob; i++) {
        cin >> o[i].value >> o[i].weight;
        o[i].ratio = (double)o[i].value / (double)o[i].weight;
    }
    sort(o.begin(), o.end(), compare);
}

void knapsack::function() {
    input();
    solve();
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        knapsack k;
        k.function();
    }
    return 0;
}