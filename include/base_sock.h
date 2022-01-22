#ifndef BASE_SOCK_H
#define BASE_SOCK_H
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <functional>
#include <string>
/* Unused arguments generate annoying warnings... */
#define UNUSED(expr)   \
    {                  \
        (void) (expr); \
    }
#define ON_ERROR_CALLBACK                                                                         \
    std::function<void(int, std::string)> onError = [](int errorCode, std::string errorMessage) { \
        UNUSED(errorCode);                                                                        \
        UNUSED(errorMessage)                                                                      \
    }
class BaseSocket
{
protected:
    int sockfd = 0;

    static std::string ipToString(sockaddr_in addr);

public:
    const uint32_t BUFFER_SIZE = 0x20000;
    enum SocketType { TCP = SOCK_STREAM, UDP = SOCK_DGRAM };

    sockaddr_in address;
    bool isClosed = false;
    /*
    build socket
    input : socket domain, socket type, socketFD)
    socketfd records the socket status : -1 means fail, 0 means success
    */
    explicit BaseSocket(ON_ERROR_CALLBACK, SocketType sockType = UDP, int socketFD = -1);

    virtual void Close();

    std::string remoteAddress();
    int remotePort();
    int fileDescriptor() const { return this->sockfd; }
};
#endif