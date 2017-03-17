#include<iostream>											
#include <windows.h>												                                                  
#include <stdio.h>														                                                  
#include <conio.h>														
#include <time.h>																													
#include"help.h"																													
#include <string>															
#include <stdlib.h>														
#include <fstream>
#include <math.h>
using namespace std;
void b(int x1, int y1, int x2, int y2, int c1, int c2, int c3,int width);
void thanks(int x1, int y1, int x2, int y2,int width);
void baloons(int x1, int y1, int x2, int y2, int c1, int c2, int c3);
void load (char arr[],int &linex,int &liney,bool answer,int &x1,int &x2,int &y1,int &y2,int &c1,int &c2,int &c3,int &width,int &amount,int &check_of_condition,int &direction,int &colorcheck);
void catenation(char a[],char b[]);
void color(int &c1,int &c2,int &c3,int &x1,int &y1,int &x2,int &y2,int &colorcheck,int &width);
void cs(int &x1,int &direction,int &y1,int &x2, int &y2 , int &c1,int &c2 ,int &c3,int &width,int &linex,int &liney);
void square(int a, int &direction, bool &answer, int &x1, int &x2, int &y1, int &y2, int &c1, int &c2, int &c3,int &width);
void Width(int &a,int &width);
void circle(int a, int &direction, bool &answer, int &x1, int &x2, int &y1, int &y2, int &c1, int &c2, int &c3,int &width);
void cursor(int direction,int &linex,int &liney,int &x1,int &x2,int &y1,int &y2,int &c1,int &c2,int &c3,int &width);
void fd(int a,int &linex,int &liney,int &direction,bool &answer,int &x1 ,int &x2 , int &y1 ,int &y2,int &c1,int &c2,int &c3,int &width);
void lt(int a,int &direction,int &linex,int &liney,int &x1,int &x2,int &y1 ,int &y2,int &c1,int &c2,int &c3,int &width);
void rt(int a,int &direction,int &linex,int &liney,int &x1,int &x2,int &y1 ,int &y2,int &c1,int &c2,int &c3,int &width);
void bk(int a,int &direction,int &linex,int &liney,bool &answer,int &x1 ,int &x2 , int &y1 ,int &y2,int &c1,int &c2,int &c3,int &width);
void repeat (char condition_1[],char condition_2[],char arr[],int &linex,int &liney,bool answer,int &x1,int &x2,int &y1,int &y2,int &c1,int &c2,int &c3,int &width,int &amount,int &check_of_condition,int &direction,int &colorcheck);
bool pu();
bool pd();
void exit();
void save(char a[][100],int &no_of_commands_given,int &startingpoint,char arr[]);
void interface1(int width,int forline);
int convert(char arr[],int &check,int &colorcheck);

