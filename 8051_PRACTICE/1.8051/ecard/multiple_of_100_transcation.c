#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
static int bal=1000;
const int pinn=1234;
int amount;
int with()
{
printf("enter the pin\n");
int a;
scanf("%d",&a);
if(a==pinn)
{
	printf("enter the amount to withdraw (in mutiple of 100):\n");
	scanf("%d",&amount);
	if(amount%100==0&&amount<=bal)
	{
		bal-=amount;
		printf("withdraw suceessfull : remaining ballace %d\n",bal);
	}
	else 
	{
		printf("invalid amount\n");
	}

}
else 
printf("invalid password try again \n");
}
int deposite(void)
{
int a;
printf("enter the deposite amount\n");
scanf("%d",&a);
bal+=a;
}
void check(void)
{
printf("your balance is:%d\n",bal);
}

void pin(void)
{

}

int main(void)
{
while(1)
{
	
printf("1.withdraw 2.deposite 3.check ballace 5.exit 4.change pin\n");
char ch=0;
__fpurge(stdin);
scanf("%c",&ch);
switch(ch)
{
case '1':with();break;
case '2':deposite();break;
case '3':check();break;
case '5': exit(1);break;
case '4': pin();break;
default : printf("invalid key\n");
}
}
}
