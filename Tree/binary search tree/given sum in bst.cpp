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
bool givensum(node* root,int sum,unordered_set<int>&s)
{
    if(root==NULL)
    return false;
    if(s.find(sum-root->data)!=s.end())
    {
        return true;
    }
    else
    s.insert(root->data);
    return givensum(root->left,sum,s)||givensum(root->right,sum,s);

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
    unordered_set<int>s;
    cout<<givensum(root,15,s);
}