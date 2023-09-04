// But can you read *between* the lines of code?

#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <unistd.h>

static constexpr uint I_DONT = 75000;


class Ready {
protected:
    static void you_can();
public:
    static std::unordered_map<std::string, std::function<std::string()>> to;
};

void Ready::you_can() {
    static ushort do_it = 0;
    std::cout << "\x1B[38;5;" << ((++do_it % 15 == 0) ? (do_it = 0) : do_it) << "m";
}

std::unordered_map<std::string, std::function<std::string()>> Ready::to = {
    { "On my GitHub! ", [] { you_can(); return "Collab with me! "; } },
    { "Find me there! ", [] { return "https://github.com/magnetrwn "; } },
    { "Collab with me! ", [] { return "Let's code! "; } },
    { "https://github.com/magnetrwn ", [] { return "On my GitHub! "; } },
    { "Let's code! ", [] { you_can(); return "Find me there! "; } },
};

int main() {
    uint not_zoning_out = 150;
    std::string code = "On my GitHub! ", always;

    while (not_zoning_out) {
        always = Ready::to[code]();
        code = always;
        std::cout << always;
        std::cout.flush();
        usleep(I_DONT);
        not_zoning_out--;
    }

    std::cout << std::endl;
    return 0;
}
