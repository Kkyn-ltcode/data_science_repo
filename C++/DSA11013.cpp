#include <iostream>
using namespace std;

struct node {
    int value;
    node *left;
    node *right;
};

class binary_tree {
   public:
    node *make_node(int);
    void insert(node *, int, int, char);
    node *input();
    bool is_leaf(node *);
    int left_leaf_sum(node *);
    void in_order(node *);
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
        if (root->value == data && (root->left == NULL || root->right == NULL)) {
            if (direct == 'L') {
                if (root->left == NULL)
                    root->left = make_node(child);
            } else {
                if (root->right == NULL)
                    root->right = make_node(child);
            }
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

bool binary_tree::is_leaf(node *root) {
    if (root == NULL)
        return false;
    if (root->left == NULL && root->right == NULL)
        return true;
    return false;
}

int binary_tree::left_leaf_sum(node *root) {
    int sum = 0;
    if (root != NULL) {
        if (is_leaf(root->left))
            sum += root->left->value;
        else
            sum += left_leaf_sum(root->left);
        sum += left_leaf_sum(root->right);
    }
    return sum;
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
    in_order(root);
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