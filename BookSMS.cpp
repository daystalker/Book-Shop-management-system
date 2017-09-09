/* Book Shop Management System
author Siddhant Saurabh K1630_b_46 LOVELY PROFESSIONAL UNIVERSITY*/

#include<iostream>
#include<string.h>	//for using string functions
#include<windows.h>	//for clearing screen functions and using dos functions
#include<fstream>	//for reading and writing in the hard-disk
#include<iomanip>
using namespace std;

class book
{
	private:
		// various book details declaration in private
		long book_id;
		char book_name[30];	
		char book_author[30];
		int book_pieces;
		float book_cost;
	public:     
		// methods of setting data
		void set_book_id(long id)
		{
			book_id=id;
		}
		void set_book_name(string s)
		{
			int i;								//Note we should not write object into a file if the object contain strings as instead of data, pointers are written
			for(i=0;s[i]!='\0';i++)
			{
				book_name[i]=s[i];
			}
			book_name[i]='\0';
		}
		void set_book_author(string s)
		{
			int i;
			for(i=0;s[i]!='\0';i++)
			{
				book_author[i]=s[i];
			}
			book_author[i]='\0';
		}
		void set_book_pieces(int n)
		{
			book_pieces=n;
		}
		void set_book_cost(float c)
		{
			book_cost=c;
		}		
		// methods of getting data
		long get_book_id()
		{
			return book_id;
		}
		string get_book_name()
		{
			return book_name;
		}
		string get_book_author()
		{
			return book_author;
		}
		int get_book_pieces()
		{
			return book_pieces;
		}
		float get_book_cost()
		{
			return book_cost;
		}
};
class bill
{
	private:
		// various bill details
		long bill_id;
		int no_of_books;					// no of different no. of book
		char customer_name[30];
		char date[30];
		char product_name[30][30];
		long product_id[30];
		float product_cost[30];
		int quantity[30];
		float total_cost;
	public:
		// methods of setting data
		void set_bill_id(long id)
		{
			bill_id=id;
		}
		void set_no_of_books(int n)
		{
			no_of_books=n;
		}
		void set_customer_name(string s)
		{
			int i;
			for(i=0;s[i]!='\0';i++)
			{
				customer_name[i]=s[i];
			}
			customer_name[i]='\0';
		}
		void set_date(string s)
		{
			int i;
			for(i=0;s[i]!='\0';i++)
			{
				date[i]=s[i];
			}
			date[i]='\0';
		}
		void set_product_name(string s,int n)
		{
			int i;
			for(i=0;s[i]!='\0';i++)
			{
				product_name[n][i]=s[i];
			}
			product_name[n][i]='\0';
		}
		void set_product_id(long pid,int n)
		{
			product_id[n]=pid;
		}
		void set_product_cost(float p,int n)
		{
			product_cost[n]=p;
		}
		void set_quantity(int q,int n)
		{
			quantity[n]=q;
		}
		void set_total_cost(float tc)
		{
			total_cost=tc;
		}
		// methods of getting data
		long get_bill_id()
		{
			return bill_id;
		}
		int get_no_of_books()
		{
			return no_of_books;
		}
		string get_customer_name()
		{
			return customer_name;
		}
		string get_date()
		{
			return date;
		}
		string get_product_name(int n)
		{
			return product_name[n];
		}
		long get_product_id(int n)
		{
			return product_id[n];
		}
		float get_product_cost(int n)
		{
			return product_cost[n];
		}
		int get_quantity(int n)
		{
			return quantity[n];
		}
		float get_total_cost()
		{
			return total_cost;
		}
		
};

//non member function for manipulation of data
void sellBook();
void viewBill();
void deleteBill();
void searchBook();
void viewStockBook();
void updateBookNo();
void addBook();
void deleteBook();
void siddhant();