int main()
{
	char condition_1[20]; // for use in repeat function
	char condition_2[20]; // for use in repeat function
	int amount=0;
	int width_const=1; // width for interface
	int width=1;
	int forline=2; // width
	interface1(width_const,forline); // to make the initial interface
	int startingpoint=0; // to take care of the apppending thing in the save function
	int c1=255; // colours
	int c2=255;										////// color selectoer  ///////
	int c3=255;
	int colorcheck=1; // for colour
	int y1=154; // initial cursor
	int x1=314;	// initial cursor													/// initiate coordinates of the cursor///
	int x2=330; // initial cursor
	int y2=170; // initial cursor
	int count_of_record=1; // for saving
	int linex=x1+8; // final coordinates of the line and first cooordinates of the next line
	int liney=y2; // coordinates
	int one_by_one=1; // for history box
	int direction=0; // angle
	myEllipse(x1,y1,x2,y2,c1,c2,c3,width); // CURSOR
	int check_of_condition=0; // for command processing
	char storer[10000][100]; // 2D ARRAY to store commands
	char record[4][100]; 
	int index1=0;  // history boxes
	int index2=1;
	int index3=2;
	int index4=3;
	int i=0; 
	int no_of_commands_given=0; 
	bool answer=false; // pen up and down
	while(1)
	{
		gotoxy(0,23); // commands box

		
		char arr[300]; // to save command
		int a;														//// getting input in the form of a string///
		gets(arr); // take command

			for(;i<10000;i++) // taking control of the number of rows
		    {
			int j=0;
		        for(;arr[j]!='\0';j++) // for columns
		          {
		               storer[i][j]=arr[j];
					   
		          }
				no_of_commands_given++; // to note  down how many commands are given

		storer[i][j]='\0';
		i++;
		break;
		}
			if(one_by_one>=5) // to check if history box is full
			{
				index1++;
				index2++;
				index3++;
				index4++;

//				if(count_of_record==1)
	//		{
				
		gotoxy(58,15); // history box coordinates
		cout<<storer[index1];
		cout<<"                      ";
		//count_of_record++;
		//one_by_one++;
			//}
		 //if(count_of_record==2)
		//{
			
		gotoxy(58,17);
		cout<<storer[index2];
		cout<<"                      ";
		//count_of_record++;
		//one_by_one++;
			//}
		 //if(count_of_record==3)
		//{
			
		gotoxy(58,19);
		cout<<storer[index3];
		cout<<"                      ";
		//count_of_record++;
		//one_by_one++;
		//}
		 //if(count_of_record==4)
		//{
			
		gotoxy(58,21);
		cout<<storer[index4];
		cout<<"                      ";
		//count_of_record=1;
		//one_by_one++;
		//}

		

			}
			if(count_of_record==1) // store first command
			{
				
		gotoxy(58,15);
		cout<<storer[index1];
		count_of_record++;
		one_by_one++;
			}
		else if(count_of_record==2) // second command
		{
			
		gotoxy(58,17);
		cout<<storer[index2];
		count_of_record++;
		one_by_one++;
			}
		else if(count_of_record==3) // third command
		{
			
		gotoxy(58,19);
		cout<<storer[index3];
		count_of_record++;
		one_by_one++;
		}
		else if(count_of_record==4)
		{
			
		gotoxy(58,21);
		cout<<storer[index4];
		count_of_record=1;
		one_by_one++;
		}
		

		
		/*int count_of_record=0;
		for(int y=0;y<4;y++)
		{
			for(int j=0;arr[j]!='\0';j++)
			{
				record[i][j]=arr[j];

			}
			record[i][j]='\0';
			//count_of_record++;*/
			//if(count_of_record==3)
			//{
			//swap(record[i],record[i-1]);
			//	}
			

				//}


				a=convert(arr,check_of_condition,colorcheck); // to check the given command

			if(check_of_condition==1)                                /// check condition and acts accordingly////
				fd(a,direction,linex,liney,answer,x1,x2,y1,y2,c1,c2,c3,width);

			else if(check_of_condition==2)

				bk(a,direction,linex,liney,answer,x1,x2,y1,y2,c1,c2,c3,width);

			else if(check_of_condition==3)
				rt(a,direction,linex,liney,x1,x2,y1,y2,c1,c2,c3,width);
			else if(check_of_condition==4)
				lt(a,direction,linex,liney,x1,x2,y1,y2,c1,c2,c3,width);
			else if(check_of_condition==5)
				answer=pu();
			else if (check_of_condition==6)
				answer=pd();
			else if(check_of_condition==7)
				circle(a,direction,answer,x1,x2,y1,y2,c1,c2,c3,width);
			else if(check_of_condition==8)
				square(a,direction,answer,x1,x2,y1,y2,c1,c2,c3,width);
			else if(check_of_condition==9)
				cs(x1,direction,y1,x2,y2,c1,c2,c3,width,linex,liney);
			else if(check_of_condition==10)
				Width(a,width);
			else if(check_of_condition==12)
			{
				//int size;
				repeat(condition_1,condition_2,arr,linex,liney,answer,x1,x2,y1,y2,c1,c2,c3,width,amount,check_of_condition,direction,colorcheck );
				//for(int i=1;i<=amount;i++)
				//{
				// size=convert(arr,check_of_condition,colorcheck,condition_1,condition_2);
				//}
			}
			else if(check_of_condition==11)
				color(c1,c2,c3,x1,y1,x2,y2,colorcheck,width);
			/*else if(check_of_condition==7)
			repeat(arr,direction,linex,liney,answer,x1,x2,y1,y2,c1,c2,c3);*/
			else if(check_of_condition==13)
			{
			save(storer,no_of_commands_given,startingpoint,arr); // save commands
			
			}
				else if(check_of_condition==14)
			{ 
			load(arr,linex,liney,answer,x1,x2,y1,y2,c1,c2,c3,width,amount,check_of_condition,direction,colorcheck);
			
			}
					else if(check_of_condition==15)
			{
			exit();	
			break;
			}
			gotoxy(0,23);
			cout<<"                                                                                ";										 // to clear screen after first command//
			
			interface1(width_const,forline); // to print interface after every interval
		}


		system("pause");
	}
	void fd(int a,int &direction,int &linex,int &liney,bool &answer,int &x1,int &x2 , int &y1 ,int &y2,int  &c1,int &c2,int &c3,int &width)
	{
		int count_of_pixels_for_x=0; // to check if someone has put a character after a digit
		int x_1=x1;
		int y_1=y1;
		int x_2=x2;
		int y_2=y2;
		

		if(direction==0 || direction==360 || direction==-360)
		{
			myEllipse(x1,y1,x2,y2,0,0,0,width);

			y1=y1-a;
			y2=y2-a;
			
			/// to move forward in the upward direction ///
	
			myLine(linex,liney,x1+8,y2+1,c1,c2,c3,width);
			myEllipse(x1,y1,x2,y2,c1,c2,c3,width);
			if(answer==false) // condition for pen up and down
				myLine(linex,liney,x1+8,y2+1,c1,c2,c3,width);
			linex=x1+8; // saving coordinates
			liney=y2+1;
		}



		else if(direction==45 || direction==-315)												/// to move forward right at 45 or forward left at 315 in the upward direction ///

		{
			myEllipse(x1,y1,x2,y2,0,0,0,width);
			x1=x1+a;
			x2=x2+a;
			y1=y1-a;
			y2=y2-a;

			myEllipse(x1,y1,x2,y2,c1,c2,c3,width);
			if(answer==false)
				myLine(linex,liney,x1-1,y2-8,c1,c2,c3,width);
			linex=x1-1;
			liney=y2-8;

		}

		else if(direction==90 || direction==-270)													/// to move forward left of forward right in the upward direction ///

		{
			myEllipse(x1,y1,x2,y2,0,0,0,width);
			x1=x1+a;
			x2=x2+a;
			myEllipse(x1,y1,x2,y2,c1,c2,c3,width);
			if(answer==false)
				myLine(linex,liney,x1-1,y2-8,c1,c2,c3,width);
			linex=x1-1;
			liney=y2-8;


		}

		else if(direction==135 || direction == -225)															/// to move forward at 135 or forward at 225 in the upward direction ///

		{

			myEllipse(x1,y1,x2,y2,0,0,0,width);
			y2=y2+a;
			if(y2>=268 )
			{
				while(y2!=268)
				{
					count_of_pixels_for_x++; // for having it above the command line..
					y2--;
				}
				y1=268-16; // because the cursor's y coordinates have a difference of 16
				x1=x1+a-count_of_pixels_for_x; // the amount like fd "60"
				x2=x2+a-count_of_pixels_for_x;
			}
			else 
			{
			x1=x1+a;
			x2=x2+a;
			y1=y1+a;
			
			}
			myEllipse(x1,y1,x2,y2,c1,c2,c3,width);
			if(answer==false)
				myLine(linex,liney,x1-1,y2-8,c1,c2,c3,width);
			linex=x1-1;
			liney=y2-8;
			count_of_pixels_for_x=0;

		}

		else if(direction==180 ||direction ==-180)																	/// to move forward at 180 of forward at 180 in the upward direction ///
		{
			myEllipse(x1,y1,x2,y2,0,0,0,width);
			y1=y1+a;
			y2=y2+a;
			if(y2>=268 )
			{
				y2=268;
				y1=268-16;
			}
			myEllipse(x1,y1,x2,y2,c1,c2,c3,width);
			if(answer==false)
				myLine(linex,liney,x1+8,y1-1,c1,c2,c3,width);
			linex=x1+8;
			liney=y1-1;
			count_of_pixels_for_x=0;
		}



		else if(direction==225 || direction == -135)																/// to move forward at 135 or forward at 225 in the upward direction ///

		{
			myEllipse(x1,y1,x2,y2,0,0,0,width);
			y2=y2+a;
			if(y2>=268 )
			{
				while(y2!=268)
				{
					count_of_pixels_for_x++;
					y2--;
				}
				y1=268-16;
				x1=x1-a+count_of_pixels_for_x;
				x2=x2-a+count_of_pixels_for_x;
			}
			else 
			{
			x1=x1-a;
			x2=x2-a;
			y1=y1+a;
			
			}
			myEllipse(x1,y1,x2,y2,c1,c2,c3,width);
			if(answer==false)
				myLine(linex,liney,x2+1,y2-8,c1,c2,c3,width);
			linex=x2+1;
			liney=y2-8;
			count_of_pixels_for_x=0;
		}



		else if(direction==270 || direction == -90)																	/// to move forward at 90 or forward at 270 in the upward direction ///				


		{
			myEllipse(x1,y1,x2,y2,0,0,0,width);
			x1=x1-a;
			x2=x2-a;
			myEllipse(x1,y1,x2,y2,c1,c2,c3,width);
			if(answer==false)
				myLine(linex,liney,x2+1,y2-8,c1,c2,c3,width);
			linex=x2+1;
			liney=y2-8;
		}

		else if(direction==315 || direction == -45)																	/// to move forward at 45 of forward at 315 in the upward direction ///


		{
			myEllipse(x1,y1,x2,y2,0,0,0,width);
			x1=x1-a;
			x2=x2-a;
			y1=y1-a;
			y2=y2-a;
			myEllipse(x1,y1,x2,y2,c1,c2,c3,width);
			if(answer==false)
				myLine(linex,liney,x2+1,y2-8,c1,c2,c3,width);
			linex=x2+1;
			liney=y2-8;
		}


	}
	void rt(int a,int &direction,int &linex,int &liney,int &x1,int &x2,int &y1 ,int &y2,int &c1,int &c2,int &c3,int &width)
	{
		if(a%45==0) // angle 45
		{
		direction=direction+a; //  adding the angle to direction
		while(direction>360)
			direction=direction-360;
		cursor(direction,linex,liney,x1,x2,y1,y2,c1,c2,c3,width); // change of cursor
		}
		else 
		{
			{
			gotoxy(0,23); // error handling
			cout<<"                                                                                ";
			gotoxy (25,23);
			cout<<"Enter a multiple of 45 in the input please!!"; // error handling
			Sleep(1500); // if error, then stop for 1.5 sec...
			gotoxy(0,23);
			cout<<"                                                                                ";
		}
		}
	}
	void lt(int a,int &direction,int &linex,int &liney,int &x1,int &x2,int &y1 ,int &y2,int &c1,int &c2,int &c3,int &width)
	{
		if(a% 45==0)
		{
		direction=direction-a;
		while(direction<-360)
			direction=direction+360;
		cursor(direction,linex,liney,x1,x2,y1,y2,c1,c2,c3,width);
		}
		else
		{
			{
			gotoxy(0,23);
			cout<<"                                                                                ";
			gotoxy (25,23);
			cout<<"Enter a multiple of 45 in the input please!!";
			Sleep(1500);
			gotoxy(0,23);
			cout<<"                                                                                ";
		}
		}
	}
	void bk(int a,int &direction,int &linex,int &liney,bool &answer,int &x1,int &x2 , int &y1 ,int &y2,int &c1,int &c2,int &c3,int &width)
	{
		int count_of_pixels_for_x=0; // error checking if there's something wrong ahead of for
		int x_1=x1;
		int y_1=y1;
		int x_2=x2;
		int y_2=y2;
		if(direction==0 || direction == 360 || direction==-360)
		{

			myEllipse(x1,y1,x2,y2,0,0,0,width);
			myLine(x1+8,y1,x1+8,y2,c1,c2,c3,width);
			y1=y1+a;
			y2=y2+a;
			if(y2>=268 )
			{
				y2=268;
				y1=268-16;
			}

			myEllipse(x1,y1,x2,y2,c1,c2,c3,width);
			if(answer==false)
				myLine(linex,liney,x1+8,y2-1,c1,c2,c3,width);
			linex=x1+8;
			liney=y2-1;
			count_of_pixels_for_x=0; // checking error next time
		}



		else if(direction==45 || direction==-315)

		{
			myEllipse(x1,y1,x2,y2,0,0,0,width);
			y2=y2+a;
			if(y2>=268 )
			{
				while(y2!=268)
				{
					count_of_pixels_for_x++;
					y2--;
				}
				y1=268-16;
				x1=x1-a+count_of_pixels_for_x;
				x2=x2-a+count_of_pixels_for_x;
			}
			else 
			{
			x1=x1-a;
			x2=x2-a;
			y1=y1+a;
			
			}
			myEllipse(x1,y1,x2,y2,c1,c2,c3,width);
			if(answer==false)
				myLine(linex,liney,x1+8,y2-17,c1,c2,c3,width);
			linex=x1+8;
			liney=y2-17;
			count_of_pixels_for_x=0;
		}



		else if(direction==90 || direction==-270)

		{
			myEllipse(x1,y1,x2,y2,0,0,0,width);
			x1=x1-a;
			x2=x2-a;
			myEllipse(x1,y1,x2,y2,c1,c2,c3,width);
			if(answer==false)
				myLine(linex,liney,x2+1,y2-8,c1,c2,c3,width);
			linex=x2+1;
			liney=y2-8;
		}




		else if(direction==135 || direction == -225)
		{
			myEllipse(x1,y1,x2,y2,0,0,0,width);
			x1=x1-a;
			x2=x2-a;
			y1=y1-a;
			y2=y2-a;
			myEllipse(x1,y1,x2,y2,c1,c2,c3,width);
			if(answer==false)
				myLine(linex,liney,x1-1,y2-8,c1,c2,c3,width);
			linex=x1-1;
			liney=y2-8;
		}

		else if(direction==180 || direction==-180)
		{
			myEllipse(x1,y1,x2,y2,0,0,0,width);
			y1=y1-a;
			y2=y2-a;
			/// to move forward in the upward direction ///

			myEllipse(x1,y1,x2,y2,c1,c2,c3,width);
			if(answer==false)
				myLine(linex,liney,x1+8,y2-1,c1,c2,c3,width);
			linex=x1+8;
			liney=y2-1;
		}



		else if(direction==225 || direction==-135)

		{

			myEllipse(x1,y1,x2,y2,0,0,0,width);
			x1=x1+a;
			x2=x2+a;
			y1=y1-a;
			y2=y2-a;

			myEllipse(x1,y1,x2,y2,c1,c2,c3,width);
			if(answer==false)
				myLine(linex,liney,x2+1,y2-8,c1,c2,c3,width);
			linex=x2+1;
			liney=y2-8;
		}



		else if(direction==270 || direction==-90)

		{
			myEllipse(x1,y1,x2,y2,0,0,0,width);
			x1=x1+a;
			x2=x2+a;
			myEllipse(x1,y1,x2,y2,c1,c2,c3,width);
			if(answer==false)
				myLine(linex,liney,x1-1,y2-8,c1,c2,c3,width);
			linex=x1-1;
			liney=y2-8;

		}

		else if(direction==315 || direction ==-45)

		{
			myEllipse(x1,y1,x2,y2,0,0,0,width);
			y2=y2+a;
			if(y2>=268 )
			{
				while(y2!=268)
				{
					count_of_pixels_for_x++;
					y2--;
				}
				y1=268-16;
				x1=x1+a-count_of_pixels_for_x; // command line error handling
				x2=x2+a-count_of_pixels_for_x;
			}
			else 
			{
			x1=x1+a;
			x2=x2+a;
			y1=y1+a;
			}
			myEllipse(x1,y1,x2,y2,c1,c2,c3,width);
			if(answer==false)
				myLine(linex,liney,x2+1,y2-8,c1,c2,c3,width);
			linex=x2+1;
			liney=y2-8;
			count_of_pixels_for_x=0;
		}


	}
	bool pu()
	{
		bool answer;
		answer=true;
		return answer;
	}
	bool pd()
	{
		bool answer;
		answer=false;
		return answer;
	}
	int convert(char arr[],int &check,int &colorcheck)
	{
		int p=strlen(arr); // finding size of the array(command)
		int i=0; 

		if((arr[0]=='f' && arr[1]=='d' && arr[2]=='\0') || (arr[0] =='f' && arr[1]=='o' && arr[2]=='r' && arr[3]=='w'&& arr[4]=='a' && arr[5]=='r' && arr[6] =='d' && arr[7]=='\0'))                     ////returns the/////
		{    // if just fd or forward is entered
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
		else if((arr[0]=='f' && arr[1]=='d' && arr[2]==' ') || (arr[0] =='f' && arr[1]=='o' && arr[2]=='r' && arr[3]=='w'&& arr[4]=='a' && arr[5]=='r' && arr[6] =='d' && arr[7]==' '))                     ////returns the/////
		{ // error handling
			if(arr[3]=='\0' || arr[8]=='\0')
				{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
			else
			check=1; // processing function
		}
		/////condition////	
		else if((arr[0]=='b' && arr[1]=='k' && arr[2]=='\0') || (arr[0] =='b' && arr[1]=='a' && arr[2]=='c' && arr[3]=='k'&& arr[4]=='w' && arr[5]=='a' && arr[6] =='r' && arr[7]=='d' && arr[8]=='\0'))/// checker/////
		{
			// error handling
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
		else if((arr[0]=='b' && arr[1]=='k' && arr[2]==' ') || (arr[0] =='b' && arr[1]=='a' && arr[2]=='c' && arr[3]=='k'&& arr[4]=='w' && arr[5]=='a' && arr[6] =='r' && arr[7]=='d' && arr[8]==' '))/// checker/////

		{ // error handling
			if(arr[3]=='\0' || arr[8]=='\0')
				{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
			else
						check=2; // processing function
		}
		else if(arr[0]=='r' && arr[1]=='t' && arr[2]=='\0')
		{ // error handling
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
		else if(arr[0]=='r' && arr[1]=='t' && arr[2]==' ')
		{
			if(arr[3]=='\0' )
				{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
			else
			check=3; // processing function
		}
		else if(arr[0]=='l' && arr[1]=='t' && arr[2]=='\0')
		{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
		else if(arr[0]=='l' && arr[1]=='t' && arr[2]==' ')
		{
			if(arr[3]=='\0' )
				{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
			else
			check=4;
		}

		else if(arr[0]=='p' && arr[1]=='u' )
		{ 
			if(arr[2]!='\0')
			{

				gotoxy(0,23);
				cout<<"                                                                                ";
				gotoxy (25,23);
				cout<<"I don't know this command!!";
				Sleep(1500);
				gotoxy(0,23);
				cout<<"                                                                                ";
			}
			else 
				check=5;
			goto end;
		}
		else if(arr[0]=='p' && arr[1]=='d' )
		{
			if(arr[2]!='\0')
			{

				gotoxy(0,23);
				cout<<"                                                                                ";
				gotoxy (25,23);
				cout<<"I don't know this command!!";
				Sleep(1500);
				gotoxy(0,23);
				cout<<"                                                                                ";
			}
			else
				check=6;
			goto end;
		}
		else if(arr[0]=='c' && arr[1]=='i' && arr[2]=='r' && arr[3]=='c' && arr[4]=='l' && arr[5]=='e'&& arr[6]=='\0' )
		{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
		else if(arr[0]=='c' && arr[1]=='i' && arr[2]=='r' && arr[3]=='c' && arr[4]=='l' && arr[5]=='e'&& arr[6]==' ' )
		{
			if(arr[7]=='\0' )
				{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
			else
			check=7;
		}
		else if(arr[0]=='s' && arr[1]=='q' && arr[2]=='u' && arr[3]=='a' && arr[4]=='r' && arr[5]=='e'&& arr[6]=='\0')
		{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
		else if(arr[0]=='s' && arr[1]=='q' && arr[2]=='u' && arr[3]=='a' && arr[4]=='r' && arr[5]=='e'&& arr[6]==' ')
		{
			if(arr[7]=='\0' )
				{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
			else
			check=8;
		}
		else if(arr[0]=='c' && arr[1]=='s')
		{
			if(arr[2]!='\0')
			{

				gotoxy(0,23);
				cout<<"                                                                                ";
				gotoxy (25,23);
				cout<<"I don't know this command!!";
				Sleep(1500);
				gotoxy(0,23);
				cout<<"                                                                                ";
			}
			else
				check=9;
			goto end;
		}
		else if(arr[0]=='w' && arr[1]=='i' && arr[2]=='d' && arr[3]=='t' && arr[4]=='h'&& arr[5]=='\0')
		{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
		else if(arr[0]=='w' && arr[1]=='i' && arr[2]=='d' && arr[3]=='t' && arr[4]=='h'&& arr[5]==' ')
		{
			if(arr[6]=='\0' )
				{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
			else
			check=10;
		}
		else if(arr[0]=='c' && arr[1]=='o' && arr[2]=='l' && arr[3]=='o' && arr[4]=='r'&& arr[5]=='\0')
		{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
		else if(arr[0]=='c' && arr[1]=='o' && arr[2]=='l' && arr[3]=='o' && arr[4]=='r'&& arr[5]==' ')
		{
			if(arr[6]=='\0')
				{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
			else 
			{
			for(;i<p;i++)
			{                                                  ////////////// to convert the string///////////////////
				if(arr[i]==' ')
					break;
			}
			i++;
			int loop_check=p-i;

			char colour[10];
			int y=0;
			for(;y<loop_check;y++)
			{
				colour[y]=arr[i];
				i++;
			}
			colour[y]='\0';
			
			if(colour[0]=='W' && colour[1]=='H' && colour[2]=='I' && colour[3]=='T' && colour[4]=='E' && colour[5]=='\0' )
				{
					colorcheck=1;
					check=11;
			}
			else if(colour[0]=='R' && colour[1]=='E' && colour[2]=='D'  && colour[3]=='\0')
				{
					colorcheck=2;
					check=11;
			}
			else if(colour[0]=='B' && colour[1]=='L' && colour[2]=='U' && colour[3]=='E'&& colour[4]=='\0')
			{
				colorcheck=3;
				check=11;
			}
			else if(colour[0]=='G' && colour[1]=='R' && colour[2]=='E' && colour[3]=='E' && colour[4]=='N'&& colour[5]=='\0')
				{
					colorcheck=4;
					check=11;
			}
			else if(colour[0]=='P' && colour[1]=='I' && colour[2]=='N' && colour[3]=='K'&& colour[4]=='\0')
			{
				colorcheck=5;
				check=11;
			}
			else if(colour[0]=='P' && colour[1]=='U' && colour[2]=='R' && colour[3]=='P' && colour[4]=='L' && colour[5]=='E'&& colour[6]=='\0')
			{
				colorcheck=6;
				check=11;
			}

			else if(colour[0]=='A' && colour[1]=='Q' && colour[2]=='U' && colour[3]=='A'&& colour[4]=='\0')
			{
				colorcheck=7;
				check=11;
			}
			else if(colour[0]=='O' && colour[1]=='R' && colour[2]=='A' && colour[3]=='N' && colour[4]=='G' && colour[5]=='E'&& colour[6]=='\0')
			{
				colorcheck=8;
				check=11;
			}
			else if(colour[0]=='Y' && colour[1]=='E' && colour[2]=='L' && colour[3]=='L' && colour[4]=='O' && colour[5]=='W'&& colour[6]=='\0')
			{
				colorcheck=9;
				check=11;
			}
			else if(colour[0]=='G' && colour[1]=='R' && colour[2]=='E' && colour[3]=='Y'&& colour[4]=='\0')
			{
				colorcheck=10;
				check=11;
			}
			else 
				{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Wrong Colour!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}

			
			}
			goto end;
		}

		else if(arr[0]=='r' && arr[1]=='e' && arr[2]=='p' && arr[3]=='e' && arr[4]=='a' && arr[5]=='t' && arr[6]=='\0')
		{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
		else if(arr[0]=='r' && arr[1]=='e' && arr[2]=='p' && arr[3]=='e' && arr[4]=='a' && arr[5]=='t' && arr[6]==' ')
		{
			if(arr[7]=='\0' )
				{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
			else
			check=12;
			goto end;
		}
		else if(arr[0]=='s' && arr[1]=='a' && arr[2]=='v' && arr[3]=='e' && arr[4]=='\0')
		{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
		else if(arr[0]=='s' && arr[1]=='a' && arr[2]=='v' && arr[3]=='e' && arr[4]==' ' && arr[5]=='"')
		{
			if(arr[5]=='\0' )
				{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
			else
			check=13;
			goto end;
		}
		else if(arr[0]=='l' && arr[1]=='o' && arr[2]=='a' && arr[3]=='d' && arr[4]=='\0')
		{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
		else if(arr[0]=='l' && arr[1]=='o' && arr[2]=='a' && arr[3]=='d' && arr[4]==' '&& arr[5]=='"')
		{
			if(arr[5]=='\0' )
				{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
		
			else
			check=14;
			goto end;
		}
		else if(arr[0]=='e' && arr[1]=='x' && arr[2]=='i' && arr[3]=='t' )
		{


			check=15;
			goto end;
		}

		else 
		{
			gotoxy(0,23);
			cout<<"                                                                                ";
			gotoxy (25,23);
			cout<<"I don't know this command!!";
			Sleep(1500);
			gotoxy(0,23);
			cout<<"                                                                                ";
		}
		i=0;      // the upper one might be used in color command.
		for(;i<p;i++)
		{                                                  ////////////// to convert the string///////////////////
			if(arr[i]==' ')
				break;
		}
		i++;
		int loop_check=p-i;

		char digit[100];
		for(int y=0;y<loop_check;y++)
		{
			digit[y]=arr[i];
			if(arr[i]>57 || arr[i]<48)
			{
				
			gotoxy(0,23);
			cout<<"                                                                                ";
			gotoxy (25,23);
			cout<<"Invalid pixels input!!";
			Sleep(1500);
			gotoxy(0,23);
			cout<<"                                                                                ";
		
				check=-1;
				return 0;
			}
			i++;
		}
		int req=atoi(digit);
		return req;
		end:;
	}
 	void repeat (char condition_1[],char condition_2[],char arr[],int &linex,int &liney,bool answer,int &x1,int &x2,int &y1,int &y2,int &c1,int &c2,int &c3,int &width,int &amount,int &check_of_condition,int &direction,int &colorcheck)
	{
		
 		bool yes_or_no=false;
		int p=strlen(arr);
		int	i=0;      // the upper one might be used in color command.
		for(;i<p;i++)
		{                                                  ////////////// to convert the string///////////////////
			if(arr[i]==' ')
				break;
		}
		
		i++;
		int loop_check=p-i;
		int index=0;
		char repetition[10];
		for(;arr[i]!='\0';i++)
		{
			if(arr[i]=='[')
			{
				yes_or_no=true;
				break;
			}
			repetition[index]=arr[i];
			index ++;
		}
		i++;
		if(yes_or_no==false)
		{
			
			gotoxy(0,23);
			cout<<"                                                                                ";
			gotoxy (25,23);
			cout<<"Incomplete command!!";
			Sleep(1500);
			gotoxy(0,23);
			cout<<"                                                                                ";
		}
		else
		{
		yes_or_no=false;
		index=0;
		amount=atoi(repetition);

		for(;arr[i]!='\0';i++)
		{
			if(arr[i]==' ')
			{
				yes_or_no=true;
				break;
			}
			condition_1[index]=arr[i];
			index++;
		}
		condition_1[index]='\0';
		i++;
		if(yes_or_no==false)
		{
			
			gotoxy(0,23);
			cout<<"                                                                                ";
			gotoxy (25,23);
			cout<<"Incomplete command!!";
			Sleep(1500);
			gotoxy(0,23);
			cout<<"                                                                                ";
		}
		else
		{
		yes_or_no=false;
		char condition_1_2[20];
		index=0;
		for(;arr[i]!='\0';i++)
		{
			if(arr[i]==' ')
			{
				yes_or_no=true;
				break;
			}
			condition_1_2[index]=arr[i];
			index++;
		}
		condition_1_2[index]='\0';
		i++;
		if(yes_or_no==false)
		{
			
			gotoxy(0,23);
			cout<<"                                                                                ";
			gotoxy (25,23);
			cout<<"Incomplete command!!";
			Sleep(1500);
			gotoxy(0,23);
			cout<<"                                                                                ";
		}
		else
		{
		yes_or_no=false;
		catenation(condition_1,condition_1_2);
		int size=convert(condition_1,check_of_condition,colorcheck);
		{


			if(check_of_condition==1)                                /// check condition and acts accordingly////
				;

			else if(check_of_condition==2)

;

			else if(check_of_condition==3)
;
			else if(check_of_condition==4)
;
			else if(check_of_condition==5)
;
			else if (check_of_condition==6)
;
			else if(check_of_condition==7)
;
			else if(check_of_condition==8)
;
			else if(check_of_condition==9)
;
			else if(check_of_condition==10)
;
			else if(check_of_condition==11)
;
			else 
				goto brek;    // if the given command is none of the above, it ends it.



		}
		index=0; // re initialization for condition 2

		for(;arr[i]!='\0';i++)
		{
			if(arr[i]==' ')
			{
				yes_or_no=true;
				break;
			}
			condition_2[index]=arr[i];
			index++;
		}
		condition_2[index]='\0';
		i++;
		if(yes_or_no==false)
		{
			
			gotoxy(0,23);
			cout<<"                                                                                ";
			gotoxy (25,23);
			cout<<"Incomplete command!!";
			Sleep(1500);
			gotoxy(0,23);
			cout<<"                                                                                ";
		}
		else
		{
		yes_or_no=false;
		char condition_2_2[20];
		index=0;
		for(;arr[i]!='\0';i++)
		{
			if(arr[i]==']')
			{
				yes_or_no=true;
				break;
			}
			condition_2_2[index]=arr[i];
			index++;
		}
		if(yes_or_no==false)
		{
			
			gotoxy(0,23);
			cout<<"                                                                                ";
			gotoxy (25,23);
			cout<<"Incomplete command!!";
			Sleep(1500);
			gotoxy(0,23);
			cout<<"                                                                                ";
		}
		else
		{
		condition_2_2[index]='\0';
		i++;
		catenation(condition_2,condition_2_2);
		size=convert(condition_2,check_of_condition,colorcheck);
		{


			if(check_of_condition==1)   ;                             /// check condition and acts accordingly////
		//		fd(size,direction,linex,liney,answer,x1,x2,y1,y2,c1,c2,c3,width);

			else if(check_of_condition==2);

			//	bk(size,direction,linex,liney,answer,x1,x2,y1,y2,c1,c2,c3,width);

			else if(check_of_condition==3);
				//rt(size,direction,linex,liney,x1,x2,y1,y2,c1,c2,c3,width); 
			else if(check_of_condition==4);
				//lt(size,direction,linex,liney,x1,x2,y1,y2,c1,c2,c3,width);
			else if(check_of_condition==5);
				//answer=pu();
			else if (check_of_condition==6);
				//answer=pd();
			else if(check_of_condition==7);
				//circle(size,direction,answer,x1,x2,y1,y2,c1,c2,c3,width);
			else if(check_of_condition==8);
				//square(size,direction,answer,x1,x2,y1,y2,c1,c2,c3,width);
			else if(check_of_condition==9);
				//cs(x1,direction,y1,x2,y2,c1,c2,c3,width,linex,liney);
			else if(check_of_condition==10);
				//Width(size,width);
			else if(check_of_condition==11);
				//color(c1,c2,c3,x1,y1,x2,y2,colorcheck,width);
			else 
				goto brek;
		}
		int check_counting=0;
		for(int i=1;i<=amount*2;i++)
		{
			if(check_counting==0)
			{
				size=convert(condition_1,check_of_condition,colorcheck);
				check_counting=1;
			}
			else if(check_counting==1)
			{
				size=convert(condition_2,check_of_condition,colorcheck);
				check_counting=0;
			}
			if(check_of_condition==1)                                /// check condition and acts accordingly////
				fd(size,direction,linex,liney,answer,x1,x2,y1,y2,c1,c2,c3,width);

			else if(check_of_condition==2)

				bk(size,direction,linex,liney,answer,x1,x2,y1,y2,c1,c2,c3,width);

			else if(check_of_condition==3)
				rt(size,direction,linex,liney,x1,x2,y1,y2,c1,c2,c3,width);
			else if(check_of_condition==4)
				lt(size,direction,linex,liney,x1,x2,y1,y2,c1,c2,c3,width);
			else if(check_of_condition==5)
				answer=pu();
			else if (check_of_condition==6)
				answer=pd();
			else if(check_of_condition==7)
				circle(size,direction,answer,x1,x2,y1,y2,c1,c2,c3,width);
			else if(check_of_condition==8)
				square(size,direction,answer,x1,x2,y1,y2,c1,c2,c3,width);
			else if(check_of_condition==9)
				cs(x1,direction,y1,x2,y2,c1,c2,c3,width,linex,liney);
			else if(check_of_condition==10)
				Width(size,width);
			else if(check_of_condition==11)
				color(c1,c2,c3,x1,y1,x2,y2,colorcheck,width);
			else 
				break;
		
		}
		}
		}
		}
		}
		}
		brek:;
		}
	void cursor(int direction,int &linex,int &liney,int &x1,int &x2,int &y1,int &y2,int &c1,int &c2,int &c3,int &width)
	{
		if (direction==0 || direction==360 || direction==-360)
		{
			myEllipse(x1,y1,x2,y2,0,0,0,width);
			
			x1=linex-8;
			x2=linex+8;
			y1=liney-16;
			y2=liney;
			myEllipse(x1,y1,x2,y2,c1,c2,c3,width);
		}
		else if(direction==45 || direction==-315 || direction==90 || direction==-270 || direction==135 || direction==-225 )
		{
			myEllipse(x1,y1,x2,y2,0,0,0,width);
			
			x1=linex+1;
			x2=linex+16+1;
			y1=liney-8;
			y2=liney+8;
			myEllipse(x1,y1,x2,y2,c1,c2,c3,width);
		}

		else if(direction==180 || direction==-180)
		{
			myEllipse(x1,y1,x2,y2,0,0,0,width);
			x1=linex-8;
			x2=linex+8;
			y1=liney+2;
			y2=liney+16+2;
			myEllipse(x1,y1,x2,y2,c1,c2,c3,width);
		}

		else if(direction==225 || direction==-135 || direction==270 || direction==-90 || direction==315 || direction==-45 )
		{
			myEllipse(x1,y1,x2,y2,0,0,0,width);
			x1=linex-16-1;
			x2=linex-1;
			y1=liney-8;
			y2=liney+8;
			myEllipse(x1,y1,x2,y2,c1,c2,c3,width);
		}
	}
	void circle(int a, int &direction, bool &answer, int &x1, int &x2, int &y1, int &y2, int &c1, int &c2, int &c3,int &width)
	{
		int centrex=x1+8,centrey=y1+8;
		if(answer==false)
			ymyEllipse(x1+8-a, y1+8-a, x2-8+a, y2-8+a, c1, c2, c3,width);
		//{	

			//for(int i=0;i<=360;i++)
			//int i=20;
				//int x=a*cos(i) +centrex; 
				//int y=a*sin(i) +centrey;
				//myLine(x,y,x+1,y+1,c1,c2,c3,width);

			//}
		
		myEllipse(x1, y1, x2, y2, c1, c2, c3,width); // check it, it may be extra
		myRect(0,272,80*8,25*12,0,0,0,width);
	}
	void square(int a, int &direction, bool &answer, int &x1, int &x2, int &y1, int &y2, int &c1, int &c2, int &c3,int &width)
	{
		if(answer==false)
			ymyRect(x1+8+a, y1+8+a, x2-8-a, y2-8-a, c1,c2,c3,width);
		/*{
			myLine( x1+8-(a/2 ),y1+8-(a/2),x1+8+(a/2),y1+8-(a/2),c1,c2,c3,width);
			myLine(x1+8+(a/2),y1+8-(a/2),x1+8+(a/2),y1+8-(a/2)+a , c1,c2,c3,width);
			myLine( x1+8+(a/2),y1+8-(a/2)+a ,x1+8-(a/2),y1+8-(a/2)+a, c1,c2,c3,width);
			myLine( x1+8-(a/2),y1+8-(a/2)+a,x1+8-(a/2),y1+8-(a/2), c1,c2,c3,width);
		}*/
		myEllipse(x1, y1, x2, y2, c1, c2, c3,width); // check it, it may be extra
		myRect(0,272,80*8,25*12,0,0,0,width);
	}
	void cs(int &x1,int &direction,int &y1,int &x2, int &y2 , int &c1,int &c2 ,int &c3,int &width,int &linex,int &liney)  
	{
		myRect(0,0,460,269,0,0,0,width);
		myRect(460,0,639,174,0,0,0,width);
		y1=154;
	x1=314;														/// initiate coordinates of the cursor///
	 x2=330;
	 y2=170;
	 linex=x1+8;
	liney=y2;
	direction=0;
	width=1;
	c1=255;
	c2=255;
	c3=255;
		myEllipse(x1,y1,x2,y2,c1,c2,c3,width);
		myRect(458,174,80*8,25*12,0,0,0,width);
		interface1(1,2);
	}
	void Width(int &a,int &width)
	{
		width=a;	
	}
	void color(int &c1,int &c2,int &c3,int &x1,int &y1,int &x2,int &y2,int &colorcheck,int &width)
	{
		if(colorcheck==1)          //white
		{
			c1=255;c2=255;c3=255;
		}
		else if(colorcheck==2)				// red
		{
			c1=255;c2=0;c3=0;
		}
		else if(colorcheck==3)				//blue
		{
			c1=0;c2=0;c3=255;
		}
		else if(colorcheck==4)		//green
		{
			c1=0;c2=255;c3=0;
		}
		else if(colorcheck==5)		//pink
		{
			c1=255;c2=0;c3=255;
		}
		else if(colorcheck==6)				//purple
		{
			c1=51;c2=0;c3=102;
		}
		else if(colorcheck==7)       //aqua
		{
			c1=51;c2=255;c3=255;
		}
		else if(colorcheck==8)        //orange
		{
			c1=255;c2=50;c3=0;
		}
		else if(colorcheck==9)       //yellow 
		{
			c1=255;c2=255;c3=0;
		}
		else if(colorcheck==10)     //grey
		{
			c1=100;c2=100;c3=100;
		}
		myEllipse(x1,y1,x2,y2,c1,c2,c3,width);         // to colour the cursor right after the color command
	}
	void catenation(char a[],char b[])
	{
		int i=0;
		for(;a[i]!='\0';i++){;}
		a[i]=' ';
		i++;
		int j=0;
		for(;b[j]!='\0';j++)
		{
			a[i]=b[j];
			i++;
		}
		a[i]='\0';
	}
	void save(char a[][100],int &no_of_commands_given,int &startingpoint,char arr[])
	{
		string str1=".txt";
		char filename[20];
		int index=0;
		bool do_it_or_not=false;
		for(int i=6;arr[i]!='\0';i++)
		{
			if(arr[i]=='"')
			{
				do_it_or_not=true;
				break;
			}
			filename[index]=arr[i];
			index++;
		}
		if(do_it_or_not==false)
			{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
		else
		{
		filename[index]='\0';
		string str2=filename;
		string str3=str2+str1;
		ofstream aout(str3,ios::out | ios :: app);
		int carrier=no_of_commands_given;
		
		int carrier1=no_of_commands_given-startingpoint;
		if(carrier1>=100)
			carrier=startingpoint+100;
		for(; startingpoint<carrier;startingpoint++)
		{
			aout<<a[startingpoint]<<endl;
		} 
		startingpoint=carrier;
		aout.close();
		}
	}
 	void load(char arr[],int &linex,int &liney,bool answer,int &x1,int &x2,int &y1,int &y2,int &c1,int &c2,int &c3,int &width,int &amount,int &check_of_condition,int &direction,int &colorcheck)
	{string string1=".txt";
		char filename[20];
		int index=0;
		bool do_it_or_not=false;
		for(int i=6;arr[i]!='\0';i++)
		{
			if(arr[i]=='"')
			{
				do_it_or_not=true;
				break;
			}
			filename[index]=arr[i];
			index++;
		}
		if(do_it_or_not==false)
			{
			gotoxy(0,23);
					cout<<"                                                                                ";
					gotoxy (25,23);
					cout<<"Incomplete command!!";
					Sleep(1500);
					gotoxy(0,23);
					cout<<"                                                                                 ";

		}
		else
		{
		filename[index]='\0';
		string string2=filename;
		string string3=string2+string1;
		ifstream ain(string3);
		char store[100][100];
		char arr1[50];
		int no_of_commands_given=0;
		int startingpoint=0;
		char condition_1[20];
		char condition_2[20];
				ain.getline(arr1,50);
				int i=0;
				for(;i<100;i++)
		    {
			int j=0;
		        for(;arr1[j]!='\0';j++)
		          {
		               store[i][j]=arr1[j];
					   
		          }
				no_of_commands_given++;

		store[i][j]='\0';
		i++;
		break;
		}
		while(ain.eof()==false)
		{


		int a=convert(arr1,check_of_condition,colorcheck);

			if(check_of_condition==1)                                /// check condition and acts accordingly////
				fd(a,direction,linex,liney,answer,x1,x2,y1,y2,c1,c2,c3,width);

			else if(check_of_condition==2)

				bk(a,direction,linex,liney,answer,x1,x2,y1,y2,c1,c2,c3,width);

			else if(check_of_condition==3)
				rt(a,direction,linex,liney,x1,x2,y1,y2,c1,c2,c3,width);
			else if(check_of_condition==4)
				lt(a,direction,linex,liney,x1,x2,y1,y2,c1,c2,c3,width);
			else if(check_of_condition==5)
				answer=pu();
			else if (check_of_condition==6)
				answer=pd();
			else if(check_of_condition==7)
				circle(a,direction,answer,x1,x2,y1,y2,c1,c2,c3,width);
			else if(check_of_condition==8)
				square(a,direction,answer,x1,x2,y1,y2,c1,c2,c3,width);
			else if(check_of_condition==9)
				cs(x1,direction,y1,x2,y2,c1,c2,c3,width,linex,liney);
			else if(check_of_condition==10)
				Width(a,width);
			else if(check_of_condition==12)
			{
				//int size;
				repeat(condition_1,condition_2,arr1,linex,liney,answer,x1,x2,y1,y2,c1,c2,c3,width,amount,check_of_condition,direction,colorcheck );
				//for(int i=1;i<=amount;i++)
				//{
				// size=convert(arr,check_of_condition,colorcheck,condition_1,condition_2);
				//}
			}
			else if(check_of_condition==11)
				color(c1,c2,c3,x1,y1,x2,y2,colorcheck,width);
			/*else if(check_of_condition==7)
			repeat(arr,direction,linex,liney,answer,x1,x2,y1,y2,c1,c2,c3);*/
			else if(check_of_condition==13)
			{
			save(store,no_of_commands_given,startingpoint,arr1);
			
			}
				else if(check_of_condition==14)
			{
			load(arr1,linex,liney,answer,x1,x2,x1,y2,c1,c2,c3,width,amount,check_of_condition,direction,colorcheck);
			
			}
					else if(check_of_condition==15)
			{
			exit();	
			break;
			}
			gotoxy(0,23);
			cout<<"                                                                                ";										 // to clear screen after first command//
			
			interface1(1,2);
					ain.getline(arr1,50);
					for(;i<100;i++)
		    {
			int j=0;
		        for(;arr1[j]!='\0';j++)
		          {
		               store[i][j]=arr1[j];
					   
		          }
				no_of_commands_given++;

		store[i][j]='\0';
		i++;
		break;
		}
					Sleep(100);
		}
		ain.close();
		}
	}
    void b(int x1, int y1, int x2, int y2, int c1, int c2, int c3,int width)
{
	myEllipse(x1, y1, x2, y2, c1, c2, c3,width);
	//myLine(x1 + 20, y2, x1 + 20, y2 + 50, 255, 255, 255);
	int x = 0;
	while (x < 50)
	{
		Sleep(30);
		myEllipse(x1, y1 + 2, x2, y2 + 2, 0, 0, 0,width);
		myLine(x1 + 20, y2 + 30 + 3, x1 + 20, y2, 0, 0, 0,width);
		myEllipse(x1, y1, x2, y2, c1, c2, c3,width);
		myLine(x1 + 20, y2 + 30, x1 + 20, y2, c1, c2, c3,width);
		y2--;
		y1--;
		x++;
	}
}
    void thanks(int x1, int y1, int x2, int y2,int width)
{
	Sleep(50);
	//myLine(x1, y1, x1, y1+20,255,255,255);
	//myLine(x1, y1+20, x1+50, y1+20, 255, 255, 255);
	//myLine(x1+50, y1, x1 + 50, y1 + 20, 255, 255, 255);
	//myEllipse(x1+120, y1-60, x2-40, y2, 255, 255, 255);
	//myEllipse(x1 + 30, y1 - 20, x2 - 40, y2, 255, 255, 255);
	myEllipse(x1 + 200 - 90, y1 + 200 - 80, x1 - 90, y1 - 50, 255, 255, 255,width);
	gotoxy(36, 10);
	int a = 0;
	while (a == 0)
	{
		Sleep(100);
		cout << " T";
		Sleep(100);
		cout << "H";
		Sleep(100);
		myEllipse(x1 + 200 - 90, y1 + 200 - 80, x1 - 90, y1 - 50, 255, 255, 0,width);
		//Sleep(100);
		cout << "A";
		Sleep(100);
		cout << "N";
		Sleep(100);
		cout << "K";
		Sleep(100);
		myEllipse(x1 + 200 - 90, y1 + 200 - 80, x1 - 90, y1 - 50, 0, 0, 255,width);
		cout << "S";
		Sleep(500);
		myEllipse(x1 + 200 - 90, y1 + 200 - 80, x1 - 90, y1 - 50, 255, 0, 127,width);
		cout << endl;
		gotoxy(36, 11);
		cout << "T";
		Sleep(100);
		cout << "H";
		Sleep(100);
		cout << "A";
		Sleep(100);
		cout << "T";
		Sleep(100);
		cout << "'";
		Sleep(100);
		myEllipse(x1 + 200 - 90, y1 + 200 - 80, x1 - 90, y1 - 50, 153, 255, 153,width);
		cout << "S ";
		Sleep(100);
		cout << "O";
		Sleep(100);
		cout << "U";
		Sleep(100);
		cout << "R ";
		Sleep(500);
		myEllipse(x1 + 200 - 90, y1 + 200 - 80, x1 - 90, y1 - 50, 255, 0, 127,width);
		cout << endl;
		gotoxy(36, 12);
		Sleep(100);
		cout << " P";
		Sleep(100);
		cout << "R";
		Sleep(100);
		cout << "O";
		Sleep(100);
		myEllipse(x1 + 200 - 90, y1 + 200 - 80, x1 - 90, y1 - 50, 255, 255, 0,width);
		cout << "J";

		Sleep(100);
		cout << "E";
		Sleep(100);
		cout << "C";
		Sleep(100);
		cout << "T!";
		Sleep(500);
		myEllipse(x1 + 200 - 90, y1 + 200 - 80, x1 - 90, y1 - 50, 0, 0, 0,width);
		Sleep(100);
		a = 1;
		cout << endl;
		gotoxy(0, 23);
	}
}
    void baloons(int x1, int y1, int x2, int y2, int c1, int c2, int c3) // popping up of baloons in the end
{
	int width =1;
	b(x1, y1, x2, y2, 102, 255, 102,width);
	b(x1 + 80, y1, x2 + 80, y2, 255, 255, 255,width);
	b(x1 - 80, y1, x2 - 80, y2, 255, 0, 127,width);
	b(x1 + 160, y1, x2 + 160, y2, 255, 128, 0,width);
	b(x1 - 160, y1, x2 - 160, y2, 255, 0, 255,width);
	b(x1, y1, x2, y2, 0, 0, 0,width);
	b(x1 + 80, y1, x2 + 80, y2, 0, 0, 0,width);
	b(x1 - 80, y1, x2 - 80, y2, 0, 0, 0,width);
	b(x1 + 160, y1, x2 + 160, y2, 0, 0, 0,width);
	b(x1 - 160, y1, x2 - 160, y2, 0, 0, 0,width);
	thanks(x1, y1, x2, y2,width);
}
    void exit() // exiting the function and pops up baloons
{
	int width=1;
	myRect(0,0,80*8,25*12,0,0,0,width);
	int x1, y1, x2, y2;
	int c1, c2, c3;
	c1 = 
	x1 = 320;
	x2 = 360;
	y1 = 110;
	y2 = 160;
	baloons(x1, y1, x2, y2, 0, 0, 255);
}
    void interface1(int width,int forline) // interface for the project
{
	
	myLine(0,269,638,269,0,0,200,width); 
	myLine(0,271,638,271,200,0,0,forline); 
	myLine(0,272,638,272,0,200,0,width); 
	myLine(460,270,460,175,255,0,0,width);
	myLine(460,175,638,175,255,0,0,width);
	myLine(460,198,638,198,255,0,0,width);
	myLine(460,221,638,221,255,0,0,width);
	myLine(460,244,638,244,255,0,0,width);
}