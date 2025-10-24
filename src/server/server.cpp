#include "servercfg.hpp"

bool s::server::init() {

	if (WSAStartup(MAKEWORD(2, 2), &ws) == INVALID_SOCKET) {
	
		handle_error("err in winsock api\n", e.what());
		return FALSE;

	}

	return TRUE;

}

void s::server::setupsock(){

	

}