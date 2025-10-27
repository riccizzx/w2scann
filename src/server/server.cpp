#include "servercfg.hpp"

//	 get info from who has connected to the server
void s::server::con_infos(char* host, char* service)
{

	if (getnameinfo((sockaddr*)&client_addr, sizeof(client_addr),
		host, NI_MAXHOST,
		service, NI_MAXSERV, 0) == 0) {

		printf(host, "connected on port: ", service, "\n");

	}
	else {
		inet_ntop(AF_INET, &client_addr.sin_addr, host, NI_MAXHOST);
		int np = ntohs(client_addr.sin_port);
		
		printf(host, "connected on port: ", np);
	}

}

bool s::server::init() {

	if (WSAStartup(MAKEWORD(2, 2), &ws) == INVALID_SOCKET) {
	
		handle_error("err in winsock api\n", e.what());
		return FALSE;

	}

	return TRUE;

}

void s::server::setupsock(){

	char host[NI_MAXHOST];	// get host log
	char service[NI_MAXSERV];	// port from host


	server_sock = socket(AF_INET, SOCK_STREAM, 0);

	if (server_sock == INVALID_SOCKET) {

		handle_error("err in socket creation!\n");

	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	inet_pton(AF_INET, "0.0.0.0", &server_addr.sin_addr);

	if (bind(server_sock, (sockaddr*)&server_addr, sizeof(server_addr))== SOCKET_ERROR) {
		
		handle_error("failed to bind the ip/port");

	}

	if (listen(server_sock, SOMAXCONN) == SOCKET_ERROR) {

		handle_error("failed to listen for connections!");

	}
	else {

		printf("socket is listening state\n");

	}

	client_sock = accept(server_sock, NULL, NULL);
	if (client_sock == INVALID_SOCKET) {

		handle_error("can't connect to the server!\n");

	}

	else {
		
		memset(host, 0, NI_MAXHOST);
		memset(service, 0, NI_MAXSERV);

		try {

			con_infos(host, service);
			
		}
		catch (const std::exception& e) {
			handle_error("failed in get client infos", e.what()"\n");
		
		}
	
	}

	

}