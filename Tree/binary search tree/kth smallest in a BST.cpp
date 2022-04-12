#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    int lcount;
    node* left;
    node* right;
    node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
        lcount=0;
    }
};
node* insertnode(node* root,int x)
{
    if(root==NULL)
    {
        root=new node(x);
        return root;
    }
    if(x<=root->data)
    {
        root->lcount++;
        root->left=insertnode(root->left,x);
    }
    else
    root->right=insertnode(root->right,x);
    return root;
    
}
void printnode(node* root)
{
    if(root==NULL)
    return;
    printnode(root->left);
    cout<<root->data<<endl;
    printnode(root->right);
}
node* kthelement(node* root,int k)
{
    if(root==NULL)
    return NULL;
    int count=root->lcount+1;
    if(count==k)
    return root;
    if(k<count)
    {
        kthelement(root->left,k);
    }
    else
    kthelement(root->right,k-count);
}
node* successor(node* root)
{
    if(root==NULL)
    return NULL;
    root=root->right;
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
node* deletenode(node* root,int x)
{
    if(root==NULL)
    return root;
    if(x<root->data)
    {
        root->left=deletenode(root->left,x);
        root->lcount--;
    }
    else if(x>root->data)
    root->right=deletenode(root->right,x);
    else
    {
        if(root->left==NULL&&root->right==NULL)
        return NULL;
        if(root->left==NULL)
        return root->right;
        if(root->right==NULL)
        return root->left;
        node* ptr=successor(root);
        root->data=ptr->data;
        root->right=deletenode(root->right,ptr->data);
        return root;
    }
}
int main()
{
    node* root=NULL;
    root=insertnode(root,15);
root=insertnode(root,22);
root=insertnode(root,3);
root=insertnode(root,40);
root=insertnode(root,5);
root=insertnode(root,7);
root=insertnode(root,9);
    root=insertnode(root,4);
    root=deletenode(root,40);
  printnode(root);
   node* temp=kthelement(root,5);
   cout<<temp->data;
}