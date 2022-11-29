#pragma once
#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <utility>
#include <sstream>
template<typename T>
struct Node{
    Node<T>* right;
    Node<T>* left;
    T value;

    Node(const Node& other): right(0), left(0), value(other.value){}
    Node(const T& value): right(0), left(0), value(value){}
    Node(const Node* other): right(other->right), left(other->left), value(other->value){}
};

template <typename T>
class BinarySearchTree {
    Node<T>* root;

    public:
        BinarySearchTree(): root(0){}

        Node<T>* recursiveCopy(Node<T>* other){
            if (other == 0){
                return 0;
            }
            Node<T>* newNode = new Node<T>(*other);
            newNode->left = recursiveCopy(other->left);
            newNode->right = recursiveCopy(other->right);
            return newNode;
        }

        BinarySearchTree(const BinarySearchTree& other): root(0){
            this->root = recursiveCopy(other.root);
        }

        BinarySearchTree& operator=(const BinarySearchTree& other){
            if (this != &other){
                if (this->root != 0){
                    recursiveDelete(root);
                    root = recursiveCopy(other.root);
                }
            }

            return *this;
        }

        void recursiveDelete(Node<T>* other){
            if (other != 0){
                recursiveDelete(other->left);
                recursiveDelete(other->right);
                delete other;
                other = nullptr;
            }
            
        }

        void makeEmpty(){
            recursiveDelete(this->root);
        }

        ~BinarySearchTree(){
            recursiveDelete(this->root);
        }

        void recursiveInsert(Node<T>* node, const T& object){
            if (node == 0){
                Node<T>* newNode = new Node(object);
                root = newNode;
            }
            else if (node->value > object){
                if (node->left == 0){
                    Node<T>* newNode = new Node(object);
                    node->left = newNode;
                }
                else{
                    recursiveInsert(node->left, object);
                }
            }
            else if (node->value < object){
                if (node->right == 0){
                    Node<T>* newNode = new Node(object);
                    node->right = newNode;
                }
                else{
                    recursiveInsert(node->right, object);
                }
            }
        }

        void insert(const T& object){
            recursiveInsert(this->root, object);
        }

        void recursiveRemove(Node<T>* prev, Node<T>* helper, const T& object){
            if (helper != 0){
                if (helper->value == object){
                    if (prev == 0){
                        if (helper->left != 0){
                            helper->value = deleteMax(helper, helper->left);
                        }
                        else if (helper->right != 0){
                            root = helper->right;
                            delete helper;
                        }
                        else{
                            root = 0;
                            delete helper;
                        }
                    }
                    else{
                        if (helper->left != 0){
                            helper->value = deleteMax(helper, helper->left);
                        }
                        else if (helper->right != 0){
                            if (prev->left == helper){
                                prev->left = helper->right;
                            }
                            else{
                                prev->right = helper->right;
                            }
                            delete helper;
                        }
                        else{
                            if (prev->left == helper){
                                prev->left = 0;
                            }
                            else{
                                prev->right = 0;
                            }
                            delete helper;
                        }
                    }
                    
                }
                else{
                    recursiveRemove(helper, helper->left, object);
                    recursiveRemove(helper, helper->right, object);
                }
            }
        }

        void remove(const T& object){
            recursiveRemove(0, root, object);
        }

        void print_tree(std::ostream& os = std::cout) const{
            if (this->root == 0){
                os << "<empty>\n";
            }
            recursivePrint(root, 0, os);
        }

        void recursivePrint(const Node<T>* node, size_t offset, std::ostream& os) const{
            if (node != 0){
                recursivePrint(node->right, offset + 1, os);
                for (size_t i = 0; i < offset; i++){
                    os << "  ";
                }
                os << node->value << std::endl;
                recursivePrint(node->left, offset + 1, os);
            }
        }

        const T& find_min(){
            if (this->root == 0){
                throw std::invalid_argument("Tree is empty");
            }
            Node<T>* helper = root;
            while (helper->left != 0){
                helper = helper->left;
            }

            return helper->value;
        }

        const T& find_max(){
            if (this->root == 0){
                throw std::invalid_argument("Tree is empty");
            }
            Node<T>* helper = root;
            while (helper->right != 0){
                helper = helper->right;
            }

            return helper->value;
        }

        T deleteMax(Node<T>* prev, Node<T>* node){
            Node<T>* helper = node;
            Node<T>* helperPrev = prev;
            while (helper->right != 0){
                helperPrev = helper;
                helper = helper->right;
            }

            T helperValue = helper->value;
            if (helperPrev != prev){
                helperPrev->right = 0;
            }
            else{
                helperPrev->left = 0;
            }
            delete helper;
            return helperValue;
        }

        bool recursiveContains(Node<T>* helper, const T& object){
            if (helper == 0){
                return false;
            }
            else if (helper->value == object){
                return true;
            }
            else{
                if (recursiveContains(helper->left, object)){
                    return true;
                }
                if (recursiveContains(helper->right, object)){
                    return true;
                }
            }
            return false;
        }

        bool contains(const T& object){
            return recursiveContains(root, object);
        }



};
