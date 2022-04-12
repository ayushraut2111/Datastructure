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
bool childsum(node* root)
{
    if(root==NULL)
    return true; 
if(root->left==NULL&&root->right==NULL)
return true;
bool y=childsum(root->left);
bool z=childsum(root->right);
if(y&&z)
{
    if(root->left->key+root->right->key==root->key)
    return true;
    return false;
}
return false;

}
int main()
{
    node* root=NULL;
root=inserttree(root,20);
root=inserttree(root,8);
root=inserttree(root,12);
root=inserttree(root,3);
root=inserttree(root,5);
if(childsum(root)==true)
cout<<"yes";
else
cout<<"no";

}