#include <climits>
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
    node *make_node(int);
    int create_tree(vector<int>, node *, int, int, int, int);
    void post_order(node *);
    void function();
};

node *binary_tree::make_node(int data) {
    node *new_node = new node;
    new_node->value = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int binary_tree::create_tree(vector<int> pre_order, node *root,
                             int n, int index, int max, int min) {
    if (index == n || pre_order[index] < min || pre_order[index] > max)
        return index;
    if (pre_order[index] < root->value) {
        root->left = make_node(pre_order[index]);
        index += 1;
        index = create_tree(pre_order, root->left, n, index, root->value, min);
    }
    if (index == n || pre_order[index] < min || pre_order[index] > max)
        return index;
    root->right = make_node(pre_order[index]);
    index += 1;
    index = create_tree(pre_order, root->right, n, index, max, root->value);
    return index;
}

void binary_tree::post_order(node *root) {
    if (root != NULL) {
        post_order(root->left);
        post_order(root->right);
        cout << root->value << " ";
    }
}

void binary_tree::function() {
    int n;
    cin >> n;
    vector<int> pre_order(n);
    for (int i = 0; i < n; i++)
        cin >> pre_order[i];
    node *root = make_node(pre_order[0]);
    create_tree(pre_order, root, n, 1, INT_MAX, INT_MIN);
    post_order(root);
    cout << endl;
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
