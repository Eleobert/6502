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

inline void set_over_flag(status& s, uint8_t a, uint8_t b, uint8_t res)
{
    s.flags &= ~flags::overflow;
    if((a ^ res) & (b ^ res) & 0x80)
    {
        s.flags |= flags::overflow;
    }
}

inline void set_cary_flag(status& s, uint8_t lhs, uint8_t res)
{
    s.flags &= ~flags::carry;
    if(res < lhs)
    {
        s.flags |= flags::carry;
    }
}

inline void set_negt_flag(status& s, uint8_t value)
{
    s.flags &= ~flags::negative;
    s.flags |= flags::negative & value;
}

// increment
inline void add(status& s, uint8_t& value, uint8_t steps)
{
    uint8_t res = value + steps;
    set_over_flag(s, value, steps, res);
    set_zero_flag(s, res);
    set_negt_flag(s, res);
    set_cary_flag(s, value, res);
    value = res;
}

inline void inc(status& s, uint8_t& value, uint8_t steps)
{
    uint8_t res = value + steps;
    set_zero_flag(s, res);
    set_negt_flag(s, res);
    value = res;
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
    s.flags &= ~flags::carry; 

    if(dir == -1)
    {
        s.flags |= flags::carry & what;
        what <<= 1;
    }
    else if (dir == 1)
    {
        s.flags |= flags::carry & (what << 7);
        what >>= 1;
    }
    
    set_negt_flag(s, what);
    set_zero_flag(s, what);

}

inline auto cmp(status& s, uint8_t a, uint8_t b)
{
    auto lw = a < b;
    auto eq = a == b;

    using namespace flags;
    s.flags &= ~(negative | carry | zero);
    s.flags |=  (negative * lw) | (zero * eq) | (carry * (not lw));
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
