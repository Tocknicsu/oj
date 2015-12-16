
#include<iostream>
#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

class node{
    public:
        node();
        node(int value);
        ~node();
        friend void gothrough(node *p);
    private:
        node *left, *right; // the left child and the right child pointer
        int number; // record the node's number
        int is_threadl, is_threadr; //the flag to record whether the pointer is a thread or not
        friend class op_tree_totum;//you could access all valuables in class op_tree_totum
};
//ctor
node::node(){
    left = right = NULL;
    is_threadl = 1;
    is_threadr = 1;
}
//ctor
node::node(int value){
    number = value;
    left = right = NULL;
    is_threadl = 1;
    is_threadr = 1;
}
//dtor
node::~node(){
}
class op_tree_totum{
    public:
        op_tree_totum();
        ~op_tree_totum();
        void insertion(int s);
        void deletion(int s);
        void inorder_run();
        void reverseorder_run();
        int size();
    private:
        node *root, *head, *tail;
        int num;//caculate how many nodes in the totum
};

//ctor
op_tree_totum::op_tree_totum(){
    head = new node();
    tail = new node();
    head->right = tail; //initialize the head node to connect to the tail node
    tail->left = head;
    root = NULL;
    num = 0;
}

//dtor
op_tree_totum::~op_tree_totum(){
    node *p = root;
    gothrough(p); // walk through the tree from the root node to delete all nodes connected
    num = 0;
    if (head != NULL)delete head;
    if (tail != NULL)delete tail;
}

void gothrough(node *p){
    if (p->left) gothrough(p->left);
    if (p->right) gothrough(p->right);
    if (p->left == NULL && p->right == NULL)delete p;
}

void op_tree_totum::insertion(int s){
    if(root == NULL){
        root = new node(s);
        root->right = tail;
        tail->left = root;
        root->left = head;
        head->right =root;
    } else {
        node *now = root, *parent;
        while(now != NULL){
            parent = now;
            now = s > now->number ? (now->is_threadr ? NULL : now->right) : (now->is_threadl ? NULL : now->left);
        }
        now = new node(s);
        if(now->number > parent->number){
            now->right = parent->right;
            if(parent->right == tail)
                tail->left = now;
            now->left = parent;
            parent->right = now;
            parent->is_threadr = 0;
        } else {
            now->left = parent->left;
            if(parent->left == head)
                head->right = now;
            now->right = parent;
            parent->left = now;
            parent->is_threadl = 0;
        }
    }
}

void op_tree_totum::deletion(int s){
    node *now = root;
    while(now != NULL && now->number != s){
        now = s > now->number ? (now->is_threadr ? NULL : now->right) : (now->is_threadl ? NULL : now->left);
    }
    if(now == NULL) return;
    while(now->is_threadl == 0 || now->is_threadr == 0){
        node *tmp;
        if(now->is_threadl == 0){
            tmp = now->left;
            while(tmp->is_threadr == 0) tmp = tmp->right;
        } else {
            tmp = now->right;
            while(tmp->is_threadl == 0) tmp = tmp->left;
        }
        now->number = tmp->number;
        now = tmp;
    }
    if(now == root){
        root = NULL;
        head->right = tail;
        tail->left = head;
    } else if(now->left->right == now && now->left->is_threadr == 0){
        if(now->right == tail)
            tail->left = now->left;
        now->left->right = now->right;
        now->left->is_threadr = 1;
    } else {
        if(now->left == head)
            head->right = now->right;
        now->right->left = now->left;
        now->right->is_threadl = 1;
    }
    delete now;
}

void op_tree_totum::inorder_run(){
    node *now = head->right;
    while(now != tail){
        cout << now->number << ' ';
        if(now->is_threadr){
            now = now->right;
        } else {
            now = now->right;
            while(now->is_threadl == 0)
                now = now->left;
        }
    }
    cout << endl;
}


void op_tree_totum::reverseorder_run(){
    node *now = tail->left;
    while(now != head){
        cout << now->number << ' ';
        if(now->is_threadl){
            now = now->left;
        } else {
            now = now->left;
            while(now->is_threadr == 0)
                now = now->right;
        }
    }
    cout << endl;
}

int op_tree_totum::size(){
    return num;
}

int detect_number(char* buffer){//detect the number in the input buffer	
	int sum = 0;
	for (int i = 2; buffer[i] >= '0' && buffer[i] <= '9'; i++){
		sum = sum * 10 + buffer[i] - '0';
	}
	return sum;
}


    int main(int argc,char* argv[])
    {
        op_tree_totum *optt = new op_tree_totum();

        char buffer[100];
        while (fgets(buffer, 100, stdin) != NULL){
            switch (buffer[0]){
                int num;
                case 'I':// insert the node
                    num = detect_number(buffer);
                    optt->insertion(num);
                    break;
                case 'D':// delete the node
                    num = detect_number(buffer);
                    optt->deletion(num);
                    break;
                case 'C':// inorder path
                    cout << "Change! Change myself into a cute mahou shoujo!!\n";
                    cout << "The path: ";
                    optt->inorder_run();
                    cout << endl;
                    break;
                case 'B':// reverseorder path
                    cout << "Back! Back to the original life!!\n";
                    cout << "The reverse path: ";
                    optt->reverseorder_run();
                    cout << endl;
                    break;
            }
        }
        return 0;
    }