int main()
{
	int home_choice=0;
	system("cls");
	cout<<"======================================================\n      Welcome to Book Shop Management System";
	cout<<"\n======================================================";
	cout<<"\n 1 Sell Book From Stock \n 2 View Bill Data \n 3 Delete Bill Data \n 4 Search Book In Stock \n 5 View All Books In Stock \n 6 Update Number of Pieces Of Book In Stock \n 7 Add Book To Stock \n 8 Delete Book From Stock \n 9 Exit \n====================================================== \n PRESS CORRESPONDING KEYS TO PERFORM THE OPERATION : ";
	cin>>home_choice;
	
	//choice
	switch(home_choice)
	{
		case 1:
			sellBook();
			break;
		case 2:
			viewBill();
			break;
		case 3:
			deleteBill();
			break;
		case 4:
			searchBook();
			break;
		case 5:
			viewStockBook();
			break;
		case 6:
			updateBookNo();
			break;
		case 7:
			addBook();
			break;
		case 8:
			deleteBook();
			break;
		default:
			siddhant();
	}
}

void siddhant()
{
	system("cls");
	cout<<"\n          Lovely Professional University \n                 Siddhant Saurabh \n                   11602270 B46\n          Thankyou for using my software.\n \n \n===================================================";
	Sleep(2000);
	exit(1);
}

void addBook()
{	system("cls");
	cout<<"=======================================================\n                    Add Book To Stock              \n=======================================================\n";
	book b;
	
	// method of determining the greatest book id
	long id=0;
	fstream inid("book.dat",ios::binary|ios::in);
	if(inid!=NULL)
		while(inid.read((char *)&b,sizeof(b)))
			if(id<b.get_book_id())
				id=b.get_book_id();
	inid.close();
	cout<<" Id of Book is       : "<<id+1<<endl;
	b.set_book_id(id+1);
	
	fstream out("book.dat",ios::binary|ios::app|ios::ate|ios::out);
	
	string bookname;
	cout<<" Enter Book Name     : ";
	cin.ignore();
	getline(cin,bookname);
//	cin>>bookname;
	b.set_book_name(bookname);
	
	string bookauthor;
	cout<<" Enter Author Name   : ";
	getline(cin,bookauthor);
//	cin>>bookauthor;
	b.set_book_author(bookauthor);
	
	float price;
	cout<<" Enter Cost of Book  : ";
	cin>>price;
	b.set_book_cost(price);
	
	int pieces;
	cout<<" Enter No. of Pieces : ";
	cin>>pieces;
	b.set_book_pieces(pieces);
		
	//writing object in the file	
	out.write((char *)&b,sizeof(b));
	cout<<"=======================================================\n File Written Successfuly\n";
	out.close();
		
	int ch;
	cout<<"=======================================================\n PRESS 1 TO ADD NEW BOOK OR ANY KEY TO EXIT WRITING : ";
	cin>>ch;
	if(ch==1)
		addBook();
		
	cout<<"=======================================================\n PRESS 1 TO GO TO MAIN MENU AND 0 TO EXIT: ";
	int module_choice;
	cin>>module_choice;
	if(module_choice==1)
		main();
	else
		siddhant();
}

void searchBook()
{
	system("cls");
		
	cout<<"=======================================================\n                    Search Book In Stock              \n=======================================================\n";
	cout<<" Enter the Book Id   : ";
	long id;
	int flag=0;
	cin>>id;
	cout<<"=======================================================\n";
	book b;
	
	fstream in("book.dat",ios::binary|ios::in);
	if(in!=NULL)
		while(in.read((char *)&b,sizeof(b)))
			{
				if(b.get_book_id()==id)
				{
					cout<<"\n Book Id       : "<<b.get_book_id()<<endl;
					cout<<" Book Name     : "<<b.get_book_name()<<endl;
					cout<<" Author Name   : "<<b.get_book_author()<<endl;
					cout<<" Cost of Book  : "<<b.get_book_cost()<<endl;
					cout<<" No. of Pieces : "<<b.get_book_pieces()<<endl;
					cout<<"\n=======================================================\n";
					flag=1;
				}
			}
	else
		cout<<" 'book.dat' File does not Exists \n=======================================================\n";
	in.close();
	if(flag==0)
		cout<<" Book Not Found !!! \n=======================================================\n";
		
	int module_choice;
	cout<<" PRESS 1 TO SEARCH ANOTHER BOOK ELSE 0 : ";
	cin>>module_choice;
	if(module_choice==1)
		searchBook();
	
	cout<<"=======================================================\n PRESS 1 TO GO TO MAIN MENU AND 0 TO EXIT: ";
	cin>>module_choice;
	if(module_choice==1)
		main();
	else
		siddhant();
}

