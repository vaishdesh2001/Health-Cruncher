#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void delay1()
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
			delay1();
			cout<<"|";
		}
	cout<<endl;
	}
	gotoxy(0,0);
	for( i=1;i<22;i+=2)
	{
		for(int j=0;j<80;j++)
		{
			delay1();
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
		if(f.eof())
			break;
	}
	cout<<endl;
	cout<<"PRESS ANY KEY TO BEGIN"<<endl;
	getch();
	clrscr();
}

char nfile[30];
 //BASIC INPUT OUTPUT FOR REGISTRATION
struct date
{
	 int dd;
	 int mm;
	 int yy;
};
void health_test();
void dic();
void delay()
{
	for(int j=0;j<1000;j++)
		{
			for(int i=0;i<1000;i++)
				{
					cout<<"";
				}
		}
}

class registration
{
    private:
    char name[50];
    date dob;
    char gender;
    char mobile[12];
    char email[50];
    float height;
    float weight;
    float bmi;
    char username[50]; 
   	//Check whether unique
	char password[50];
    char confirm_pass[50];
	//Check whether it matches or not

    public:
    void enter();
    void pwd_chk(char []);
    void enter_username();
    void reconfirm();
    void calbmi();
    void login();
    void display();
    void display_courses(int);
};

void registration :: pwd_chk(char str[])     //To replace letters of password with other character
{
	int i;
	for(i=0; ; i++)
    {
		str[i] = getch();

		if(str[i] == 8 )
		{
			putch('\b');
			cout<<" ";
			putch('\b');
			i-=2;
        }

		else if(str[i] != 13)
		{
			putch('*');
		}

		else if(str[i]==13)
			break;
    }
	
	str[i]= '\0';
    cout<<endl;
}


void registration::enter()
{
	cout<<"Name:        ";
	gets(name);
	cout<<"Date of birth:        ";
	day:
	cout<<endl;
	cout<<"Enter Day"<<endl;
   	cin>>dob.dd;
	if(dob.dd>31 && dob.dd<1)
	{
		cout<<"Enter Valid day"<<endl;
		goto day;
	}
	
	mon:
	cout<<"Enter Month"<<endl;
   	cin>>dob.mm;
	if(dob.mm>12&& dob.mm<1)
	{
		cout<<"Enter Valid month"<<endl;
		goto mon;
	}
	
	year:
	cout<<"Enter Year"<<endl;
   	cin>>dob.yy;
	if(dob.yy<1)
	{
		cout<<"Enter Valid Year"<<endl;
		goto year;
	}

	cout<<"Gender:    (m/f)    ";
    cin>>gender;
	phone:
	cout<<"Enter the mobile number"<<endl;
    cin>>mobile;
	int len = strlen(mobile);
	int chk = 0;
	for(int i = 0; mobile[i]!=0; i++)
	{
		if(!isdigit(mobile[i]))
		{
			chk = 1;
			break;
		}
	}
			
		
	
	if(chk == 1 || len!=10)
	{
		cout<<"Enter Valid Mobile Number"<<endl;
		goto phone;
	}
	
	cout<<"Enter email address"<<endl;
	cin>>email;

	enter_username();
	cout<<"Enter password to be set:        ";
   	pwd_chk(password);
   	reconfirm();

	cout<<"Enter your height (in cm)        :";
    cin>>height;
    height = height/100.0;
   
	cout<<"Enter your weight (in kg)                      :";
   	cin>>weight; 
	cout<<"Press enter to confirm"<<endl;
	getch();
	calbmi();

}

void registration::enter_username()
{
    int chk=-1;
    fstream f;
    registration r;


    f.open(nfile,ios::in | ios::binary);




	check1:

	cout<<"Username you want to set:        ";
    cin >> username;

    f.seekp(ios::beg);
    while(f.read((char*)&r, sizeof(r)))
    {

        if(strcmpi(r.username,username)==0)
       {

            chk=0;
            break;
	   }
    }

    if(chk==-1)
        cout<<"Username available"<<endl;
	else
    {
		chk = -1;
		cout<<"Username already taken!"<<endl;
		goto check1;

    }

	f.seekp(0, ios::end);

    f.close();
}


void registration::reconfirm()
{
	cout<<"Reconfirm the password:        ";
	check:
    pwd_chk(confirm_pass);

    if(!(strcmp(confirm_pass,password)==0))
    {
		strcpy(confirm_pass,"\0");
		cout<<"Password mismatch, please renter: "<<endl;
		goto check;
    }
}

