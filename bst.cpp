#include <iostream>
#define MAX 100
using namespace std;
class node
{
    public:
    int data;
    node *left;
    node *right;
    node *create(node *root)
    {
        node *temp;
        char ans2;
        do
        {
            temp=new node;
            temp->left=temp->right=NULL;
            
            cout<<"\nEnter the data: ";
            cin>>temp->data;
            
            if(root==NULL)
                root=temp;
            else
                insertnode(root,temp);
                
            cout<<"\n\nDo u want 2 add another node?(y/n) : ";
            cin>>ans2;
            
        }while(ans2=='y'|| ans2=='Y');
        
        return(root);
    }
    void insertnode(node *root,node *temp)
    {
        if(temp->data < root->data)
        {
            if(root->left==NULL)
                root->left=temp;
            else
            {
                insertnode(root->left,temp);
            }
        }
        if(temp->data > root->data)
        {
            if(root->right==NULL)
                root->right=temp;
            else
                insertnode(root->right,temp);
        }
    }
    void printInorder(node*root)
    {
        if (root == NULL)
        return;
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }
    void printPreOrder(node * root)
    { 
        if (root == NULL)
        return;
        cout << root->data << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
    node* findmin(node *root)
    {
        node* current = root;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }
    node* findmax(node *root)
    {
        node* current = root;
        while (current && current->right != NULL)
            current = current->right;
        return current;
    }
    node* deleteNode(struct node* root, int key)
    {
        if (root == NULL)
            return root;
            
        if (key < root->data)
            root->left = deleteNode(root->left, key);
            
        else if (key > root->data)
                root->right = deleteNode(root->right, key);
                
        else
        {
            if (root->left == NULL and root->right == NULL)
                return NULL;
                
            else if (root->left == NULL)
            {
                node* temp = root->right;
                free(root);
                return temp;
            }
                
            else if (root->right == NULL)
            {
                node* temp = root->left;
                free(root);
                return temp;
            }
    
                node* temp = findmin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
            return root;
        }
    
        
    node* find(node* root, int key)
    {
        if (root == NULL || root->data == key)
        {
            return root;
        }
        if (root->data < key)
        {
            return find(root->right, key);
        } 
        return find(root->left, key);
    }
};

int main()
{
    node n1;
    int ch2;
    char ans1;
    node *root=NULL;
    
    do
    {
        cout<<"\n1.CREATE TREE\n2.Find Minimum\n3.Find Maximum\n4.Print INORDER\n5.PrintPREORDER\n6.Find Key\n7.Deletenode\n8.Exit";
        cout<<"\n\nEnter the choice: ";
        cin>>ch2;

        switch(ch2)
        {
            case 1:
                root=n1.create(root);
                break;
            case 2:
                cout<<"\nMinimum Element is : "<<(n1.findmin(root))->data;
                break;
            case 3:
                cout<<"\nMaximum Element is : "<<(n1.findmax(root))->data;
                break;
            case 4:
                n1.printInorder(root);
                break;
            case 5:
                n1.printPreOrder(root);
                break;
            case 6:
                int key3;
                node *res;
                cout<<"\nEnter key to search: ";
                cin>>key3;
                res = n1.find(root, key3);
                if(res->data)
                    cout<<"\nElement found...";
                else
                    cout<<"\nElement Not Found...";
                break;
            case 7:
                int key2;
                node* res1;
                cout<<"\nEnter key to delete: ";
                cin>>key2;
                res1 = n1.deleteNode(root, key2);
                if(res1->data)
                    cout<<"\nDeleted Successfully...";
                else
                    cout<<"\nElement Not Found...";
                break;
            }
            cout<<"\nDo u want to continue...?(y/n) : ";
            cin>>ans1;
        }while(ans1=='y' || ans1=='Y');
        return 0;
}