void viewStockBook()
{
	system("cls");
	cout<<"=======================================================\n                    Books In Stock              \n=======================================================\n";
	book b;
	
	fstream in("book.dat",ios::binary|ios::in);
	if(in!=NULL)
		while(in.read((char *)&b,sizeof(b)))
			{
				cout<<"\n Book Id       : "<<b.get_book_id()<<endl;
				cout<<" Book Name     : "<<b.get_book_name()<<endl;
				cout<<" Author Name   : "<<b.get_book_author()<<endl;
				cout<<" Cost of Book  : "<<b.get_book_cost()<<endl;
				cout<<" No. of Pieces : "<<b.get_book_pieces()<<endl;
				cout<<"\n=======================================================\n";
			}
	else
		cout<<" 'book.dat' File does not Exists \n=======================================================\n";
	in.close();
	
	int module_choice;
	cout<<" PRESS 1 TO GO TO MAIN MENU AND 0 TO EXIT: ";
	cin>>module_choice;
	if(module_choice==1)
		main();
	else
		siddhant();
}

void deleteBook()
{
	system("cls");
	
	cout<<"=======================================================\n               Delete Book From Stock              \n=======================================================\n";
	cout<<" Enter the Book Id   : ";
	long id;
	int flag=0;
	cin>>id;
	cout<<"=======================================================\n";
	book b,b2;
	
	fstream in("book.dat",ios::binary|ios::in);
	fstream out("book_temp.dat",ios::binary|ios::app|ios::ate|ios::out);
	if(in!=NULL)
		while(in.read((char *)&b,sizeof(b)))
			{
				if(b.get_book_id()==id)
				{
					flag=1;
					continue;
				}
				else
				{
					b2.set_book_id(b.get_book_id());
					b2.set_book_name(b.get_book_name());
					b2.set_book_author(b.get_book_author());
					b2.set_book_cost(b.get_book_cost());
					b2.set_book_pieces(b.get_book_pieces());
					out.write((char *)&b2,sizeof(b2));
				}
			}
	else
		cout<<" 'book.dat' File does not Exists \n=======================================================\n";
	in.close();
	out.close();
	
	if(flag==0)
	{
		cout<<" Book Not Found !!! \n=======================================================\n";
		system("del book_temp.dat");  //deteting book_temp.dat
	}
	else
	{
		system("del book.dat"); //deteting book.dat
		system("rename book_temp.dat book.dat"); //system rename book_temp.dat to book.dat
		cout<<" Book List has been Updated\n=======================================================\n";
	}
	
	int module_choice;
	cout<<" PRESS 1 TO DELETE ANOTHER BOOK ELSE 0 : ";
	cin>>module_choice;
	if(module_choice==1)
		deleteBook();
	cout<<"=======================================================\n PRESS 1 TO GO TO MAIN MENU AND 0 TO EXIT: ";
	cin>>module_choice;
	if(module_choice==1)
		main();
	else
		siddhant();
}

