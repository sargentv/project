#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
# define auth 1234
FILE *fp, *fp1, *fp2;
struct d{
	 int date;
	 int month;
	 char day[10];
  	 int year;
	};
struct p{
	struct d st;
	int time;
	int seats;
	float price;
	};
typedef struct{		//for entering new movie
	      char m_name[25];
	      int rating;
	      char m_type[10];
	      char theatre[25];
	      char actor_name[3][25];
	      int nos;
	      struct d r_date;
	      struct p x[21];		//only 3 shows in a day
	      }movie;
typedef struct{		//for booking tickets
	       float t_cost;
	       float c_charge;
	       int credit;
               long int bank_card;
               long int a_id;
               char cin[25];
               char mov[25];
               int s_no[100];
	       struct p q;		//show date, time, price
	      }book;
typedef struct{		//for user profile
	      long int a_id;		//account id
	      char pass[25];
	      char name[25];
	      char email[100];
	      int credits;	
	      long long int p_no;		//phone no.
	      }user;
void home( ){		//home page
	printf("\n\n\n\t\t\tBOOK MY SHOW- Movies");
	printf("\n\t\t\t\t\tWELCOME!!!\n\n\nChoose an option from the menu:\n\n1.User Login\n2.Create an Account\n3.Executive Login\n4.View 		recent release\n5.Exit\n\n(Note-to book a movie you must have an account with us.)\n\nEnter your choice:");
	}

user booker(user u){		//for booking tickets
	char c,h;
	long int a;
	fp2=fopen("tic.txt","a+");
	fp1=fopen("exe.txt","r+");
		if((fp2!=NULL)||(fp1!=NULL))
			{rewind(fp1);
			int i,j;
			book b;
			movie m;
			int flag;
			flag=0;
			b.a_id=u.a_id;
			printf("\nenter name of theatre:");
			scanf("%s",b.cin);
			printf("\nenter movie name:");
			scanf("%s",b.mov);
			printf("\nenter show details:\nDate:");
			scanf("%d",&(b.q.st.date));
			printf("\nenter month:");
			scanf("%d",&(b.q.st.month));
			printf("\nenter year:");
			scanf("%d",&(b.q.st.year));
			printf("\nenter  day:");
			scanf("%s",b.q.st.day);
			printf("\nenter show time:");
			scanf("%d",&(b.q.time));
				while(!feof(fp1))
					{fread(&m,sizeof(movie),1,fp1);
						if((strcmp(m.m_name,b.mov)==0)&&(strcmp(b.cin,m.theatre)==0))
						{
							for(i=0;i<m.nos;i++)
								{if((m.x[i].st.date==b.q.st.date)&&(m.x[i].st.month==b.q.st.month)&&(m.x[i].st.year==b.q.st.year)&&(m.x[i].time==b.q.time)&&(strcmp(m.x[i].st.day,b.q.st.day)==0))
									flag=1;break;}
						}			
						a=ftell(fp1);
						break;
					}	
				if(flag==1)
					{
					printf("\nenter no of seats(max %d):",m.x[i].seats);
					scanf("%d",&(b.q.seats));
						if(m.x[i].seats<b.q.seats)
							printf("\nseats unavalible");
						else
							{int y,z;
							float dis;
							z=u.credits/10;
							y=m.x[i].price*b.q.seats;
							dis=0.1*z*y;
							b.c_charge=0.1*y;
							b.t_cost=y+b.c_charge-dis;
							printf("\nconvinience charge(10%% of total ticket charge)=Rs.%f",b.c_charge);
							printf("\ndiscount offered on %d credits (disount=%d%%) =Rs.%f",u.credits,z*10,dis);
							printf("\ntotal cost =Rs.%f",b.t_cost);
							if(z!=0)
							u.credits=0;
							printf("\nenter bank card no:"); 
							scanf("%ld",&(b.bank_card));
							printf("\n\nSEATS:");
								for(j=0;j<b.q.seats;j++)
									{b.s_no[j]=m.x[i].seats;
									printf(" %d,",b.s_no[j]);
									m.x[i].seats--;
									}
							u.credits+=b.q.seats;
							fseek(fp1,(a+((-1)*sizeof(movie))),0);
							fwrite(&m,sizeof(movie),1,fp1);
							fseek(fp2,0,2);
							fwrite(&b,sizeof(book),1,fp2);
							fclose(fp1);
							fclose(fp2);
							printf("\n%d seats booked",b.q.seats);
							}
					}				
				else
					printf("\nMovie with above specifications not found");
					}				
				else
					printf("\nan error occured while booking tickets! Try again!");
				scanf("%c",&c);
				scanf("%c",&h);
return(u);
}



