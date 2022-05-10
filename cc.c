#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
void verification(int,int,int);
void allotment(int);
int student();
int admin();
int verifypw()
{
	int t=0;
    char password[20],rpw[20];
    FILE *fptr;
	printf("\nEnter password:\n ");
			fptr=fopen("password.txt","r");
            fscanf(fptr,"%s",&rpw);
            fclose(fptr);
            do
            {
             	password[t]=getch();
        	    if(password[t]!='\r')
        	    {
        		  printf("*");
			    }
			   t++;
		    }while(password[t-1]!='\r');
		    password[t-1]='\0';
		    if(strcmp(password,rpw)==0)
		    {
		      printf("\n SUCCESS");
			  admin();
		    }
		    else
         	{
         		system("CLS");  
		        printf("INCORRECT PASSWORD");
				verifypw();
          	}
}
struct details
{
	char name[20];
	char fathers_name[20];
    char gender[3];
	char date_of_birth[10];
	int rank;
	int hall_ticket;
	char region[5];
	char caste[6];
	char reservation[3];
};
struct prior
{
	int count;
	char namea[20];
	char fathers_namea[20];
	char gendera[3];
	char date_of_birtha[10];
	int ranka;
	int hall_ticketa;
	char regiona[5];
	char castea[6];
	char reservationa[3];
};
struct colleges
{
	char college[20];	
};
int student()
{
   fflush(stdin);
   struct details d[10];
   int n=0,i,v,sa;
   char ver;
   char dob[10];
   FILE *fptr;
  fptr = fopen("program.txt","r");
  for(n=0;n<10;n++)
   {
   fscanf(fptr," %s %s %s %s %d %d %s %s %s ", &d[n].name,&d[n].fathers_name,&d[n].gender,&d[n].date_of_birth,
   &d[n].rank,&d[n].hall_ticket,&d[n].region,&d[n].caste,&d[n].reservation);
   }
    fclose(fptr); 
   printf("\n Enter Hall ticket no. to log in:");
   scanf("%d",&i);
   printf("\nEnter the DOB(DD-MM-YYYY):");
   scanf("%s",&dob);
   if((i-1901==0||(i-1901<10)&&(i-1901>0))&&strcmp(dob,d[i-1901].date_of_birth)==0)
   {
   printf("Student's name: %s\n", d[i-1901].name);
   printf("Father's name: %s\n", d[i-1901].fathers_name);
   printf("Gender: %s\n", d[i-1901].gender);
   printf("Date of birth: %s\n", d[i-1901].date_of_birth);
   printf("Rank: %d\n", d[i-1901].rank);
   printf("Hall ticket: %d\n", d[i-1901].hall_ticket);
   printf("Region: %s\n", d[i-1901].region);
   printf("Caste: %s\n", d[i-1901].caste);
   printf("Reservation(if any): %s\n", d[i-1901].reservation);
   fflush(stdin);	
   	printf("Press '1' if details are verified or else press any number \n");
	scanf("%d",&v);
	if(v==1)
	{
		printf("Press '1' for selecting colleges and '2' for allotment \n");
		scanf("%d",&sa);
     verification(i,v,sa);
    }
    else
    {
	printf("CONTACT ADMINISTRATION OFFICE");
	}
 }
   else 
   {
   	system("CLS");
    printf("INVALID DATA \a");
    student();
   }
   return 0;
   
}
void verification(int i,int v,int sa)
{
	 fflush(stdin);
	int l=0,c=0,pt[20],p=1,codes[50],s,ve;
	char num[100];
	FILE *fptr;
	fptr=fopen("codes.txt","r");
            for(s=0;s<50;s++)
            {
            	fscanf(fptr,"%d",&codes[s]);
			}
			fclose(fptr);
		if(sa==1)
		{
			
			printf("\nPress '1' for updating your colleges,'2'for verification and '3' for log out");
			scanf("%d",&ve);
			switch(ve)
			{
			case 1:
		    {
		    	system("CLS");
				 printf("SELECT COLLEGES \n");
			fptr = fopen("collegelist.txt","r");
			while(l<100)
			{
			fscanf(fptr,"%c",&num[l]);
            printf("%c",num[l]);
            l++;
            }
            fclose(fptr);
            printf("\n Press 501 once done \n");
            {
	        if(codes[((i-1901)*5)-1]!=5)
			 {
             codes[((i-1901)*5)-1]=0;
             }
            }
            for(c=(i-1901)*5;c<(i-1900)*5;)
            {
            if(codes[c-1]!=501)
            {
            	
            	printf("\nEnter your %d college code:",p);
            	scanf("%d",&codes[c]);
            	c++;
            	p++;
			}
			else 
			break;
		    }
		    fptr=fopen("codes.txt","w");
		    for(s=0;s<50;s++)
		    {
		    	fprintf(fptr,"%d \n",codes[s]);
			}
			fclose(fptr);	
				verification(i,v,sa);
				break;
			    }
			case 2:
				{
					system("CLS");
				s=1;
				 if(codes[(i-1901)*5]==0)
				 {
				 	printf("No colleges have been selected by you");
				 }
				 else
				 {	
				  printf("\t \tVERIFICATION");
				  for(c=(i-1901)*5;c<(i-1900)*5;c++)
				  {
				    if(codes[c]!=0&&codes[c]!=501)
				    {
				     printf("\n %d college entered by you is %d",s,codes[c]);
				     s++;	
				    } 
				  }
				}
				verification(i,v,sa);
				break;
			    }
			case 3:
				{
				break;
			    }
			}
		}
		else if(sa==2)
		{
			allotment(i);
			}	
 }

