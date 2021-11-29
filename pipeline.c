#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>



typedef char* string;

typedef struct human{
    int age;
    char  name[20];
}mesage;
bool work=true;
 pid_t slaveid;

void startloop(int start,pid_t prcssnum ,pid_t prcssnum2);

int main(int argc, char *argv [])


{
    int mesg_pipe[2];
    char mybuffer[128];
    if(pipe(mesg_pipe)==-1){ //setup the pipe 
        printf("Problem Occured  pipe didnt setup \n");
        return 1 ;
    }
    pid_t id1 = fork(); //start two processes 
    
    if (id1==0){
        
        
        //sleep(1);
        //receivemesage(&slaveid,&mesg_pipe[0]);
        //printf("slaveid is %d \n",slaveid);
        mesage exit1;
        strcpy(exit1.name,"exit");
        exit1.age=0;
        
        
        printf("   Child process pid  =%d \n",getpid());

         while (work){
             
            mesage mesage1;
            
            printf("please enter ur name :  \n");
            scanf("%s",mesage1.name);      

            if (strcmp(mesage1.name,exit1.name)==0){ // mesage == "exit"
                int bytehr=write(mesg_pipe[1],&exit1,sizeof(exit1));
                printf("byte writed %d \n",bytehr);

                
                break;
                
            }

            fflush(NULL);
            printf("please enter ur age :  \n");
            scanf("%d",&mesage1.age);
            
           int bytenum= write(mesg_pipe[1],&mesage1,sizeof(mesage1));
           printf("byte writed %d \n",bytenum);
           sleep(1);
         }
           
          
            
            close(mesg_pipe[1]);
            close(mesg_pipe [0]);

            printf("PROCESS CHILD EXITING ........\n");

            
            
    
    }else{
        printf("   Parent process pid= %d   \n",getpid());
        mesage msg2;
        
        while(work==true){
            
        memset(&msg2,0,sizeof(mesage)); //initialise structur with 0 bytes
            
        
        
        read(mesg_pipe[0],&msg2,sizeof(msg2)); //blocking method reads from pipe [0]
        if( strcmp(msg2.name,"exit")==0){
            wait(NULL);
            break;
        }
        
        printf("Parent Process got  Message >> name is %s , age %d \n",msg2.name,msg2.age);
        
        
        } // while loop
        
        close(mesg_pipe[0]);
        close(mesg_pipe[1]);
        printf("Parent Process EXITING  ........ \n");

        
        
        
    }
    
 
   
    
    
    
    
    
   
    
    
    
    
    
    
    
    
    
    
    
    
	return 0;
}

   
    
    
    
    
    
   
     // startloop(start,id1,id2);
    
    
    
    
    
    
    
    
    
    
    
    



    

    
    
    
    


    
 




















   