void updateBookNo()
{
	system("cls");
	
	cout<<"=======================================================\n       Update Number of Pieces Of Book In Stock            \n=======================================================\n";
	cout<<" Enter the Book Id   : ";
	long id;
	int flag=0;
	cin>>id;
	cout<<"=======================================================\n";
	book b,b2;
	
	fstream in("book.dat",ios::binary|ios::in);
	fstream out("book_temp.dat",ios::binary|ios::app|ios::ate|ios::out);
	if(in!=NULL)
		while(in.read((char *)&b,sizeof(b)))
			{
				if(b.get_book_id()==id)
				{
					flag=1;
					
					int pieces;
					cout<<" Enter No. of Pieces : ";
					cin>>pieces;
					b2.set_book_pieces(pieces);
					
					b2.set_book_id(b.get_book_id());
					b2.set_book_name(b.get_book_name());
					b2.set_book_author(b.get_book_author());
					b2.set_book_cost(b.get_book_cost());					
					cout<<"=======================================================\n";					
					cout<<" Book Id       : "<<b2.get_book_id()<<endl;
					cout<<" Book Name     : "<<b2.get_book_name()<<endl;
					cout<<" Author Name   : "<<b2.get_book_author()<<endl;
					cout<<" Cost of Book  : "<<b2.get_book_cost()<<endl;
					cout<<" No. of Pieces : "<<b2.get_book_pieces()<<endl;					
					out.write((char *)&b2,sizeof(b2));
				}
				else
				{
					b2.set_book_id(b.get_book_id());
					b2.set_book_name(b.get_book_name());
					b2.set_book_author(b.get_book_author());
					b2.set_book_cost(b.get_book_cost());
					b2.set_book_pieces(b.get_book_pieces());
					out.write((char *)&b2,sizeof(b2));
				}
			}
	else
		cout<<" 'book.dat' File does not Exists \n=======================================================\n";
	in.close();
	out.close();
	
	if(flag==0)
	{
		cout<<" Book Not Found !!! \n=======================================================\n";
		system("del book_temp.dat");  //deteting book_temp.dat
	}
	else
	{
		system("del book.dat"); //deteting book.dat
		system("rename book_temp.dat book.dat"); //system rename book_temp.dat to book.dat
		cout<<"=======================================================\n Book List has been Updated\n=======================================================\n";
	}
	
	int module_choice;
	cout<<" PRESS 1 TO UPDATE ANOTHER BOOK ELSE 0 : ";
	cin>>module_choice;
	if(module_choice==1)
		updateBookNo();
	cout<<"=======================================================\n PRESS 1 TO GO TO MAIN MENU AND 0 TO EXIT: ";
	cin>>module_choice;
	if(module_choice==1)
		main();
	else
		siddhant();
}

