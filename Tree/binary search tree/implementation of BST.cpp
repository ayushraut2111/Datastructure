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
node* insert(node* root,int x)
{
    if(root==NULL)
    {
        root=new node(x);
        return root;
    }
    if(x<=root->data)
    {
        root->left=insert(root->left,x);
    }
    else
    {
        root->right=insert(root->right,x);
    }
    return root;
}
node* insertbyiterator(node* root,int x)
{
    node* ptr=new node(x);
    if(root==NULL)
    {
        root=ptr;
        return root;
    }
    node* temp=root;
    node* parent;
    while(temp!=NULL)
    {
        parent=temp;
        if(x<temp->data)
        temp=temp->left;
        else if(x>temp->data)
        temp=temp->right;
        else
        return root;
    }
    if(x<parent->data)
    parent->left=ptr;
    else
    parent->right=ptr;
    return root;

}
void preprint(node* root)
{
    if(root==NULL)
    return ;
    cout<<root->data<<endl;
    preprint(root->left);
    preprint(root->right);
}
bool searchtree(node* root,int x)
{
    if(root==NULL)
    return false;
    if(root->data==x)
    return true;
    if(x<root->data)
    searchtree(root->left,x);
    else
    searchtree(root->right,x);

}
bool searchbyiterator(node* root, int x)
{
    if(root==NULL)
    return false;
    node* temp=root;
    while(temp!=NULL)
    {
        if(temp->data==x)
         return true;
        else if(x<temp->data)
        {
            temp=temp->left;
        }
        else
        temp=temp->right;
    }
    return false;
}
node* getsuccessor(node* root)
{
    root=root->right;
    while(root!=NULL&&root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
node* deletenode(node* root,int x)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(x<root->data)
    root->left=deletenode(root->left,x);
    else if(x>root->data)
    root->right=deletenode(root->right,x);
    else                                             // if we got the root to be deleted
    {
        if(root->left==NULL&&root->right==NULL)
        return NULL;
        if(root->left==NULL)
        return root->right;
        if(root->right==NULL)
        return root->left;
        node* successor=getsuccessor(root);
        root->data=successor->data;
        root->right=deletenode(root->right,successor->data);
        return root;
    }
    return root;
}
int main()
{
    node* root=NULL;
    root=insert(root,89);
root=insert(root,2);
root=insert(root,3);
root=insert(root,1);
    root=insert(root,5);
    root=insert(root,6);
    root=insertbyiterator(root,9);
    root=deletenode(root,1);
    preprint(root);
   /* if(searchbyiterator(root,9)==true)
    cout<<"present";
    else
    cout<<"not present"; */

}