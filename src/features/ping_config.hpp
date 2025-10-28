
// ping using raw socket


#ifdef		_WIN32

#include <WS2tcpip.h>
#include <WinSock2.h>

#include <stdio.h>

#include <signal.h>

#include <sys/types.h>

#include <setjmp.h>

#include <errno.h>



#define		PACKET_SIZE     4096

#define		MAX_WAIT_TIME   5
	
#define		MAX_NO_PACKETS  3

namespace features {

	class icmp {

		void stats(int signo);

		unsigned short cal_chksum(unsigned short* addr, int len);

		int pack(int pack_no);

		void send_package(void);

		void recv_packet(void);

		int unpack(char* buf, int len);

		void tv_sub(struct timeval* out, struct timeval* in);

	};

}


#elif		defined(LINUX)



#endif		// !_WIN32
