#include "types.hpp"
#include "lookup.hpp"
#include "utility.hpp"

#include <fmt/core.h>
#include <fmt/ranges.h>

#include <ranges>
#include <span>
#include <cerrno>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <ios>
#include <string>
#include <tuple>
#include <thread>
#include <algorithm>
#include <vector>
#include <cstring>


// convert operands to the address of the actual operands
auto operands(uint8_t* bus, const status& s, mode m) -> std::tuple<uint8_t, uint8_t>
{
    // if this is the last instruction and we are in the last address
    // this breaks
    const auto pc = s.regs.pc;
    auto low = bus[pc + 1], hig = bus[pc + 2];

    if(m == modes::abiwx || m == modes::abiwy)
    {
        auto idx  = (m == modes::abiwx) ? s.regs.x: s.regs.y;
        auto addr = to_uint16(low, hig) + idx;
        std::tie(low, hig) = to_uint8(addr);
    }
    else if(m == modes::abslt) 
    {
    }
    else if(m == modes::zrpag)
    {

    } 
    else if(m == modes::immed)
    {
        // address will point to operands 
        std::tie(low, hig) = to_uint8(s.regs.pc + 1);
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

auto fmt_hexcode(uint16_t pc, uint8_t* bus)
{
    const auto opcode     = bus[pc];
    const auto [op, mode] = db[opcode];
    auto result = fmt::format("{:0X}", bus[pc]);
    
    const auto low = (mode.size > 1)? bus[pc + 1]: ' ';
    const auto hig = (mode.size > 2)? bus[pc + 2]: ' ';
    
    if(mode.size == 1)
    {
        return fmt::format("{:02X}      ", bus[pc]);
    }
    else if(mode.size == 2)
    {
        return fmt::format("{:02X} {:02X}   ", bus[pc], bus[pc + 1]);
    }
    else if(mode.size == 3)
    {
        return fmt::format("{:02X} {:02X} {:02X}", bus[pc], bus[pc + 1], bus[pc + 2]);
    }
    std::abort();
}


auto fmt_mmenoic(const status& s, uint8_t* bus)
{
    auto opcode     = bus[s.regs.pc];
    auto result     = names[opcode];
    auto [op, mode] = db[opcode];
    const auto low = bus[s.regs.pc + 1];
    const auto hig = bus[s.regs.pc + 2];
    
    if(mode == modes::immed || mode == modes::pcrlr)
    {
        result += fmt::format(" #{:02X}", low);
    }
    else if(mode == modes::abslt)
    {
        result += fmt::format(" #{:04X}", to_uint16(low, hig));
    }
    else if(mode == modes::abiwy)
    {
        result += fmt::format(" #{:04X},Y", to_uint16(low, hig));
    }
    else if(mode == modes::abiwx)
    {
        result += fmt::format(" #{:04X},X", to_uint16(low, hig));
    }
    return result;
}


auto read_file(const std::string& name)
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

auto fmt_stack(const status& s, const std::vector<uint8_t>& text)
{
    // fmt still does not support formatting range elements
    using namespace std::ranges::views;
    const auto size  = std::min(5, 0xff - s.regs.sp);
    const auto stack = std::span(&text[0xff - size + 1], size) | reverse;
    auto result = stack.empty()? "[": fmt::format("[{:02X}", stack.front());
    
    for(const auto& e: stack | drop(1))
    {
        result += fmt::format(" {:02X}", e);
    }
    return result + "]";
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


    fmt::print("{}: {:20} | {} | {}\n", "Addr", "Instruction", 
        "A  X  Y  SP NOUBDIZC", "Stack");

    while(true)
    {
        using namespace std::ranges::views;
        
        const auto hex = fmt_hexcode(s.regs.pc, text.data());
        const auto mmc = fmt_mmenoic(s, text.data());
        const auto rgs = fmt::format("{:02X} {:02X} {:02X} {:02X} {:08b}",  
            s.regs.a, s.regs.x, s.regs.y, s.regs.sp, s.flags);
        const auto stk = fmt_stack(s, text);

        fmt::print("{:04X}: {} {:11} | {} | {}\n", s.regs.pc, hex, mmc, rgs, stk);
        
        std::tie(s, ncycles) = run(s, text.data());
        // std::this_thread::sleep_for(0.0s * ncycles);
    }
}
