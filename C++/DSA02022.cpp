#include <iostream>
#include <vector>
using namespace std;
int n, FOPT, cost, cmin;
int c[16][16], a[16], b[16];

int minCost() {
    int min = 1000;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j && c[i][j] < min)
                min = c[i][j];
    return min;
}

void input() {
    a[1] = 1;
    cost = 0;
    cmin = minCost();
    FOPT = 3200;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    for (int i = 1; i <= n; i++)
        b[i] = 1;
}

void update() {
    int sum = cost + c[a[n]][1];
    if (sum < FOPT)
        FOPT = sum;
}

void Try(int i) {
    for (int j = 2; j <= n; j++) {
        if (b[j]) {
            a[i] = j;
            b[j] = 0;
            cost += c[a[i - 1]][a[i]];
            if (i == n)
                update();
            else if (cost + cmin * (n - i + 1) < FOPT)
                Try(i + 1);
            b[j] = 1;
            cost -= c[a[i - 1]][a[i]];
        }
    }
}

int main() {
    cin >> n;
    input();
    Try(2);
    cout << FOPT;
    return 0;
}
