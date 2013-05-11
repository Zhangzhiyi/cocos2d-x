#include "SocketAPI.h"

#if _WINDOWS
#else
#include <sys/types.h>			// for accept()
#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>			// for inet_xxx()
#include <netinet/in.h>
#include <errno.h>				// for errno
#endif

char Error[_ESIZE] ;
SOCKET SocketAPI::socket_ex ( int domain , int type , int protocol ) 
{

    SOCKET s = ::socket(domain,type,protocol);

    if ( s == INVALID_SOCKET ) 
    {
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
        switch ( errno ) 
        {
            case EPROTONOSUPPORT :
            case EMFILE : 
            case ENFILE : 
            case EACCES : 
            case ENOBUFS : 
            default : 
                {
                    break;
                }
        }//end of switch
#else
		int iErr = WSAGetLastError() ;
		switch ( iErr ) 
		{
		case WSANOTINITIALISED : 
			strncpy( Error, "WSANOTINITIALISED", _ESIZE ) ;
			break ;
		case WSAENETDOWN : 
			strncpy( Error, "WSAENETDOWN", _ESIZE ) ;
			break ;
		case WSAEAFNOSUPPORT : 
			strncpy( Error, "WSAEAFNOSUPPORT", _ESIZE ) ;
			break ;
		case WSAEINPROGRESS : 
			strncpy( Error, "WSAEINPROGRESS", _ESIZE ) ;
			break ;
		case WSAEMFILE : 
			strncpy( Error, "WSAEMFILE", _ESIZE ) ;
			break ;
		case WSAENOBUFS : 
			strncpy( Error, "WSAENOBUFS", _ESIZE ) ;
			break ;
		case WSAEPROTONOSUPPORT : 
			strncpy( Error, "WSAEPROTONOSUPPORT", _ESIZE ) ;
			break ;
		case WSAEPROTOTYPE : 
			strncpy( Error, "WSAEPROTOTYPE", _ESIZE ) ;
			break ;
		case WSAESOCKTNOSUPPORT : 
			strncpy( Error, "WSAESOCKTNOSUPPORT", _ESIZE ) ;
			break ;
		default : 
			{
			strncpy( Error, "UNKNOWN", _ESIZE ) ;
			break ;
			};
		};
#endif
    }

    return s;

}

BOOL SocketAPI::bind_ex ( SOCKET s , const struct sockaddr * addr , unsigned int addrlen ) 
{

    if ( bind ( s , addr , addrlen ) == SOCKET_ERROR ) 
    {
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
        switch ( errno ) 
        {
            case EADDRINUSE :
            case EINVAL : 
            case EACCES : 
            case ENOTSOCK : 
            case EBADF : 
            case EROFS : 
            case EFAULT : 
            case ENAMETOOLONG : 
            case ENOENT : 
            case ENOMEM : 
            case ENOTDIR : 
            case ELOOP : 
            default :
                {
                    break;
                }
        }//end of switch
#else
		int iErr = WSAGetLastError() ;
		switch ( iErr ) 
		{
		case WSANOTINITIALISED : 
			strncpy( Error, "WSAESOCKTNOSUPPORT", _ESIZE ) ;
			break ;
		case WSAENETDOWN : 
			strncpy( Error, "WSAENETDOWN", _ESIZE ) ;
			break ;
		case WSAEADDRINUSE : 
			strncpy( Error, "WSAEADDRINUSE", _ESIZE ) ;
			break ;
		case WSAEADDRNOTAVAIL : 
			strncpy( Error, "WSAEADDRNOTAVAIL", _ESIZE ) ;
			break ;
		case WSAEFAULT : 
			strncpy( Error, "WSAEFAULT", _ESIZE ) ;
			break ;
		case WSAEINPROGRESS : 
			strncpy( Error, "WSAEINPROGRESS", _ESIZE ) ;
			break ;
		case WSAEINVAL : 
			strncpy( Error, "WSAEINVAL", _ESIZE ) ;
			break ;
		case WSAENOBUFS : 
			strncpy( Error, "WSAENOBUFS", _ESIZE ) ;
			break ;
		case WSAENOTSOCK : 
			strncpy( Error, "WSAENOTSOCK", _ESIZE ) ;
			break ;
		default :
			{
			strncpy( Error, "UNKNOWN", _ESIZE ) ;
			break ;
			};
		};
#endif

        return FALSE ;
    }

    return TRUE ;

}

