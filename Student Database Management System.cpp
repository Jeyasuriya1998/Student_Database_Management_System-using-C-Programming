#include<stdio.h>   									  //header file for input and output console
#include<stdlib.h>										  //header file for system clear and pause
#include<string.h>  									  //header file for string manupilation.

struct student										    //structer for the student database.
{
	int roll_no;										//Roll number of the student in integer
	
	char name[20];   									//name of the student in string.

	int mark;        									//mark of the student in integer.

	char father_name[20];   							//name of the student's father name in string.

	char mother_name[20];   							//name of the student's mother name in string.

	char gender[10];       								//specifiction of the students MALE or FEMALE in string.

	long long int contact_details;  					//contact number of the student in long integer.
}s;

int add_details();   									 //function prototype for add .

int search_student();  									//function prototype for search.

int modify_details();  									//function prototype for modify.

int delete_record();   									//function prototype for delete.

int view_file();										//fuction prototype for view all.

int main()												//main function.
{
	printf("\t\tLogin Screen\t\t\n\n");

    long long  password;

    printf("Enter your password : ");					//Enter the password to login

    scanf("%lld",&password);

    if(password==8189880266)							//Check the entered password.
    {
    	system("cls");

	    int number;

    	struct student s;

    	do {
    		system("cls");
    		
    		x:printf("\t\t\tWELCOME TO STUDENT DATABASE    \n\n");

		printf("\t\t****************************************\n\n");
		
		printf("\t\t1.Add the student details:\n\n\t\t2.Search the student detils\n\n\t\t3.Modify the student details\n\n\t\t4.Delete the student record\n\n\t\t5.View details\n\n\t\t0.Exit\n\n");
        
        printf("\t\t*****************************************\n\n");
    	printf("\t\tEnter the number you want : ");

    	scanf("%d",&number);     							//read your choice.
    	system("cls");

	    switch(number)								
    	{
	    	case 1:
     			{
	    			add_details();    						//function call for add the details.
		    		break;
	    		}
     		case 2:
	    		{
		    		search_student();   					//function call for search the details.
	    			break;
		    	}
    		case 3:
	    		{
		    		modify_details();    					//function call for modify the details.
			    	break;
		    	}
     		case 4:
     			{
    				delete_record();  						//function call for detete details
	    			break;
		    	}
		    case 5:
		    	{
		    		view_file();							//function call for veiw all the student details.
		    		break;
				}
			case 0:
				{
					exit(0); 								//To exit the database enter 0.
					system("pause");
				}
		    default:
     		{
	    		printf("\t\tYour choice is invalied\n");     //your choice is invalied.
	    		system("pause");
	    		system("cls");
	    	}
	    
	    }}while(number==6);
	goto x;       											//goto statement for go to the specifiction mark.
	}
	printf("\t\tYour password is wrong");
	system("pause");    
	return 0;												//end of the program.
}

int add_details()   										//add function declaration.
{
	printf("\n\nADD THE STUDENT DEATLS\n\n");
    
	printf("****************************** *\n");
	 
	FILE *file_add;   										//pointer file.

	file_add=fopen("data.txt","ab+");  				//syntax : filename=fopen("local disk file","mode");

	if(file_add==NULL)      								//if no file is detected in the local disk returns null.
	{
		printf("File doesnot exist");
	}
	else
	{	
	    printf("\n\nFile created successfully\n");	   		//add the details of the student.

	    printf("\nStudent number details\n");

   		printf("\nEnter the roll number : ");
   		
   		scanf("%d",&s.roll_no);
   		
		printf("\nEnter the student name : ");
   		
   		scanf("%s",s.name);                          		//name.

   		printf("\nEnter the total mark of the student : ");
   
		scanf("%d",&s.mark);                         		//mark.

		printf("\nEnter the student FATHER name : ");
		
		scanf("%s",s.father_name);                    		//student's father name.

    	printf("\nEnter the student MOTHER name : ");
		
		scanf("%s",s.mother_name);                   		//student's mother name

    	printf("\nEnter the gender of the student[Male/Female] : ");
		
		scanf("%s",s.gender);                         		//student's gender.

    	printf("\ncontact number : ");
		
		scanf("%lld",&s.contact_details);             		//student's contact details.
	
	    fwrite(&s,sizeof(s),1,file_add);              		//syntax : fwrite(address of struct variable,size of struct,1,declared filename);
    }
    fclose(file_add);                            		// close the file using fclose(filename);

    printf("\nFILE IS CREATED SUCCESSFULLY\n");    		//file is added
    
 	printf("\n\n****************************************************\n\n");
 	
	system("pause");
 	
	system("cls");
}

