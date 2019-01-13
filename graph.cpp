//circular linklist
#include<iostream>
#include<stack_array_str.h>
using namespace std;

	class node1
	{
	    public: char name;
                int weight;
                node1 *next;
	};
	class node
	{
	    public: char name;
                node1 *next;
	};

node* insert1(node *,node *);

node* insert1(node *,node *){

}

int main()
{
    node *root=NULL;
	int n,c;
	cout<<"\n enter the num of nodes";
        cin>>n;
        node **arr123;
        arr123=new node*[n];
	do
	{       cout<<"\n*********************************\n";

		cout<<"\n\n\n enter your choice \n 1.Create graph. \n 2.display \n 3.display dfs \n 4.display bfs. \n 0.exit.";
		cin>>c;
		switch(c)
		{
			case 1:{
			    int input;
                for(int i=0;i<n;i++)
                {
                    arr123[i]=new(node);
                    cout<<"\n entter the name of node "<<i+1;
                    cin>>arr123[i]->name;
                }
                for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                    {
                        if(i!=j)
                        {
                            cout<<"\n is "<<arr123[i]->name<<" ajacent to "<<arr123[j]->name<<"\n 1.if yes \n 0.if no";
                            cin>>input;
                            if(input==1)
                            {
                                 node1 *a;
                                 a=new(node1);
                                 cout<<"\n enter the weight:";
                                 cin>>a->weight;
                                 a->name=arr123[j]->name;
                                 a->next=NULL;
                                 if(arr123[i]->next==NULL)
                                 {
                                     arr123[i]->next=a;
                                 }
                                 else
                                 {
                                     node1 *ptr=arr123[i]->next;
                                     while(ptr->next!=NULL)
                                     {
                                         ptr=ptr->next;
                                     }
                                     ptr->next=a;
                                 }
                            }
                        }

                    }
				break;
				}
            case 2:{
                for(int i=0;i<n;i++)
                {
                    node1 *ptr=arr123[i]->next;
                    if(ptr!=NULL)
                    {
                        cout<<"\n nodes adjacent to "<<arr123[i]->name<<" is/are \n";
                        while(ptr!=NULL)
                        {
                            cout<<" =>"<<ptr->name<<" and having weight "<<ptr->weight<<"\n";
                            ptr=ptr->next;
                        }
                    }
                    else
                    {
                        cout<<"\n"<<arr123[i]->name<<" doesn't have any adjacent node";
                    }
                }
				break;
            }
            case 3:{
                char visited[n],output[n],stack1[n];
                int topv=-1,topo=-1,tops=-1;
                for(int i=0;i<n;i++)
                {
                    visited[i]=0;
                }
               tops=push(stack1,tops,arr123[0]->name);
                visited[0]=1;
                for(int i=0;i<n;i++)
                {
                    node1 *ptr=arr123[i]->next;
                    topo=push(output,topo,pop(stack1,tops));
                    tops--;
                    if(ptr!=NULL)
                    {
                        int j=i+1;
                        while(ptr!=NULL)
                        {
                            if(visited[j]!=1)
                            {
                                tops=push(stack1,tops,ptr->name);
                                visited[j]=1;
                            }
                             ptr=ptr->next;
                             j++;
                        }
                    }
                }
                output[n]='\0';
                cout<<"\n output:"<<output;
				break;
            }
		}
	    cout<<"\n___________________________________________________\n";
	}while(c!=0);
	return 0;
}


