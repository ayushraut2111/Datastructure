#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
    node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};
node* insert(node* root,int x)
{
    if(root==NULL)
    {
        root=new node(x);
        return root;
    }
    if(x<=root->data)
    {
        root->left=insert(root->left,x);
    }
    else
    {
        root->right=insert(root->right,x);
    }
    return root;
}
node* ceiling(node* root,int x)
{
    if(root==NULL)
    return root;
    if(root->data==x)
    return root;
    if(x>root->data)
    return ceiling(root->right,x);
    else
    {
        node* res=ceiling(root->left,x);
        if(x<res->data)
        return res;
        return root;
    }
}