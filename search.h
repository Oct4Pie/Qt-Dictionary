#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
class Node {
   public:
    T value;
    Node<T>* left;
    Node<T>* right;
    Node<T>* dict;
    Node(T data, Node<T>* l = 0, Node<T>* r = 0, Node<T>* dict = 0) {
        this->value = data;
        this->left = l;
        this->right = r;
        this->dict = dict;
    }
};

template <typename T>
class BST {
   public:
    Node<T>* root;
    Node<T>** a;
    int count;
    int size;
    BST() {
        count = 0;
        root = 0;
        size = 100;
        a = (Node<T>**)malloc(sizeof(Node<T>*) * size);
    }

    Node<T>* _root() {
        return this->root;
    }

    Node<T>* add(T data, Node<T>* l = 0) {
        Node<T>* node = new Node<T>(data);
        node->dict = l;
        if (count >= size) {
            a = (Node<T>**)realloc(a, (count + 100) * sizeof(Node<T>*));
            size = count + 100;
        }
        a[count++] = node;
        if (root == 0) {
            root = node;
            return root;
        }
        Node<T>* c = root;
        while (c) {
            if (c->value == data) {
                return (Node<T>*)NULL;
            }
            if (c->value < data) {
                if (c->right == 0) {
                    c->right = node;
                    return node;
                }
                c = c->right;
                continue;
            }
            if (c->value > data) {
                if (c->left == 0) {
                    c->left = node;
                    return node;
                }
                c = c->left;
            }
        }
        return (Node<T>*)NULL;
    }

    Node<T>** nodes() {
        return a;
    }

    Node<T>* find(T data) {
        Node<T>* n = root;
        while (n) {
            if (data > n->value) {
                n = n->right;
                continue;
            }
            if (data < n->value) {
                n = n->left;
                continue;
            }
            return n;
        }
        return n;
    }

    //    private:
    //     Node<T>* root;
};
