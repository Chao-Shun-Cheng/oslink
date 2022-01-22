#include "udp_sock.h"

#include <string.h>

#include <fstream>
#include <iostream>
UDPSocket::UDPSocket(std::function<void(int, std::string)> onError, int socketFD) : BaseSocket(onError, UDP, socketFD)
{
    build_type_ = SocketBuildType::None;
}

void UDPSocket::SendTo(std::string message, std::string host, uint16_t port, std::function<void(int, std::string)> onError)
{
    this->SendTo(message.c_str(), message.length(), host, port, onError);
}

void UDPSocket::SendTo(const char *tx_buf, size_t tx_len, std::string host, uint16_t port, std::function<void(int, std::string)> onError)
{
    sockaddr_in hostAddr;

    struct addrinfo hints, *res, *it;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;

    int status;
    if ((status = getaddrinfo(host.c_str(), NULL, &hints, &res)) != 0) {
        onError(errno, "Invalid address." + std::string(gai_strerror(status)));
        return;
    }

    for (it = res; it != NULL; it = it->ai_next) {
        if (it->ai_family == AF_INET) {  // IPv4
            memcpy((void *) (&hostAddr), (void *) it->ai_addr, sizeof(sockaddr_in));
            break;  // for now, just get first ip (ipv4)
        }
    }

    freeaddrinfo(res);

    hostAddr.sin_port = htons(port);
    hostAddr.sin_family = AF_INET;

    if (sendto(this->sockfd, tx_buf, tx_len, 0, (sockaddr *) &hostAddr, sizeof(hostAddr)) < 0) {
        onError(errno, "Cannot send message to the address.");
        return;
    }
}

int UDPSocket::Send(std::string message) noexcept(false)
{
    return this->Send(message.c_str(), message.length());
}

int UDPSocket::Send(const char *tx_buf, size_t tx_len) noexcept(false)
{
    if (this->isClosed)
        return -1;

    int sent = 0;
    try {
        if ((sent = send(this->sockfd, tx_buf, tx_len, 0)) < 0) {
            throw std::system_error(EFAULT, std::generic_category());
        }
    } catch (std::system_error &error) {
        std::cout << "Error: " << error.code() << " - " << error.what() << '\n';
        if (error.code() == std::errc::connection_refused || error.code() == std::errc::bad_address)
            return 0;
    }

    return sent;
}

void UDPSocket::Connect(std::string peer, uint16_t port, std::function<void(int, std::string)> onError)
{
    struct addrinfo hints, *res, *it;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_DGRAM; // UDP

    int status;
    if ((status = getaddrinfo(peer.c_str(), NULL, &hints, &res)) != 0) {
        onError(errno, "Invalid address." + std::string(gai_strerror(status)));
        return;
    }

    for (it = res; it != NULL; it = it->ai_next) {
        if (it->ai_family == AF_INET) {  // IPv4
            memcpy((void *) (&this->address), (void *) it->ai_addr, sizeof(sockaddr_in));
            break;  // for now, just get first ip (ipv4).
        }
    }

    freeaddrinfo(res);

    this->Connect((uint32_t) this->address.sin_addr.s_addr, port, onError);
}

void UDPSocket::Connect(uint32_t ipv4, uint16_t port, std::function<void(int, std::string)> onError)
{
    this->address.sin_family = AF_INET;
    this->address.sin_port = htons(port);
    this->address.sin_addr.s_addr = ipv4;

    // Try to connect.
    if (connect(this->sockfd, (const sockaddr *) &this->address, sizeof(sockaddr_in)) < 0) {
        onError(errno, "Connection failed to the peer.");
        return;
    }
}

void UDPSocket::Bind(uint16_t port, std::function<void(int, std::string)> onError)
{
    this->Bind("0.0.0.0", port, onError);
}

/*
Start socket server 
int bind(int sockfd, struct sockaddr* addr, int addrlen)
*/
void UDPSocket::Bind(std::string IPv4, std::uint16_t port, std::function<void(int, std::string)> onError)
{
    if (inet_pton(AF_INET, IPv4.c_str(), &this->address.sin_addr) <= 0) {
        onError(errno, "Invalid address. Address type not supported.");
        return;
    }

    this->address.sin_family = AF_INET;
    this->address.sin_port = htons(port);

    if (bind(this->sockfd, (const sockaddr *) &this->address, sizeof(this->address)) < 0) {
        onError(errno, "Cannot bind the socket.");
        return;
    }
}

ssize_t UDPSocket::RecvFrom(char *rx_buf, ssize_t rx_buf_max_size)
{
    if (this->isClosed)
        return -1;
    sockaddr_in hostAddr;
    socklen_t hostAddrSize = sizeof(hostAddr);
    size_t byte_recv;
    try {
        byte_recv = recvfrom(this->sockfd, rx_buf, rx_buf_max_size, 0, (struct sockaddr *) &hostAddr, &hostAddrSize);
        if (byte_recv < 0)
            throw std::system_error(EFAULT, std::generic_category());
    } catch (std::system_error &error) {
        std::cout << "Error: " << error.code() << " - " << error.what() << '\n';
        if (error.code() == std::errc::connection_refused || error.code() == std::errc::bad_address)
            return 0;
    }
    return byte_recv;
}
