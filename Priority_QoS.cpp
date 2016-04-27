#include<iostream>
using namespace std;
#define SIZE 3
int id[SIZE]={-1,-1,-1},p[SIZE]={0,0,0};//message id and priority
int s=0;//current size of queue
int findhigh() //finds index of lowest priority message
{
    int h=0;
    for(int i=0;i<SIZE;i++)
        if(p[h]<p[i])
            h=i;
    return h;
}
int findlow() //finds index of lowest priority message
{
    int l=0;
    for(int i=0;i<s;i++)
        if(p[l]>p[i])
            l=i;
    return l;
}
void disp() //displays the queue
{
    if(s<=0)
    {
        cout<<"\n\nQueue is empty.";
        return;
    }
    cout<<"\n\nQueue is:";
    for(int i=0;i<SIZE;i++)
        if(id[i]!=-1)
            cout<<"\nMessage: "<<id[i]<<"\tPriority: "<<p[i];
}
int findemp() //finds empty location
{
    for(int i=0;i<SIZE;i++)
    {
        if(id[i]==-1)
            return i;
    }
    return 0;
}
void add(int mid,int priority)//tries to add message with ID mid and priority priority to the queue
{
    if(s>=SIZE)
    {
        cout<<"Queue is full.";
        int l=findlow();
        if(p[l]>=priority)
        {
            cout<<" New message discarded.";
            return;
        }
        cout<<" Message "<<id[l]<<" with priority "<<p[l]<<" dropped.";
        id[l]=mid;
        p[l]=priority;
    }
    else
    {
        int l=findemp();
        id[l]=mid;
        p[l]=priority;
        s++;
        cout<<"Message "<<mid<<" inserted into the queue.";
    }
}
void send() //sends highest priority message
{
    if(s<0)
    {
        cout<<"Queue is empty.";
    }
    if(s>0)
    {
        int h=findhigh();
        cout<<"Message "<<id[h]<<" with priority "<<p[h]<<" sent.";
        id[h]=-1;
        p[h]=0;
        s--;
    }
}
int main()  {
    int ch;
    do{
        cout<<"\n\n1.Send Message\n2.Add message\n3.Exit\n";
        cin>>ch;
        switch(ch)   {
        case 1:
            send();
            disp();
            break;
        case 2: cout<<"\nEnter message ID\n";
            int id;
            cin>>id;
            cout<<"Enter priority of message\n";
            int priority;
            cin>>priority;
            add(id,priority);
            disp();
            break;
        case 3: break;
        default: cout<<"\Incorrect choice.";
        }
    }while(ch!=3);
    return 0;
}
