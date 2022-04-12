#include<bits/stdc++.h>
using namespace std;
struct node
{
    int key;
    node* left;
    node* right;
    node(int k)
    {
        key=k;
        left=NULL;
        right=NULL;
    }
};
node* inserttree(node* root,int data)
{
    node* ptr=new node(data);
    if(root==NULL)
    {
        root=ptr;
        return root;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp->left==NULL)
        {
            temp->left=ptr;
            break;
        }
        else
        {
            q.push(temp->left);
        }
        if(temp->right==NULL)
        {
            temp->right=ptr;
            break;
        }
        else
        {
            q.push(temp->right);
        }
    }
    return root;
}
node* deletelast(node* root,node* ptr)
{
    if(root==ptr)
    {
        delete(root);
        return NULL;
    }
    queue<node*>q;
    q.push(root);
    node* temp;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->right!=NULL)       // we are traversing right node first to save the time as we know that it is the address of the right node
        {
            if(temp->right==ptr)
            {
                temp->right=NULL;
                delete(ptr);
                return root;
            }
            else
            {
                q.push(temp->right);
            }
        }
        if(temp->left!=NULL)
        {
            if(temp->left==ptr)
            {
                temp->left=NULL;
                delete(ptr);
                return root;
            }
            else
            {
                q.push(temp->left);
            }
        }
    }
}
node* deletedata(node* root,int data)
{
    if(root==NULL)
    {
        return root;
    }
    queue<node*>q;
    node* datanode;     // it saves the node to be deleted
    node* ptr;         // it saves the last node
    q.push(root);
    while(!q.empty())
    {
        ptr=q.front();
        q.pop();
        if(ptr->key==data)
        {
            datanode=ptr;    // saving the node which is to be deleted
        }
        if(ptr->left!=NULL)
        q.push(ptr->left);
        if(ptr->right!=NULL)
        q.push(ptr->right);
    }
    int x=ptr->key;     //last node's value which is to be copied 
    root=deletelast(root,ptr);
    datanode->key=x;
    return root;

}
int searchtree(node* root,int data)
{
    if(root==NULL)
    {
        cout<<"empty"<<endl;
        return INT_MAX;
    }
    queue<node*>q;
    node* temp;
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->key==data)
        {
            return 1;
        }
        if(temp->left!=NULL)
        q.push(temp->left);
        if(temp->right!=NULL)
        q.push(temp->right);
    }
    return 0;
}
void preorder(node* root)
{
    if(root==NULL)
    return;
    cout<<root->key<<endl;
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->key<<endl;
    inorder(root->right);    
}
void postorder(node* root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<endl;
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
int treeheight(node* root)
{
    if(root==NULL)
    return 0;
    int leftheight=treeheight(root->left);
    int rightheight=treeheight(root->right);
    return max(leftheight,rightheight)+1;
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
    int x=searchtree(root,1);
    if(x==1)
    cout<<"found"<<endl;
    else if(x==0)
    cout<<"not found"<<endl;
    preorder(root);
    cout<<"height of a tree is "<<treeheight(root)<<endl;
    
}