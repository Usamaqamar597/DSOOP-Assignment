#include<iostream>
using namespace std;
class complex
{ 
 public:
		double a,b;
		complex*next;

		void setdata()
	{		
		cout<<"ENTER the complexnumber's real part  ";
		cin>>a;
		cout<<"Now ENTER the complexnumber's imag part  ";
		cin>>b;
		cout<<endl;
	}
		void showdataofcomplex()
	{	    
		cout<<"    ("<<a<<")+("<<b<<")i"<<endl;
	}
		complex operator +(complex v)
	{		
		complex add;
		add.a=a+v.a;
		add.b=b+v.b;
		return add;
	}
		complex operator -(complex v)
	{		
		complex sub;
		sub.a=a-v.a;
		sub.b=b-v.b;
		return sub;
	}
		complex operator *(complex v)
	{		
		complex mul;
		mul.a=(a*v.a)-(b*v.b);
		mul.b=(a*v.b)+(b*v.b);
		return mul;
	}
		complex operator /(complex v)
try {	{	
			complex div;
           if (((v.a*v.a)+(v.b*v.b))==0)
		      throw (4);
	       else
	  {			div.a=((a*v.a)+(b*v.b))/((v.a*v.a)+(v.b*v.b));
				div.b=((b*v.a)-(a*v.b))/((v.a*v.a)+(v.b*v.b));
				return div; 
	  }   
		 }
	}
catch(int e)
		{
			cout<<"DIVISION  by ZERO condition"<<endl;
		}

};

class linklist
{ 
	private:
			complex *head,*tail;

	public:
			linklist()
	      {		head=NULL;
				tail=NULL;
		  }
	
	

			void insertatstart(complex v)
	     {	
				complex*temp=new complex;
				temp->a=v.a;
				temp->b=v.b;
				temp->next=NULL;
					if (head==NULL)
					{
						head=temp;
					}
					else 
					{
						temp->next=head;
						head=temp;
					}

		 }
			void insertafterposition(int pos,complex c)
         {				
				complex*newnode;
				complex*temp;
				newnode=new complex;
				newnode->a=c.a;
				newnode->b=c.b;
				newnode->next=NULL;
				temp=head;
					for(int i=1;i<pos;i++)
				{	
					temp=temp->next;
				}
				newnode->next=temp->next;
				temp->next=newnode;

		}
	     	void deleteatposition(int pos)
		{
				complex *current=new  complex;
				complex *previous=new  complex;
				current=head;
					for(int i=1;i<pos;i++)
				{
					previous=current;
					current=current->next;
				}
				previous->next=current->next;
  
		}
			void getvalueatpos(int po)
	    {		
				int count=1;
				complex*cur=head;
					while(cur!=NULL)
	           {		if (count==po)
								cout<<"  ("<<cur->a<<")+("<<cur->b<<")i"<<endl;
						count++;
						cur=cur->next;
				}
	    }
            void showdatoflinklist()
        {
				 complex* temp = head;
		             while (temp)
		        {
						cout <<"("<< temp->a << ")+("<<temp->b<<")i" << "  ";
						temp = temp->next;
		        }
				 cout << endl;
		}

};


int main()
{
			
					complex c1,c2,c3,c4,c5,c6,c7;
		linklist c;
	cout<<"                       Set the values for first complexnumber"<<endl;
	c1.setdata();
	c1.showdataofcomplex();
	cout<<"                       Set the values for second complexnumber"<<endl;
	c2.setdata();
	c2.showdataofcomplex();
	cout<<"                       Set the values for 3rd complexnumber"<<endl;
	c3.setdata();
	c3.showdataofcomplex();
	cout<<endl;
	cout<<"                ADDITION of 1st two complexnumbers is =   ";
	c4=c1+c2;
	c4.showdataofcomplex();
	cout<<endl;
	cout<<"linklist IS  ";
	c.insertatstart(c4);
    c.showdatoflinklist();
	cout<<endl;
	cout<<"               SUBTRACTION of 1st and 3rd complexnumber is = ";
	c5=c1-c3;
	c5.showdataofcomplex();
	cout<<endl;
	cout<<"UPDATED linklist IS THUS  ";
	c.insertafterposition(1,c5);
	c.showdatoflinklist();
	cout<<endl;
    cout<<"               MULTIPLICATION of 2nd and 3rd complexnumber is = ";
	c6=c2*c3;
	c6.showdataofcomplex();
	cout<<endl;
	cout<<"UPDATED linklist IS  ";
	c.insertafterposition(2,c6);
	c.showdatoflinklist();
	cout<<endl;
    cout<<"               DIVISION of 1st and 3rd complexnumber is = ";
	c7=c1/c3;
	c7.showdataofcomplex();
	cout<<endl;
	cout<<"UPDATED  linklist IS  ";
	c.insertafterposition(3,c7);
	
	c.showdatoflinklist();
	cout<<endl;
    c.deleteatposition(4);
	cout<<"UPDATED  linklist after deleting at 4 IS  ";
	
	c.showdatoflinklist();
	cout<<endl;
	cout<<"VALUE at position no 3 in linklist is   ";
	c.getvalueatpos(3);
	
	return 0;

}
