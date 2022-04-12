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
void spiralprint1(node* root)
{
    if(root==NULL)
    {
        cout<<"empty tree"<<endl;
        return;
    }
    queue<node*>q;
    q.push(root);
    int count=0;
    while(!q.empty())
    {
        if(count%2==0)         //printing even nodes normally(n=0,2,4......)
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
               node* temp=q.front();
               q.pop();
               cout<<temp->key<<endl;
                if(temp->left!=NULL)
            q.push(temp->left);
            if(temp->right!=NULL)
            q.push(temp->right);
            }
        }
        else                          //printing odd nodes reverse order (n=1,3,5......)
        {
            stack<node*>s;
            while(!q.empty())              //reversing queue with the help of stack
            {
                s.push(q.front());
                q.pop();
            }
            while(!s.empty())
            {
                q.push(s.top());
                s.pop();
            }
            int size=q.size();
            for(int i=0;i<size;i++)                 //printing in opposite direction
            {
               node* temp=q.front();
               q.pop();
               cout<<temp->key<<endl;
                if(temp->right!=NULL)        //first pushing right node then left node so that when n is even we can traverse it from left to right by reversing it
            q.push(temp->right);
                if(temp->left!=NULL)
            q.push(temp->left);
            }
            while(!q.empty())                 // reversing the queue again to make even level traverse from left to right
            {
                s.push(q.front());
                q.pop();
            }
            while(!s.empty())
            {
                q.push(s.top());
                s.pop();
            }
        }
        count++;        // incrementing count to check whether the level(n) is even or odd
    }
}
void spiralprint2(node* root)
{
     if(root==NULL)
    {
        cout<<"empty tree"<<endl;
        return;
    }
    queue<node*>q;
    stack<node*>s;
    q.push(root);
    int count=0;
    while(!q.empty())
    {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
               node* temp=q.front();
               q.pop();
               if(count%2==0)
               cout<<temp->key<<endl;      //if it is the even level then simply printing the nodes
               else
               s.push(temp);                // if it is the odd level then pushing it to the stack to be printed later in reverse direction 
                if(temp->left!=NULL)
            q.push(temp->left);               // if it is the odd level then also we are saving its child in same order and in the place of printing is same order 
            if(temp->right!=NULL)             // we are saving it in stack to print reversely
            q.push(temp->right);
            }
            if(count%2!=0)
            {
                while(!s.empty())
                {
                    node* temp=s.top();
                    s.pop();
                    cout<<temp->key<<endl;
                }
            }
            count++;
}
}
void spiralprint3(node* root)
{
    if(root==NULL)
    {
        cout<<"empty"<<endl;
        return ;
    }
    stack<node*>s1,s2;
    s1.push(root);
    while(!s1.empty()||!s2.empty())
    {
        while(!s1.empty())
        {
            node* temp=s1.top();
            s1.pop();
            cout<<temp->key<<endl;
            if(temp->left!=NULL)
            s2.push(temp->left);               
            if(temp->right!=NULL)             
            s2.push(temp->right);
        }
        while(!s2.empty())
        {
            node* temp=s2.top();
            s2.pop();
            cout<<temp->key<<endl;        
            if(temp->right!=NULL)             
            s1.push(temp->right);   
             if(temp->left!=NULL)
            s1.push(temp->left);       
        }
    }
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
root=inserttree(root,7);
root=inserttree(root,8);
root=inserttree(root,9);
root=inserttree(root,10);
spiralprint3(root);
}