void history(user u)		//booking history
	{char c,h;
	printf("\n\nTickets booked:\n");
	fp1=fopen("tic.txt","a+");
	if(fp1==NULL)
		printf("an error occured. Try again!!");
	else
		{int flag,i;
		flag=0;
		rewind(fp1);
		while(!feof(fp1))
			{book b;
			fread(&b,sizeof(book),1,fp1);
				if(b.a_id==u.a_id)
					{printf("\n\nTheatre:%s\tMovie:%s\tdate:%d-%d-%d\tday:%s\ttime:%d\tTotal cost:%f\nBank card no:%ld\nseat nos: ",b.cin,b.mov,b.q.st.date,b.q.st.month,b.q.st.year,b.q.st.day,b.q.time,b.t_cost,b.bank_card);
					for(i=0;i<b.q.seats;i++)
						printf("%d,",b.s_no[i]); 
					flag=1;
				}
		}
		if(flag==0)
			printf("\nyou have not booked any tickets with us");
		}
	fclose(fp1);
	scanf("%c",&c);
	scanf("%c",&h);
	}



void ulogin()		//user login
	{char p[25];
	long int e;
	printf("\n\nenter your acoount_Id:");
	scanf("%ld",&e);
	printf("\nenter your password:");
	scanf("%s",p);
	fp=fopen("user.txt","r+");
	if(fp==NULL) 
		{printf("an error occured!\ttry again.");}
	else
		{rewind(fp);
		user u;
		int flag;
		long int a;
		flag=0;
		while(!feof(fp))
			{fread(&u,sizeof(user),1,fp);
 			if((u.a_id==e)&&(strcmp(u.pass,p)==0)&&(u.a_id!=0))
 				{start1: printf("\n\n\t\tWelcome %s\nchoose an option from list:\n1.Book ticket\n2.Edit profile\n3.Delete account\n4.View profile\n5.View booked tickets\n6.Logout",u.name);flag=1;a=ftell(fp);break;}
			}
		if(flag==0) 
			printf("account not found");
		else
			{printf("\n\nenter your choice:");
			int ch;
			scanf("%d",&ch);
			switch(ch){
				case 1: u=booker(u); fseek(fp,a+((-1)*sizeof(user)),0);fwrite(&u,sizeof(user),1,fp); fclose(fp); break;
				case 2:printf("\nenter your name:");
					scanf("%s",u.name);
					printf("\nenter your e-mail Id:");
					scanf("%s",u.email);
					printf("\nenter your Phone no:");
					scanf("%lld",&(u.p_no));
					printf("\nenter a password for your account(max 25 characters):");
					scanf("%s",u.pass);
					fseek(fp,(a+((-1)*sizeof(user))),0);fwrite(&u,sizeof(user),1,fp); fclose(fp); printf("\n\n your account has been modified");  break;
				case 3: u.a_id=0;strcpy(u.pass,"");fseek(fp,(a+((-1)*sizeof(user))),0); fwrite(&u,sizeof(user),1,fp); fclose(fp); printf("\n\n your account has been deleted");  break;
				case 4:printf("\n\nAccount Id:%ld\nName:%s\nemail:%s\nCredits earned:%d\nphone no:%lld",u.a_id,u.name,u.email,u.credits,u.p_no); fclose(fp);break;
				case 5:history(u); fclose(fp); break;
				case 6:fclose(fp);printf("\nyou have logged out succesfully"); break;
				default: printf("\nwrong choice!! enter again"); goto start1;
			}
			if((ch==6)||(ch==3)) ;
			else
			goto start1;
		}
	}
}



void create()		//creating account
	{user u;
	char c,p;
	printf("\nenter your name:");
	scanf("%s",u.name);
	printf("\nenter your e-mail Id:");
	scanf("%s",u.email);
	printf("\nenter your Phone no:");
	scanf("%lld",&(u.p_no));
	printf("\nenter a password for your account(max 25 characters):");
	scanf("%s",u.pass);
	u.credits=0;
	u.a_id=(rand()/1000);
	fp=fopen("user.txt","a");
	if(fp==NULL) 
		{printf("\nan error occured while creating account.\tplease try again");}
	else
		{fseek(fp,0,2);
		fwrite(&u,sizeof(user),1,fp);
		fclose(fp);
		printf("\nyour account_id is:%ld\n\tACCOUNT CREATED SUCCESSFULLY",u.a_id);
		}
	scanf("%c",&c);
	scanf("%c",&p);
	}


