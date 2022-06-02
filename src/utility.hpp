#include <cstdint>
#include <tuple>
#include "types.hpp"

inline auto to_uint16(uint8_t low, uint8_t hig) -> uint16_t
{
    auto tmp = static_cast<uint16_t>(hig);
    return low + (tmp << 8);
}

inline auto to_uint8(uint16_t value) -> std::tuple<uint8_t, uint8_t>
{
    auto low = static_cast<uint16_t>(value & 0x00ff);
    auto hig = static_cast<uint16_t>(value & 0xff00) >> 8;

    return {low, hig};
}

inline void set_zero_flag(status& s, uint8_t value)
{
    if(not value)
    {
        s.flags = s.flags | flags::zero;
    }
    else 
    {
        s.flags = s.flags & (~flags::zero);
    }
}

inline void set_negative_flag(status& s, uint8_t value)
{
    s.flags |= flags::negative & value;
}

// increment
inline void inc(status& s, uint8_t& value, int steps)
{
    value += steps;
    set_zero_flag(s, value);
}

inline void inc(status& s, uint16_t& value, int steps)
{
    value += steps;
    set_zero_flag(s, value);
}

// store
inline void str(status& s, uint8_t& to, uint8_t from)
{
    to = from;
    set_zero_flag(s, to);
}

// shift and set the cary flag
inline void shift(status& s, uint8_t& what, int dir)
{
    if(dir == -1)
    {
        s.flags = (s.flags &  0b01111111) | (what & 0b10000000);
        what <<= 1;
    }
    else if (dir == 1)
    {
        s.flags = (s.flags &  0b11111110) | (what & 0b00000001);
        what >>= 1;
    }
}

inline auto cmp(status& s, uint8_t a, uint8_t b)
{
    auto lw = a < b;
    auto eq = a == b;

    using namespace flags;
    s.flags &= ~(negative | carry | zero);
    s.flags |= negative * (not (lw || eq)) | (zero * eq) | (carry * (not lw));
}


inline auto push(status& s, uint8_t* bus, uint8_t value)
{
    bus[s.regs.sp] = value;
    s.regs.sp--;
}

inline auto push(status& s, uint8_t* bus, uint16_t value)
{
    auto [addr_low, addr_hig] = to_uint8(value);
    
    push(s, bus, addr_low);
    push(s, bus, addr_hig);
}
