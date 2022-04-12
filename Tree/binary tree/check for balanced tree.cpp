#include<bits/stdc++.h>
using namespace std;
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
int treeheight(node* root)
{
    if(root==NULL)
    return 0;
    int leftheight=treeheight(root->left);
    int rightheight=treeheight(root->right);
    return max(leftheight,rightheight)+1;
}
bool balancetree(node* root)
{
    if(root==NULL)
    return true;
    int x=treeheight(root->left);
    int y=treeheight(root->right);
    if(balancetree(root->left)&&balancetree(root->right))
    {
        if(abs(x-y)<=1)
        {
            return true;
        }
        return false;
    }
    return false;
}
int balanceheighttree(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int x=balanceheighttree(root->left);
    int y=balanceheighttree(root->right);
    if(x==-1||y==-1)
    return -1;
    if(abs(x-y)>1)
    return -1;
    else
    {
        return max(x,y)+1;
    }
}
int main()
{
    node* root=NULL;
    root=new node(8);
    root->left=new node(4);
    root->right=new node(20);
    root->right->left=new node(13);
    root->right->right=new node(70);
    if(balanceheighttree(root)==-1)
    cout<<"no"<<endl;
    else
    cout<<"yes"<<endl;
}