#include <iostream>
using namespace std;

struct node {
    int value;
    node *left;
    node *right;
} * B;

class binary_tree {
   public:
    binary_tree() {
        B = NULL;
    }
    node *make_node(int);
    void make_root(int);
    void insert(node *, int, int, char);
    bool check_level(node *, int, int &);
    void clear_tree(node *);
    void function();
};

node *binary_tree::make_node(int value) {
    node *new_node = new node;
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void binary_tree::make_root(int value) {
    node *tmp = make_node(value);
    B = tmp;
}

void binary_tree::insert(node *B, int root, int child, char direct) {
    if (B != NULL) {
        if (B->value == root) {
            if (direct == 'R') {
                B->right = make_node(child);
                return;
            } else {
                B->left = make_node(child);
                return;
            }
        }
        insert(B->left, root, child, direct);
        insert(B->right, root, child, direct);
    }
}

bool binary_tree::check_level(node *B, int level, int &leaf_level) {
    if (B == NULL)
        return true;
    if (B->left == NULL && B->right == NULL) {
        if (leaf_level == 0) {
            leaf_level = level;
            return true;
        }
        return (leaf_level == level);
    }
    return check_level(B->left, level + 1, leaf_level) &&
           check_level(B->right, level + 1, leaf_level);
}

void binary_tree::clear_tree(node *root) {
    if (root != NULL) {
        clear_tree(root->left);
        clear_tree(root->right);
        delete (root);
    }
}

void binary_tree::function() {
    int total_edge, root, child;
    char direct;
    cin >> total_edge >> root >> child >> direct;
    make_root(root);
    insert(B, root, child, direct);
    total_edge--;
    while (total_edge--) {
        cin >> root >> child >> direct;
        insert(B, root, child, direct);
    }
    int level = 0, leaf_level = 0;
    if (check_level(B, level, leaf_level))
        cout << 1;
    else
        cout << 0;
    cout << endl;
    clear_tree(B);
    B = NULL;
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
