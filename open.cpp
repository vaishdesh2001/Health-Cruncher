#include<fstream.h>
#include<conio.h>
void delay()
{
 for(int k=0;k<1000;k++)
 cout<<"";
}

void  intro()
{
  for(int i=0;i<22;i+=2)
  {
		for(int j=0;j<80;j++)
		{
			delay();
			cout<<"|";
		}
  cout<<endl;
  }
gotoxy(0,0);
  for( i=1;i<22;i+=2)
  {
		for(int j=0;j<80;j++)
		{
			delay();
			cout<<".";
		}
  cout<<endl;
  }
clrscr();

fstream f;
f.open("intro.txt",ios::in);
char str[80];
while(f.getline(str,80,'*'))
{
 cout<<str;
}
cout<<endl;
cout<<"PRESS ANY KEY TO BEGIN"<<endl;
getch();
clrscr();
}