#ifndef UDPSOCKET_H
#define UDPSOCKET_H
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <unistd.h>

#include <cerrno>
#include <functional>
#include <iostream>
#include <memory>
#include <string>

#include "base_sock.h"
#include "err.h"
using err_cb = std::function<void(int, std::string)>;
class UDPSocket : public BaseSocket
{
public:
    enum class SocketBuildType { BindSocket, ConnectSocket, None };
    SocketBuildType build_type_;
    std::function<void(std::string, std::string, std::uint16_t)> onMessageReceived;
    std::function<void(const char *, int, std::string, std::uint16_t)> onRawMessageReceived;

    explicit UDPSocket(ON_ERROR_CALLBACK, int socketFd = -1);

    void SendTo(std::string message, std::string host, uint16_t port, ON_ERROR_CALLBACK);
    void SendTo(const char *tx_buf, size_t tx_len, std::string host, uint16_t port, ON_ERROR_CALLBACK);

    int Send(std::string message);
    int Send(const char *tx_buf, size_t tx_len);

    ssize_t RecvFrom(char *rx_buf, ssize_t rx_buf_max_size);
    void Connect(std::string host, uint16_t port, ON_ERROR_CALLBACK);
    void Connect(uint32_t ipv4, uint16_t port, ON_ERROR_CALLBACK);

    void Bind(std::uint16_t port, ON_ERROR_CALLBACK);
    void Bind(std::string IPv4, std::uint16_t port, ON_ERROR_CALLBACK);

    friend std::ostream &operator<<(std::ostream &os, const UDPSocket &sock_obj)
    {
        char ip_buf[INET_ADDRSTRLEN];
        struct sockaddr_in ip_addr;
        bzero(&ip_addr, sizeof(ip_addr));
        socklen_t len = sizeof(struct sockaddr_in);
        int port;
        switch (sock_obj.build_type_) {
        case SocketBuildType::ConnectSocket:
            getpeername(sock_obj.sockfd, (struct sockaddr *) &ip_addr, &len);
            inet_ntop(AF_INET, &ip_addr.sin_addr, ip_buf, sizeof(ip_buf));
            port = ntohs(ip_addr.sin_port);
            std::cout << "Sender Socket Connect to: ";
            break;
        case SocketBuildType::None:
        case SocketBuildType::BindSocket:
            getsockname(sock_obj.sockfd, (struct sockaddr *) &ip_addr, &len);
            inet_ntop(AF_INET, &ip_addr.sin_addr, ip_buf, sizeof(ip_buf));
            port = ntohs(ip_addr.sin_port);
            std::cout << "Recviver Socket Bind to: ";
            break;
        default:
            throw Error("Undefine build-type!");
            break;
        }
        os << "IP: " << ip_buf << " Port: " << port << std::endl;

        return os;
    }
    /*Factory method to construct a udp socket object*/
    template <typename... Args>
    static std::shared_ptr<UDPSocket> Create(Args... args)
    {
        std::shared_ptr<UDPSocket> udp_socket = std::make_shared<UDPSocket>();
        udp_socket->build(args...);
        return udp_socket;
    }
    template <typename... Args>
    void build(Args... args)
    {
        _build(args...);
    }
    template <typename... Args>
    void _build(std::string ip_addr, std::uint16_t port, SocketBuildType type = SocketBuildType::None, Args... args)
    {
        build_type_ = type;
        switch (build_type_) {
        case SocketBuildType::ConnectSocket:
            Connect(ip_addr, port);
            break;
        case SocketBuildType::BindSocket:
            Bind(ip_addr, port);
            break;
        case SocketBuildType::None:
            break;
        default:
            throw Error("Undefine build-type!");
            break;
        }
        _build(args...);
    }
    template <typename... Args>
    void _build(std::uint16_t port, SocketBuildType type = SocketBuildType::BindSocket, Args... args)
    {
        build_type_ = type;
        switch (build_type_) {
        case SocketBuildType::BindSocket:
            Bind(port);
            break;
        case SocketBuildType::None:
            break;
        default:
            throw Error("Undefine/Ambiguous build-type!");
            break;
        }
        _build(args...);
    }
    /*internal helper function for different connection of constructor*/
    void _build() const
    {
        /**print out socket building detail */
        std::cout << std::ref((*this)) << std::endl;
    }
};

#endif