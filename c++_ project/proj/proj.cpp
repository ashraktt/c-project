#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;
struct list { string name  ;int ID;int num_pices;double price;};

bool checkk(list l1,list l2){
	if(l1.name==l2.name)
		return true;
	else 
		return false;
}

void Delet_Item(int y, list items [],int  &num_items){
	items[y].ID=0;items[y].name="0";items[y].num_pices=0;items[y].price=0;
  for(int i=y;i<num_items;i++)
  {
	 swap(items[i].name,items[i+1].name);
	 swap(items[i].ID,items[i+1].ID);
	 swap(items[i].num_pices,items[i+1].num_pices);
	 swap(items[i].price,items[i+1].price);
				 
  }
  num_items--;
 cout<<"del"<<endl;

}
void Display( list items [], int & num_items){
	
 cout<<"ID"<<setw(8)<<"name"<<setw(8)<<"pices"<<setw(8)<<"price"<<endl;
  for(int i=1;i<=num_items;i++)
	 cout<<i<<setw(8)<<items[i].name<<setw(8)<<items[i].num_pices<<setw(8)<<items[i].price<<endl;
 
 		
}
void Enter_items(list items [],int &num_items){
  char answer;
  for(int i=1;i<1000;i++)
 {  
  cout<<"enter the name of items: ";
  cin>>items[i].name;
  items[i].ID=i;
  cout<<"enter the number of the item: ";
  cin>>items[i].num_pices;
  cout<<"enter the price of  the item: ";
  cin>>items[i].price;
  cout<<"if you finsh enter 'y/n' :";
  cin>>answer;
  num_items++;
    if(answer=='y')
	   break;
 }
}
void Add_items(list items[],int &num_items)
{   char answer;
		 for(int i=num_items+1;i<1000;i++)
	 {  
		cout<<"enter the name of items: ";
		cin>>items[i].name;
		items[i].ID=i;
	    cout<<"enter the number of the item: ";
	    cin>>items[i].num_pices;
	    cout<<"enter the price of  the item: ";
	    cin>>items[i].price;
		cout<<"if you finsh enter 'y/n' :";
		cin>>answer;
		num_items++;
		if(answer=='y')
			 break;
				    
				    
	 }
}
double total_price(list items[],int &num_items)
{double sum=0;
  for(int i=1;i<=num_items;i++)
    sum+=(items[i].price*items[i].num_pices);
	return sum;
}
int main()
{  int x; bool q=false;
  list items[1000];

  items[1].name="%";
  int num_items=0; double sum=0,sum2=0; double result=0;double dicount=0;
 
  cout << "welcome "<<endl;;
do
	{
		 first :
		system("pause"); 
		system("CLS");   
		cout << "\n 1:to enter the items \n";//ÇÏÎÇá ÚäÇÕÑ
		cout << "\n 2:to add the items \n";//ÇÖÇÝå ÚäÇÕÑ
		cout << "\n 3:to delete an item \n"; //ãÓÍ ÚäÇÕÑ
		cout << "\n 4:to show a list with all the items in the bill \n";//ÚÑÖ ÇáÚäÇÕÑ ÇáÇæáí(ÇáÓáÚ   Ýí ÇáÞÇÊãå  
		cout << "\n 5:to show the total amount of the bill \n";//ÚÑÖ ÇáãÌãæÚ Çáßáí  
		cout << "\n 6:to make discount on the total amount \n";//ÇáÎÕã
		cout << "\n 7:to show a list with all the items in the bill after the dicount \n ";//ÇáÚÑÖ ÈÚÏ ÇáÎÕã
		cout << "\n 8:to end the program \n";//ÇáÎÑæÌ
		cout<<endl;
		cin >> x;
		 

		switch (x)
		{
		case 1:
			{   
				Enter_items(items,num_items);
				for	(int i=1;i<num_items;i++)
				{
					if(checkk(items[i],items[i+1]))
					{
						items[i].num_pices+=items[i+1].num_pices;
						Delet_Item(i+1,items,num_items);
					}
				}
				break;
			}
		case 2:
			{  
				if(items[1].name!="%")
					Add_items(items,num_items);
				else
				   cout<<"not found items to adding this with them"<<endl;
				
				
			     break;
			
			}

		case 3:
			{   
				if(items[1].name!="%")
				{
				  int y;
				  cout<<"enter the item'ID : ";
				  cin>>y;
				  Delet_Item(y,items,num_items);
				}
				else
					cout<<"not found items to delete some of them"<<endl;
			break;
			}
		case 4: 
			{
				if(items[1].name!="%")
				{	Display(items,num_items);
				    cout<<"***********************************************************"<<endl;
					cout<<"the total price is : "<<total_price(items,num_items)<<endl;
				}

				else
					cout<<"not found items"<<endl;

			break; 
			}
		
		
         case 5: 
			 {   if(items[1].name!="%")
				    cout<<"the total price is : "<< total_price(items,num_items)<<endl;
			    else
					cout<<"not found any items"<<endl;
				break;
			}
		case 6:                              
			{	if(items[1].name!="%")
				{   double sum=0;
					double x=0;
			        char e;
				    cout<<"enter the value of dicount :";
				    cin>>dicount>>e;
				    x=dicount/100;
					sum=total_price(items,num_items);
				    result=(sum-(x*sum));
				    cout<<"the total price after the dicount is :"<<result<<endl;
			    }
			    else
					cout<<"not found items to make dicount for them"<<endl;
				break;
			}
		case 7:
			{   if(items[1].name!="%")
			  {
				  Display(items,num_items);
				  cout<<"the total price before the dicount is :"<<total_price(items,num_items)<<endl;
				  cout<<"after the dicount is :"<<result<<endl;
			  }
			else
				cout<<"not found items"<<endl;
				 
				break; 
			}
		
			
			
			
		case 8:
			{
				return 0;
				break;
			}
			
		  default:cout << "error\n"; goto first; break;



		}
	} while (x != 8);

	system("pause");
	
}




