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
node* floor(node* root,int x)
{
    if(root==NULL)
    return NULL;
    if(root->data==x)
    return root;
    if(x<root->data)
    return floor(root->left,x);
    if(x>root->data)
    {
        node* temp=floor(root->right,x);
        if(x>=temp->data)
        return temp;
    }
    return root;
}
node* flooriterator(node* root,int x)
{
    if(root==NULL)
    return NULL;
    node* temp=root;
    node* ptr=NULL;
    while(temp!=NULL)
    {
        if(temp->data==x)
        return root;
        else if(x<temp->data)
        {
            temp=temp->left;
        }
        else
        {
            ptr=temp;
            temp=temp->right;
        }
    }
    return ptr;
}
int main()
{
    node* root=NULL;
    root=insert(root,89);
root=insert(root,2);
root=insert(root,3);
root=insert(root,1);
    root=insert(root,5);
    root=insert(root,6);
    node* ptr=floor(root,90);
    cout<<ptr->data;
}