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
    bool is_same_tree(node *, node *);
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

bool binary_tree::is_same_tree(node *root1, node *root2) {
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 != NULL && root2 != NULL) {
        return (root1->value == root2->value &&
                is_same_tree(root1->left, root2->left) &&
                is_same_tree(root1->right, root2->right));
    }
    return false;
}

void binary_tree::function() {
    node *root1 = input();
    node *root2 = input();
    cout << is_same_tree(root1, root2) << endl;
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