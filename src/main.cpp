#include "types.hpp"
#include "lookup.hpp"
#include "utility.hpp"

#include <cerrno>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <ios>
#include <sys/types.h>
#include <tuple>
#include <thread>
#include <algorithm>
#include <vector>
#include <cstring>


auto print_flags(uint8_t flags)
{
    uint8_t f = 0b10000000;

    for(auto i = 0; i < 8; i++)
    {
        char c = (flags & f) ? '1': '0';
        std::putchar(c);
        flags = flags << 1;
    }
}


auto print_status(const status& s, uint8_t* bus)
{
    print_flags(s.flags);
    printf("\nA:%x\tX:%x\tY:%x\tpc:%x\nop:%x\n\n", s.regs.a, s.regs.x, s.regs.y, 
           s.regs.pc, bus[s.regs.pc]);
}


auto operands(uint8_t* bus, const status& s, mode m) -> std::tuple<uint8_t, uint8_t>
{
    // if this is the last instruction and we are in the last address
    // this breaks
    const auto pc = s.regs.pc;
    auto low = bus[pc + 1], hig = bus[pc + 2];

    if(m == modes::abiwy)
    {
        auto addr = to_uint16(low, hig) + s.regs.y;
        std::tie(low, hig) = to_uint8(addr);
    }
    else if(m == modes::pcrlr)
    {
        // TODO: should I solve the aaddres here too?
        //const auto offset = static_cast<int8_t>(low);
    }

    return {low, hig};
}

auto run(status s, uint8_t* bus) -> std::tuple<status, uint8_t>
{
    const auto opcode = bus[s.regs.pc];
    const auto pc     = s.regs.pc;

    auto [op, mode] = db[opcode];
    auto p = operands(bus, s, mode);
    auto [a, b] = p;

    op(s, bus, a, b);

    // do not advance if operation updated the program counter!!
    // s.regs.pc = (pc == s.regs.pc)? pc + mode.size: s.regs.pc;
    s.regs.pc += mode.size;

    return {s, mode.cycles};

}


static auto read_file(const std::string& name)
{
    std::ifstream ifs(name, std::ios::binary | std::ios::ate);

    if(not ifs.good())
    {
        std::fprintf(stderr, "%s: %s\n", name.c_str(), std::strerror(errno));
        std::exit(errno);
    }

    auto pos = ifs.tellg();

    auto result = std::vector<uint8_t>(pos);
    auto* ptr = reinterpret_cast<char*>(result.data());

    ifs.seekg(0, std::ios::beg);
    ifs.read(ptr, pos);

    return result;
}

int main(int argc, char** argv)
{
    using namespace std::literals;

    if(argc != 1)
    {
        std::fprintf(stdin, "run <input file>");
    } 

    auto text = read_file(argv[1]);
    text.resize(0xffff, 0xff);

    auto s       = status();
    auto ncycles = 0;

    print_status(s, text.data());
    
    while(true)
    {
        std::tie(s, ncycles) = run(s, text.data());
        print_status(s, text.data());
        std::this_thread::sleep_for(0.1s * ncycles);
    }
}
