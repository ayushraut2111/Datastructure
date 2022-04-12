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
void leftprint(node* root)
{
    if(root==NULL)
    return ;
    queue<node*>q;
    q.push(root);
    node* temp;
    while(!q.empty())
    {
       int size=q.size();
       for(int i=0;i<size;i++)
       {
           temp=q.front();
           q.pop();
           if(i==0)
           cout<<temp->key<<endl;
           if(temp->left!=NULL)
           q.push(temp->left);
           if(temp->right!=NULL)
           q.push(temp->right);
       }
    }
}
int main()
{
    node* root=NULL;
root=inserttree(root,10);
root=inserttree(root,20);
root=inserttree(root,30);
root=inserttree(root,40);
root=inserttree(root,50);
root=inserttree(root,60);
leftprint(root);
}