BOOL SocketAPI::connect_ex ( SOCKET s , const struct sockaddr * addr , unsigned int addrlen )
{

    if ( connect(s,addr,addrlen) == SOCKET_ERROR ) 
    {
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
        switch ( errno ) {
            case EALREADY : 
            case EINPROGRESS : 
            case ECONNREFUSED : 
            case EISCONN : 
            case ETIMEDOUT : 
            case ENETUNREACH : 
            case EADDRINUSE : 
            case EBADF : 
            case EFAULT : 
            case ENOTSOCK : 
            default :
                {
                    break;
                }
        }//end of switch
#else
		int iErr = WSAGetLastError() ;
		switch ( iErr ) 
		{
		case WSANOTINITIALISED : 
			strncpy( Error, "WSANOTINITIALISED", _ESIZE ) ;
			break ;
		case WSAENETDOWN : 
			strncpy( Error, "WSAENETDOWN", _ESIZE ) ;
			break ;
		case WSAEADDRINUSE : 
			strncpy( Error, "WSAEADDRINUSE", _ESIZE ) ;
			break ;
		case WSAEINPROGRESS : 
			strncpy( Error, "WSAEINPROGRESS", _ESIZE ) ;
			break ;
		case WSAEALREADY : 
			strncpy( Error, "WSAEALREADY", _ESIZE ) ;
			break ;
		case WSAEADDRNOTAVAIL : 
			strncpy( Error, "WSAEADDRNOTAVAIL", _ESIZE ) ;
			break ;
		case WSAEAFNOSUPPORT : 
			strncpy( Error, "WSAEAFNOSUPPORT", _ESIZE ) ;
			break ;
		case WSAECONNREFUSED : 
			strncpy( Error, "WSAECONNREFUSED", _ESIZE ) ;
			break ;
		case WSAEFAULT : 
			strncpy( Error, "WSAEFAULT", _ESIZE ) ;
			break ;
		case WSAEINVAL : 
			strncpy( Error, "WSAEINVAL", _ESIZE ) ;
			break ;
		case WSAEISCONN : 
			strncpy( Error, "WSAEISCONN", _ESIZE ) ;
			break ;
		case WSAENETUNREACH : 
			strncpy( Error, "WSAENETUNREACH", _ESIZE ) ;
			break ;
		case WSAENOBUFS : 
			strncpy( Error, "WSAENOBUFS", _ESIZE ) ;
			break ;
		case WSAENOTSOCK : 
			strncpy( Error, "WSAENOTSOCK", _ESIZE ) ;
			break ;
		case WSAETIMEDOUT : 
			strncpy( Error, "WSAETIMEDOUT", _ESIZE ) ;
			break ;
		case WSAEWOULDBLOCK  : 
			strncpy( Error, "WSAEWOULDBLOCK", _ESIZE ) ;
			break ;
		default :
			{
			strncpy( Error, "UNKNOWN", _ESIZE ) ;
			break ;
			};
		};
#endif
        return FALSE ;
    }

    return TRUE ;
}

