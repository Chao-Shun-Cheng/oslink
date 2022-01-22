#ifndef UNEX_CASTER_H
#define UNEX_CASTER_H
#include <array>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "err.h"
/*
 Trust me, you need these C wrappers every time when tring to use Unex provieded header file in C++ program
 to avoid the need to deal with the incompatible bugs of Unex’s shit-like shared objects
 */
extern "C" {
#include "dsrc_caster_service.h"
#include "error_code_enum.h"
#include "error_code_user.h"
#include "math.h"
}
namespace unex_caster_tools
{
class Unex_caster
{
public:
    Unex_caster() = default;
    ~Unex_caster() noexcept(false)
    {
        auto ret = dsrc_caster_release(handler);

        if (ret != 0) {
            throw Error("Failed to release caster , ret: " + ret);
        }
    }
    void set_config(std::string ip, uint16_t caster_id, caster_comm_mode_t comm_mode) noexcept
    {
        config.ip = ip.c_str();
        config.caster_id = caster_id;
        config.caster_comm_mode = comm_mode;
    }
    void set_config(caster_comm_config_t config) noexcept
    {
        config.ip = config.ip;
        config.caster_id = config.caster_id;
        config.caster_comm_mode = config.caster_comm_mode;
    }
    auto data_send(void *tx_buf, size_t tx_len) noexcept(false)
    {
        try {
            auto ret = dsrc_caster_tx(handler, NULL, (uint8_t *) tx_buf, tx_len);
            if (IS_SUCCESS(ret)) {
                printf("Transmitted %zu bytes!\n", tx_len);
            } else {
                throw ret;
            }
            return ret;
        } catch (int retval) {
            printf("Failed to transmit data, err code is:%d, msg = %s\n", retval, ERROR_MSG(retval));
            /** exception handler*/
        }
    }
    auto data_recv(void *rx_buf, size_t &rx_len) noexcept(false)
    {
        try {
            auto ret = dsrc_caster_rx(handler, &rx_info, (uint8_t *) rx_buf, &rx_len);
            if (IS_SUCCESS(ret)) {
                printf("DSRC:Received %zu bytes!\n", rx_len);
                return ret;
            } else {
                /* The user may still get the payload with len is non-zero. */
                /* It means the data has some prolbems, such as security check failure */
                /* Users can determine to trust the data or not by themself */
                if (rx_len != 0) {
                    printf("DSRC:Received %zu bytes, but had some issues! err code is:%d, msg = %s\n", rx_len, ret, ERROR_MSG(ret));
                } else {
                    throw ret;
                }
            }
        } catch (int retval) {
            printf("Failed to receive data, err code is:%d, msg = %s\n", retval, ERROR_MSG(retval));
            return retval;
            /** exception handler*/
        }
    }
    void allocate() noexcept(false)
    {
        tx_info = {0};
        rx_info = {0};
        int ret = dsrc_caster_create(&handler, &config);
        if (ret != 0) {
            /** throw exception */
            throw Error("Failed to create rx caster , ret: " + ret);
        }
    }

    template <typename... Args>
    static std::shared_ptr<Unex_caster> Create(Args... args)
    {
        std::shared_ptr<Unex_caster> caster = std::make_shared<Unex_caster>();
        caster->build(args...);
        return caster;
    }
    template <typename... Args>
    void build(Args... args)
    {
        _build(args...);
    }
    template <typename... Args>
    void _build(caster_comm_config_t config, Args... args)
    {
        set_config(config);
        _build(args...);
    }
    template <typename... Args>
    void _build(std::string ip, uint16_t caster_id, caster_comm_mode_t comm_mode, Args... args)
    {
        set_config(ip, caster_id, comm_mode);
        _build(args...);
    }
    void _build() { allocate(); }

protected:
    dsrc_tx_info_t tx_info;
    dsrc_rx_info_t rx_info;
    caster_handler_t handler;
    caster_comm_config_t config;
};
}  // namespace unex_caster_tools
#endif