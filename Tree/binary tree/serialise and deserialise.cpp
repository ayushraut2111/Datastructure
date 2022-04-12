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
void levelprint(node* root)
{
    if(root==NULL)
    return;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        cout<<temp->key<<endl;
        q.pop();
        if(temp->left!=NULL)
        q.push(temp->left);
        if(temp->right!=NULL)
        q.push(temp->right);

    }
}
void serialise(node* root,vector<int>&v)
{
    if(root==NULL)
    {
        v.push_back(NULL);
        return ;
    }
    v.push_back(root->key);
    serialise(root->left,v);
    serialise(root->right,v);
}
node* deserialise(vector<int>&v)
{
    if(v.empty())
    {
        return NULL;
    }
    int val=v.back();
    v.pop_back();
    if(val==-1)
    return NULL;
    node* root=new node(val);
    root->left=deserialise(v);
    root->right=deserialise(v);
    return root;
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
    vector<int>v;
    serialise(root,v);
    //levelprint(root);
   for(int i=0;i<v.size();i++)
    cout<<v[i]<<endl;
    //reverse(v.begin(),v.end());
    //root=deserialise(v);
    //levelprint(root);
}