BOOL SocketAPI::listen_ex ( SOCKET s , unsigned int backlog ) 
{

    if ( listen( s , backlog ) == SOCKET_ERROR ) 
    {
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
        switch ( errno ) 
        {
            case EBADF : 
            case ENOTSOCK :
            case EOPNOTSUPP :
            default :
                {
                    break;
                }
        }//end of switch
#else
		int iErr = WSAGetLastError() ;
		switch ( iErr ) 
		{
		case WSANOTINITIALISED : 
			strncpy( Error, "WSANOTINITIALISED", _ESIZE ) ;
			break ;
		case WSAENETDOWN : 
			strncpy( Error, "WSAENETDOWN", _ESIZE ) ;
			break ;
		case WSAEADDRINUSE : 
			strncpy( Error, "WSAEADDRINUSE", _ESIZE ) ;
			break ;
		case WSAEINPROGRESS : 
			strncpy( Error, "WSAEINPROGRESS", _ESIZE ) ;
			break ;
		case WSAEINVAL : 
			strncpy( Error, "WSAEINVAL", _ESIZE ) ;
			break ;
		case WSAEISCONN : 
			strncpy( Error, "WSAEISCONN", _ESIZE ) ;
			break ;
		case WSAEMFILE : 
			strncpy( Error, "WSAEMFILE", _ESIZE ) ;
			break ;
		case WSAENOBUFS : 
			strncpy( Error, "WSAENOBUFS", _ESIZE ) ;
			break ;
		case WSAENOTSOCK : 
			strncpy( Error, "WSAENOTSOCK", _ESIZE ) ;
			break ;
		case WSAEOPNOTSUPP : 
			strncpy( Error, "WSAEOPNOTSUPP", _ESIZE ) ;
			break ;
		default :
			{
			strncpy( Error, "UNKNOWN", _ESIZE ) ;
			break ;
			};
		};
#endif

        return FALSE ;
    }

    return TRUE ;

}

SOCKET SocketAPI::accept_ex ( SOCKET s , struct sockaddr * addr , unsigned int * addrlen )
{

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
    SOCKET client = accept( s , addr , (socklen_t*)addrlen );
#else
	SOCKET client = accept( s , addr , (int*)addrlen );
#endif

    if ( client == INVALID_SOCKET ) 
    {
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
        switch ( errno ) 
        {

            case EWOULDBLOCK : 

            case ECONNRESET :
            case ECONNABORTED :
            case EPROTO :
            case EBADF : 
            case ENOTSOCK : 
            case EOPNOTSUPP : 
            case EFAULT : 

            default :
                {
                    break;
                }
        }//end of switch
#else
		int iErr = WSAGetLastError() ;
		switch ( iErr ) 
		{
		case WSANOTINITIALISED : 
			strncpy( Error, "WSANOTINITIALISED", _ESIZE ) ;
			break ;
		case WSAENETDOWN : 
			strncpy( Error, "WSAENETDOWN", _ESIZE ) ;
			break ;
		case WSAEFAULT : 
			strncpy( Error, "WSAEFAULT", _ESIZE ) ;
			break ;
		case WSAEINPROGRESS : 
			strncpy( Error, "WSAEINPROGRESS", _ESIZE ) ;
			break ;
		case WSAEINVAL : 
			strncpy( Error, "WSAEINVAL", _ESIZE ) ;
			break ;
		case WSAEMFILE : 
			strncpy( Error, "WSAEMFILE", _ESIZE ) ;
			break ;
		case WSAENOBUFS : 
			strncpy( Error, "WSAENOBUFS", _ESIZE ) ;
			break ;
		case WSAENOTSOCK : 
			strncpy( Error, "WSAENOTSOCK", _ESIZE ) ;
			break ;
		case WSAEOPNOTSUPP : 
			strncpy( Error, "WSAEOPNOTSUPP", _ESIZE ) ;
			break ;
		case WSAEWOULDBLOCK : 
			strncpy( Error, "WSAEWOULDBLOCK", _ESIZE ) ;
			break ;
		default :
			{
			strncpy( Error, "UNKNOWN", _ESIZE ) ;
			break ;
			};
		};
#endif
	} else {
    }

    return client;

}