void registration :: calbmi()
{
    bmi = weight/(height*height);
}

void registration::login()
{

	fstream f;
	char user[50];
	char pass[50];
	int chk=-1;
	registration q;
	clrscr();

	f.open(nfile,ios::in|ios::binary|ios::out);
	reenter:

	clrscr();
	f.close();
	f.open(nfile,ios::in|ios::binary|ios::out);
	cout<<"Enter the username as 'quit' if you want to go back to menu"<<endl;
	gotoxy(15,15);
	cout<<"Username: ";
	gets(user);
	if (strcmp(user, "quit") == 0)
	  {
			cout << "quitting";
			f.seekp(0, ios::end);
			f.close();
         chk++;
	  }
	else
	  {
			gotoxy(15,16);
			strcpy(pass,"\0");
			cout<<"Password: ";
			pwd_chk(pass);
	  }
	f.seekg(0);

	while(f.read((char*)&q, sizeof(q)))
	{
		if((strcmp(q.username,user)==0) && (strcmp(q.password,pass)==0))
		{
			q.display();
			cout<<"Press Enter";
			getch();
			chk++;
			break;
		}
	 }

	if(chk==-1)
	 {
		cout<<"INCORRECT Username/Password"<<endl;
		getch();
		goto reenter;
	 }

	f.seekp(0, ios::end);
	f.close();
}

void display_diet()
{
	char str[80];
	fstream q;
	q.open("diet.txt",ios::in);
	while(q.getline(str,80,'*'))
	{
		cout<<str;
		if (q.eof())
			break;
	}
}

void registration :: display()
{
	int choice;
	clrscr();
	cout<<"--------------------------USER PROFILE-------------------------------"<<endl;
	cout<<"Username: "<<username<<endl;
	cout<<"Name: "<<name<<endl;
	cout<<"Date of birth: "<<dob.dd<<"-"<<dob.mm<<"-"<<dob.yy<<endl;
	cout<<"Gender: "<<gender<<endl;
	cout<<"Mobile Number: "<<mobile<<endl;
	cout<<"Email address: "<<email<<endl;
	cout<<"Height: (in m) "<<height<<endl;
	cout<<"Weight:  (in kg)"<<weight<<endl;
	cout<<"BMI: (in  kg/m^2) "<<bmi<<endl;
	l:
	cout<<"1. View your allotted course: "<<endl;
	cout<<"2. View your allotted diet plan"<<endl;
	cout<<"3. Go back to menu"<<endl;
	cout<<"Enter your choice"<<endl;
	 cin>>choice;
	if(choice==1)
	{
		clrscr();
		display_courses(bmi);
		cout<<"Press Enter"<<endl;
		getch();
		goto l;
	}

	 else if(choice==2)
	{
		clrscr();
		display_diet();
		cout<<"Press Enter"<<endl;
		getch();
		goto l;
	}
	else if(choice == 3)
		goto p;

	p:

}


void access_file()    //Takes details of only ONE user as and when called
{
	registration r;

	r.enter();
	fstream f;


	f.open(nfile, ios::app | ios::binary);
	f.write((char*)&r, sizeof(r));


	f.close();
}

void access_filelogin()
{
	 registration r;
	 r.login();
}


void registration :: display_courses(int val)
{
    fstream f, f1;
	char str[80];
    if(val<=18.5)
	{

		f.open("beginner.txt", ios::in);

		while(f.getline(str, 80, '*'))
		{
			cout<<str;
			cout<<endl;
			if(f.eof())
				break;
		}
	    f.close();

    }

    else if(val>18.5 && val<=25)
    {

		f.open("intermed.txt", ios::in);

		while(f.getline(str, 80, '*'))
		{
			cout<<str;
			cout<<endl;
			if(f.eof())
				break;
		}
		f.close();

    }
    else if(val>25 && val<=30)
    {
		f.open("advanced.txt", ios::in);

		while(f.getline(str, 80, '*'))
		{
			cout<<str;
			cout<<endl;
			if(f.eof())
				break;
		}
		f.close();
    }
    else if(val>30)
    {


		f.open("beginner.txt", ios::in);

		while(f.getline(str, 80, '*'))
		{
			cout<<str;
			cout<<endl;
			if(f.eof())
				break;
		}
	    f.close();

    }
}

void drawrect(int, int);

void sign_up()
{
	access_file();
}

void log_in()
{
	access_filelogin();
}


