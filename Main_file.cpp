#include<constream.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<fstream.h>
#include<stdlib.h>
void intro();
void boundary();
void up(char,int);
void down(char,int);
void left(char,int);
void right(char,int);
void exception();
void erase(char);
void undo(char,int);
void Cond();
void Condf();

int r=12,c=40,o=0,ct,rt,k=0,rang=15,x,y,z;
unsigned int b=0;
char obj,temp='.',move='.';
fstream mfile;
ifstream file;

void print(char str[],int x=0,int y=0,int d=100)
    {
     if(x==0)
	x=40-(strlen(str)/2);
     if(y==0)
       y=12;

     randomize();

     for(int i=0;i<strlen(str);i++)
	{
	 gotoxy(x+i,y);
	 int a=1+random(15);
	 textcolor(a);
	 putch(str[i]);
	 delay(d);
	}
    }

void clear(int r=24,int ci=1,int ct=80)
    {
     gotoxy(ci,r);
     for(int i=ci;i<=ct;i++)
	cout<<" ";
    }

void main()
    {
     clrscr();
     print("WELCOME !");
     getch();
     print("Enter Your Choice : ");
     cin>>obj;
     temp=obj;
     clrscr();
     mfile.open("moves.txt",ios::in|ios::out|ios::trunc);
     gotoxy(40,12);
     cout<<obj;
     start:
     move='.';
     boundary();
     while(move!='x'||move!='X')
	  {
	   x=1;
	   y=24;
	   z=0;
	   print("Enter Your Move : ",x,y,z);
	   move=getch();
	   b=b+1;
	   if(move=='u'||move=='U')
	     {
	     k=0;
	     textcolor(rang);
	     char filename[20],moves;
	     int ch;
	     gotoxy(1,24);
	     x=1;
	     y=24;
	     z=7;
	     print("Enter the file name to be opened :",x,y,z);
	     textcolor(rang);
	     cin>>filename;
	     x=24;
	     y=1;
	     z=39;
	     clear(x,y,z);
	     c=40;
	     r=12;
	     file.open(filename,ios::binary);
	     gotoxy(40,12);
	     textcolor(rang);
	     while(file.get(move))
		  {
		   Condf();
		  }
	     file.close();
	     break;
	     }
	   if(move=='z'||move=='Z')
	     {
	     k=1;
	     clrscr();
	     boundary();
	     c=40;
	     r=12;
	     b=b-2;
	     obj=temp;
	     mfile.close();
	     mfile.open("moves.txt",ios::in|ios::out|ios::binary);
	     mfile.seekg(0);
	     rang=15;
	     textcolor(rang);
	     for(int i=0;i<b;i++)
		  {
		   mfile.get(move);
		   Condf();
		  }
	     mfile.seekp(mfile.tellg());
	     }
	   else
	     {
	      mfile<<move;
	      Cond();
	     }
	  }
       goto start;
       }

//3. FUNCTION DEFINITIONS

void up(char obj,int rang)
    {
     gotoxy(c,r);
     textcolor(rang);
     putch(obj);
     r=r-1;
     gotoxy(c,r);
     textcolor(15);
     putch('_');
    }

void down(char obj,int rang)
    {
     gotoxy(c,r);
     textcolor(rang);
     putch(obj);
     r=r+1;
     gotoxy(c,r);
     textcolor(15);
     putch('_');
    }

void left(char obj,int rang)
    {
     gotoxy(c,r);
     textcolor(rang);
     putch(obj);
     c=c-1;
     gotoxy(c,r);
     textcolor(15);
     putch('_');
    }

void right(char obj,int rang)
    {
     gotoxy(c,r);
     textcolor(rang);
     putch(obj);
     c=c+1;
     gotoxy(c,r);
     textcolor(15);
     putch('_');
    }
void boundary()
    {
     for(int i=1;i<=80;i++)
	{
	 gotoxy(i,1);
	 cout<<"_";
	 gotoxy(i,23);
	 cout<<"_";
	}
    }
void exception()
    {
     if(r<2)
       {
	++r;
	gotoxy(40,24);
	textcolor(4);
	cprintf("Please stay within the boundaries !");
	textcolor(15);
	boundary();
       }
     if(r>22)
       {
	--r;
	gotoxy(40,24);
	textcolor(4);
	cprintf("Please stay within the boundaries !");
	textcolor(15);
	boundary();
       }
     if(c<1)
       {
	++c;
	gotoxy(40,24);
	textcolor(4);
	cprintf("Please stay within the boundaries !");
	textcolor(15);
	boundary();
       }
     if(c>80)
       {
	--c;
	gotoxy(40,24);
	textcolor(4);
	cprintf("Please stay within the boundaries !");
	textcolor(15);
	boundary();
       }
    }