BOOL SocketAPI::getsockopt_ex ( SOCKET s , int level , int optname , void * optval , unsigned int * optlen )
{

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
    if ( getsockopt( s , level , optname , optval , (socklen_t*)optlen ) == SOCKET_ERROR ) 
    {
        switch ( errno ) 
        {
            case EBADF : 
            case ENOTSOCK : 
            case ENOPROTOOPT : 
            case EFAULT : 
            default :
                {
                    break;
                }
        }//end of switch

        return FALSE ;
    }
#else
	if ( getsockopt( s , level , optname , (char*)optval , (int*)optlen ) == SOCKET_ERROR ) 
	{
		int iErr = WSAGetLastError() ;
		switch ( iErr ) 
		{
		case WSANOTINITIALISED : 
			strncpy( Error, "WSANOTINITIALISED", _ESIZE ) ;
			break ;
		case WSAENETDOWN : 
			strncpy( Error, "WSAENETDOWN", _ESIZE ) ;
			break ;
		case WSAEFAULT : 
			strncpy( Error, "WSAEFAULT", _ESIZE ) ;
			break ;
		case WSAEINPROGRESS : 
			strncpy( Error, "WSAEINPROGRESS", _ESIZE ) ;
			break ;
		case WSAEINVAL : 
			strncpy( Error, "WSAEINVAL", _ESIZE ) ;
			break ;
		case WSAENOPROTOOPT : 
			strncpy( Error, "WSAENOPROTOOPT", _ESIZE ) ;
			break ;
		case WSAENOTSOCK : 
			strncpy( Error, "WSAENOTSOCK", _ESIZE ) ;
			break ;
		default : 
			{
			strncpy( Error, "UNKNOWN", _ESIZE ) ;
			break ;
			};
		};

		return FALSE ;
	}
#endif
    return TRUE ;

}

unsigned int SocketAPI::getsockopt_ex2 ( SOCKET s , int level , int optname , void * optval , unsigned int * optlen )
{

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
    if ( getsockopt( s , level , optname , optval , (socklen_t*)optlen ) == SOCKET_ERROR ) 
    {
        switch ( errno ) 
        {
            case EBADF : 
                return 1;
            case ENOTSOCK : 
                return 2;
            case ENOPROTOOPT : 
                return 3;
            case EFAULT : 
                return 4;
            default :
                return 5;
        }//end of switch
    }
    return 0;

#else
	if ( getsockopt( s , level , optname , (char*)optval , (int*)optlen ) == SOCKET_ERROR ) 
	{
		int iErr = WSAGetLastError() ;
		switch ( iErr ) 
		{
		case WSANOTINITIALISED:
			strncpy( Error, "WSANOTINITIALISED", _ESIZE ) ;
			break ;
		case WSAENETDOWN:
			strncpy( Error, "WSAENETDOWN", _ESIZE ) ;
			break ;
		case WSAEFAULT:
			strncpy( Error, "WSAEFAULT", _ESIZE ) ;
			break ;
		case WSAEINPROGRESS:
			strncpy( Error, "WSAEINPROGRESS", _ESIZE ) ;
			break ;
		case WSAEINVAL:
			strncpy( Error, "WSAEINVAL", _ESIZE ) ;
			break ;
		case WSAENOPROTOOPT:
			strncpy( Error, "WSAENOPROTOOPT", _ESIZE ) ;
			break ;
		case WSAENOTSOCK:
			strncpy( Error, "WSAENOTSOCK", _ESIZE ) ;
			break ;
		default : 
			{
			strncpy( Error, "UNKNOWN", _ESIZE ) ;
			break ;
			};
		}
	}
#endif

	return 0;
}

