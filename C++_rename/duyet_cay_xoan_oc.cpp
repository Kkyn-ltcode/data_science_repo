#include <deque>
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
    void spiral_order(node *);
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

void binary_tree::spiral_order(node *root) {
    deque<node *> dq;
    dq.push_front(NULL);
    dq.push_front(root);
    while (dq.size() > 1) {
        while (dq.front() != NULL) {
            node *tmp = dq.front();
            dq.pop_front();
            cout << tmp->value << " ";
            if (tmp->right != NULL)
                dq.push_back(tmp->right);
            if (tmp->left != NULL)
                dq.push_back(tmp->left);
        }
        while (dq.back() != NULL) {
            node *tmp = dq.back();
            dq.pop_back();
            cout << tmp->value << " ";
            if (tmp->left != NULL)
                dq.push_front(tmp->left);
            if (tmp->right != NULL)
                dq.push_front(tmp->right);
        }
    }
    cout << endl;
}

void binary_tree::function() {
    int total_edge;
    cin >> total_edge;
    int i_root, child;
    char direct;
    cin >> i_root >> child >> direct;
    node *root = make_node(i_root);
    insert(root, i_root, child, direct);
    total_edge--;
    while (total_edge--) {
        cin >> i_root >> child >> direct;
        insert(root, i_root, child, direct);
    }
    spiral_order(root);
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
