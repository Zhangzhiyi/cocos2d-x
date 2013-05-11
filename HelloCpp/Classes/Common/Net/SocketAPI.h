#ifndef __SOCKET_API_H__
#define __SOCKET_API_H__

#include "platform/CCPlatformConfig.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include <WinSock.h>
#else
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#define VOID			void			//标准空
typedef unsigned char	UCHAR;			//标准无符号CHAR
typedef char			CHAR;			//标准CHAR
typedef wchar_t         WCHAR;			//标准WCHAR
typedef unsigned int	uint;			//标准无符号INT
typedef int				INT;			//标准INT
typedef unsigned short	USHORT;			//标准无符号short
typedef short			SHORT;			//标准short
typedef unsigned long	ULONG;			//标准无符号LONG(不推荐使用)
typedef long			LONG;			//标准LONG(不推荐使用)
typedef float			FLOAT;			//标准float
typedef UCHAR			uchar;
typedef USHORT			ushort;
//typedef UINT			UINT;
typedef ULONG			ulong;
typedef ULONG			IP_t;
typedef USHORT			PacketID_t;
typedef INT				BOOL;
typedef UCHAR			BYTE;
#define     TRUE        1 
#define     FALSE       0 
#endif
#define _ESIZE 256

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
typedef		int		SOCKET;
#define     INVALID_SOCKET   -1
#define		SOCKET_ERROR	 -1
#endif

static const int SOCKET_ERROR_WOULDBLOCK = -100;

typedef struct sockaddr SOCKADDR;
typedef struct sockaddr_in SOCKADDR_IN;
static const unsigned int  szSOCKADDR_IN = sizeof(SOCKADDR_IN);
namespace SocketAPI 
{
	SOCKET socket_ex (int domain, int type, int protocol) ;

	BOOL bind_ex (SOCKET s, const struct sockaddr* name, unsigned int namelen) ;

	BOOL connect_ex (SOCKET s, const struct sockaddr* name, unsigned int namelen) ;

	BOOL listen_ex (SOCKET s, unsigned int backlog) ;

	SOCKET accept_ex (SOCKET s, struct sockaddr* addr, unsigned int* addrlen) ;

	BOOL getsockopt_ex (SOCKET s, int level, int optname, void* optval, unsigned int* optlen) ;

	unsigned int getsockopt_ex2 (SOCKET s, int level, int optname, void* optval, unsigned int* optlen) ;

	BOOL setsockopt_ex (SOCKET s, int level, int optname, const void* optval, unsigned int optlen) ;

	unsigned int send_ex (SOCKET s, const void* buf, unsigned int len, unsigned int flags) ;

	unsigned int sendto_ex (SOCKET s, const void* buf, int len, unsigned int flags, const struct sockaddr* to, int tolen) ;

	unsigned int recv_ex (SOCKET s, void* buf, unsigned int len, unsigned int flags) ;

	unsigned int recvfrom_ex (SOCKET s, void* buf, int len, unsigned int flags, struct sockaddr* from, unsigned int* fromlen) ;
	 
	BOOL closesocket_ex (SOCKET s) ;

	BOOL ioctlsocket_ex (SOCKET s, LONG cmd, ULONG* argp) ;

	BOOL getsocketnonblocking_ex (SOCKET s) ;

	BOOL setsocketnonblocking_ex (SOCKET s, BOOL on) ;

	unsigned int availablesocket_ex (SOCKET s) ;

	BOOL shutdown_ex (SOCKET s, unsigned int how) ;

	int select_ex (int maxfdp1, fd_set* readset, fd_set* writeset, fd_set* exceptset, struct timeval* timeout) ;
}; 



#endif
