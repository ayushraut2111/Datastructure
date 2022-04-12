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
int maxwidth(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    queue<node*>q;
    q.push(root);
    int res=0;
    while(!q.empty())
    {
        int size=q.size();
        res=max(res,size);
        for(int i=0;i<size;i++)
        {
            node* temp=q.front();
            q.pop();
            if(temp->left!=NULL)
            q.push(temp->left);
            if(temp->right!=NULL)
            q.push(temp->right);
        }
    }
    return res;
}
int main()
{
     node* root=NULL;
    root=new node(8);
    root->left=new node(4);
    root->right=new node(20);
    root->right->left=new node(13);
    root->right->right=new node(70);
    cout<<maxwidth(root)<<endl;
}