BOOL SocketAPI::setsockopt_ex ( SOCKET s , int level , int optname , const void * optval , unsigned int optlen )
{

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
    if ( setsockopt( s , level , optname , optval , optlen ) == SOCKET_ERROR ) 
    {
        switch ( errno ) 
        {
            case EBADF : 
            case ENOTSOCK : 
            case ENOPROTOOPT : 
            case EFAULT : 
            default :
                {
                    break;
                }
        }//end of switch

        return FALSE ;
    }
#else
	if ( setsockopt( s , level , optname , (char*)optval , optlen ) == SOCKET_ERROR ) 
	{
		int iErr = WSAGetLastError() ;
		switch ( iErr ) 
		{
		case WSANOTINITIALISED : 
			strncpy( Error, "WSANOTINITIALISED", _ESIZE ) ;
			break ;
		case WSAENETDOWN : 
			strncpy( Error, "WSAENETDOWN", _ESIZE ) ;
			break ;
		case WSAEFAULT : 
			strncpy( Error, "WSAEFAULT", _ESIZE ) ;
			break ;
		case WSAEINPROGRESS : 
			strncpy( Error, "WSAEINPROGRESS", _ESIZE ) ;
			break ;
		case WSAEINVAL : 
			strncpy( Error, "WSAEINVAL", _ESIZE ) ;
			break ;
		case WSAENETRESET : 
			strncpy( Error, "WSAENETRESET", _ESIZE ) ;
			break ;
		case WSAENOPROTOOPT : 
			strncpy( Error, "WSAENOPROTOOPT", _ESIZE ) ;
			break ;
		case WSAENOTCONN : 
			strncpy( Error, "WSAENOTCONN", _ESIZE ) ;
			break ;
		case WSAENOTSOCK : 
			strncpy( Error, "WSAENOTSOCK", _ESIZE ) ;
			break ;
		default :
			{
			strncpy( Error, "UNKNOWN", _ESIZE ) ;
			break ;
			};
		};

		return FALSE ;
	}
#endif
    return TRUE ;

}

unsigned int SocketAPI::send_ex ( SOCKET s , const void * buf , unsigned int len , unsigned int flags )
{

    int nSent;
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	nSent = send(s,buf,len,flags);
#else
	nSent = send(s,(const char *)buf,len,flags);
#endif

    if ( nSent == SOCKET_ERROR ) 
    {
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
        switch ( errno ) 
        {

            case EWOULDBLOCK : 
                return SOCKET_ERROR_WOULDBLOCK;

            case ECONNRESET :
            case EPIPE :

            case EBADF : 
            case ENOTSOCK : 
            case EFAULT : 
            case EMSGSIZE : 
            case ENOBUFS : 

            default : 
                {
                    break;
                }
        }//end of switch
		//printf("the SOCKET ID:%d\n", s);
#else
		int iErr = WSAGetLastError() ;
		switch ( iErr ) 
		{
		case WSANOTINITIALISED : 
			strncpy( Error, "WSANOTINITIALISED", _ESIZE ) ;
			break ;
		case WSAENETDOWN : 
			strncpy( Error, "WSAENETDOWN", _ESIZE ) ;
			break ;
		case WSAEACCES : 
			strncpy( Error, "WSAEACCES", _ESIZE ) ;
			break ;
		case WSAEINPROGRESS : 
			strncpy( Error, "WSAEINPROGRESS", _ESIZE ) ;
			break ;
		case WSAEFAULT : 
			strncpy( Error, "WSAEFAULT", _ESIZE ) ;
			break ;
		case WSAENETRESET : 
			strncpy( Error, "WSAENETRESET", _ESIZE ) ;
			break ;
		case WSAENOBUFS : 
			strncpy( Error, "WSAENOBUFS", _ESIZE ) ;
			break ;
		case WSAENOTCONN : 
			strncpy( Error, "WSAENOTCONN", _ESIZE ) ;
			break ;
		case WSAENOTSOCK : 
			strncpy( Error, "WSAENOTSOCK", _ESIZE ) ;
			break ;
		case WSAEOPNOTSUPP : 
			strncpy( Error, "WSAEOPNOTSUPP", _ESIZE ) ;
			break ;
		case WSAESHUTDOWN : 
			strncpy( Error, "WSAESHUTDOWN", _ESIZE ) ;
			break ;
		case WSAEWOULDBLOCK : 
			strncpy( Error, "WSAEWOULDBLOCK", _ESIZE ) ;
			return SOCKET_ERROR_WOULDBLOCK ;
			break ;
		case WSAEMSGSIZE : 
			strncpy( Error, "WSAEMSGSIZE", _ESIZE ) ;
			break ;
		case WSAEHOSTUNREACH : 
			strncpy( Error, "WSAEHOSTUNREACH", _ESIZE ) ;
			break ;
		case WSAEINVAL : 
			strncpy( Error, "WSAEINVAL", _ESIZE ) ;
			break ;
		case WSAECONNABORTED : 
			strncpy( Error, "WSAECONNABORTED", _ESIZE ) ;
			break ;
		case WSAECONNRESET : 
			strncpy( Error, "WSAECONNRESET", _ESIZE ) ;
			break ;
		case WSAETIMEDOUT : 
			strncpy( Error, "WSAETIMEDOUT", _ESIZE ) ;
			break ;
		default :
			{
			strncpy( Error, "UNKNOWN", _ESIZE ) ;
			break ;
			};
		};
#endif
    } 
    else if ( nSent == 0 )
    {
    }


    return nSent;

}