int search_student()                      					//search function declaration.
{
	printf("\n\nSEARCHING THE STUDENT\n\n");

	int search;                        					//name of the student.

	printf("Enter the Roll number : ");

	fflush(stdin);

	scanf("%d",&search);                     					//get the name of the student.

	int found=0;

	FILE *file_search;                  					//declare FILE.

	file_search = fopen("data.txt","rb+");    		//syntax : filename=fopen("local disk file","mode"); rb = read in binary mode.

	if(file_search==NULL)
	{
		printf("File doesnot exist\n");              		//if no file is dected in the local file print FILE NOT EXISITS.
	}
	else
	{
		while(fread(&s,sizeof(s),1,file_search)==1)    		//read the file.
		{                                             		//syntax : fread(address of struct variable,size of struct,1,declared filename);
			if(s.roll_no == search)                		//compaare the string s_id and s.name.
			{
				found=1;                              		//if the condition is true found varible assign 1.
				break;                               		//then break.
			}
		}

	    if(found==1)                                  		//display automatically if the string comparetion is true.
	    {
	    	printf("\nRoll number of the student : %d\n",s.roll_no);
	      	
       	    printf("\nName of the student : %s\n",s.name);

	   	    printf("\nMark of the student : %d\n",s.mark);

    	    printf("\nFather name of the student : %s\n",s.father_name);

    	    printf("\nmother name of the student : %s\n",s.mother_name);

	   	    printf("\nGender of the student[Male/female] : %s\n",s.gender);

	   	    printf("\nContact details of the student : %lld\n\n",s.contact_details);
	    }
	    else
	    {
		    printf("Sorry,no record is found\n");
	    }
		fclose(file_search);
    }
    printf("****************************************************\n\n");
    
	system("pause");
    
	system("cls");
}

int modify_details()       									 //mofife function is declared
{
	printf("\n\nMODE TO CHANGE THE DATABASE\n\n");
	
	FILE *file_modify;             							 //declare the file name.

	file_modify=fopen("data.txt","rb+");    		//syntax : filename=fopen("local disk file","mode"); rb = read in binary mode.
	
	int modify,choice;          								//name of the student.

	printf("\nEnter the roll number of the student : ");

	scanf("%d",&modify);         								//enter the name of the student.
	
	if(file_modify!=NULL)
    {
	    while(fread(&s,sizeof(s),1,file_modify)==1)    		//syntax : fread(address of struct variable,size of struct,1,declared filename);
	    {	
		    if(s.roll_no == modify)          			//compare the to strings of student name.
		    {	
		 	   printf("\n1.Change the name of the student\n\n2.Change the mark of the student\n\n3.Change thefather name of the student\n\n4.Change the mother name of the student\n\n5.Change the gender of the student\n\n6.Change the contact details of the student\n\n7.Change the all details of the student\n\n");
				
				printf("\nEnter your choice : ");
				
				scanf("%d",&choice);
				
				system("cls");
				
				switch(choice)
				{
					case 1:
						{
							printf("Current name of the student : %s\n\n",s.name);
							
							printf("Name of the student : ");         //if the conditon is true then you can modify the details of the student.
							
							scanf("%s",s.name);     						//name.
							
							break;
						}
					case 2:
			        	{
			        		printf("\nCurrent mark of the student : %d\n",s.mark);
			        		
							printf("\nMark of the student : ");
							
							scanf("%d",&s.mark);    						 //mark
							
							break;
						}
					case 3:
        	    		{
							printf("\nCurrent father name of the student : %s\n",s.father_name);
							
							printf("\nFather name of the student : ");
							
							scanf("%s",s.father_name);                    //father name.
							
							break;
						}
					case 4:
         	    		{
							printf("\nCurrent mother name of the student : %s\n",s.mother_name);
							
							printf("\nmother name of the student : ");
							
							scanf("%s",s.mother_name);                    //mother name.
							
							break;
						}
					case 5:
						{
							printf("\nCurrent gender of the student : %s\n",s.gender);
							
							printf("\nGender of the student[Male/female] : ");
							
							scanf("%s",s.gender);                         //male/female.
							
							break;
						}
					case 6:
						{
							printf("\nCurrent contact detail of the student : %lld\n",s.contact_details);
							
							printf("\nContact details of the student : ");
							
							scanf("%lld",&s.contact_details);             //contact details of the student.
							
							break;
						}
					case 7:
						{	
							printf("\nCurrent name of the student : %s\n",s.name);
							
							printf("\n\nName of the student : ");         //if the conditon is true then you can modify the details of the student.
							
							scanf("%s",s.name);     						//name.
							
							printf("\nCurrent mark of the student : %d\n",s.mark);
							
							printf("\nMark of the student : ");
							
							scanf("%d",&s.mark);    						 //mark
							
							printf("\nCurrent father name of the student : %s\n",s.father_name);
							
							printf("\nFather name of the student : ");
							
							scanf("%s",s.father_name);                    //father name.
							
							printf("\nCurrent Mother name of the student : %s\n",s.mother_name);
							
							printf("\nmother name of the student : ");
							
							scanf("%s",s.mother_name);                    //mother name.
							
							printf("\nCurrent gender of the student : %s\n",s.gender);
							
							printf("\nGender of the student[Male/female] : ");
							
							scanf("%s",s.gender);                         //male/female.
							
							printf("\nCurrent contact number of the student : %lld\n\n",s.contact_details);
							
							printf("\nContact details of the student : ");
							
							scanf("%lld",&s.contact_details);             //contact details of the student.
							
							break;
						}
					default:
						{
							printf("Your choice is in valid");
						}
				}
    	       fseek(file_modify,-sizeof(s),SEEK_CUR);     	/*syntax : fseek(FILE *pointer, long int offset, int position)*/

    	       fwrite(&s,sizeof(s),1,file_modify);   		////syntax : fwrite(address of struct variable,size of struct,1,declared filename);
    	    
    	   	   printf("\nFile was modified successfully\n\n");
    	   	   
    	   	   break;
            }
		}
	}
	else
	{
	   	printf("\n\nResult doesnot exists\n");           	// if no file is detected then print no file.
	}
	fclose(file_modify);                              		//colse the file.

    printf("--------------------------------------------\n\n");
    
	system("pause");
    
	system("cls");
}

