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
bool checkbst(node* root,int max,int min)
{
    if(root==NULL)
    return true;
    if(root->data>min&&root->data<max)
    {
        bool x=checkbst(root->left,root->data,min);
        bool y=checkbst(root->right,max,root->data);
        if(x&&y)
        return true;
        return false;
    }   
    return false;
}
int main()
{
    node* root=NULL;
    root=new node(13);
    root->left=new node(1);
    root->right=new node(16);

if(checkbst(root,INT_MAX,INT_MIN)==false)
cout<<"no";
else
cout<<"yes";
}