unsigned int SocketAPI::sendto_ex ( SOCKET s , const void * buf , int len , unsigned int flags , const struct sockaddr * to , int tolen )
{

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
    int nSent = sendto(s,buf,len,flags,to,tolen);
#else
	int nSent = sendto(s,(const char *)buf,len,flags,to,tolen);
#endif

    if ( nSent == SOCKET_ERROR ) 
    {
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
        switch ( errno ) 
        {

            case EWOULDBLOCK : 
                return 0;

            case ECONNRESET :
            case EPIPE :

            case EBADF : 
            case ENOTSOCK : 
            case EFAULT : 
            case EMSGSIZE : 
            case ENOBUFS : 

            default : 
                {
                    break;
                }
        }	
#else
#endif
    }

    return nSent;

}

unsigned int SocketAPI::recv_ex ( SOCKET s , void * buf , unsigned int len , unsigned int flags )
{

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
    int nrecv = recv(s,buf,len,flags);
#else
	int nrecv = recv(s,(char*)buf,len,flags);
#endif

    if ( nrecv == SOCKET_ERROR ) 
    {
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
        switch ( errno ) 
        {

            case EWOULDBLOCK : 
                return SOCKET_ERROR_WOULDBLOCK;

            case ECONNRESET :
            case EPIPE :
            case EBADF : 
            case ENOTCONN : 
            case ENOTSOCK : 
            case EFAULT : 
            default : 
                {
                    break;
                }
        }//end of switch

#else
		int iErr = WSAGetLastError() ;
		switch ( iErr ) 
		{
		case WSANOTINITIALISED : 
			strncpy( Error, "WSANOTINITIALISED", _ESIZE ) ;
			break ;
		case WSAENETDOWN : 
			strncpy( Error, "WSAENETDOWN", _ESIZE ) ;
			break ;
		case WSAEFAULT : 
			strncpy( Error, "WSAEFAULT", _ESIZE ) ;
			break ;
		case WSAENOTCONN : 
			strncpy( Error, "WSAENOTCONN", _ESIZE ) ;
			break ;
		case WSAEINPROGRESS : 
			strncpy( Error, "WSAEINPROGRESS", _ESIZE ) ;
			break ;
		case WSAENETRESET : 
			strncpy( Error, "WSAENETRESET", _ESIZE ) ;
			break ;
		case WSAENOTSOCK : 
			strncpy( Error, "WSAENOTSOCK", _ESIZE ) ;
			break ;
		case WSAEOPNOTSUPP : 
			strncpy( Error, "WSAEOPNOTSUPP", _ESIZE ) ;
			break ;
		case WSAESHUTDOWN : 
			strncpy( Error, "WSAESHUTDOWN", _ESIZE ) ;
			break ;
		case WSAEWOULDBLOCK : 
			strncpy( Error, "WSAEWOULDBLOCK", _ESIZE ) ;
			return SOCKET_ERROR_WOULDBLOCK ;
			break ;
		case WSAEMSGSIZE : 
			strncpy( Error, "WSAEMSGSIZE", _ESIZE ) ;
			break ;
		case WSAEINVAL : 
			strncpy( Error, "WSAEINVAL", _ESIZE ) ;
			break ;
		case WSAECONNABORTED : 
			strncpy( Error, "WSAECONNABORTED", _ESIZE ) ;
			break ;
		case WSAETIMEDOUT : 
			strncpy( Error, "WSAETIMEDOUT", _ESIZE ) ;
			break ;
		case WSAECONNRESET : 
			strncpy( Error, "WSAECONNRESET", _ESIZE ) ;
			break ;
		default :
			{
			strncpy( Error, "UNKNOWN", _ESIZE ) ;
			break ;
			};
		};
#endif
    } 
    else if ( nrecv == 0 )
    {
    }

    return nrecv;

}

