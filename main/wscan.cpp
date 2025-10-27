// wscan.cpp: entry point for application
//

#include "wscan.h"

int main() {

	s::server sv;
	try {
		sv.init();
		sv.setupsock();
	}
	catch (const std::exception& e) {
		std::cerr << e.what();
	}
	return 0;

}