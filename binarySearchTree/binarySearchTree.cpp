#include <iostream>
using namespace std;

struct node {
    int key;
    struct node* left, * right;
};

struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key == node->key)
        return node;
    else
        node->right = insert(node->right, key);

    return node;
}

struct node* minValueNode(struct node* node) {
    struct node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Удаление узла
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Если у узла один дочерний элемент или их нет
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);

        root->key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

node* find(node* r, float d)
{
    if (r == NULL) return NULL;

    if (r->key == d) return r;

    if (d <= r->key)
    {
        if (r->left != NULL) return find(r->left, d); // рекурсивный поиск влево
        else return NULL;
    }
    else
    {
        if (r->right) return find(r->right, d);// рекурсивный поиск вправо
        else return NULL;
    }
}

void printBT(const string& prefix, const node* node, bool isLeft)
{
    if (node != nullptr)
    {
        cout << prefix;

        cout << (isLeft ? "L---" : "R---");

        // print the value of the node
        cout << node->key << endl;

        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "|   " : "    "), node->left, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

int main() {
    struct node* root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 44);
    root = insert(root, 18);
    root = insert(root, 13);
    root = insert(root, 43);

    cout << "List: " << endl;
    printBT("", root, false);

    if (find(root, 10)) cout << find(root, 10)->key << endl;
    else cout << "such element doesn't exist" << endl;

    cout << "\nAfter removing node with key - 10\n" << endl;
    root = deleteNode(root, 10);
    root = deleteNode(root, 3);

    if (find(root, 10)) cout << find(root, 10)->key << endl;
    else cout << "such element doesn't exist" << endl;

    cout << "List: " << endl;
    printBT("", root, false);
}