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
    vector<int> input();
    node *construct_BST(vector<int>);
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

vector<int> binary_tree::input() {
    int n;
    cin >> n;
    vector<int> pre_order(n);
    for (int i = 0; i < n; i++)
        cin >> pre_order[i];
    return pre_order;
}

node *binary_tree::construct_BST(vector<int> pre_order) {
    if (pre_order.size() == 0)
        return NULL;
    node *root = make_node(pre_order[0]);
    vector<int> left_sub, right_sub;
    for (int i = 1; i < pre_order.size(); i++){
        if (pre_order[i] < pre_order[0])
            left_sub.push_back(pre_order[i]);
        else if (pre_order[i] > pre_order[0])
            right_sub.push_back(pre_order[i]);
    }
    root->left = construct_BST(left_sub);
    root->right = construct_BST(right_sub);
    return root;
}

void binary_tree::post_order(node *root){
    if (root != NULL){
        post_order(root->left);
        post_order(root->right);
        cout << root->value << " ";
    }
}

void binary_tree::function() {
    vector<int> pre_order = input();
    node * root =construct_BST(pre_order);
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