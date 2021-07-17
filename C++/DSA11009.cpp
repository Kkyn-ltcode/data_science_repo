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
    bool is_leaf(node *);
    bool is_sum_tree(node *);
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

bool binary_tree::is_leaf(node *root) {
    if (root == NULL)
        return false;
    if (root->left == NULL && root->right == NULL)
        return true;
    return false;
}

bool binary_tree::is_sum_tree(node *root) {
    if (root == NULL || is_leaf(root))
        return true;
    int left_sum;
    int right_sum;
    if (is_sum_tree(root->left) && is_sum_tree(root->right)) {
        if (root->left == NULL)
            left_sum = 0;
        else if (is_leaf(root->left))
            left_sum = root->left->value;
        else
            left_sum = 2 * (root->left->value);

        if (root->right == NULL)
            right_sum = 0;
        if (is_leaf(root->right))
            right_sum = root->right->value;
        else
            right_sum = 2 * (root->right->value);
        return (root->value == left_sum + right_sum);
    }
    return false;
}

void binary_tree::function() {
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
    cout << is_sum_tree(root) << endl;
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