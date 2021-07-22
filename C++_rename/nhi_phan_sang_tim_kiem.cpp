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
    int index;
    node *make_node(int);
    void insert(node *, int, int, char);
    void store_value(node *, vector<int> &);
    void convert_to_BST(node *root, vector<int>);
    void in_order(node *);
    node *input();
    void function();
};

node *binary_tree::make_node(int data) {
    node *new_node = new node;
    new_node->value = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void binary_tree::insert(node *root, int data, int child, char direct) {
    if (root != NULL) {
        if (root->value == data) {
            if (direct == 'L')
                root->left = make_node(child);
            else
                root->right = make_node(child);

        } else {
            insert(root->left, data, child, direct);
            insert(root->right, data, child, direct);
        }
    }
}

node *binary_tree::input() {
    int total_node;
    cin >> total_node;
    node *root = NULL;
    while (total_node--) {
        int i_root, child;
        char direct;
        cin >> i_root >> child >> direct;
        if (root == NULL) {
            root = make_node(i_root);
            insert(root, i_root, child, direct);
        } else
            insert(root, i_root, child, direct);
    }
    return root;
}

void binary_tree::store_value(node *root, vector<int> &in) {
    if (root != NULL) {
        store_value(root->left, in);
        in.push_back(root->value);
        store_value(root->right, in);
    }
}

void binary_tree::convert_to_BST(node *root, vector<int> in) {
    if (root != NULL) {
        convert_to_BST(root->left, in);
        root->value = in[index];
        index++;
        convert_to_BST(root->right, in);
    }
}

void binary_tree::in_order(node *root) {
    if (root != NULL) {
        in_order(root->left);
        cout << root->value << " ";
        in_order(root->right);
    }
}

void binary_tree::function() {
    node *root = input();
    vector<int> in;
    store_value(root, in);
    sort(in.begin(), in.end());
    index = 0;
    convert_to_BST(root, in);
    in_order(root);
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