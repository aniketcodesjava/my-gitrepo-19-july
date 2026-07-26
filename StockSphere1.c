#include<stdio.h>

void signup()
{
	char fname[40];
	char lname[40];
	char email[50];
	char password[50];
	printf("          *Fill This Form\n");
	printf("\n");
	printf("enter your first name:");
	scanf("%s",&fname);
	printf("enter your last name:");
	scanf("%s",&lname);
	printf("enter your email:");
	scanf("%s",&email);
	printf("enter your password:");
	scanf("\n%s",&password);
	printf("\n");
	printf("Sign-Up Successfully Completed..");
	printf("\n");
}

void login()
{
	char email[50];
	char password[50];
	printf("\n");
	printf("         *Login Page:");
	 printf("\n");
	 printf("\n");
	printf("Enter Your Email:");
	scanf("%s",&email);
	printf("Enter Your Password:");
	scanf("%s",&password);
    printf("\n");
    printf("Login Successfully Completed..");
    printf("\n");
    printf("\n");
}


void addProduct()
{
	struct product
	{
		 int id;
		 char name[50];
		 int price;
	};
	
       FILE *p;
       struct product p1;
       printf("Enter Product Id:");
       scanf("%d",&p1.id);
       printf("Enter Product Name:");
       scanf("%s",&p1.name);
       printf("Enter Product Price:");
       scanf("%d",&p1.price);
       p=fopen("Stock.txt","a");
       if(p==NULL)
       {
       	 printf("Product Will Be Not Found.");
	   }
	   fprintf(p,"%d %s %d\n", p1.id,p1.name,p1.price);
	   fclose(p);
	   printf("Product Added Successfully...");
	   printf("\n");
}



 int update()
 {
 	FILE *p, *f;
 	int id,qty,newqty,sid;
 	char name[40];
 	int found=0;
 	p=fopen("Stock.txt","r");
 	f=fopen("temp.txt","w");
 	
 	if(p==NULL || f==NULL)
 	{
 		printf("Product Not Found.");
	 }
	 
	 printf("Enter Your Search Id:");
	 scanf("%d",&sid);
	 while(fscanf(p,"%d %s %d",&id,name,&qty)!=EOF)
	 {
	 	if(id==sid)
	 	{
	 		printf("Increase Product Price:");
	 		printf("\n");
	 		scanf("%d",&newqty);
	 	    qty+=newqty;
	 		found =1;
		 }
		fprintf(f, "%d %s %d\n", id, name, qty);
	 }
	  fclose(p);
	  fclose(f);
	  remove("Stock.txt");
	  rename("temp.txt","Stock.txt");
	  
	  if(found)
	  {
	  	printf("Stock Update Successfully..");
	  }
	  else
	  {
	  	printf("Stock Not Update..");
	  }
 }

int display()
{
	FILE *p;
	char ch;
	p=fopen("Stock.txt","r");
	if(p==NULL)
	{
		printf("Products Not Found..");
		return 0;
	}
	while((ch=fgetc(p))!=EOF)
	{
		printf("%c",ch);
	}
	fclose(p);
	return 0;
}

int delete()
{
	FILE *p,*f;
	int id,qty,did;
	char name[40];
	p=fopen("Stock.txt","r");
	f=fopen("temp.txt","w");
	if(p==NULL || f==NULL)
	{
		printf("Products Not Found..");
		return 0;
	}
	printf("Enter Id To Delete:");
	scanf("%d",&did);
	while(fscanf(p,"%d %s %d",&id,name,&qty)!=EOF)
	{
		if(id!=did)
		{
			fprintf(f,"%d %s %d\n",id,name,qty);
		}
	}
	 fclose(p);
	 fclose(f);
	 
	 remove("Stock.txt");
	 rename("temp.txt","Stock.txt");
	 printf("record deleted successfully..");
}


void search()
{
	FILE *pf;
	int n,p,f=0;
	char srch[40];
	char name[50];
	pf=fopen("Stock.txt","r");
	if(pf==NULL)
	{
	   printf("Product not found.");
	}
	printf("Enter Product name to search:");
	scanf("%s",&srch);
	while((fscanf(pf,"%d %s %d",&n,name,&p)!=EOF))
	{
		if(strcmp(srch,name)==0)
		{
			printf("Product Found:   ");
			printf("Number:%d Name:%s Price:%d",n,name,p);
			f=1;
			break;
		}
	}
	  if(!f)
	  {
	  	printf("product not found:");
	  }
	   fclose(pf);
}