void allotment(int i)
{
	 fflush(stdin);
	int s,codes1[50],n,r,t,temp,f,clg,rv,check,fi;
	   struct details d[10];
	   struct prior pr[5];
	   struct colleges codec[5];
	   char temp1[10];
	   int ca;
	FILE *fptr;
	fptr=fopen("codes.txt","r");
            for(s=0;s<50;s++)
            {
            	fscanf(fptr,"%d",&codes1[s]);
			}
			fclose(fptr);
			if(codes1[(i-1901)*5]==0)
			printf("Details are not entered by you");
				fptr = fopen("program.txt","r");
                for(n=0;n<10;n++)
                {
                	fscanf(fptr," %s %s %s %s %d %d %s %s %s ", &d[n].name,&d[n].fathers_name,&d[n].gender,&d[n].date_of_birth,
                    &d[n].rank,&d[n].hall_ticket,&d[n].region,&d[n].caste,&d[n].reservation);
                }
                fclose(fptr);
                for(r=0;r<9;r++)
                {
                	for(t=0;t<10-r-1;t++)
                	if(d[t].rank>d[t+1].rank)
                	{
                		temp=d[t].rank;
                		d[t].rank=d[t+1].rank;
                		d[t+1].rank=temp;
                		temp=d[t].hall_ticket;
                		d[t].hall_ticket=d[t+1].hall_ticket;
                		d[t+1].hall_ticket=temp;
                		strcpy(temp1,d[t].name);
                		strcpy(d[t].name,d[t+1].name);
                		strcpy(d[t+1].name,temp1);
                		strcpy(temp1,d[t].fathers_name);
                		strcpy(d[t].fathers_name,d[t+1].fathers_name);
                		strcpy(d[t+1].fathers_name,temp1);
                		strcpy(temp1,d[t].gender);
                		strcpy(d[t].gender,d[t+1].gender);
                		strcpy(d[t+1].gender,temp1);
                		strcpy(temp1,d[t].region);
                		strcpy(d[t].region,d[t+1].region);
                		strcpy(d[t+1].region,temp1);
                		strcpy(temp1,d[t].date_of_birth);
                		strcpy(d[t].date_of_birth,d[t+1].date_of_birth);
                		strcpy(d[t+1].date_of_birth,temp1);
						strcpy(temp1,d[t].caste);
                		strcpy(d[t].caste,d[t+1].caste);
                		strcpy(d[t+1].caste,temp1);
                		strcpy(temp1,d[t].reservation);
                		strcpy(d[t].reservation,d[t+1].reservation);
                		strcpy(d[t+1].reservation,temp1);
					}
				}
			    for(r=0;r<5;r++)
			    {
			    	pr[r].count=0;
				}
                fptr = fopen("colleges.txt","r");
                for(n=0;n<5;n++)
                {
                 fscanf(fptr," %s",&codec[n].college);
                }     
                fclose(fptr);
			printf("\n To display your alloted college press '1' or if you want to display the respective college list press '2'");
                 fflush(stdin);			    
			scanf("%d",&ca);
			switch(ca)
			{
			case 1:
				{
				
				for(r=0;r<10;r++)
				{
					if(d[r].hall_ticket==i)
					{
						rv=d[r].rank;
						break;
					}
				}
			    for(r=0;r<rv;r++)
				{
					f=d[r].hall_ticket;
					for(t=(f-1901)*5;t<(f-1900)*5;)
					{
					 clg=codes1[t];
					 check=0;
					 if(pr[clg-1].count<2)
					 {
					 	pr[clg-1].count++;
				        check=1;
					 	break;
					 }	
					 else
					 {
					 	t++;
					 }
			        }
			    }
				if(check==0||clg==0||clg==501)
				{
				 system("CLS");
				 printf("No college has been alloted");
			    }
				else
				{ 
				    system("CLS");
					printf("The alloted college for %d is %d i.e %s",f,clg,codec[clg-1].college);
				}   
				 break;
			    }
				case 2:   
				{
					 system("CLS");
					 printf("Enter the college code to display:");
				     scanf("%d",&check);
				     printf(" \t \t %s \t \t \n",codec[check-1].college);
				     printf("Hall_ticket_no.\t Rank\t Name    \t Father's_name \t Gender          DOB \t    region\tCaste\t Reservation\t ");
				for(r=0;r<10;r++)
				{
					f=d[r].hall_ticket;
					for(t=(f-1901)*5;t<(f-1900)*5;)
					{
					 clg=codes1[t];
					 if(pr[clg-1].count<2)
					 { 
					 	pr[clg-1].count++;
				        strcpy(pr[clg-1].namea,d[r].name);
						strcpy(pr[clg-1].fathers_namea,d[r].fathers_name);
				        strcpy(pr[clg-1].gendera,d[r].gender);
				        pr[clg-1].hall_ticketa=d[r].hall_ticket;
				        strcpy(pr[clg-1].date_of_birtha,d[r].date_of_birth);
				        pr[clg-1].ranka=d[r].rank;
				        strcpy(pr[clg-1].regiona,d[r].region);
				        strcpy(pr[clg-1].castea,d[r].caste);
				        strcpy(pr[clg-1].reservationa,d[r].reservation);
				        if(clg==check)
				        {
					      printf("\n     %d\t   %d\t %s\t   %s\t    %s       %s   \t %s    \t %s\t    %s\t  ",pr[check-1].hall_ticketa,pr[check-1].ranka,
					      pr[check-1].namea,pr[check-1].fathers_namea,pr[check-1].gendera,pr[check-1].date_of_birtha,pr[check-1].regiona,pr[check-1].castea,
					      pr[check-1].reservationa);
				        }
				        break;
					 }	
					 else if(clg==0)
					 {
					 	break;
					 } 
					 else if(pr[clg-1].count>2||clg!=0)
					 {
					 	t++;
					 }
				    }
			    }	
				if(pr[check-1].count==0)
				printf("\n \t \t \tno students have been alloted this college");	    
		      	break;
	            }
            }
    printf("\n Press '1' to go back else press '2'to log out");
    scanf("%d",&fi);
    switch(fi)
    {
    	case 1:
    		{
    			allotment(i);
    			break;
			}
		case 2:
		    {
			 break;
			}	
	} 
}
int admin()
{
	int s,codes1[50],n,r,t=0,temp,f,clg,choice,check,fi,m;
	   struct details d[10];
	   struct prior pr[5];
	   struct colleges codec[5];
	   char temp1[10];
	   int ca;
	FILE *fptr;
	fptr=fopen("codes.txt","r");
            for(s=0;s<50;s++)
            {
            	fscanf(fptr,"%d",&codes1[s]);
			}
			fclose(fptr);
				fptr = fopen("program.txt","r");
                for(n=0;n<10;n++)
                {
                	fscanf(fptr," %s %s %s %s %d %d %s %s %s ", &d[n].name,&d[n].fathers_name,&d[n].gender,&d[n].date_of_birth,
                    &d[n].rank,&d[n].hall_ticket,&d[n].region,&d[n].caste,&d[n].reservation);
                }
                fclose(fptr);
                for(r=0;r<9;r++)
                {
                	for(t=0;t<10-r-1;t++)
                	if(d[t].rank>d[t+1].rank)
                	{
                		temp=d[t].rank;
                		d[t].rank=d[t+1].rank;
                		d[t+1].rank=temp;
                		temp=d[t].hall_ticket;
                		d[t].hall_ticket=d[t+1].hall_ticket;
                		d[t+1].hall_ticket=temp;
                		strcpy(temp1,d[t].name);
                		strcpy(d[t].name,d[t+1].name);
                		strcpy(d[t+1].name,temp1);
                		strcpy(temp1,d[t].fathers_name);
                		strcpy(d[t].fathers_name,d[t+1].fathers_name);
                		strcpy(d[t+1].fathers_name,temp1);
                		strcpy(temp1,d[t].gender);
                		strcpy(d[t].gender,d[t+1].gender);
                		strcpy(d[t+1].gender,temp1);
                		strcpy(temp1,d[t].region);
                		strcpy(d[t].region,d[t+1].region);
                		strcpy(d[t+1].region,temp1);
                		strcpy(temp1,d[t].date_of_birth);
                		strcpy(d[t].date_of_birth,d[t+1].date_of_birth);
                		strcpy(d[t+1].date_of_birth,temp1);
						strcpy(temp1,d[t].caste);
                		strcpy(d[t].caste,d[t+1].caste);
                		strcpy(d[t+1].caste,temp1);
                		strcpy(temp1,d[t].reservation);
                		strcpy(d[t].reservation,d[t+1].reservation);
                		strcpy(d[t+1].reservation,temp1);
					}
				}
			    for(r=0;r<5;r++)
			    {
			    	pr[r].count=0;
				}
                fptr = fopen("colleges.txt","r");
                for(n=0;n<5;n++)
                {
                 fscanf(fptr," %s",&codec[n].college);
                }     
                fclose(fptr);
                {
                	printf("\n click 1 for students in particular college and 2 for no. of vacancies:");
				    scanf("%d",&choice);
				    switch(choice)
				    {
					   case 1:
				       {
				 	    system("CLS");
					    printf("Enter the college code to display:");
				        scanf("%d",&check);
				        printf(" \t \t %s \t \t \n",codec[check-1].college);
				        printf("Hall_ticket_no.\t Rank\t name\t Father's_name\t Gender\t     DOB\tregion\t Caste\t Reservation\t ");
				        for(r=0;r<10;r++)
				        {
					     f=d[r].hall_ticket;
				      	 for(t=(f-1901)*5;t<(f-1900)*5;)
					     {
					       clg=codes1[t];
					       if(pr[clg-1].count<2)
					       { 
					 	     pr[clg-1].count++;
				             strcpy(pr[clg-1].namea,d[r].name);
						     strcpy(pr[clg-1].fathers_namea,d[r].fathers_name);
				             strcpy(pr[clg-1].gendera,d[r].gender);
				             pr[clg-1].hall_ticketa=d[r].hall_ticket;
				             strcpy(pr[clg-1].date_of_birtha,d[r].date_of_birth);
				             pr[clg-1].ranka=d[r].rank;
				             strcpy(pr[clg-1].regiona,d[r].region);
				             strcpy(pr[clg-1].castea,d[r].caste);
				             strcpy(pr[clg-1].reservationa,d[r].reservation);
				             if(clg==check)
				             {
					           printf("\n     %d\t   %d\t %s\t   %s\t    %s\t %s\t %s\t %s\t %s\t  ",pr[check-1].hall_ticketa,pr[check-1].ranka,
					           pr[check-1].namea,pr[check-1].fathers_namea,pr[check-1].gendera,pr[check-1].date_of_birtha,pr[check-1].regiona,pr[check-1].castea,
					           pr[check-1].reservationa);
				             }
				             break;
					       }	
					        else if(clg==0)
					       {
					 	      break;
					       } 
					       else if(pr[clg-1].count>2||clg!=0)
					       {
					 	      t++;
					       }
				        }
			          }	
				if(pr[check-1].count==0)
				printf("\n \t \t \tno students have been alloted this college");	    
					
				  break;
			    }
				case 2:
					 system("CLS");
					 for(r=0;r<10;r++)
				        {
					     f=d[r].hall_ticket;
				      	 for(t=(f-1901)*5;t<(f-1900)*5;)
					     {
					       clg=codes1[t];
					       if(pr[clg-1].count<2)
					       { 
					 	     pr[clg-1].count++;
				             break;
					       }	
					        else if(clg==0)
					       {
					 	      break;
					       } 
					       else if(pr[clg-1].count>2||clg!=0)
					       {
					 	      t++;
					       }
				        }
			          }	
					printf("\nThis page gives the no. of seats in each college");
					printf("\nCOLEGE NAME    \t\t    No. of vacancies");
					for(m=0;m<5;m++)
					{
						printf(" \n %s \t \t \t %d",codec[m].college,2-(pr[m].count));
					}
					break;
				}
				
				printf("\n press 1 to go back and 2 to exit");
				scanf("%d",&m);
				switch(m)
				{
					case 1:
						{
							admin();
							break;
						}
					case 2:
						{
							break;
						}
				}
        }
 }
void main()
{ 
    int con,t=0;
    char password[20],rpw[20];
    FILE *fptr;
	printf(" click 1 for admin page and 2 for student page: ");
	scanf("%d",&con);
	switch(con)
	{
	case 1:
		{
			verifypw();
			break;
		}
	case 2:
		{
			student();
			break;
		}
		default:
		{
			 system("CLS");   
			printf("invalid choice\n");
			main();
		}
	}
}

