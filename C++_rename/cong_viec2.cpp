#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool comparison2(Job a, Job b) {
    return (a.profit > b.profit);
}

bool comparison1(Job a, Job b) {
    return (a.deadline > b.deadline);
}

void result(Job a[], int n) {
    bool slot[1000];
    int max_profit = 0;
    int num_of_job = 0;
    sort(a, a + n, comparison1);
    for (int i = 0; i < a[0].deadline; i++)
        slot[i] = false;
    sort(a, a + n, comparison2);
    for (int i = 0; i < n; i++) {
        for (int j = min(a[i].deadline, n) - 1; j >= 0; j--) {
            if (!slot[j]) {
                num_of_job++;
                max_profit += a[i].profit;
                slot[j] = true;
                break;
            }
        }
    }
    cout << num_of_job << " " << max_profit << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Job a[1000];
        for (int i = 0; i < n; i++)
            cin >> a[i].id >> a[i].deadline >> a[i].profit;
        result(a, n);
    }
    return 0;
}