/*
Largest Independent Set in a tree
*/

#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};
int LISS(struct Node *root);

int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout<<LISS(root)<<endl;
  }
  return 0;
}


int LISS(struct Node *root)
{
    if(root == NULL)
        return 0;
    
    int size_ex = LISS(root->left)+LISS(root->right);
    int size_inc = 1;
    
    if(root->left)
        size_inc += LISS(root->left->left)+LISS(root->left->right);
    if(root->right)
        size_inc += LISS(root->right->left)+LISS(root->right->right);
    
    return size_ex>size_inc?size_ex:size_inc;
}   