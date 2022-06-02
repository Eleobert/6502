#include "types.hpp"
#include "lookup.hpp"
#include "utility.hpp"


// TODO: pass pointers instead of low and high, if passing
// a value is needed point to a 'static' variable to hold the
// value. This is to avoid having 2 functions for the same
// opcode, as for example lsr which can operate on accumulator
// or operand
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
        hig = 0;
    }
    else if(m == modes::immed)
    {
        // address will point to operands
        std::tie(low, hig) = to_uint8(s.regs.pc + 1);
    }
    else if(m == modes::pcrlr)
    {
        // cannot simply clear `hig`: need to taake into
        // conasideration the signal
        uint16_t adr_neg = s.regs.pc + int8_t(low);
        std::tie(low, hig) = to_uint8(adr_neg);
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
