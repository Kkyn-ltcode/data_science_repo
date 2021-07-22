#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct node {
    int value;
    node *left;
    node *right;
};

class binary_tree {
   public:
    int num_of_leaf = 0;
    node *make_node(int);
    vector<int> input();
    node *construct_BST(vector<int>, int, int);
    void function();
};

node *binary_tree::make_node(int data) {
    node *new_node = new node;
    new_node->value = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

vector<int> binary_tree::input() {
    int n;
    cin >> n;
    vector<int> in_order(n);
    for (int i = 0; i < n; i++)
        cin >> in_order[i];
    sort(in_order.begin(), in_order.end());
    return in_order;
}

node *binary_tree::construct_BST(vector<int> in_order, int start, int end) {
    if (start > end)
        return NULL;
    int mid = start + (end - start) / 2;
    node *root = make_node(in_order[mid]);
    root->left = construct_BST(in_order, start, mid - 1);
    root->right = construct_BST(in_order, mid + 1, end);
    if (root->left == NULL && root->right == NULL)
        num_of_leaf++;
    return root;
}

void binary_tree::function() {
    vector<int> in_order = input();
    node *root = construct_BST(in_order, 0, in_order.size() - 1);
    cout << num_of_leaf << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        binary_tree b;
        b.function();
    }
    return 0;
}