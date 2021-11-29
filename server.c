

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <sys/select.h>

#define Socket_place "/home/elmehdi/sockets/serversock"
#define Buffer_size 128

//server test select



int main(int argc, char *argv[])
{
    unlink(Socket_place);

	struct sockaddr_un mysocketadr; //this is equivalent to (IP_addresse,port) in Internet socket 
    fd_set file_desc_set;  //struct of set

    
    
    //in his example name 
    int on=1;
    int highest_fd;
    
    int socketfiledesc;
    int client_socket_fd,client_socket_fd2;
    int bindreturn,listenreturn;
    int result=0,result2=0;
    int returnread,returnwrite;//used in reading,writing 
    int data,data2; 
    char buffer [Buffer_size];
    char buffer2 [Buffer_size];
    int client1_leave,client2_leave;

    
    
     //create socket if succeed it return the file descriptor
    socketfiledesc=socket(AF_UNIX,SOCK_STREAM,0);
    
    
    // AF_unix means purpose is unix processes comunication
    // sock_stream mean tcp connection not udp
    // 0 means IP but in our example the type and protocol are unrelevant because processes will run inside the same host
   
   if (socketfiledesc==-1){
       perror("SOCKET ERROR \n");
       exit(EXIT_FAILURE);
   } 
   
   printf("SERVER SOCKET CREATED \n" );
   printf("Socket file descriptor is %d , socketprocess id = %d \n",socketfiledesc,getpid());
   
   memset(&mysocketadr,0,sizeof( struct sockaddr_un));
    //and we initialise this structure with o byte
    
    
    mysocketadr.sun_family=AF_UNIX;
    strncpy(mysocketadr.sun_path,Socket_place,sizeof(Socket_place)-1);
    
    bindreturn=bind(socketfiledesc,(const struct sockaddr  *) &mysocketadr,sizeof(struct sockaddr_un));
    // mysocketadr  has socket familly and socket  place and we bind thos infos to our socket
    // in case of sockaddr_in we use ip and port
    if (bindreturn==-1){
        perror("BIND FAILLURE \n");
        exit(EXIT_FAILURE);
    }
    printf("BINDING SUCCEED  \n");
    
 
    
    
    
    //// first while
     
    
    while(on){
        
        
      listenreturn=listen(socketfiledesc,5);
    // 30 queue size that means how many client can connect tpo this socket
    //on success return 0
    if (listenreturn==-1){
        perror("LISTENING FAILED \n ");
        exit(EXIT_FAILURE);
    }
        
        printf("Waiting for First  incoming connection......... \n");
        client_socket_fd=accept(socketfiledesc,NULL,NULL);
        printf("Waiting for second  incoming Connection ....... \n");
        client_socket_fd2=accept(socketfiledesc,NULL,NULL);
        result=0;
       client1_leave=0;
       client2_leave=0;
       memset(buffer,0,Buffer_size);


        
        // bloking method..
        // if success these system returns file descriptor for the accepted socket
        
        if (client_socket_fd==-1 || client_socket_fd2==-1){
             perror("Listening failed \n");
             exit(EXIT_FAILURE);       
        }
        
        printf("Conection accepted  from client with fie_descriptor = %d  \n",client_socket_fd);
        printf("Conection accepted  from client with fie_descriptor = %d  \n",client_socket_fd2);
        
        highest_fd=(client_socket_fd>client_socket_fd2 ? client_socket_fd:client_socket_fd2)+1;
        
    
    //FD_SET(socketfiledesc,&file_desc_set);


    
       
       
        
        while(on){
            FD_ZERO(&file_desc_set);
            FD_SET(client_socket_fd,&file_desc_set);
             FD_SET(client_socket_fd2,&file_desc_set);
             memset(buffer,0,Buffer_size); //initialise buffer to 0 byte 


            int res= select(highest_fd,&file_desc_set,NULL,NULL,NULL);
            
            if (res==-1){
                
              perror("ERORR in Select \n");
              exit(EXIT_FAILURE);
                
                
            }else  if (res==0){
            
                printf("Wait data from client ............\n"); // if timeout expired
                
            }
            else{
                
                if(FD_ISSET(client_socket_fd,&file_desc_set)){                       //if (data2==0) break;
                
                printf("Client 1 sent Data  ... \n");


                       returnread= read(client_socket_fd,buffer,Buffer_size); 
                       // read nbytes from file descriptor client_socket and put in buffer 
                     //read is blocking call
                        // read  128 byte from file descriptor and stores it in buffer
                       if (returnread==-1){
                             perror("Read problem");
                             exit(EXIT_FAILURE);
                                                            }
                        memcpy(&data,buffer,sizeof(int)); // copy 4 byte from buffer into data
                        
                        if (data==0){
                            client1_leave=1;
                            data=1;
                            
                            printf("Client 1 want to leave  ... \n");
                            memset(buffer,0,Buffer_size);
                           
                        }else{
                            
                                                    result=data+result;
                                                    printf("result is %d \n",result);

                        }
                        
                        
                        
                }
                
                if(FD_ISSET(client_socket_fd2,&file_desc_set)){
                    printf("Client 2 sent Data  ... \n");
                       returnread= read(client_socket_fd2,buffer2,Buffer_size); 
                       // read nbytes from file descriptor client_socket and put in buffer 
                     //read is blocking call
                        // read  128 byte from file descriptor and stores it in buffer
                       if (returnread==-1){
                             perror("Read problem");
                             exit(EXIT_FAILURE);
                                                            }
                                                            
                        memcpy(&data2,buffer2,sizeof(int)); // copy 4 byte from buffer into data
                            if (data2==0){
                                 client2_leave=1;
                                 data2=1;
                            printf("Client 2 want to leave  ... \n");
                            memset(buffer,0,Buffer_size);
                               
                        }else{
                                                   
                       
                           result=data2*result;
                                                                            


                            
                        }
                        
                        //if (data==0) break;
                        
                }
                if (client1_leave && client2_leave){
                
                sprintf(buffer,"result=%d ",result);
                returnwrite=write(client_socket_fd,buffer,Buffer_size);
                returnwrite=write(client_socket_fd2,buffer,Buffer_size);


                 if(returnwrite==-1){
                                        perror("write Problem \n");
                                        exit(EXIT_FAILURE);
            
                                               }

                        if(returnwrite==-1){
                                        perror("write Problem \n");
                                        exit(EXIT_FAILURE);
                                                                   }
                                        

                    break;
                }
            
                
            } //else select()
             
            
     
            
            
            
            
            
           
        
            
        
                     
                
        
        //memset(buffer,0,Buffer_size);

        //sprintf(buffer,"result=%d ",result); // giver the result = to our char buffer 
        //sprintf(buffer2,"result=%d ",result2); // giver the result = to our char buffer 

        
        
        
       // printf("Sending  Result  To clients .....\n ");
        
        
            
        }//1st while
        
        
        
        close(client_socket_fd); //close client socket
        close(client_socket_fd2);//client socket 2
        
        
        
    
        
    }//2nd while
     
     
     
    close(socketfiledesc);
    printf("Server Socket Exiting \n ......................");            
    unlink(Socket_place);
    exit(EXIT_SUCCESS);
}
    
    
    
    
    
    
    
    
    
    
    
    