#include <iostream>
#include <queue>
#include <math.h>
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
    bool is_perfect_tree(node *, int);
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

bool binary_tree::is_perfect_tree(node *root, int level) {
    queue<node *> q;
    q.push(root);
    int total_node = 0;
    while (!q.empty()) {
        total_node = q.size();
        if (total_node != pow(2, level))
            return false;
        for (int i = 0; i < total_node; i++) {
            node *tmp = q.front();
            q.pop();
            if (tmp->left != NULL)
                q.push(tmp->left);
            if (tmp->right != NULL)
                q.push(tmp->right);
        }
        level++;
    }
    return true;
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
    if (is_perfect_tree(root, 0))
        cout << "Yes";
    else
        cout << "No";
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