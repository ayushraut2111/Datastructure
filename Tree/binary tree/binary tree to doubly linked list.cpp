#include<bits/stdc++.h>
using namespace std;
int res=0;
struct node
{
    int key;
    node* left;
    node* right;
    node(int x)
    {
        key=x;
        left=NULL;
        right=NULL;
    }
};
node* inserttree(node*root,int x)
{
    node* ptr=new node(x);
    if(root==NULL)
    {
        root=ptr;
        return root;
    }
    queue<node*>q;
    node* temp;
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->left==NULL)
        {
            temp->left=ptr;
            return root;
        }
        else
        q.push(temp->left);
        if(temp->right==NULL)
        {
            temp->right=ptr;
            return root;
        }
        else
        {
            q.push(temp->right);
        }
    }
}
node* btdll(node* root)
{

    if(root==NULL)
    return NULL;
    if(root->left==NULL&&root->right==NULL)
    return root;
    node* lh=btdll(root->left);
    node* rh=btdll(root->right);
    lh->right=root;
    root->left=lh;
    root->right=rh;
    rh->left=root;
    cout<<lh->key<<endl;
    return rh;
}
void printnode(node* root)
{
    node* temp=root;
    while(temp!=NULL)
    {
        cout<<temp->key<<endl;
        temp=temp->right;
    }
}
int main()
{
      node* root=NULL;
root=inserttree(root,1);
root=inserttree(root,2);
root=inserttree(root,3);
root=inserttree(root,4);
root=inserttree(root,5);
root=inserttree(root,6);
root=inserttree(root,7);
root=inserttree(root,8);
root=inserttree(root,9);
root=inserttree(root,10);
root=btdll(root);
printnode(root);
}