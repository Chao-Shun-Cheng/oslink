#ifndef ERR_H
#define ERR_H
#include <cerrno>
#include <cstring>
#include <stdexcept>
#include <system_error>
class Error : public std::runtime_error
{
public:
    Error(const std::string &msg) : std::runtime_error(msg){};
    Error(const std::string &&msg) : std::runtime_error(msg){};
};
class Except : virtual public std::exception
{
protected:
    int error_number;
    std::string error_message;

public:
    explicit Except(const std::string &msg, int err_num) : error_number(err_num), error_message(msg) {}

    virtual ~Except() throw() {}

    virtual const char *what() const throw() { return error_message.c_str(); }
    /** Returns error number.*/
    virtual int getErrorNumber() const throw() { return error_number; }
};
#endif