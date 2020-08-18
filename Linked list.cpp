#include <bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  struct node *next;
};
class listed
{
  private:
  node *head,*tail;
  public:
  listed()
  {
    head=0;
    tail=0;
  }
  void add(int n)
  {
    node *temp;
    temp= new node;
    temp->data=n;
    temp->next=0;
    if(head==0)
    {
      head=temp;
      tail=temp;
    }
    else
    {
      tail->next=temp;
      tail=tail->next;
    }
  }
  void print()
  {
    node *p;
    if(head==0)
    {
      cout<<"linked list is empty!"<<"\n";
    }
    else
    {
    p=head;
    while(p!=0)
    {
      cout<<p->data<<" ";
      p=p->next;
    }
    }
  }

  void front(int n)
  {
    node *p;
    p=new node;
    p->data=n;
    p->next=head;
    head=p;
  }

  void end(int n)
  {
    node *p;
    p=new node;
    p->data=n;
    p->next=0;
    tail->next=p;
    tail=tail->next;
  }

  void mid(int n, int m)
  {
    node *p,*q;
    int count=0;
    p= new node;
    p->data=n;
    q=head;
    while(q!=0)
    {
      if(q->data==m)
      {
        p->next=q->next;
        q->next=p;
        count++;
        break;
      }
      q=q->next;
    }
    if(count==0)
    {
      cout<<"you enter the wrong element !";
    }
  }

  void free_end()
  {
    node *p,*q;
    p=head;
    if(head!=0)
    {
    if (head->next==0)
    {
      head=0;
      free(head);
      cout<<"you delete the last node!"<<"\n";
    }
    else
    {
    while(p->next!=0)
    {
      q=p;
      p=p->next;
    }
    q->next=0;
    free(p);
    }
    }
  }

  void free_beg()
  {
    node *p;
    if(head!=0)
    {
      if (head->next==0)
    {
      head=0;
      free(head);
      cout<<"you delete the last node!"<<"\n";
    }
    else
    {
    p=head;
    head=p->next;
    free(p);
    }
  }
  }

  void free_mid(int m)
  {
    node *p,*q;
    p=head;
    int count=0;
    while(p!=0)
    {
      q=p;
      count++;
      p=p->next;
      if(count==m)
      {
        break;
      }
    }
    p=p->next;
    while(p!=0)
    {
      q=p;
      p=p->next;
    }
    free(p);
  }
};

int main() 
{
  int n,c,i,b,d;
  listed a;
  cout<<"enter the number of nodes: ";
  cin>>n;
  for(i=0;i<n;i++)
  {
    cin>>c;
    a.add(c);
  }

  cout<<"this is the linked list: "<<"\n";
  a.print();

  cout<<"\n\n";
  cout<<"Following is the list of operation. You must have to press one of these numbers: "<<"\n\n";
  cout<<"press 1 for insertion at the beginning! "<<"\n";
  cout<<"press 2 for insertion at the end! "<<"\n";
  cout<<"press 3 for insertion after the given point! "<<"\n";
  cout<<"press 4 for deletion of the node from ending! "<<"\n";
  cout<<"press 5 for deletion of the node from beginning! "<<"\n";
  cout<<"press 9 for exit! ";

  int x;
  while(1)
  {
    cout<<"\n\n"<<"enter the number: ";
    cin>>x;
    switch(x)
    {
       case 1:
       cout<<"enter the number you want to insert: "; 
       cin>>b;
       a.front(b);
       cout<<"your new linked list is: ";
       a.print();
       break;

       case 2:
       cout<<"enter the number you want to insert: "; 
       cin>>b;
       a.end(b);
       cout<<"your new linked list is: ";
       a.print();
       break;

       case 3:
       cout<<"enter the element after which you want to insert the new node: ";
       cin>>d;
       cout<<"enter the number you want to insert: "; 
       cin>>b;
       a.mid(b,d);
       cout<<"your new linked list is: ";
       a.print();
       break;

       case 4:
       a.free_end();
       cout<<"your new linked list is: ";
       a.print();
       break;

       case 5:
       a.free_beg();
       cout<<"your new linked list is: ";
       a.print();
       break;

       case 6:
       cout<<"enter the position after which uh want to delete the element: ";
       cin>>b;
       a.free_mid(b);
       cout<<"your new linked list is: ";
       a.print();
       break;

       case 9:
       exit(1);

       default:
       cout<<"you enter a wrong number!";

    }
  }
}
