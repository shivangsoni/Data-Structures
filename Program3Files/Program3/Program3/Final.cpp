#include<iostream>

using namespace std;

class AVLNode{
 public:
 int data;
 int height;
 AVLNode* left;
 AVLNode* right;
 AVLNode* parent;
 int balance;
 bool root;
 
 AVLNode(int dat){
   data = dat;
   height = 0;
   root = true;
   left = null;
   right = null;
   parent = null;
 }
 
 AVLNode* singleRightRotate(AVLNode* &t)
    {
        AVLNode* u = t->left;
        t->left = u->right;
        u->right = t;
        u->parent = t->parent;
        u->right->parent = t;
        t->parent = u;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(u->left), t->height)+1;
        return u;
   }

 AVLNode* singleLeftRotate(AVLNode* &t)
 {
        AVLNode* u = t->right;
        t->right = u->left;
        t->right->parent = t;
        u->left = t;
        u->parent = t->parent;
        t->parent = u;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(t->right), t->height)+1 ;
        return u;
 }


 AVLNode* doubleLeftRotate(AVLNode* &t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

 AVLNode* doubleRightRotate(AVLNode* &t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

 AVLNode* findMin(AVLNode* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }
 int height(){
       
 }
};