void display_options()
{
	gotoxy(35,8);
	cout<<"1.SIGN UP";

	gotoxy(35,12);
	cout<<"2.LOG IN";

	gotoxy(35,16);
	cout<<"3.EXERCISE";
	gotoxy(35, 17);
	cout<<"BROWSER";

	gotoxy(35, 21);
	cout<<"4.HEALTH TEST";

	gotoxy(60,3);
	cout<<"Press 0 to exit"<<endl;

	gotoxy(10, 25);
	cout<<"MOVE THE RECTANGLE USING 1, 2, and 3 keys AND HIT ENTER TO CHOOSE "<<endl;

}

void menu()
{
	char choice;
	int i;
	int q;

	display_options();
	drawrect(28, 5);

	for(i=0; ; i++)
	{
		choice = getch();
		if(choice == '1')
		{
			clrscr();
			display_options();
			q = 6;
			drawrect(28,5);
		}

		if(choice == '2')
		{
			clrscr();
			display_options();
			q = 10;
			drawrect(28,9);
		}

		if(choice == '3')
		{
			clrscr();
			display_options();
			q = 14;
			drawrect(28,13);
		}

		if(choice == '4')
		{
			clrscr();
			display_options();
			q = 19;
			drawrect(28,18);
		}
		else if(choice == '0')
			exit(0);


		if(choice == 13)
		{
			if(q==6)
			{
				clrscr();
				sign_up();
				clrscr();
				display_options();
				//cout<<"Press enter to return to menu"<<endl;
				//getch();
				//sign up
			}
			
			else if(q==10)
			{
				clrscr();
				log_in();
				clrscr();
				display_options();
				//login;
			}
			else if(q==14)
			{

				clrscr();
				dic();
				clrscr();
				display_options();

			}

			else if(q==19)
			{
				clrscr();
				health_test();
				clrscr();
				display_options();
			}
		}

    }

}

void drawrect(int posx, int posy)
{
	int i;
	int x, y ;
	 x = posx;
	 y = posy;
	 for(i=0; i<20; i++,x++)
	 {
	  gotoxy(x,y);
	cout<<".";

	 }

	  for(i=0; i<4; i++,y++)
	 {
	gotoxy(x,y);
	cout<<".";

	  }

	 for(i=0; i<20; i++,x--)
	 {
	gotoxy(x,y);
	  cout<<".";

	 }

	 for(i=0; i<4; i++,y--)
	 {
	  gotoxy(x,y);
	cout<<".";

	 }


}

void dic()
{
	char str[80],find[80],s[80];
	int check=0;
	start:
	cout<<"Search for exercise:"<<endl;
	gets(find);
	fstream f;
	f.open("dic.txt",ios::in);
	strcat(find,"@*");
	while(f.getline(str,80))
	{
		if(strcmpi(str,find)==0)
		{
			check++;
			for(int i=0;i<4;i++)
			{
				f.getline(str,80,'*');
				cout<<str;
				if(f.eof())
				break;
			}
		}
	}
	cout<<endl;
	cout<<"Hit Enter"<<endl;
	getch();
	
	if(check==0)
	{
		cout<<"Exercise doesn't exist!!"<<endl;
		cout<<"Enter a valid exercise!"<<endl;
		goto start;
	}
}


