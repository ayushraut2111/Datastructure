#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *create()
{
    node *temp=new node();
    cout<<"enter 0 to exit or any number to continue"<<endl;
    int n;
    cin>>n;
    if(n==0)
    {
        return 0;
    }
    else
    {
        cout<<"enter data"<<endl;
        int data;
        cin>>data;
        temp->data=data;
        cout<<"enter the left child of "<<data<<endl;
        temp->left=create();
        cout<<"enter the right child of "<<data<<endl;
        temp->right=create();
        return temp;
    }
}
node *prin(node *temp)
{
    if(temp==NULL)
        return 0;
    cout<<temp->data<<endl;
    prin(temp->left);
    prin(temp->right);
}
int main()
{
    node *root;
    root=create();
    prin(root);
}
