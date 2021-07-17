#include <iostream>
using namespace std;

struct node {
    int value;
    node *left;
    node *right;
};

class binary_tree {
   public:
    int path = 0;
    node *make_node(int);
    node *input();
    void insert(node *, int, int);
    int find_path(node *);
    bool is_leaf(node *);
    void print_path() void function();
};

node *binary_tree::make_node(int data) {
    node *new_node = new node;
    new_node->value = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *binary_tree::input() {
    int n;
    cin >> n;
    node *root = NULL;
    for (int i = 0; i < n - 1; i++) {
        int node, child;
        cin >> node >> child;
        if (root == NULL) {
            root = make_node(node);
            insert(root, node, child);
        } else
            insert(root, node, child);
    }
    return root;
}

void binary_tree::insert(node *root, int node, int child) {
    if (root != NULL) {
        if (root->value == node) {
            if (root->left == NULL)
                root->left = make_node(child);
            else if (root->right == NULL)
                root->right = make_node(child);
        } else {
            insert(root->left, node, child);
            insert(root->right, node, child);
        }
    }
}

bool binary_tree::is_leaf(node *root) {
    if (root->left == NULL && root->right == NULL)
        return true;
    return false;
}

int binary_tree::find_path(node *root) {
    if (root != NULL) {
        if (is_leaf(root))
            print_path(root);
        find_path(root->left);
        find_path(root->right);
    }
}

void binary_tree::function() {
    node *root = input();
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