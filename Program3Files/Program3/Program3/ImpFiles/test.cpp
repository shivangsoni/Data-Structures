#include<iostream>
#include "list.h"
#include "BalanceFactor.h"

using namespace std;

int main(){
 AVLTree<int> a = new AVLTree<int>();
 a.Insert(10);
 a.Insert(20);
 a.Insert(30);
 a.PrintBreadthSearchFirst();
}
