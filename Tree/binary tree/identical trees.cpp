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
bool identical(node*root1,node* root2)
{
    if(root1==NULL&&root2!=NULL)
    return false;
    if(root2==NULL&&root1!=NULL)
    return false;
    if(root1==NULL&&root2==NULL)
    return true;
    queue<node*>q1,q2;
    q1.push(root1);
    q2.push(root2);
    while(!q1.empty()&&!q2.empty())
    {
        node* temp1=q1.front();
        node* temp2=q2.front();
        q1.pop();
        q2.pop();
        if(temp1->key!=temp2->key)
        return false;
        if(temp1->left!=NULL)
        q1.push(temp1->left);
        if(temp1->right!=NULL)
        q1.push(temp1->right);
        if(temp2->left!=NULL)
        q2.push(temp2->left);
        if(temp2->right!=NULL)
        q2.push(temp2->right);
    }
    if(!q1.empty()||!q2.empty())
    return false;
    return true;

}
int main()
{
     node* root=NULL;
     node* root1=NULL;
    root=inserttree(root,1);
    root=inserttree(root,2);
    root=inserttree(root,5);
    root1=inserttree(root1,0);
    root1=inserttree(root1,2);
    root1=inserttree(root1,5);
    int x=identical(root,root1);
    if(x==1)
    cout<<"yes";
    else
    cout<<"no";

}