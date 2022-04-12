#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
    node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};
node* insertnode(node* root,int x)
{
    if(root==NULL)
    {
        root=new node(x);
        return root;
    }
    if(x<=root->data)
    {
        root->left=insertnode(root->left,x);
    }
    else
    {
        root->right=insertnode(root->right,x);
    }
    return root;
}
void verticaltraversal(node* root)
{
    if(root==NULL)
    return;
    map<int,vector<int>>m;
    queue<pair<node*,int>>q;
    q.push({root,0});
    while(!q.empty())
    {
        pair<node*,int> p=q.front();
        q.pop();
        m[p.second].push_back(p.first->data);
        if(p.first->left!=NULL)
        {
            q.push({p.first->left,p.second-1});
        }
        if(p.first->right!=NULL)
        {
            q.push({p.first->right,p.second+1});
        }
    }
    for(auto it=m.begin();it!=m.end();it++)
    {
        for(int i=0;i<it->second.size();i++)
        {
            cout<<it->second[i]<<endl;
        }
    }
}
int main()
{
    node* root=NULL;
    root=insertnode(root,15);
root=insertnode(root,22);
root=insertnode(root,3);
root=insertnode(root,40);
root=insertnode(root,5);
root=insertnode(root,7);
root=insertnode(root,9);
    root=insertnode(root,4);
    verticaltraversal(root);
}