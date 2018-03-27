#include<iostream>
#include<stack>
using namespace std;

class BST
{
public:
    struct node
    {
        int data;
        node* left;
        node* right;
        int height;
    };

    node* root;
    long int array[10000];
    int index;
    void makeEmpty(node* t)
    {
        if(t == NULL)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }

    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->height = 0;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
        {
            t->left = insert(x, t->left);
            if(height(t->left) - height(t->right) == 2)
            {
                if(x < t->left->data)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if(x > t->data)
        {
            t->right = insert(x, t->right);
            if(height(t->right) - height(t->left) == 2)
            {
                if(x > t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }

        t->height = max(height(t->left), height(t->right))+1;
        return t;
    }

    node* singleRightRotate(node* &t)
    {
        node* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(u->left), t->height)+1;
        return u;
    }

    node* singleLeftRotate(node* &t)
    {
        node* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(t->right), t->height)+1 ;
        return u;
    }

    node* doubleLeftRotate(node* &t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    node* doubleRightRotate(node* &t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t)
    {
        node* temp;

        // Element not found
        if(t == NULL)
            return NULL;

        // Searching for element
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);

        // Element found
        // With 2 children
        else if(x == t->data && t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        // With one or zero child
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
        if(t == NULL)
            return t;

        t->height = max(height(t->left), height(t->right))+1;

        // If node is unbalanced
        // If left node is deleted, right case
        if(height(t->left) - height(t->right) == 2)
        {
            // right right case
            if(height(t->left->left) - height(t->left->right) == 1)
                return singleLeftRotate(t);
            // right left case
            else
                return doubleLeftRotate(t);
        }
        // If right node is deleted, left case
        else if(height(t->right) - height(t->left) == 2)
        {
            // left left case
            if(height(t->right->right) - height(t->right->left) == 1)
                return singleRightRotate(t);
            // left right case                return doubleRightRotate(t);
        }
        return t;
    }

    int height(node* t)
    {
        return (t == NULL ? -1 : t->height);
    }

    int getBalance(node* t)
    {
        if(t == NULL)
            return 0;
        else
            return -height(t->left) + height(t->right);
    }

    int size(node* t){
    if(t == NULL){
     return 0;
    }
     return (1+size(t->left)+size(t->right));
    }

    void inorder(node* t)
    {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

   void postorder(node* t){
      if(t!=NULL)
      {
        array[index++] = t->data;
        postorder(t->left);
        postorder(t->right);
      }
   }

   node* getParent(node* root, int child)
   {
      if(root->data == child){
        return NULL;
      }
      else
      {
       node* y = root;
       node* prev = NULL;
       while(child != y->data){
         prev = y;
         if(y->data > child){
            y = y->left;
         }
         else if(y->data < child){
            y = y->right;
         }
       }
       return prev;
      }
   }
//public:
   
    BST()
    {
        root = NULL;
        for(int i=0;i<10000;i++)
        {
          array[i] = 0;
        }
       index = 0;
    }

    void insert(int x)
    {
        root = insert(x, root);
    }

    void remove(int x)
    {
        root = remove(x, root);
    }


void iterativePreorder(node *root)
{
    // Base Case
    if (root == NULL)
       return;

    // Create an empty stack and push root to it
    stack<node *> nodeStack;
    nodeStack.push(root);

    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false)
    {
        // Pop the top item from stack and print it
        struct node *node = nodeStack.top();
        //printf ("%d ", node->data);
        array[index++]=node->data;
        nodeStack.pop();

        // Push right and left children of the popped node to stack
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}



    void display()
    {
        postorder(root);
        cout << endl;
    }
   
    int getP(int e){
      node* f= getParent(root,e);
       if(f != NULL)
        return f->data;

    }
  
    void DeleteMin(){
      node* o = findMin(root);
      remove(o->data);
    }

    node* search(int f,node* t){
         if(t->data == f)
          return t;
         else if(t->data<f)
          return search(f,t->right);
         else if(t->data>f)
          return search(f,t->left);
        //return NULL;
    }
 

    int hsearch(int a){
       node* d = search(a,root);
       return height(d);
    }
    int nunodes(){
     return size(root);
    }
  
    int Balancefactor(int f){
     node * qq = search(f,root);
     return getBalance(qq);
    }
    int ssize(){
      return size(root); 
    }
};
/*
int main()
{
    BST t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.insert(40);
    t.insert(50);
    
    t.remove(30);
//    t.display();
    //t.getP(25);
    t.DeleteMin();
    t.display();
    //t.display();
    int h = t.size(t.root);
   // cout<<h<<endl;
    for(int i=0;i<t.index;i++){
       cout<<t.array[i]<<"\t";
    }
   int bf=t.Balancefactor(t.array[0]);
   cout<<bf;
   int qw = t.hsearch(t.array[0]);  
   cout<<endl<<qw;
   qw = t.ssize();
   cout<<endl<<"The size is"<<qw;
}*/
