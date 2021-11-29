
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

//client sleect

#define cl_socket_place "/home/elmehdi/sockets/serversock"
#define  Buffer_size   128

int main(int argc, char  *argv[])
{
	struct sockaddr_un addr; // define the struct that we will use for the socket which includes the path and name
    int i ; // data to be sended
    int socket_fd;
    int ret;
    char buffer[Buffer_size];
    
    // cretae a socket which will be connected to server socket 
    socket_fd=socket(AF_UNIX,SOCK_STREAM,0);
   
     printf("Server with socket fd %d , and Client with process number %d created... \n",socket_fd,getpid());    
    
    if (socket_fd==-1){
        perror("client socket faillure \n");
        exit(EXIT_SUCCESS);
        
    }
    
    memset(&addr,0,sizeof(struct sockaddr));
     
     
     // addr=adresse of the port and path of the server socket and same time client socket
     
    addr.sun_family=AF_UNIX;
    memcpy(addr.sun_path,cl_socket_place,sizeof(cl_socket_place)-1); // take n bytes from cl_socket_place and store in addr.sunpath
     
     // connect to server socket
     ret=connect(socket_fd,(const struct sockaddr *) &addr,sizeof(struct sockaddr_un));
     //no blocking 
     
     if (ret==-1){
         
        perror("There is No server Connected  \n ");
        exit(EXIT_FAILURE);
        
        
     }
     
     do {
         printf("Enter A value to send \n");
         scanf("%d",&i);
         
        ret=write(socket_fd,&i,sizeof(int));    
     
         if (ret==-1){
             perror("Send  data failed \n");
             break;
         }
         
         printf("data sent %d , bytes sent %d \n",i,ret);
         
        
         
         
         
     }while(i!=0);
         
    memset(buffer,0,Buffer_size); //buffer intitliase with 0 bytes
    
    ret= read(socket_fd,buffer,Buffer_size);
      
    if (ret==-1){
        perror("Read Faillure \n");
        exit(EXIT_FAILURE);
        
        
    }


  printf(" Complete %s \n",buffer);

  
  
  close(socket_fd);
  exit(EXIT_SUCCESS);
  
  
  
    
     
     
    
    
    
    
    
}