unsigned int SocketAPI::recvfrom_ex ( SOCKET s , void * buf , int len , unsigned int flags , struct sockaddr * from , unsigned int * fromlen )
{

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
    int nReceived = recvfrom(s,buf,len,flags,from,(socklen_t*)fromlen);

#else
	int nReceived = recvfrom(s,(char*)buf,len,flags,from,(int*)fromlen);
#endif
    if ( nReceived == SOCKET_ERROR ) 
    {
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
        switch ( errno ) 
        {

            case EWOULDBLOCK : 
                return SOCKET_ERROR_WOULDBLOCK;

            case ECONNRESET :
            case EPIPE :

            case EBADF : 
            case ENOTCONN : 
            case ENOTSOCK : 
            case EFAULT : 

            default : 
                {
                    break;
                }
        }
#else
#endif
    }

    return nReceived;

}

BOOL SocketAPI::closesocket_ex ( SOCKET s )
{

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
    close(s);  //changed form close(s)
#else
	if ( closesocket(s) == SOCKET_ERROR ) 
	{
		int iErr = WSAGetLastError() ;
		switch ( iErr ) 
		{
		case WSANOTINITIALISED : 
			strncpy( Error, "WSANOTINITIALISED", _ESIZE ) ;
			break ;
		case WSAENETDOWN : 
			strncpy( Error, "WSAENETDOWN", _ESIZE ) ;
			break ;
		case WSAENOTSOCK : 
			strncpy( Error, "WSAENOTSOCK", _ESIZE ) ;
			break ;
		case WSAEINPROGRESS : 
			strncpy( Error, "WSAEINPROGRESS", _ESIZE ) ;
			break ;
		case WSAEWOULDBLOCK : 
			strncpy( Error, "WSAEWOULDBLOCK", _ESIZE ) ;
			break ;
		default : 
			{
			strncpy( Error, "UNKNOWN", _ESIZE ) ;
			break ;
			};
		};

		return FALSE ;
	}
#endif
    return TRUE ;


    return FALSE ;
}

BOOL SocketAPI::ioctlsocket_ex ( SOCKET s , LONG cmd , ULONG * argp )
{

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
#else
	if ( ioctlsocket(s,cmd,argp) == SOCKET_ERROR ) 
	{
		int iErr = WSAGetLastError() ;
		switch ( iErr ) 
		{
		case WSANOTINITIALISED : 
			strncpy( Error, "WSANOTINITIALISED", _ESIZE ) ;
			break ;
		case WSAENETDOWN : 
			strncpy( Error, "WSAENETDOWN", _ESIZE ) ;
			break ;
		case WSAEINPROGRESS : 
			strncpy( Error, "WSAEINPROGRESS", _ESIZE ) ;
			break ;
		case WSAENOTSOCK : 
			strncpy( Error, "WSAENOTSOCK", _ESIZE ) ;
			break ;
		case WSAEFAULT : 
			strncpy( Error, "WSAEFAULT", _ESIZE ) ;
			break ;
		default :
			{
			strncpy( Error, "UNKNOWN", _ESIZE ) ;
			break ;
			};
		};

		return FALSE ;
	}
#endif
    return TRUE ;

}

