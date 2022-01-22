#include <iostream>
#include <thread>
#include <vector>

#include "Unex_caster.h"
#include "arg_parser.h"
#include "task.h"
using namespace std;
using namespace arg_parse_tools;
using namespace unex_caster_tools;
using namespace thread_tools;
int main(int argc, const char *argv[])
{
    struct option_setting {
        string peer_ip_opt{};
        string host_ip_opt{};
        int host_port_opt{};
        int peer_port_opt{};
    };

    auto parser = command_options<option_setting>::Create({{"--peer_ip", &option_setting::peer_ip_opt},
                                                           {"--host_ip", &option_setting::host_ip_opt},
                                                           {"--host_port", &option_setting::host_port_opt},
                                                           {"--peer_port", &option_setting::peer_port_opt}});

    auto my_option = parser->parse(argc, argv);

    std::cout << "Host IP Opt= " << my_option.host_ip_opt << endl;
    std::cout << "Peer IP Opt= " << my_option.peer_ip_opt << endl;
    std::cout << "Host Port Opt = " << my_option.host_port_opt << endl;
    std::cout << "Peer Port Opt = " << my_option.peer_port_opt << endl;
    start_task(my_option.peer_ip_opt, my_option.peer_port_opt, my_option.host_ip_opt, my_option.host_port_opt, 0, CASTER_MODE_TX, 0, CASTER_MODE_RX);
    return 0;
}
