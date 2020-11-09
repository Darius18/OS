#include <string>
#include <memory>
#include <iostream>
#include <algorithm>

#include <readline/readline.h>
#include <readline/history.h>

// clean up user input by deleting spaces from each end
inline std::string& trim(std::string& s, const char* t = " \t")
{
    s.erase(s.find_last_not_of(t) + 1);
    s.erase(0, s.find_first_not_of(t));
    return s;
}

// smart pointer to clean up memory
// allocated by readline

struct malloc_deleter
{
    template <class T>
    void operator()(T* p) { std::free(p); }
};

typedef std::unique_ptr<char, malloc_deleter> cstring_uptr;

int main()
{
    // this directory needs to exist beforehand
    const std::string config_dir = "/home/wibble/.prog";

    using_history();
    read_history((config_dir + "/.history").c_str());

    std::string shell_prompt = "> ";

    cstring_uptr input;
    std::string line, prev;

    input.reset(readline(shell_prompt.c_str()));

    // copy input into a std::string
    while(input && trim(line = input.get()) != "exit")
    {
        if(!line.empty())
        {
            // only add line to history if it is different
            // from previous line
            if(line != prev)
            {
                add_history(line.c_str());
                write_history((config_dir + "/.history").c_str());
                prev = line;
            }

            // process the input
            std::reverse(line.begin(), line.end());

            // give relevant output
            std::cout << "reply: " << line << '\n';

        }
        input.reset(readline(shell_prompt.c_str()));
    }
}