void Cond()
    {

			    //CONDITIONS
/*CONDITION #1*/	if(move=='c'||move=='C')
			  {
			   print("Enter Color Code : ",40,24,7);
			   cin>>rang;
			   mfile<<rang;
			   x=24;
			   y=40;
			   z=80;
			   clear(x,y,z);
			  }
/*CONDITION #2*/	if(move=='w'||move=='W')//up
			  {
			   up(obj,rang);
			   x=24;
			   clear(x);
			  }
/*CONDITION #3*/	if(move=='s'||move=='S')//down
			  {
			   down(obj,rang);
			   x=24;
			   clear(x);
			  }
/*CONDITION #4*/	if(move=='a'||move=='A')//left
			  {
			   left(obj,rang);
			   x=24;
			   clear(x);
			  }
/*CONDITION #5*/	if(move=='d'||move=='D')//right
			  {
			   right(obj,rang);
			   x=24;
			   clear(x);
			  }
/*CONDITION #6*/        if(move=='x'||move=='X')
			  {
			   exit(0);
			   mfile.close();
			  }
/*CONDITION #7*/	if(move=='e'||move=='E')//eraser
			  {
			   temp=obj;
			   obj=' ';
			  }
/*CONDITION #8*/	if(move=='r'||move=='R')//reset object
			  {
			   obj=temp;
			  }
/*CONDITION #9*/	if(move=='q'||move=='Q')//new object
			  {
			   temp=obj;
			   x=40;
			   y=24;
			   z=6;
			   print("Enter a new character : ",x,y,z);
			   obj=getche();
			   mfile<<obj;
			   x=24;
			   y=40;
			   z=80;
			   clear(x,y,z);
			  }
/*CONDITION #10*/	if(move=='t'||move=='T')//Text entry
			  {
			   int rt,ct;
			   char temp[20];
			   gotoxy(40,24);
			   cout<<"Row number :";
			   cin>>rt;
			   mfile<<rt;
			   x=24;
			   clear(x);
			   gotoxy(40,24);
			   cout<<"Column number :";
			   cin>>ct;
			   mfile<<ct;
			   gotoxy(40,24);
			   cout<<"Enter text here :";
			   gets(temp);
			   x=24;
			   clear(x);
			   gotoxy(ct,rt);
			   cout<<temp;
			   for(int i=0;temp[i]!='\0';i++)
			      mfile<<temp[i];
			   mfile<<' ';
			  }
/*CONDITION #11*/	if(move=='j'||move=='J')//Jump to (?,?) :-p
			  {
			   int rj,cj;
			   gotoxy(40,24);
			   cout<<"Row number :";
			   cin>>rj;
			   gotoxy(40,24);
			   cout<<"Column number :";
			   cin>>cj;
			   r=rj;
			   c=cj;
			  }

/*CONDITION #12*/	if(move=='p'||move=='P')
			  {
			   clrscr();
			   boundary();
			  }
/*CONDITION #13*/	if(move=='z'||move=='Z')
			  {

			  }
/*CONDITION #14*/	if(move=='m'||move=='M')//Save
			  {
			   char ch,savefile[20];        //Why not udf . . . .?
			   gotoxy(1,24);
			   x=1;
			   y=24;
			   z=5;
			   print("Enter your file name : ",x,y,z);
			   cin>>savefile;
			   ofstream save(savefile);
			   mfile.seekg(0);
			   while(mfile.get(ch))
				{
				 if(ch=='p'||ch=='P')
				 save.write(savefile,ios::trunc);
				 save<<ch;
				}
			   mfile.seekg(0,ios::end);
			   save.close();
			   x=24;
			   clear(x);
			  }
			exception();
    }

void Condf()
    {

			    //CONDITIONS
/*CONDITION #1*/	if(move=='c'||move=='C')
			  {
			   if(k==1)
			     { mfile>>rang;
			     }
			   else
			      { file>>rang;
			      }
			   textcolor(rang);
			  }
/*CONDITION #2*/	if(move=='w'||move=='W')//up
			  {
			   up(obj,rang);
			   x=24;
			   clear(x);
			   if(k==0)
			   delay(50);
			  }
/*CONDITION #3*/	if(move=='s'||move=='S')//down
			  {
			   down(obj,rang);
			   x=24;
			   clear(x);
			   if(k==0)
			   delay(50);
			  }
/*CONDITION #4*/	if(move=='a'||move=='A')//left
			  {
			   left(obj,rang);
			   x=24;
			   clear(x);
			   if(k==0)
			   delay(50);
			  }
/*CONDITION #5*/	if(move=='d'||move=='D')//right
			  {
			   right(obj,rang);
			   x=24;
			   clear(x);
			   if(k==0)
			   delay(50);
			  }
/*CONDITION #6*/	if(move=='x'||move=='X')//exit
			  {
			   mfile.close();
			   exit(0);
			  }
/*CONDITION #7*/	if(move=='e'||move=='E')//eraser
			  {
			   temp=obj;
			   obj=' ';
			  }
/*CONDITION #8*/	if(move=='r'||move=='R')//reset object
			  {
			   obj=temp;
			  }
/*CONDITION #9*/	if(move=='q'||move=='Q')//new object
			  {
			   if(k==1)
			      mfile>>obj;
			   else
			       {file>>obj;}
			  }
/*CONDITION #10*/	if(move=='t'||move=='T')//Text entry
			  {int i=0;
			   char tempo[20];
			   file>>rt;
			   file>>ct;
			   file.seekg(file.tellg()+1);
			   X:
			   file>>tempo[i];
			   i=i+1;
			   if(tempo[i]!='\0')
			     goto X;
			   clear(x);
			   gotoxy(ct,rt);
			   puts(tempo);
			   file.seekg(file.tellg()+1);
			  }
/*CONDITION #11*/	if(move=='j'||move=='J')//Jump to (?,?) :-p
			  {
			   int rj,cj;
			   gotoxy(40,24);
			   cout<<"Row number :";
			   cin>>rj;
			   gotoxy(40,24);
			   cout<<"Column number :";
			   cin>>cj;
			   r=rj;
			   c=cj;
			  }

/*CONDITION #12*/	if(move=='p'||move=='P')
			  {
			   clrscr();
			   boundary();

			  }
/*CONDITION #13*/	if(move=='z'||move=='Z')
			  {

			  }
			exception();
    }
