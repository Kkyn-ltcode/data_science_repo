#include <math.h>

#include <iostream>
#include <queue>
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
    bool is_full_binary_tree(node *);
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

bool binary_tree::is_full_binary_tree(node *root) {
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    else if (root->left == NULL || root->right == NULL)
        return false;
    return (is_full_binary_tree(root->left) &&
            is_full_binary_tree(root->right));
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
    cout << is_full_binary_tree(root) << endl;
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