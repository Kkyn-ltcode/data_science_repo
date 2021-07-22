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
    node *make_node(int);
    node *create_tree(vector<int>, vector<int>, int, int, int);
    int search(vector<int>, int, int, int);
    void postorder(node *);
    void function();
};

node *binary_tree::make_node(int data) {
    node *new_node = new node;
    new_node->value = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int binary_tree::search(vector<int> in, int key, int in_start, int in_end) {
    for (int i = in_start; i <= in_end; i++)
        if (in[i] == key)
            return i;
    return 0;
}

node *binary_tree::create_tree(vector<int> pre, vector<int> in,
                               int pre_start, int in_start, int in_end) {
    if (in_start > in_end || pre_start > pre.size())
        return NULL;
    node *root = make_node(pre[pre_start]);
    int index = search(in, pre[pre_start], in_start, in_end);
    root->left = create_tree(pre, in, pre_start + 1, in_start,
                             index - 1);
    root->right = create_tree(pre, in, pre_start + index + 1 - in_start,
                              index + 1, in_end);
    return root;
}

void binary_tree::postorder(node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " ";
    }
}

void binary_tree::function() {
    int n;
    cin >> n;
    vector<int> pre(n);
    vector<int> in(n);
    for (int i = 0; i < n; i++)
        cin >> in[i];
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    node *root = create_tree(pre, in, 0, 0, in.size() - 1);
    postorder(root);
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
