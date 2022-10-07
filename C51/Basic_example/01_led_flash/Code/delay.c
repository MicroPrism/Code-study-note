#define uint unsigned int
uint i,j;
void delay(uint xms)
{
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);
}