#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

class AVLTree
{
    struct Node
    {
        int key;
        int height;
        Node* left;
        Node* right;

        explicit Node(int value)
            : key(value), height(1), left(nullptr), right(nullptr)
        {
        }
    };

    Node* root = nullptr;

    int getHeight(Node* node) const
    {
        return node == nullptr ? 0 : node->height;
    }

    int getBalance(Node* node) const
    {
        return node == nullptr ? 0 : getHeight(node->left) - getHeight(node->right);
    }

    void updateHeight(Node* node)
    {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }

    Node* rotateRight(Node* top)
    {
        Node* newTop = top->left;
        Node* transferredSubtree = newTop->right;

        newTop->right = top;
        top->left = transferredSubtree;

        updateHeight(top);
        updateHeight(newTop);
        return newTop;
    }

    Node* rotateLeft(Node* top)
    {
        Node* newTop = top->right;
        Node* transferredSubtree = newTop->left;

        newTop->left = top;
        top->right = transferredSubtree;

        updateHeight(top);
        updateHeight(newTop);
        return newTop;
    }

    Node* insert(Node* node, int key, bool& inserted)
    {
        if (node == nullptr)
        {
            inserted = true;
            return new Node(key);
        }

        if (key < node->key)
        {
            node->left = insert(node->left, key, inserted);
        }
        else if (key > node->key)
        {
            node->right = insert(node->right, key, inserted);
        }
        else
        {
            return node;
        }

        updateHeight(node);
        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
        {
            return rotateRight(node);
        }
        if (balance < -1 && key > node->right->key)
        {
            return rotateLeft(node);
        }
        if (balance > 1 && key > node->left->key)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && key < node->right->key)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    bool search(Node* node, int key) const
    {
        while (node != nullptr)
        {
            if (key == node->key)
            {
                return true;
            }
            node = key < node->key ? node->left : node->right;
        }
        return false;
    }

    void destroy(Node* node)
    {
        if (node == nullptr)
        {
            return;
        }
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    AVLTree() = default;
    AVLTree(const AVLTree&) = delete;
    AVLTree& operator=(const AVLTree&) = delete;

    ~AVLTree()
    {
        destroy(root);
    }

    bool insert(int key)
    {
        bool inserted = false;
        root = insert(root, key, inserted);
        return inserted;
    }

    bool search(int key) const
    {
        return search(root, key);
    }
};

int main()
{
    AVLTree tree;

    while (true)
    {
        cout << "\nAVL Tree Menu\n"
             << "1. Insert a key\n"
             << "2. Search for a key\n"
             << "0. Exit\n"
             << "Enter your choice: ";

        int choice;
        if (!(cin >> choice))
        {
            if (cin.eof())
            {
                break;
            }
            cout << "Invalid input. Enter a menu number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 0)
        {
            break;
        }

        if (choice != 1 && choice != 2)
        {
            cout << "Invalid choice. Select 1, 2, or 0.\n";
            continue;
        }

        int key;
        cout << "Enter the key: ";
        if (!(cin >> key))
        {
            if (cin.eof())
            {
                break;
            }
            cout << "Invalid input. Enter an integer key.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1)
        {
            if (tree.insert(key))
            {
                cout << key << " inserted.\n";
            }
            else
            {
                cout << key << " already333 exists; this is by multiple line cursor duplicate keys are ignored.\n";
            }
        }
        else if (tree.search(key))
        {
            cout << key << " is in the this is by multiple line cursor tree.\n";
        }
        else
        {
            cout << key << " is not in the this is by multiple line cursor tree.\n";
        }
    }

    return 0;
}