void health_test()
{

	clrscr();
	int var;
	float totsum =  0;
	int nv = 0;

	cout<<"Welcome to a simple way to find out how healthy you are"<<endl;
	cout<<"This is a redefined test which includes"<<endl;
	cout<<"the best methods to calculate your 'health score' "<<endl;
	cout<<"Simply check the boxes which fits the question answer best"<<endl;
	cout<<"Press enter to begin"<<endl;
	getch();
	clrscr();
	cout<<"Enter your food preferences"<<endl;
	cout<<"1. I don't have any food preferences"<<endl;
	cout<<"2. I'm a vegetarian"<<endl;
	cout<<"3. I'm a non-vegetarian"<<endl;
	cout<<"4. I'm a vegan"<<endl;
	cin>>var;
	if(var==1)
	{	totsum = 0;  nv = 1;}
	else if(var==2)
		totsum = 1;
	else if(var==3)
	{	totsum = 1.5; nv = 1;}
	else if(var==4)
		totsum = -1;
	cout<<"Hit enter to move on"<<endl;
	getch();
	clrscr();

	cout<<"How often do you have fruits"<<endl;
	cout<<"1. Once a day"<<endl;
	cout<<"2. 3-4 times a week"<<endl;
	cout<<"3. Once a week"<<endl;
	cout<<"4. Rarely"<<endl;
	cin>>var;
	if(var==1)
		totsum+=2;
	else if(var==2)
		totsum+=1;
	else if(var==3)
		totsum+=0.5;
	else if(var==4)
		totsum--;
	cout<<"Hit enter to move on"<<endl;
	getch();
	clrscr();

	cout<<"How often do you have green leafy vegetables"<<endl;
	cout<<"1. Once a day"<<endl;
	cout<<"2. 3-4 times a week"<<endl;
	cout<<"3. Once a week"<<endl;
	cout<<"4. Rarely"<<endl;
	cin>>var;
	if(var==1)
		totsum+=2;
	else if(var==2)
		totsum+=1;
	else if(var==3)
		totsum+=0.5;
	else if(var==4)
		totsum--;
	cout<<"Hit enter to move on"<<endl;
	getch();
	clrscr();

	cout<<"How often do you have vegetarian protein (cooked beans, lentils, soy and Paneer)"<<endl;
	cout<<"1. Once a day"<<endl;
	cout<<"2. 3-4 times a week"<<endl;
	cout<<"3. Once a week"<<endl;
	cout<<"4. Rarely"<<endl;
	cin>>var;
	if(var==1)
		totsum+=2;
	else if(var==2)
		totsum+=1;
	else if(var==3)
		totsum+=0.5;
	else if(var==4)
		totsum--;
	cout<<"Hit enter to move on"<<endl;
	getch();
	clrscr();

	if(nv == 1)
	{
		cout<<"How often do you have eggs"<<endl;
		cout<<"1. Once a day"<<endl;
		cout<<"2. 3-4 times a week"<<endl;
		cout<<"3. Once a week"<<endl;
		cout<<"4. Rarely"<<endl;
		cin>>var;
		if(var==1)
			totsum+=2;
		else if(var==2)
			totsum+=1;
		else if(var==3)
			totsum+=0.5;
		else if(var==4)
			totsum--;
		cout<<"Hit enter to move on"<<endl;
		getch();
		clrscr();

		cout<<"How often do you have non-veg protein"<<endl;
		cout<<"1. Once a day"<<endl;
		cout<<"2. 3-4 times a week"<<endl;
		cout<<"3. Once a week"<<endl;
		cout<<"4. Rarely"<<endl;
		cin>>var;
		if(var==1)
			totsum+=1;
		else if(var==2)
			totsum+=0.5;
		else if(var==3)
			totsum+=0.5;
		else if(var==4)
			totsum-=0.5;
			cout<<"Hit enter to move on"<<endl;
			getch();
			clrscr();
	}

	cout<<"How often do you have Dairy products"<<endl;
	cout<<"1. Once a day"<<endl;
	cout<<"2. 3-4 times a week"<<endl;
	cout<<"3. Once a week"<<endl;
	cout<<"4. Rarely"<<endl;
	cin>>var;
	if(var==1)
		totsum+=1;
	else if(var==2)
		totsum+=0.5;
	else if(var==3)
		totsum+=0.5;
	else if(var==4)
		totsum-=0.5;
	cout<<"Hit enter to move on"<<endl;
	getch();
	clrscr();

	cout<<"How often do you have Nuts or seeds"<<endl;
	cout<<"1. Once a day"<<endl;
	cout<<"2. 3-4 times a week"<<endl;
	cout<<"3. Once a week"<<endl;
	cout<<"4. Rarely"<<endl;
	cin>>var;
	if(var==1)
		totsum+=1;
	else if(var==2)
		totsum+=0.5;
	else if(var==3)
		totsum+=0.5;
	else if(var==4)
		totsum-=0.5;
	cout<<"Hit enter to move on"<<endl;
	getch();
	clrscr();

	cout<<"How often do you have sugary cereals"<<endl;
	cout<<"1. Once a day"<<endl;
	cout<<"2. 3-4 times a week"<<endl;
	cout<<"3. Once a week"<<endl;
	cout<<"4. Rarely"<<endl;
	cin>>var;
	if(var==1)
		totsum-=3;
	else if(var==2)
		totsum-=1;
	else if(var==3)
		totsum-=0.5;
	else if(var==4)
		totsum+=2;
	cout<<"Hit enter to move on"<<endl;
	getch();
	clrscr();

	cout<<"How often do you have bread, biscuits and cookies"<<endl;
	cout<<"1. Once a day"<<endl;
	cout<<"2. 3-4 times a week"<<endl;
	cout<<"3. Once a week"<<endl;
	cout<<"4. Rarely"<<endl;
	cin>>var;
	if(var==1)
		totsum-=3;
	else if(var==2)
		totsum-=1;
	else if(var==3)
		totsum-=0.5;
	else if(var==4)
		totsum+=2;
	cout<<"Hit enter to move on"<<endl;
	getch();
	clrscr();

	cout<<"How often do you have Pizzas and Pastas"<<endl;
	cout<<"1. Once a day"<<endl;
	cout<<"2. 3-4 times a week"<<endl;
	cout<<"3. Once a week"<<endl;
	cout<<"4. Rarely"<<endl;
	cin>>var;
	if(var==1)
		totsum-=3;
	else if(var==2)
		totsum-=1;
	else if(var==3)
		totsum-=0.5;
	else if(var==4)
		totsum+=2;
	cout<<"Hit enter to move on"<<endl;
	getch();
	clrscr();

	cout<<"How often do you have take-out and street food"<<endl;
	cout<<"1. Once a day"<<endl;
	cout<<"2. 3-4 times a week"<<endl;
	cout<<"3. Once a week"<<endl;
	cout<<"4. Rarely"<<endl;
	cin>>var;
	if(var==1)
		totsum-=3;
	else if(var==2)
		totsum-=1;
	else if(var==3)
		totsum-=0.5;
	else if(var==4)
		totsum+=2;
	cout<<"Hit enter to move on"<<endl;
	getch();
	clrscr();

	cout<<"How often do you have pastries, desserts or candy"<<endl;
	cout<<"1. Once a day"<<endl;
	cout<<"2. 3-4 times a week"<<endl;
	cout<<"3. Once a week"<<endl;
	cout<<"4. Rarely"<<endl;
	cin>>var;
	if(var==1)
		totsum-=3;
	else if(var==2)
		totsum-=1;
	else if(var==3)
		totsum-=0.5;
	else if(var==4)
		totsum+=2;
	cout<<"Hit enter to move on"<<endl;
	getch();
	clrscr();

	cout<<"How many glasses of water do you usually drink (Per day)"<<endl;
	cout<<"1. 2-3 glasses"<<endl;
	cout<<"2. 5-6 glasses"<<endl;
	cout<<"3. 7-8 glasses"<<endl;
	cout<<"4. 9-10 glasses"<<endl;
	cin>>var;
	if(var==1)
		totsum-=3;
	else if(var==2)
		totsum-=1;
	else if(var==3)
		totsum+=1;
	else if(var==4)
		totsum+=2;
	cout<<"Hit enter to move on"<<endl;
	getch();
	clrscr();

	cout<<"How many glasses of sugary or carbonated drink do you take  (Per day)"<<endl;
	cout<<"1. None"<<endl;
	cout<<"2. 1 glass"<<endl;
	cout<<"3. 3-4 glasses"<<endl;
	cout<<"4. More than 5 glasses"<<endl;
	cin>>var;
	if(var==1)
		totsum+=2;
	else if(var==2)
		totsum-=1;
	else if(var==3)
		totsum-=1;
	else if(var==4)
		totsum-=4;
	cout<<"Hit enter to move on"<<endl;
	getch();
	clrscr();

	cout<<"Your current health score is loading"<<endl;
	for(int k=0;k<7;k++)
	{
		delay();
		cout<<".";
	}
	cout<<endl;
	cout<<"Press enter to view your score"<<endl;

	getch();

	float perc;

	if(totsum >= 0)
	{
		perc = (totsum/(26.5))*100;
	}
	else
	{
		perc = (totsum/26.5)*100;
		perc = 100 + perc;
	}

	if(perc>=90)
		cout<<"Your diet is perfect"<<endl;
	else if(perc<90 && perc>=80)
		cout<<"Good Job! You are leading a healthy lifestyle"<<endl;
	else if(perc<80 && perc>=60)
		cout<<"Great! You are leading a fine lifestyle"<<endl;
	else if(perc<60 && perc>=30)
		cout<<"It's time to shape up and get fitter"<<endl;
	else if(perc<30 && perc>5)
		cout<<"Consider changing your dietary plan completely"<<endl;
	else if(perc<=5)
		cout<<"You must transform your entire lifestyle"<<endl;

	cout<<"Your percentage was"<<endl;
	cout<<perc<<endl;
	cout<<"Sign up/Log in for the best advice and personalized plans"<<endl;
	getch();
}




main()
{
	clrscr();
	intro();
	/*cout<<"Enter the name of the file you want to access"<<endl;
	gets(nfile); */
   strcpy(nfile, "proj.dat");
	clrscr();
	menu();
	getch();

}