#ifndef ARG_PARSER_I_H
#define ARG_PARSER_I_H
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <string_view>
#include <variant>

namespace arg_parse_tools
{
using namespace std;
template <class optinos>
struct command_options : optinos {
    /*
        each template parameter is of type pointer to member of Opts.
        So, at every given timepoint, a variable of type MyProp will hold a pointer to exactly one member of options
    */

    using property_ = std::variant<string optinos::*, int optinos::*, double optinos::*, bool optinos::*>;
    using arg_ = std::pair<string, property_>;

    ~command_options() = default;

    optinos parse(int argc, const char *argv[])
    {
        vector<string_view> vec_argv(argv, argv + argc);
        for (int idx = 0; idx < argc; ++idx)
            for (auto &cbk : callback_map)
                cbk.second(idx, vec_argv);

        return static_cast<optinos>(*this);
    }

    static unique_ptr<command_options> Create(std::initializer_list<arg_> args)
    {
        auto command_options_ptr = unique_ptr<command_options>(new command_options());
        for (auto arg : args)
            command_options_ptr->register_callback(arg);
        return command_options_ptr;
    }

private:
    using callback_t = function<void(int, const vector<string_view> &)>;
    map<string, callback_t> callback_map;

    command_options() = default;
    
    /*
    delete these functions.
    it's not able to copy and assign from other objects.
    */
    command_options(const command_options &) = delete;
    command_options(command_options &&) = delete;
    command_options &operator=(const command_options &) = delete;
    command_options &operator=(command_options &&) = delete;
    
    /*
      lambda function : [](){}
      std::visit allows you to apply a visitor to a list of variants.
      The visitor must be a callable. A callable is something, which you can invoke.
      Typically this can be a function, a function object, and lambda function
    */
    auto register_callback(string arg_name, property_ arg_property)
    {
        callback_map[arg_name] = /*lambda function start*/
            [this, arg_name, arg_property](int idx, const vector<string_view> &argv) {
                if (argv[idx] == arg_name) {
                    /*varient visit start*/
                    visit(
                        [this, idx, &argv](auto &&arg) {
                            if (idx < argv.size() - 1) {
                                stringstream value;
                                value << argv[idx + 1];
                                value >> this->*arg;
                            }
                        },
                        arg_property);
                }
            }; /*lambda funtion end*/
    };
    auto register_callback(arg_ arg) { return register_callback(arg.first, arg.second); }
};
}  // namespace arg_parse_tools
#endif
