#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class linked_list {
   public:
    void function();
    node *input();
    node *make_node(int);
    void insert(node *, int);
    void del(node *, int);
};

node *linked_list::make_node(int data) {
    node *tmp = new node;
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

void linked_list::insert(node *list, int data) {
    if (list != NULL) {
        if (list->next == NULL)
            list->next = make_node(data);
        else
            insert(list->next, data);
    }
}

node *linked_list::input() {
    int n;
    cin >> n;
    node *list = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        if (list == NULL)
            list = make_node(data);
        else
            insert(list, data);
    }
    return list;
}

void linked_list::del(node *list, int key) {
    while (list != NULL) {
        if (list->data == key) {
            node *tmp = list->next;
            list->data = list->next->data;
            list->next = list->next->next;
            free(tmp);
        } else {
            cout << list->data << " ";
            list = list->next;
        }
    }
}

void linked_list::function() {
    node *list = input();
    int key;
    cin >> key;
    del(list, key);
    cout << endl;
}

int main() {
    linked_list l;
    l.function();
    return 0;
}