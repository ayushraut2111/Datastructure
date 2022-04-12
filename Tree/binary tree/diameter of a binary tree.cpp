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
int height(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int x=height(root->left);
    int y=height(root->right);
    return max(x,y)+1;
}
int diameter(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL&&root->right==NULL)
        return 1;
        int x=height(root->left);
        int y=height(root->right);
        int p=diameter(root->left);
        int q=diameter(root->right);
        int res=max(p,q);
        return max(res,x+y+1);
}
int dia(node* root)
{
     if(root==NULL)
    {
        return 0;
    }
        int x=dia(root->left);
        int y=dia(root->right);
        res=max(res,x+y+1);
        return max(x,y)+1;

}
int main()
{
    node* root=NULL;
    root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    cout<<res;

}