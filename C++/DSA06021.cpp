#include <iostream>
#include <vector>
using namespace std;

int find_pivot(vector<int> a, int n) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (a[mid] > a[right])
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int binary_search(vector<int> a, int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (key == a[mid])
            return mid;
        else if (key > a[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
}

void drive() {
    int n, key;
    cin >> n >> key;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int pivot = find_pivot(a, n);
    int left = 0;
    int right = n - 1;
    if (key >= a[pivot] && key <= a[right])
        left = pivot;
    else
        right = pivot - 1;
    cout << binary_search(a, left, right, key) + 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        drive();
    }
    return 0;
}