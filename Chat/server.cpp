#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

#define AF_INET 2
#define SOCK_STREAM 1
#define SOMAXCONN 128
#define NI_MAXHOST 1025
#define NI_MAXSERV 32
#define MAX_BUFFER 4096

using namespace std;

int main() {
    
    //Create a socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1) {
        cerr << "Cannot create a socket!" << endl;
        return -1;
    }
   
   //Bind the socket to IP/port
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);
    
    if(bind(listening, (sockaddr*)&hint, sizeof(hint)) == -1) {
        cerr << "Cannot bind to IP/port" << endl;
        return -2;
    }
    
    //Mark the socket for listening in
    if(listen(listening, SOMAXCONN) == -1) {
        cerr << "Cannot listen!" << endl;
        return -3;
    }
    
    //Accept a call
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
    char host[NI_MAXHOST];
    char service[NI_MAXSERV];

    int clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

    if(clientSocket == -1) {
        cerr << "Problem with client connecting" << endl;
        return -4;
    }
   
    //Close the listening socket
    close(listening);
    memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);

    int result = getnameinfo((sockaddr*)&client,
                            sizeof(client),
                            host,
                            NI_MAXHOST,
                            service,
                            NI_MAXSERV,
                            0);

    if(result) {
        cout << host << " connected on " << service << endl;
    }
    else{
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on " << ntohs(client.sin_port) << endl;
    }

    //While receiving - display message
    char buffer[MAX_BUFFER];
    
    while(true) {
        //Clear the buffer
        memset(buffer, 0, MAX_BUFFER);
        //Wait for a message
        int bytesReceived = recv(clientSocket, buffer, MAX_BUFFER, 0);

        if (bytesReceived == -1) {
            cerr << "There was a connection issue" << endl;
            break;
        }
        if (bytesReceived == 0) {
            cerr << "The client disconnected" << endl;
            break;
        }
        //Display message
        cout << "Received: " << string(buffer, 0, bytesReceived) << endl;       
        //Resend message
        send(clientSocket, buffer, bytesReceived + 1, 0);
    }

    //Close socket
    close(clientSocket);

    return 0;
}