BOOL SocketAPI::getsocketnonblocking_ex ( SOCKET s )
{

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
    //int flags = FileAPI::fcntl_ex( s , F_GETFL , 0 );

    return O_NONBLOCK;
#else
	return FALSE ;
#endif

}

BOOL SocketAPI::setsocketnonblocking_ex ( SOCKET s , BOOL on )
{

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
    //int flags = FileAPI::fcntl_ex( s , F_GETFL , 0 );
	int flags = 0;
    if ( on )
        // make nonblocking fd
        flags |= O_NONBLOCK;
    else
        // make blocking fd
        flags &= ~O_NONBLOCK;

    //FileAPI::fcntl_ex( s , F_SETFL , flags );

    return TRUE;
#else

	ULONG argp = ( on == TRUE ) ? 1 : 0;
	return ioctlsocket_ex( s,FIONBIO,&argp);

#endif
}

unsigned int SocketAPI::availablesocket_ex ( SOCKET s )
{
	return 0;
/*#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
    return FileAPI::availablefile_ex(s);
#elif __WINDOWS__
	ULONG argp = 0;
	ioctlsocket_ex(s,FIONREAD,&argp);
	return argp;
#endif
	*/
}

BOOL SocketAPI::shutdown_ex ( SOCKET s , unsigned int how )
{

    if ( shutdown(s,how) < 0 ) 
    {
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
        switch ( errno ) {
            case EBADF : 
            case ENOTSOCK : 
            case ENOTCONN : 
            default : 
                {
                    break;
                }
        }
#else
		int iErr = WSAGetLastError() ;
		switch ( iErr ) 
		{
		case WSANOTINITIALISED : 
			strncpy( Error, "WSANOTINITIALISED", _ESIZE ) ;
			break ;
		case WSAENETDOWN :
			strncpy( Error, "WSAENETDOWN", _ESIZE ) ;
			break ;
		case WSAEINVAL : 
			strncpy( Error, "WSAEINVAL", _ESIZE ) ;
			break ;
		case WSAEINPROGRESS : 
			strncpy( Error, "WSAEINPROGRESS", _ESIZE ) ;
			break ;
		case WSAENOTCONN : 
			strncpy( Error, "WSAENOTCONN", _ESIZE ) ;
			break ;
		case WSAENOTSOCK : 
			strncpy( Error, "WSAENOTSOCK", _ESIZE ) ;
			break ;
		default :
			{
			strncpy( Error, "UNKNOWN", _ESIZE ) ;
			break ;
			};
		};
#endif
        return FALSE ;
    }

    return TRUE ;

}

int SocketAPI::select_ex ( int maxfdp1 , fd_set * readset , fd_set * writeset , fd_set * exceptset , struct timeval * timeout )
{

    int result;

    result = select( maxfdp1 , readset , writeset , exceptset , timeout );
    if( result == SOCKET_ERROR )
    {
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)

#else
		int iErr = WSAGetLastError() ;
		switch ( iErr ) 
		{
		case WSANOTINITIALISED : 
			strncpy( Error, "WSANOTINITIALISED", _ESIZE ) ;
			break ;
		case WSAEFAULT:
			strncpy( Error, "WSAEFAULT", _ESIZE ) ;
			break ;
		case WSAENETDOWN:
			strncpy( Error, "WSAENETDOWN", _ESIZE ) ;
			break ;
		case WSAEINVAL:
			strncpy( Error, "WSAEINVAL", _ESIZE ) ;
			break ;
		case WSAEINPROGRESS:
			strncpy( Error, "WSAEINPROGRESS", _ESIZE ) ;
			break ;
		case WSAENOTSOCK:
			strncpy( Error, "WSAENOTSOCK", _ESIZE ) ;
			break ;
		default :
			{
			strncpy( Error, "UNKNOWN", _ESIZE ) ;
			break ;
			};
		};
#endif
	} 
    return result;

}
