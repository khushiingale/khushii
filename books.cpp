#include<iostream>
using namespace std;
struct node
{
    string data;
    node* child[10];
    int count;
};
class csbook
{
    public:
    node* root;
    csbook()
    {
        root=NULL;
    }
    void create();
    void display();
};
void csbook::create()
{
    int i,j,k;
    
    root=new node;
    
    cout<<"\nEnter the book name : ";
    cin>>root->data;
    
    cout<<"\nHow many chapters : ";
    cin>>root->count;
    
    for(i=1;i<=root->count;i++)
    {
        cout<<"\nEnter the chapter "<<i<<" name : ";
        root->child[i]=new node;
        cin>>root->child[i]->data;
        
        cout<<"\nHow many sections : ";
        cin>>root->child[i]->count;
        
            for(j=1;j<=root->child[i]->count;j++)
            {
                root->child[i]->child[j]=new node;
                cout<<"\nEnter the section "<<j<<" name : ";
                cin>>root->child[i]->child[j]->data;
                
                cout<<"\nHow many sub sections : ";
                cin>>root->child[i]->child[j]->count;
                
                    for(k=1;k<=root->child[i]->child[j]->count;k++)
                    {
                        root->child[i]->child[j]->child[k]=new node;
                        cout<<"\nEnter the sub section "<<k<<" name : ";
                        cin>>root->child[i]->child[j]->child[k]->data;
                    }
            }
    }
}

void csbook::display()
{
    int i,j,k;
    
    cout<<"the book name : "<<root->data<<"\n";
    
    for(i=1;i<=root->count;i++)
    {
        cout<<"The chapter "<<i<<" : "<<root->child[i]->data<<"\n";
        
            for(j=1;j<=root->child[i]->count;j++)
            {
                cout<<"The section of chapter "<<root->child[i]->data<<" : "<<root->child[i]->child[j]->data<<"\n";
                    
                    for(k=1;k<=root->child[i]->child[j]->count;k++)
                    {
                        cout<<"The sub-section of section "<<root->child[i]->child[j]->data<<" :"<<root->child[i]->child[j]->child[k]->data<<"\n";
                    }
            }
    }
}

int main()
{
    csbook p;
    char ans;
    int ch;
    
    do
    {
        cout<<"-----------MAIN MENU------------ \n";
        cout<<"1.Create";
        cout<<"\n2.Display \nEnter your choice: ";
        cin>>ch;
       
        switch(ch)
        {
            case 1 :
                p.create();
                break;
            case 2 :
                p.display();
                break;
        }
        
        cout<<"\nDo u want to continue??(y/n): ";
        cin>>ans;
        
    }while(ans=='y'||ans=='Y');
    
    return 0;
}
