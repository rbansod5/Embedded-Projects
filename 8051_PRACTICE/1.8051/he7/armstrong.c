


// Define ARMSTRONG: 


12=1^2+2^2

1634=1^4+6^4+3^4+4^4=1634



int num=1234;


1)Total number of digits in a number
iterate the loop till getting zero value

temp=1234%10=4
take one variable increment it
num=1234/10

cnt=0;
while(num)//1234,123,12,1,0 breaks the loop
{

	temp=num%10;//4,3,2,1
	cnt++;//1,2,3,4
	num=num/10;//123,12,1,0
}


