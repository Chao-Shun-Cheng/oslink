#include "base_sock.h"

#include <cerrno>

std::string BaseSocket::ipToString(sockaddr_in addr)
{
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(addr.sin_addr), ip, INET_ADDRSTRLEN);

    return std::string(ip);
}

/*
build socket 
int socket(int domain, int type, int protocol)
domain : 
 * （1）AF_INET         IPv4
 * （2）AF_INET6        IPv6
 * （3）AF_UNIX         Unix ( between process )
type : 
 * （1）SOCK_STREAM     TCP
 * （2）SOCK_DGRAM      UDP
*/
BaseSocket::BaseSocket(std::function<void(int, std::string)> onError, SocketType sockType, int socketFd) : sockfd(socketFd)
{
    if (socketFd < 0) {
        if ((this->sockfd = socket(AF_INET, sockType, 0)) < 0) {
            onError(errno, "Socket creating error.");
        }
    }
}

void BaseSocket::Close()
{
    if (isClosed)
        return;

    isClosed = true;
    close(this->sockfd);
}

std::string BaseSocket::remoteAddress()
{
    return ipToString(this->address);
}

int BaseSocket::remotePort()
{
    return ntohs(this->address.sin_port);
}