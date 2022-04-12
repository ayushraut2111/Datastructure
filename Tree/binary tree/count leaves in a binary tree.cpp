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
int countleaf(node* root)
{
    if(root==NULL)
  return 0;
  if(root->left==NULL&&root->right==NULL)
  return 1;
  int count=0;
  queue<node*>q;
  q.push(root);
  while(!q.empty())
  {
      node* temp=q.front();
      q.pop();
      if(temp->left==NULL&&temp->right==NULL)
      count++;
      if(temp->left!=NULL)
      q.push(temp->left);
      if(temp->right!=NULL)
      q.push(temp->right);
  }
  return count;
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
    cout<<countleaf(root);
}