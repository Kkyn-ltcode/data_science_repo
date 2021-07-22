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
    void level_order_traversal(node *);
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
            if (direct == 'L') {
                root->left = make_node(child);
                return;
            } else {
                root->right = make_node(child);
                return;
            }
        }
        insert(root->left, data, child, direct);
        insert(root->right, data, child, direct);
    }
}

void binary_tree::level_order_traversal(node *root) {
    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        node *tmp = q.front();
        if (tmp->left != NULL)
            q.push(tmp->left);
        if (tmp->right != NULL)
            q.push(tmp->right);
        cout << tmp->value << " ";
        q.pop();
    }
    cout << endl;
}

void binary_tree::function() {
    int total_node;
    cin >> total_node;
    int i_root, child;
    char direct;
    cin >> i_root >> child >> direct;
    node *root = make_node(i_root);
    insert(root, i_root, child, direct);
    total_node--;
    while (total_node--) {
        cin >> i_root >> child >> direct;
        insert(root, i_root, child, direct);
    }
    level_order_traversal(root);
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
