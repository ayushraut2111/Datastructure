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
bool symmetric(node* root1,node* root2)
{
    if(root1==NULL&&root2==NULL)
    return true;
    if(root1->key==root2->key)
    {
        bool x=symmetric(root1->left,root2->right);
        bool y=symmetric(root1->right,root2->left);
        if(x&&y)
        return true;
    }
    return false;
}
bool issymmetric(node* root)
{
     if(root==NULL)
	    return true;
	    if(root->left==NULL&&root->right==NULL)
	    return true;
        return symmetric(root,root);
}
int main()
{
      node* root=NULL;
root=inserttree(root,2);
root=inserttree(root,1);
root=inserttree(root,2);
/*root=inserttree(root,4);
root=inserttree(root,5);
root=inserttree(root,6);
root=inserttree(root,7);
root=inserttree(root,8);
root=inserttree(root,9);
root=inserttree(root,10); */
cout<<issymmetric(root);
}