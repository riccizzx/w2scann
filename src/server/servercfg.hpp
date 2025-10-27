//  

#ifdef      _WIN32

#ifndef		SOCKET_SERVER_HPP
#define		SOCKET_SERVER_HPP

#include <stdio.h>
#include <WS2tcpip.h>
#include <WinSock2.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")



#ifndef     SERVER_ERROR_HANDLER

#define handle_error(msg) \
        do { perror(msg); exit(EXIT_FAILURE); } while(0)

#endif      // !SERVER_ERROR_HANDLER


const int PORT = 9909;


namespace s {

    class server {

    public:

        bool init();
        
        void setupsock();

        void con_infos(char* host, char* service);

        void multi_cons();

    private:

        WSADATA ws;
        SOCKET server_sock, client_sock;
        sockaddr_in server_addr, client_addr;
        int serverlen = sizeof(server_addr);
        char* buffer[1024];

    };

}

#endif  	// !SOCKET_SERVER_HPP


#elif defined(LINUX)



#endif      // 