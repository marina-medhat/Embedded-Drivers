#include <stdio.h>
#include "BIT_MATH.h"

int circshiftright(int x,int shiftno);
int circshiftleft(int x,int shiftno);

void main()
{
int x=0b00110101;//01001101    //11010100
int y,z;
int shiftno=2;
y=circshiftright(x,2);
z=circshiftleft(x,2);
printf("%d\n%d",y,z);

}


int circshiftright(int x,int shiftno)
{
int temp;
for(int i=0;i<shiftno;i++)
{
	temp=GET_BIT(x,0);
	x=x>>1;
	if(temp)
		SET_BIT(x,7);
	else
		CLR_BIT(x,7);
}
return x;
}

int circshiftleft(int x,int shiftno)
{
int temp;
for(int i=0;i<shiftno;i++)
{
	temp=GET_BIT(x,7);
	x=x<<1;
	if(temp)
		SET_BIT(x,0);
	else
		CLR_BIT(x,0);
}
return x;
}