int delete_record()          								  //delete function is declared.
{
	printf("Your Choice to delete the particular student details\n\n");
	
	FILE *file_delete,*temp;          						  //create file (i.e) one file for read and other file for write.
   	
	file_delete=fopen("data.txt","rb+");  			//open the file in read mode.

	temp=fopen("temp.txt","wb+");        					//declare the temparvary file to write.
    
	int del;       							//name of the student.
    
	printf("Enter the Roll number : ");
	
	scanf("%d",&del);        						//student name to delete.

	if(file_delete== 0)
	{
		printf("File Doesnot exists\n");
	}
	else
	{
	    while(fread(&s,sizeof(s),1,file_delete))
	    {
	    	if(s.roll_no != del)
	    	{
				fwrite(&s,sizeof(s),1,temp);
		    }
		}      
	}
	fclose(file_delete);                					//close the file.

	fclose(temp);        						//close the file.

	file_delete=fopen("data.txt","w+b");  			//open the file in read mode.

	temp=fopen("temp.txt","r+b");        					//declare the temparvary file to write.
    
	while(fread(&s,sizeof(s),1,temp))
	{
		fwrite(&s,sizeof(s),1,file_delete);
		
		printf("\n\nFile was deleted successfully\n");   		//file was successfully deleted.
	}
	fclose(file_delete);
	
	fclose(temp);    

    system("pause");
    
    system("cls");
}

int view_file()												//view function declaration
{
	printf("\n\t\t\tWelcome\n\n");
	
	FILE *file_view;										//File declaration for file_view.
	
	file_view = fopen("data.txt","rb+");			//read the file
	
	if(file_view==NULL)										//Check the file 
	{
		printf("File doesnot exists\n");
	}	
	else
	{
	    rewind(file_view);
	
	    printf("Rollno.		st.name		mark	f.name	m.name	gender	cont	\n");
	
	    while(fread(&s,sizeof(s),1,file_view)==1)        					//syntax:fread(Address of struct,sizeof struct,1,filename)
	    {
		    printf("\n%d	%s	%d	%s	%s	%s	%lld\n",s.roll_no,s.name,s.mark,s.father_name,s.mother_name,s.gender,s.contact_details);		//print the file
		
		    printf("------------------------------------------------------\n");
	    }
    }
	fclose(file_view);										//Close the file.
	
	system("pause");										//Pause the console screen.
	
	system("cls");											//Clear the console screen.
}

