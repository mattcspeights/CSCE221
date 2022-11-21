#pragma once
template<typename T>
struct Node{
    Node* right, left;
    T value;

    Node(const Node& other): right(0), left(0), value(other.value){}
    Node(T value): right(0), left(0), value(value){}
    Node(const Node* other): righ
};

template <typename T>
class BinarySearchTree {
    Node<T>* root;

    public:
        BinarySearchTree(): root(0){}

        Node<T>* recursiveCopy(Node<T>& other){
            if (other == 0){
                return 0;
            }
            Node<T>* newNode = new Node<T>(other);
            newNode->left = recursiveCopy(other.left);
            newNode->right = recursiveCopy(other.right);
            return newNode;
        }

        BinarySearchTree(const BinarySearchTree& other): root(0){
            this->root = recursiveCopy(other.root);
        }

        BinarySearchTree& operator=(const BinarySearchTree& other){
            if (this != &other){
                if (this->root != 0){

                }
            }

            return *this;
        }

        void recursiveDelete(Node<T>* other){
            if (other != 0){
                recursivedelete(other->left);
                recursivedelete(other->right);
                delete other;
                other = nullptr;
            }
            
        }

        ~BinarySearchTree(){
            recursiveDelete(this->root);
        }

        void recursiveInsert(Node<T>* node, const T& object){
            if (node->value > object){
                if (node->left == 0){
                    Node<T>* newNode(object);
                    node->left = newNode;
                }
                else{
                    recursiveInsert(node->left, object);
                }
            }
            else if (node->value < object){
                if (node->right == 0){
                    Node<T>* newNode(object);
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

        Node<T>* replaceNodeLeft(Node<T>* node){
            Node<T>* helper = node->left;
            Node<T>* prev = 0;
            while (helper->right != 0){
                prev = helper;
                helper = helper->right;
            }
            prev->right = 0;
            return helper;
        }

        void recursiveRemove(Node<T>* prev, Node<T>* node, const T& object){
            if (node == 0){
                continue;
            }
            else if (node->value == object){
                Node<T>* helper = node;
                Node<T>* prev = prev;
                // cases for removal
                // node has no children
                // node has only right child
                // node has two children
                if (node->left != 0){

                }
                else if (node->right != 0){

                }
                else{
                    delete node;
                }
            }
            else{
                recursiveRemove(node, node->left, object);
                recursiveRemove(node, node->right, object);
            }
        }


};
