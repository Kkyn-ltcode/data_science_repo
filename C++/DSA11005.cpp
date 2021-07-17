#include <iostream>
#include <unordered_map>
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
    node *create_tree(vector<int>, vector<int>,
                      unordered_map<int, int>, int, int);
    void post_order(node *);
    void function();
};

node *binary_tree::make_node(int data) {
    node *new_node = new node;
    new_node->value = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *binary_tree::create_tree(vector<int> inorder,
                               vector<int> level_order,
                               unordered_map<int, int> un,
                               int in_start, int in_end) {
    if (in_start > in_end)
        return NULL;
    int index = 0;
    int min_level = INT_MAX;
    for (int i = in_start; i <= in_end; i++) {
        if (un[inorder[i]] < min_level) {
            index = i;
            min_level = un[inorder[i]];
        }
    }
    node *root = make_node(inorder[index]);
    if (in_start == in_end)
        return root;
    root->left = create_tree(inorder, level_order, un, in_start, index - 1);
    root->right = create_tree(inorder, level_order, un, index + 1, in_end);
    return root;
}

void binary_tree::post_order(node *root) {
    if (root != NULL) {
        post_order(root->left);
        post_order(root->right);
        cout << root->value << " ";
    }
}

void binary_tree::function() {
    int n;
    cin >> n;
    vector<int> level_order(n);
    vector<int> inorder(n);
    unordered_map<int, int> un;
    for (int i = 0; i < n; i++)
        cin >> inorder[i];
    for (int i = 0; i < n; i++) {
        cin >> level_order[i];
        un[level_order[i]] = i;
    }
    node *root = create_tree(inorder, level_order,
                             un, 0, n - 1);
    post_order(root);
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
