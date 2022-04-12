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
void printtree(node* root)
{
    if(root==NULL)
    {
        cout<<"empty"<<endl;
        return ;
    }
    queue<node*>q;
    node* temp;
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        cout<<temp->key<<endl;
        if(temp->left!=NULL)
        q.push(temp->left);
        if(temp->right!=NULL)
        q.push(temp->right);
    }
}
int maxtree(node* root)
{
    if(root==NULL)
    return 0;
    int z=root->key;
    int x=maxtree(root->left);
    int y=maxtree(root->right);
    int m=max(x,y);
    return max(z,m);
}
int main()
{
    node* root=NULL;
root=inserttree(root,10);
root=inserttree(root,20);
root=inserttree(root,30);
root=inserttree(root,400);
root=inserttree(root,50);
root=inserttree(root,70);
cout<<maxtree(root);

}