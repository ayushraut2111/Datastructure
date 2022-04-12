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
bool findpath(node* root,vector<node*>&v,int n)
{
    if(root==NULL)
    return false;
    v.push_back(root);
    if(root->key==n)
    return true;
    bool x=findpath(root->left,v,n);
    bool y=findpath(root->right,v,n);
    if(x==true||y==true)
    return true;
    v.pop_back();
    return false;
}
node* LCA(node* root,int a,int b)
{
    if(root==NULL)
    return NULL;
    vector<node*>v1,v2;
    bool x=findpath(root,v1,a);
    bool y=findpath(root,v2,b);
    if(x==false||y==false)
    return NULL;
    for(int i=0;i<v1.size()&&i<v2.size();i++)
    {
        if(v1[i+1]!=v2[i+1])
        return v1[i];
    }
    return NULL;
}
node* LCA1(node* root,int a,int b)
{
    if(root==NULL)
    return NULL;
    if(root->key==a||root->key==b)
    return root;
    node*llca=LCA1(root->left,a,b);
    node* rlca=LCA1(root->right,a,b);
    if(llca!=NULL&&rlca!=NULL)
    {
        return root;
    }
    if(llca!=NULL)
    return llca;
    else
    return rlca;
}
int main()
{
    node* root=NULL;
    root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    cout<<LCA1(root,30,50)->key;
}