void elogin()		//executive login for entering movies
	{int r,i,j;
	char ch,p;
	ch='y';
	printf("\n\nenter Password:");
	scanf("%d",&r);
	if(r==auth) 
		{printf("\n\n\t\tWELCOME");
		while((ch=='y')||(ch=='Y'))
		{
			movie m;
			printf("\n\nenter movie name:");
			scanf("%s",m.m_name);
			printf("\nenter critic rating(1-5):");
			scanf("%d",&m.rating);
			printf("\nenter movie type:");
			scanf("%s",m.m_type);
			printf("\nenter theatre name:");
			scanf("%s",m.theatre);
			for(i=0;i<3;i++)
				{printf("\nenter name of actor #%d:",i+1);
				scanf("%s",m.actor_name[i]);}
			printf("\nenter release date:\ndate:");
			scanf("%d",&(m.r_date.date));
			printf("\nmonth:");
			scanf("%d",&(m.r_date.month));
			printf("\nyear:");
			scanf("%d",&(m.r_date.year));
			printf("\nday:");
			scanf("%s",m.r_date.day);
			printf("\nenter total no of shows for movie(max 3 shows/day):");
			scanf("%d",&(m.nos));
			for(j=0;j<m.nos;j++)
				{ printf("\nshow #%d\nshow date:",j+1);
				scanf("%d",&(m.x[j].st.date));
				printf("\nshow month:");
				scanf("%d",&(m.x[j].st.month));
				printf("\nshow year:");
				scanf("%d",&(m.x[j].st.year));
				printf("\nshow day:");
				scanf("%s",m.x[j].st.day);
				printf("\nenter show time:");
				scanf("%d",&(m.x[j].time));
				printf("\nenter show price:");
				scanf("%f",&(m.x[j].price));
				printf("\nenter no of seats:");
				scanf("%d",&(m.x[j].seats));
				}
			fp=fopen("exe.txt","a+");
			if(fp==NULL) 
				{printf("an error occured. TRY again!!");}
			else{
				fseek(fp,0,2);
				fwrite(&m,sizeof(movie),1,fp);
				fclose(fp);printf("\n\n\tMovie entered in database");}
			scanf("%c",&p);
			if(ch!='\n')
				printf("\nwanna enter more movies?( enter y or Y for yes):");
			scanf("%c",&ch);
			}
		}		
		else 
			printf("\n\n\tAUTHENTICATION FAILURE");
	}



void release()		//displaying movie releases
	{movie m;
	char c;
	fp=fopen("exe.txt","a+");
	if(fp==NULL)
		{printf("\nan error occured. TRY again!!");}
	else
		{int i;
		rewind(fp);
		while(!feof(fp))
			{fread(&m,sizeof(movie),1,fp);
			printf("\n\nMovie:%s\ncrirtic rating:%d\ntheatre:%s\nactor names:\n1.%s\n2.%s\n3.%s\ntype:%s\nrelease date:%d-%d-%d\nShow date\tShow day\tShow Time\tseat avalible\tprice\n",m.m_name,m.rating,m.theatre,m.actor_name[0],m.actor_name[1],m.actor_name[2],m.m_type,m.r_date.date,m.r_date.month,m.r_date.year);
			for(i=0;i<m.nos;i++)
				{printf("\n%d/%d/%d\t%s\t\t%d\t \t%d\t\t%f",m.x[i].st.date,m.x[i].st.month,m.x[i].st.year,m.x[i].st.day,m.x[i].time,m.x[i].seats,m.x[i].price);}
			}
		fclose(fp);
	}
	scanf("%c",&c);
	}


void main()		//main function
	{start:
	home();
	int ch;
	scanf("%d",&ch);
	switch(ch)
		{case 1:ulogin(); break;
 		case 2:create(); break;
 		case 3:elogin(); break;
 		case 4:release(); break;
 		case 5:exit(0);
 		default:printf("\nwrong choice"); goto start;
	}
	goto start;
	}
