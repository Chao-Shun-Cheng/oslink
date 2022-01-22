#ifndef TASK_H
#define TASK_H
#include <array>
#include <functional>
#include <iostream>
#include <thread>

#include "Unex_caster.h"
#include "err.h"
#include "udp_sock.h"
namespace thread_tools
{
using namespace unex_caster_tools;
using namespace std;
int cnt_rx = 0;
int cnt_tx = 0;
void recv_task(std::shared_ptr<UDPSocket> udp_socket, string peer_ip, int peer_port, uint16_t Recv_caster_id, caster_comm_mode_t Recv_comm_mode)
{
    auto caster_receiver = Unex_caster::Create("127.0.0.1", Recv_caster_id, Recv_comm_mode);
    char rx_buf[1460];
    size_t rx_len = 1460;
    for (;;) {
        int ret = caster_receiver->data_recv(rx_buf, rx_len);
        if (ret < 0) {
            printf("DSRC:Received %zu bytes, but had some issues! err code is:%d, msg = %s\n", rx_len, ret, ERROR_MSG(ret));
            break;
        }
        udp_socket->SendTo(rx_buf, rx_len, peer_ip, peer_port);
        cnt_rx++;
        printf("dsrc recv %d packages\n", cnt_rx);
    }
}
void send_task(std::shared_ptr<UDPSocket> udp_socket, uint16_t Send_caster_id, caster_comm_mode_t Send_comm_mode)
{
    printf("dsrc tx caster: ");
    auto caster_sender = Unex_caster::Create("127.0.0.1", Send_caster_id, Send_comm_mode);
    char tx_buf[1460];
    size_t tx_len;
    for (;;) {
        tx_len = udp_socket->RecvFrom(tx_buf, 1460);
        size_t ret = caster_sender->data_send(tx_buf, tx_len);
        cnt_tx++;
        printf("dsrc send %d packages\n", cnt_tx);
    }
}
void start_task(string peer_ip,
                int peer_port,
                string host_ip,
                int host_port,
                uint16_t Send_caster_id,
                caster_comm_mode_t Send_comm_mode,
                uint16_t Recv_caster_id,
                caster_comm_mode_t Recv_comm_mode)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    auto udp_sender = UDPSocket::Create(host_ip, host_port, UDPSocket::SocketBuildType::BindSocket);
    std::thread t2(recv_task, udp_sender, peer_ip, peer_port, Recv_caster_id, Recv_comm_mode);
    std::thread t1(send_task, udp_sender, Send_caster_id, Send_comm_mode);
    t1.join();
    t2.join();
}

}  // namespace thread_tools
#endif