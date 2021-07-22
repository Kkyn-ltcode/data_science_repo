#include <iostream>
#include <vector>
using namespace std;

void greedy(long long numerator, long long denominator) {
    if (numerator == 0)
        return;
    if (denominator % numerator == 0) {
        cout << 1 << "/" << denominator / numerator << endl;
        return;
    }
    long long largest_unit = denominator / numerator + 1;
    cout << "1/" << largest_unit << " + ";
    greedy(numerator * largest_unit - denominator, denominator * largest_unit);
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; x++) {
        long long numerator, denominator;
        cin >> numerator >> denominator;
        greedy(numerator, denominator);
    }
    return 0;
}