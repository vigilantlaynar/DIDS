#include "ip.h"

// function to validate the time
int ValidateTim(int hh , int mm , int ss)
{
    int tim=0;
    
    if(hh>18 || hh<10)   tim=1;
    if(mm>60)   tim=1;
    if(ss>60)   tim=1;
    
    return tim;
}
int ValidateDate(int dd , int mm , int yy)
{
    int valid=0;
    
    if(dd>31 || dd<0)  valid=1;
    if(mm>12)          valid=1;
    if(yy>2019)        valid=1;
    
    return valid;
}

char pass(char *username, char *password)
{

  	
	int i=0, j=0;
	char temp1[] = "admin";
	char temp2[]= "admin";
	while(i<5)
	{
		if(*(username+i)==*(temp1+i))
		{
			if(*(password+i)==*(temp2+i))
			{
				j++;
			}
			
		}
		i++;
	 }
	 if(j==5)
	 {
	 	printf("Welcome. Login Success!");
	 	return 'Y';
	  }
	  else{
	  	printf("Invalid credentials. Access denied");
	  	return 'N';
	  }
	   
}

// main function
int main()
{
	
		char username[15];
   	    char password[25];
		   char c[25];
		int i=0;
       char PassValid;
        char *IPbuffer; struct hostent *host_entry; 


    	printf("Enter Username: ");
    	scanf("%s",&username);    
		printf("Enter Password : ");
		scanf("%s",&password);
		PassValid= pass(username,password);
	if(PassValid=='N')
	{
		printf("\n Entered credentials are incorrect. \n");
		return 0;
	}

   // declare a char buffer
    char string[100]={0};
 
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
    
    // declare some local int variables
    int tim=0,hour=0,min=0,sec=0,date=0;
    fflush(stdin);
    
    printf("\nEnter the time in \"hh:mm:ss\" format : ");
    fgets(string,100,stdin);
    
    // fetch the hour,min and sec values from the
    // string and then store it in int variables
    // in order to validate them
    sscanf(string , "%d:%d:%d" , &hour,&min,&sec);
    
	//printf("\nHH : %d MM : %d SS : %d",hour,min,sec);
    // validate the time
    tim = ValidateTim(hour,min,sec);
    if(tim==1)
    {
        printf("\nData Entry access denied. Try Later.\n");
    }
    else
    {
	    
    	//date
      	int day, mon, year;
 
    	char *months[] = {
        	                "January", "February", "March", "April",
            	            "May", "June", "July", "August", 
                	        "September", "October", "November", "December",
                    	  };
    
   		printf("Enter date(MM/DD/YYY): ");
    	scanf("%d/%d/%d", &mon, &day, &year);
    	date = ValidateDate(day,mon,year);
    	if(date==1)
    	{
    		printf("\n Date is not valid.");
		}
    	else
    	{
    		FILE *fp;
			fp= fopen("minor_final.txt","a+");
			fprintf (fp,"Admin local time and date: %s", asctime (timeinfo) );
    		fputs("\nEnter the time in \"hh:mm:ss\" format : ",fp);
    		fputs(string,fp);
    		fprintf(fp,"Enter date(MM/DD/YYY): ");
    		fprintf(fp,"%d/%d/%d",mon,day,year);
    		fprintf(fp,"\nThe Time is : %d:%d:%d\n",hour,min,sec);
    		fprintf(fp,"%d",day);
    
        	printf("\nThe Time is : %d:%d:%d\n",hour,min,sec);
   		 	
			printf("%d", day);
			
    
   	 		// if day is 1 or 21 or 31, add the suffix "st"
    		if(day == 1 || day == 21 || day == 31)
    		{
        		printf("st ");
        		fprintf(fp,"st ");
    		}
    
    		// if day is 2 or 22, add the suffix "nd"
    		else if(day == 2 || day == 22)
    		{
        		printf("nd ");
        		fprintf(fp,"nd ");
    		}
    
    		// if day is 3 or 23, add the suffix "rd"
    		else if(day == 3 || day == 23)
    		{
       			printf("rd ");
       			fprintf(fp,"rd ");
    		}
    
    		// for everything else add the suffix "th"
    		else
    		{
        		printf("th ");
        		fprintf(fp,"th ");
    		}	 
	
	 		//input members
    		char name[50];
			int id; 
	  
			printf("%s, %d", months[mon - 1], year);
			fprintf(fp,"%s, %d", months[mon - 1], year);    
			
	    	puts("\nEnter your data");
			fputs("\nEnter id n name:",fp);
			scanf("%d",&id);
			gets(name);
			fprintf(fp,"\n%d %s",id,name);

			scanf("%d",&id);
			gets(name);
			fprintf(fp,"\n%d %s",id,name);

			scanf("%d",&id);
			gets(name);
			fprintf(fp,"\n%d %s",id,name);

			scanf("%d",&id);
			gets(name);
			fprintf(fp,"\n%d %s",id,name);
			fputs("\n\n",fp);
			fclose(fp);
		}
	}
	// Converts space-delimited IPv4 addresses 
// to dotted-decimal format 
void checkIPbuffer(char *IPbuffer) 
    { 
    if (NULL == IPbuffer) 
    { 
        perror("inet_ntoa"); 
        exit(1); 
    } }
    IPbuffer = inet_ntoa(*((struct in_addr*) 
                           host_entry->h_addr_list[0])); 
	sys();
	printf("\n Your IP address is stored");
    printf("Host IP: %s", IPbuffer);
	FILE *ft;
	char buffer[100];
	ft=fopen("minor_final.txt","r");
	fscanf(ft,"%[^\n]", buffer);
	printf("\n %s",buffer);
    return 0;
}




