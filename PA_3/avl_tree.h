#pragma once
#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <utility>
#include <sstream>
template<typename T>
struct AVLNode{
    AVLNode<T>* right;
    AVLNode<T>* left;
    T value;
    size_t height;

    AVLNode(const AVLNode& other): right(0), left(0), value(other.value), height(other.height){}
    AVLNode(const T& value): right(0), left(0), value(value), height(0){}
    AVLNode(const AVLNode* other): right(other->right), left(other->left), value(other->value), height(other->height){}
};

template <typename T>
class AVLTree {
    AVLNode<T>* root;

    public:
        AVLTree(): root(0){}

        AVLNode<T>* recursiveCopy(AVLNode<T>* other){
            if (other == 0){
                return 0;
            }
            AVLNode<T>* newAVLNode = new AVLNode<T>(*other);
            newAVLNode->left = recursiveCopy(other->left);
            newAVLNode->right = recursiveCopy(other->right);
            return newAVLNode;
        }

        AVLTree(const AVLTree& other): root(0){
            this->root = recursiveCopy(other.root);
        }

        AVLTree& operator=(const AVLTree& other){
            if (this != &other){
                if (this->root != 0){
                    recursiveDelete(root);
                    root = recursiveCopy(other.root);
                }
            }

            return *this;
        }

        void recursiveDelete(AVLNode<T>* other){
            if (other != 0){
                recursiveDelete(other->left);
                recursiveDelete(other->right);
                delete other;
                other = nullptr;
            }
            
        }

        ~AVLTree(){
            recursiveDelete(this->root);
        }

        void recursiveInsert(AVLNode<T>* Node, const T& object){
            if (Node == 0){
                AVLNode<T>* newAVLNode = new AVLNode(object);
                root = newAVLNode;
            }
            else if (Node->value > object){
                if (Node->left == 0){
                    AVLNode<T>* newAVLNode = new AVLNode(object);
                    Node->left = newAVLNode;
                }
                else{
                    recursiveInsert(Node->left, object);
                }
            }
            else if (Node->value < object){
                if (Node->right == 0){
                    AVLNode<T>* newAVLNode = new AVLNode(object);
                    Node->right = newAVLNode;
                }
                else{
                    recursiveInsert(Node->right, object);
                }
            }
        }

        void insert(const T& object){
            recursiveInsert(this->root, object);
        }

        void recursiveRemove(AVLNode<T>* prev, AVLNode<T>* helper, const T& object){
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

        void recursivePrint(const AVLNode<T>* Node, size_t offset, std::ostream& os) const{
            if (Node != 0){
                recursivePrint(Node->right, offset + 1, os);
                for (size_t i = 0; i < offset; i++){
                    os << "  ";
                }
                os << Node->value << std::endl;
                recursivePrint(Node->left, offset + 1, os);
            }
        }

        const T& find_min(){
            if (this->root == 0){
                throw std::invalid_argument("Tree is empty");
            }
            AVLNode<T>* helper = root;
            while (helper->left != 0){
                helper = helper->left;
            }

            return helper->value;
        }

        const T& find_max(){
            if (this->root == 0){
                throw std::invalid_argument("Tree is empty");
            }
            AVLNode<T>* helper = root;
            while (helper->right != 0){
                helper = helper->right;
            }

            return helper->value;
        }

        T deleteMax(AVLNode<T>* prev, AVLNode<T>* Node){
            AVLNode<T>* helper = Node;
            AVLNode<T>* helperPrev = prev;
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

        bool recursiveContains(AVLNode<T>* helper, const T& object){
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
