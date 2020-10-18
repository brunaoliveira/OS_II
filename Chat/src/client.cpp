#include "../include/client.h"
#include "../include/constants.h"


using namespace std;

int main() {
    //Create a socket
    int sockett = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockett == -1) {
        return 1;
    }

    //Create a hint structure for the server we're connecting with
    string ipAddress = "127.0.0.1";

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(PORT);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    //Connect to the server on the socket
    int connectResult = connect(sockett, (sockaddr*)&hint, sizeof(hint));
    if (connectResult == -1) {
        return 1;
    }

    //Comunication with server
    char buffer[MAX_BUFFER];
    string input;

    do {
        //Enter lines of text
        cout << ">> ";
        getline(cin, input);

        //Send to server
        int sendResult = send(sockett, input.c_str(), input.size() + 1, 0);
        if (sendResult == -1)
        {
            cout << "Could not send to server!" << endl;
            continue;
        }

        //Wait for response
        memset(buffer, 0, MAX_BUFFER);
        int bytesReceived = recv(sockett, buffer, MAX_BUFFER, 0);
        if (bytesReceived == -1) {
            cout << "There was an error getting response from server" << endl;
        }
        else {
            //Display response
            cout << "SERVER>" << string(buffer, bytesReceived) << "</SERVER>" << endl;
        }
    } while(true);

    //Close the socket
    close(sockett);

    return 0;
}
