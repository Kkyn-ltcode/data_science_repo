#include <iostream>
#include <stack>
using namespace std;

struct node {
    char value;
    node *left;
    node *right;
};

class binary_tree {
   public:
    node *make_node(char);
    void make_tree(string);
    bool is_operator(char);
    void inorder(node *);
    void function();
};

node *binary_tree::make_node(char value) {
    node *new_node = new node;
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void binary_tree::inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->value;
        inorder(root->right);
    }
}

bool binary_tree::is_operator(char c) {
    if (c == '+' || c == '-' || c == '*' ||
        c == '/' || c == '^')
        return true;
    return false;
}

void binary_tree::make_tree(string s) {
    stack<node *> st;
    for (int i = 0; i < s.size(); i++) {
        if (is_operator(s[i])) {
            node *Operator = make_node(s[i]);
            node *Operant1 = st.top();
            st.pop();
            node *Operant2 = st.top();
            st.pop();
            Operator->right = Operant1;
            Operator->left = Operant2;
            st.push(Operator);
        } else
            st.push(make_node(s[i]));
    }
    inorder(st.top());
}

void binary_tree::function() {
    string s;
    cin >> s;
    make_tree(s);
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