void sellBook()
{
	system("cls");
	cout<<"===============================================================\n                   Sell Book From Stock            \n===============================================================\n";
	
	book bok;
	bill bil;
	
	long bill_id=999;
	fstream inid("bill.dat",ios::binary|ios::in);
	if(inid!=NULL)
		while(inid.read((char *)&bil,sizeof(bil)))
			if(bill_id<bil.get_bill_id())
				bill_id=bil.get_bill_id();
	inid.close();
	
	cout<<" JUST ENTER BOOK ID TO CALCULATE BILL \n";	
	int flag;
	int i=-1; // for storing different elements in array sequence
	long book_id;
	float total_cost=0;
	int sell_f_choice=1;
	while(sell_f_choice==1)
	{
		// inputting product id and checking and then initialization of the objet bil and then writing
		cout<<"===============================================================\n Enter Product Id : ";
		cin>>book_id;
		cout<<"===============================================================\n";
		fstream in("book.dat",ios::binary|ios::in);
		if(in!=NULL)
		{
			flag=0;
			while(in.read((char *)&bok,sizeof(bok)))    //loop for checking id
			{
				if(book_id==bok.get_book_id())
				{
					i++;
					cout<<" Book Id     : "<<bok.get_book_id()<<endl;
					cout<<" Book Name   : "<<bok.get_book_name()<<endl;
					cout<<" Book Author : "<<bok.get_book_author()<<endl;
					cout<<" Book Price  : "<<bok.get_book_cost()<<endl;
					cout<<" Book Pieces : "<<bok.get_book_pieces();
					bil.set_product_name(bok.get_book_name(),i);
					bil.set_product_cost(bok.get_book_cost(),i);
					bil.set_product_id(bok.get_book_id(),i);
					cout<<"\n Enter Quantity Of Product : ";
					int n;
					cin>>n;
					bil.set_quantity(n,i);
					total_cost += n*bil.get_product_cost(i);
					bil.set_total_cost(total_cost);
					flag=1;
					break;	
				}
			}
			if(flag==0)
			cout<<" Book Not Found \n";			
		}
		else
		{
			cout<<"\n =======================================\n THE FILE 'bill.dat' NOT FOUND \n";
		}
		in.close();
		
		//  Updating my books in stock if flag is positive
		if(flag==1)
		{
			book b,b2;
			fstream in("book.dat",ios::binary|ios::in);
			fstream out("book_temp.dat",ios::binary|ios::app|ios::ate|ios::out);
			while(in.read((char *)&b,sizeof(b)))
			{
				if(b.get_book_id()==bil.get_product_id(i))
				{
					b2.set_book_pieces(b.get_book_pieces()-bil.get_quantity(i));
					
					b2.set_book_id(b.get_book_id());
					b2.set_book_name(b.get_book_name());
					b2.set_book_author(b.get_book_author());
					b2.set_book_cost(b.get_book_cost());
					out.write((char *)&b2,sizeof(b2));
				}
				else
				{
					b2.set_book_id(b.get_book_id());
					b2.set_book_name(b.get_book_name());
					b2.set_book_author(b.get_book_author());
					b2.set_book_cost(b.get_book_cost());
					b2.set_book_pieces(b.get_book_pieces());
					out.write((char *)&b2,sizeof(b2));
				}
			}
			in.close();
			out.close();
			system("del book.dat"); //deteting book.dat
			system("rename book_temp.dat book.dat"); //system rename book_temp.dat to book.dat
		}
		
		cout<<"===============================================================\n PRESS 1 TO ADD MORE PRODUCT OTHERWISE 0 TO GO TO BILL PAGE: ";
		cin>>sell_f_choice;
	}
	
	if(flag==1)
	{
		cout<<"\n===============================================================\n                   PUT DOWN CUSTOMER DETAILS \n===============================================================\n CUSTOMER NAME: ";
		cin.ignore();
		string cn;
		getline(cin,cn);
		bil.set_customer_name(cn);
		bil.set_bill_id(bill_id+1);
		bil.set_no_of_books(i+1);
		cout<<" Enter Date: ";
		string d;
		getline(cin,d);
		bil.set_date(d);
		
		fstream out("bill.dat",ios::binary|ios::app|ios::ate|ios::out);
		out.write((char *)&bil,sizeof(bil));
		out.close();
		
		cout<<"\n PRESS 1 TO GENERATE THE BILL : ";
		int choice;
		cin>>choice;
		if(choice==1)
		{
			//displaying the details of the bill
			system("cls");
			cout<<"\n========================================================================";
			cout<<"\n Customer Name: "<<bil.get_customer_name();
			cout<<"  Bill Id: "<<bil.get_bill_id();
			cout<<"  Date: "<<bil.get_date();
			cout<<"\n========================================================================";
			cout<<"\n Sr.No.                      Book Name      Price  Quantity    Total  \n========================================================================";
			for(int j=0;j<bil.get_no_of_books();j++)
			{
				cout<<"\n"<<setw(7)<<j+1<<setw(31)<<bil.get_product_name(j);
				cout<<setw(11)<<bil.get_product_cost(j)<<setw(10)<<bil.get_quantity(j);
				cout<<setw(9)<<(bil.get_product_cost(j)*bil.get_quantity(j));
			}
			cout<<"\n========================================================================\n                                                Total Bill: "<<setw(8)<<bil.get_total_cost();
		}
	}
	
	int module_choice;
	cout<<"\n========================================================================\n PRESS 1 TO GENERATE ANOTHER BILL, 2 TO GO TO MAIN MENU AND 0 TO EXIT: ";
	cin>>module_choice;
	if(module_choice==2)
		main();
	else if(module_choice==1)
		sellBook();
	else
		siddhant();
}

