#include <iostream>

// 定义红黑树节点颜色
enum class Color { RED, BLACK };

// 定义红黑树节点结构
template <typename T>
struct RBNode {
    T data;
    RBNode* left;
    RBNode* right;
    RBNode* parent;
    Color color;

    RBNode(T value) : data(value), left(nullptr), right(nullptr), parent(nullptr), color(Color::RED) {}
};

// 定义红黑树类
template <typename T>
class RedBlackTree {
private:
    RBNode<T>* root;
    RBNode<T>* NIL;

    // 左旋操作
    void leftRotate(RBNode<T>* x) {
        RBNode<T>* y = x->right;
        x->right = y->left;
        if (y->left != NIL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == NIL) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    // 右旋操作
    void rightRotate(RBNode<T>* y) {
        RBNode<T>* x = y->left;
        y->left = x->right;
        if (x->right != NIL) {
            x->right->parent = y;
        }
        x->parent = y->parent;
        if (y->parent == NIL) {
            root = x;
        } else if (y == y->parent->right) {
            y->parent->right = x;
        } else {
            y->parent->left = x;
        }
        x->right = y;
        y->parent = x;
    }

    // 插入修复
    void insertFixup(RBNode<T>* z) {
        while (z->parent->color == Color::RED) {
            if (z->parent == z->parent->parent->left) {
                RBNode<T>* y = z->parent->parent->right;
                if (y->color == Color::RED) {
                    z->parent->color = Color::BLACK;
                    y->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    rightRotate(z->parent->parent);
                }
            } else {
                RBNode<T>* y = z->parent->parent->left;
                if (y->color == Color::RED) {
                    z->parent->color = Color::BLACK;
                    y->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = Color::BLACK;
    }

    // 插入节点
    void insert(RBNode<T>* z) {
        RBNode<T>* y = NIL;
        RBNode<T>* x = root;

        while (x != NIL) {
            y = x;
            if (z->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        z->parent = y;
        if (y == NIL) {
            root = z;
        } else if (z->data < y->data) {
            y->left = z;
        } else {
            y->right = z;
        }

        z->left = NIL;
        z->right = NIL;
        z->color = Color::RED;

        insertFixup(z);
    }

    // 中序遍历
    void inorderTraversal(RBNode<T>* node) {
        if (node != NIL) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    RedBlackTree() {
        NIL = new RBNode<T>(T());
        NIL->color = Color::BLACK;
        root = NIL;
    }

    ~RedBlackTree() {
        // 实现析构函数，释放所有节点内存
    }

    // 对外提供的插入接口
    void insert(T value) {
        RBNode<T>* newNode = new RBNode<T>(value);
        insert(newNode);
    }

    // 对外提供的中序遍历接口
    void inorder() {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    RedBlackTree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    std::cout << "Inorder traversal of the red-black tree: ";
    tree.inorder();
    getchar();
    return 0;
}    