//Program to perform various operations on Threaded Binary Search Tree

/*
 * Created By Devashish Katoriya on 09-01-2017
 */

#include<iostream>
 
using namespace std;
 
#define LIMIT 9999

class tNode                                                      //Node Class
{
public :
    int data;
    tNode *left,*right;
    bool L,R;                          //false = child, true = thread
};
 
class TBST                                                   //Threaded Binary Tree Class
{
    int count;
    tNode *root,*head;
    tNode *create();
public :
    TBST()
    {
        count = 0;
        root = NULL;
        
        head = new tNode;
        head->L = false;
        head->left = head->right = head;
        head->R = true;
        head->data = LIMIT;
    }
    inline tNode *retRoot()
    {
        return root;
    }
    bool isEmpty()
    {
        return root == NULL;
    }
    inline int retCount()
    {
        return count;
    }
    void clr()
    {
        root = NULL;
        head->L = false;
        head->left = head->right = head;
        head->R = true;
    }
    void insert();
    void inOrder();
    void remove();
};
 
tNode *TBST::create()
{
    tNode *temp;
    temp = new tNode;
    cout<<"\nEnter data : ";
    cin>>temp->data;
    temp->L = true;
    temp->left = temp;
    temp->R = true;
    temp->right = temp;
    count++;
    return temp;
}

void TBST::insert()
{
    tNode *curr,*temp;
    curr = create();
    if(root == NULL)
    {
        root = curr;
        head->left = root;
        root->left = root->right = head;
        cout<<"\nRoot inserted Successfully!";
    }
    else
    {
        temp = root;
        while(1)
        {
            if(curr->data < temp->data)
            {
                if(temp->L)
                {
                    curr->left = temp->left;
                    curr->right = temp;
                    temp->left = curr;
                    temp->L = false;
                    cout<<"\nEntry inserted Successfully!";
                    break;
                }
                else
                    temp = temp->left;
            }
            else if(curr->data > temp->data)
            {
                if(temp->R)
                {
                    curr->right = temp->right;
                    curr->left = temp;
                    temp->right = curr;
                    temp->R = false;
                    cout<<"\nEntry inserted Successfully!";
                    break;
                }
                else
                    temp = temp->right;
            }
            else
            {
                cout<<"\nEntry already exists!";
                count--;
                break;
            }
        }
    }
    
}

void TBST::inOrder()                                               //in order traversal
{
    tNode *temp;
    int flag;
    
    if(root==NULL)
    {
        cout<<"\nEmpty Tree!";
        return;
    }
    
    flag = 0;
    temp = root;
    while(temp!=head)
    {
        if(!temp->L && flag == 0)
        {
            temp = temp->left;
        }
        else
        {
            cout<<temp->data<<",";
            if(!temp->R)
            {
                temp = temp->right;
                flag = 0;
            }
            else
            {
                temp = temp->right;
                flag = 1;
            }
        }
    }
}

void TBST::remove()
{

}
 
int main()
{
    TBST obj;
    int ch;
    char choice;
    cout<<"\nProgram to perform Various operation on Threaded Binary Search Tree.";
    do
    {
        ch = 0;
        choice = 'n';
        cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout<<"\n 1 for Construction and Insertion";
        cout<<"\n 2 for In-Order Traversal";
        cout<<"\n 3 to  Display Root";
        cout<<"\n 4 to  Remove an element";
        cout<<"\n 5 for Total Nodes Count";
        cout<<"\n 6 to  Check for Empty Tree.";
        cout<<"\n -1 to Clear whole Tree";
        cout<<"\n 0 to  Quit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        switch(ch)
        {
            case 1 : obj.insert();
                break;
            case 2 : cout<<"\nIn order Traversal is ";
                obj.inOrder();
                break;
            case 3 : if(obj.isEmpty())
                {
                    cout<<"\nEmpty Tree!";
                }
                else
                    cout<<"\nThe Root is "<<obj.retRoot()->data;
                break;
            case -1: cout<<"\nAre you sure you want to clear tree (y/n) ? ";
                cin>>choice;
                if(choice=='y'||choice=='Y')
                {
                    obj.clr();
                    cout<<"\nTree Cleared Successfully!";
                }
                else
                    cout<<"\nCancelled!";
            case 4 : obj.remove();
                break;
            case 5 : cout<<"\nThere are total "<<obj.retCount()<<" node in the tree.";
                break;
            case 6 :
                if(obj.isEmpty())
                    cout<<"\nThe tree is Empty!";
                else
                    cout<<"\nThe tree is NOT empty.";
                break;
            case 0 : break;
            default : cout<<"\nInvalid Option!";
        }
  
        /*
        if(ch!=0)
        {
            cout<<"\n\n\n\n\n\n\nPress any key to continue...";
            cin.ignore();
            cin.get();
        }
        */
    }while(ch!=0);
  
    cout<<"\nThank you for using this program :) \n\n";
    return 0;
}