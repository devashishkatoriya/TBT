
//Program to perform various operations on Threaded Binary Tree
 
#include<iostream>
 
using namespace std;
 
class node                                                      //Node Class
{
public :
    int data;
    node *left,*right;
    bool L,R;
};
 
class TBT                                                   //Threaded Binary Tree Class
{
    node *root;
    node *create();
public :
    TBT()
    {
        root = NULL;
    }
    node *retRoot()
    {
        return root;
    }
    void clr()
    {
        root = NULL;
    }
    void construct();
    void inOrder(node *);
};
 
void TBT::inOrder(node *s)                                               //in order()
{
 /*   if(s!=NULL)
    {
        inOrder(s->left);
        cout<<s->data<<",";
        inOrder(s->right);
    }
    */
}
 
int main()
{
    TBT obj;
    int ch;
    char choice;
    cout<<"\nProgram to perform Various operation on Threaded Binary Tree.";
    do
    {
        ch = 0;
        choice = 'n';
        cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout<<"\n 1 for Construction and Insertion";
        cout<<"\n 2 for In order Traversal";
        cout<<"\n 19 to Clear whole Tree";
        cout<<"\n 0 to  Quit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        switch(ch)
        {
            case 1 : obj.construct();
                break;
            case 2 : cout<<"\nIn order Traversal is ";
                obj.inOrder(obj.retRoot());
                break;
            case 19: cout<<"\nAre you sure you want to clear tree (y/n) ? ";
                cin>>choice;
                if(choice=='y'||choice=='Y')
                {
                    obj.clr();
                    cout<<"\nTree Cleared Successfully!";
                }
                else
                    cout<<"\nCancelled!";
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