void billAmount()
{
	FILE *p;
	char name[50],pname[50];
	int qty,price,number;
	int found=0;
	int total=0;
	p=fopen("Stock.txt","r");
	printf("enter product name:");
	scanf("%s",&pname);
	printf("enter product Quanity:");
	scanf("%d",&qty);
	while(fscanf(p,"%d %s %d",&number,name,&price)!=EOF)
	{
		if(strcmp(name,pname)==0)
		{
			found=1;
			total=price*qty;
			printf("Price:%d\n",price);
			printf("Quantity:%d\n",qty);
			printf("Total:%d\n",total);
			printf("\n");
			break;
		}
	}
	 if(!found)
	 {
	 	printf("product not found.");
	 }
	 fclose(p);
}




void calculator()
{
	int ch;
	do
	{
	printf("1:Addition \n2:Substraction \n3:Multiplication \n4:Division \n5:Exit");
	printf("\n");
	printf("\nEnter your choice:");
	scanf("\n%d",&ch);
	printf("\n");
	switch(ch)
	{
		case 1:
			       printf(" ");
			       int x,y;
			       Addition(x,y);
			       printf("\n");
			     break;
		case 2:
			    printf(" ");
			       int s,t;
			      Substraction(s,t);
			       printf("\n");
			     break;
		case 3:
			    printf(" ");
			       int u,v;
			       Multiplication(u,v);
			       printf("\n");
			     break;
		case 4:
			     printf(" ");
			       int e,f;
			       Division(f,e);
			       printf("\n");
			     break;
		case 5:
			      printf("Exit");
			      break;
			
	}
}  while(ch!=5);
}

                 void Addition(int a,int b)
                {
     	              int c;
     	              printf("Enter Your First Number:");
     	              scanf("%d",&a);
     	              printf(" Enter Your Second Number:");
     	              scanf("%d",&b);
     	              c=a+b;
     	              printf("                                Addition=%d:",c);
     	              printf("\n");
	            }
   
   

               
                 void Substraction(int a,int b)
                {
     	              int c;
     	              printf("Enter Your First Number:");
     	              scanf("%d",&a);
     	              printf(" Enter Your Second Number:");
     	              scanf("%d",&b);
     	              c=a-b;
     	              printf("                                Substraction=%d:",c);
     	              printf("\n");
	            }
	            
	            
	            
	            
	            
                 void Multiplication(int a,int b)
                {
     	              int c;
     	              printf("Enter Your First Number:");
     	              scanf("%d",&a);
     	              printf(" Enter Your Second Number:");
     	              scanf("%d",&b);
     	              c=a*b;
     	              printf("                                Multiplication=%d:",c);
     	              printf("\n");
	            }
	            
	            
	            
	            
	            
	            
                 void Division(int a,int b)
                {
     	              int c;
     	              printf("Enter Your First Number:");
     	              scanf("%d",&a);
     	              printf(" Enter Your Second Number:");
     	              scanf("%d",&b);
     	              c=a/b;
     	              printf("                                Division=%d:",c);
     	              printf("\n");
	            }
	            

void menu()
{
 printf("******************************************** WELCOME TO MY STORE **************************************************");
     printf("\n");  
	 printf("\n"); 
	 int choice;
    printf("Choose Your Option:");
    printf("\n");
    	do
	{
    printf("\n1:Add Product: \n2:Update Product: \n3:Delete Product: \n4:Display Product: \n5:Search Product: \n6:Billing Ammount: \n7:Use Calculator: \n8:About: \n9:Exit ");
    printf("\n");
	printf("\n");   
    printf("Enter Your Choice:");
    scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				     // printf("Add Product:");
				      addProduct();
			           break;
				      
			case 2:
				      // printf("Update Product:");
				     
				       update();
				       break;
			case 3:
				       //printf("Deleter Product");
				       delete();
				       break;
			case 4:
				       //printf("Display Product:");
				        printf("-> Availabel Products Are:");
				      printf("\n");
				       display();
				       break;
			case 5:
				       //printf("Search Product:");
				       search();
				       break;
			case 6:
				       //printf("Billing Ammount:");
				       billAmount();
				       break;
	
			case 7:
				       // printf("Calci");
				        calculator();
				        break;
			case 8:
			          

    printf("About MyStock:\n");
    printf("-> 'StockSphere' Created in 29-July-2026.\n");
    printf("-> 'StockSphere' Owner Name is 'Aniket Sawant.'\n");
    printf("-> High-quality products available at the best prices.\n");
    printf("-> Fresh stock with reliable and trusted items.\n");
    printf("-> Limited-time offers on selected products.\n");
    printf("-> Best deals with guaranteed customer satisfaction.\n");
    printf("-> Shop now and experience smooth and easy stock management.\n");
    printf("..................................................................Contact Id- aniketsawant2416@gmail.com");
    printf("\n \n");
			    
				        break;     
			case 9:
				        printf("Exit:");
				        break;
		}
	}	  while(choice!=9);
}



int main()
{
	signup();
	login();
	menu();
}
