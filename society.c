#include<stdio.h>
#include<string.h>
struct mem
{
        int id;
        char name[20];           
};
struct flat
{
        
        int flatno;
        char type[20];
        int fpay;
};
struct vendor
{
        int no;
        char name[20];
};
struct exp
{
        char date[20];
        int billno;
        char typeexp[20];
        int exp;
        struct vendor v;
};
int i,j,k,l,p,n;
struct mem m[2];
//entering member details
void mem()
{
	for(i=0;i<2;i++)
	{
	        m[i].id=i+1;
	        printf("\n Enter member name");
	       scanf("%s",m[i].name); 
	}
}
struct flat f[2];
int payment=0;
int totalexp=0;
//entering flat details
void flat()
{
	for(j=0;j<2;j++)
	{
	        f[j].flatno=j+100;
	        printf("\n enter type of flat"); 
	       scanf("%s",f[j].type); 
	       printf("\n enter flat payment");
	       scanf("%d",&f[j].fpay);
	       payment+=f[j].fpay;
	}
}
struct exp e[2];
//entering expenditure details
void expenditure()
{
	for(k=0;k<2;k++)
	{
	        e[k].billno=k+1000;
	        printf("\n expenditure date");
	       scanf("%s",e[k].date); 
	       printf("\n type of expenditure");
	       scanf("%s",e[k].typeexp); 
	       printf("\n expenditure");
	       scanf("%d",&e[k].exp);
	       totalexp+=e[k].exp;
	       printf("\n enter name of vendor");
	       scanf("%s",e[k].v.name); 
	       printf("vendor number");
	       scanf("%d",&e[k].v.no);
	}
}

//Displaying balance amount
void money()
{
	printf("\n total payment\n");
	printf("%d",payment);
	printf("\n total expenditure\n");
	printf("%d",totalexp);
	printf("\n balance amount\n");
	printf("%d",payment-totalexp);
}
//Entering new member
void newmember()
{
	printf("\n Enter details for a new member\n");
	m[i].id=i+1;
	printf("\n Enter member name");
	scanf("%s",m[i].name); 
	 f[j].flatno=j+100;
	 printf("\n enter type of flat"); 
	 scanf("%s",f[j].type); 
	 printf("\n enter flat payment");
	 scanf("%d",&f[j].fpay);
	 payment+=f[j].fpay;
	 printf("\n type of expenditure is lift");
	 strcpy(e[k].typeexp,"lift");
	 e[k].billno=k+1000;
	 printf("\n expenditure date");
	 scanf("%s",e[k].date); 
	 printf("\n expenditure");
	 scanf("%d",&e[k].exp);
	 totalexp+=e[k].exp;
	 printf("\n enter name of vendor");
	 scanf("%s",e[k].v.name); 
	 printf("vendor number");
	 scanf("%d",&e[k].v.no);
}
int main()
{
	int y=1;
	while(y==1)
	{
		int c;
		printf("\n1.Enter member details");
		printf("\n2.Enter flat details");
		printf("\n3.Enter expenditure details");
		printf("\n4.money details");
		printf("\n5.Enter new member");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				mem();
			break;
			case 2:
				flat();
			break;
			case 3:
				expenditure();
			break;
			case 4:
				money();
			break;
			case 5:
				newmember();
			break;
			default:
			break;
		}
		printf("\n do u want to continue?");
		scanf("%d",&y);
	}
	return 0;
}