void viewBill()
{
	system("cls");
	cout<<"========================================================================\n                           View Bill Data            \n========================================================================\n";
	long id;
	bill b;
	cout<<" Please Enter your Bill Id : ";
	cin>>id;
	int flag=0;
	fstream in("bill.dat",ios::binary|ios::in);
	if(in!=NULL)
	{
		while(in.read((char *)&b,sizeof(b)))
		{
			if(id==b.get_bill_id())
			{
				flag=1;
				system("cls");
				cout<<"\n========================================================================";
				cout<<"\n Customer Name: "<<b.get_customer_name();
				cout<<"  Bill Id: "<<b.get_bill_id();
				cout<<"  Date: "<<b.get_date();
				cout<<"\n========================================================================";
				cout<<"\n Sr.No.                      Book Name      Price  Quantity    Total  \n========================================================================";
				for(int j=0;j<b.get_no_of_books();j++)
				{
					cout<<"\n"<<setw(7)<<j+1<<setw(31)<<b.get_product_name(j);
					cout<<setw(11)<<b.get_product_cost(j)<<setw(10)<<b.get_quantity(j);
					cout<<setw(9)<<(b.get_product_cost(j)*b.get_quantity(j));
				}
				cout<<"\n========================================================================\n                                                Total Bill: "<<setw(8)<<b.get_total_cost();
				break;
			}
		}
		if(flag==0)
			cout<<"========================================================================\n Wrong Bill Id Entered";
	}
	else
	{
		cout<<"========================================================================\n The File 'bill.dat' not Found";
	}
	in.close();
	
	int module_choice;
	cout<<"\n========================================================================\n PRESS 1 FOR VIEWING ANOTHER BILL, 2 FOR MAIN MENU AND 0 TO EXIT: ";
	cin>>module_choice;
	if(module_choice==1)
		viewBill();
	else if(module_choice==2)
		main();
	else
		siddhant();
}

void deleteBill()
{
	system("cls");
	
	cout<<"=======================================================\n                   Delete Bill Data              \n=======================================================\n";
	cout<<" Enter the Bill Id   : ";
	long id;
	int flag=0;
	cin>>id;
	cout<<"=======================================================\n";
	bill b,b2;
	
	fstream in("bill.dat",ios::binary|ios::in);
	fstream out("bill_temp.dat",ios::binary|ios::app|ios::ate|ios::out);
	if(in!=NULL)
		while(in.read((char *)&b,sizeof(b)))
			{
				if(b.get_bill_id()==id)
				{
					flag=1;
					continue;
				}
				else
				{
					b2.set_bill_id(b.get_bill_id());
					b2.set_customer_name(b.get_customer_name());
					b2.set_date(b.get_date());
					b2.set_no_of_books(b.get_no_of_books());
					b2.set_total_cost(b.get_total_cost());
					for(int i=0;i<b.get_no_of_books();i++)
					{
						b2.set_product_name(b.get_product_name(i),i);
						b2.set_product_id(b.get_product_id(i),i);
						b2.set_product_cost(b.get_product_cost(i),i);
						b2.set_quantity(b.get_quantity(i),i);
					}
					out.write((char *)&b2,sizeof(b2));
				}
			}
	else
		cout<<" 'bill.dat' File does not Exists \n=======================================================\n";
	in.close();
	out.close();
	
	if(flag==0)
	{
		cout<<" Bill Id Not Found !!! \n=======================================================\n";
		system("del bill_temp.dat");  //deteting bill_temp.dat
	}
	else
	{
		system("del bill.dat"); //deteting bill.dat
		system("rename bill_temp.dat bill.dat"); //system rename bill_temp.dat to book.dat
		cout<<" Bill List has been Updated\n=======================================================\n";
	}

	int module_choice;
	cout<<" PRESS 1 TO DELETE ANOTHER BILL ELSE 0 : ";
	cin>>module_choice;
	if(module_choice==1)
		deleteBill();
	cout<<"=======================================================\n PRESS 1 TO GO TO MAIN MENU AND 0 TO EXIT: ";
	cin>>module_choice;
	if(module_choice==1)
		main();
	else
		siddhant();
}
