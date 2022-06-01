#include "types.hpp"
#include "utility.hpp"

#include <cstdint>
#include <cstdio>
#include <cstdlib>


inline auto noi(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    std::puts("not implemented\n");
    std::abort();
}

inline auto lda(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    str(s, s.regs.a, a);
}

inline auto sta(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    str(s, bus[to_uint16(a, b)], s.regs.a);
}

inline auto tax(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    str(s, s.regs.x, s.regs.a);
}

inline auto tay(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    str(s, s.regs.y, s.regs.a);
}

inline auto inx(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    inc(s, s.regs.x, +1);
}

inline auto iny(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    inc(s, s.regs.y, +1);
}

inline auto dex(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    inc(s, s.regs.x, -1);
}

inline auto dey(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    inc(s, s.regs.y, -1);
}


inline auto bne(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    const auto offset = static_cast<int8_t>(a);

    // jump if zero flag is clear
    if(not (s.flags & flags::zero))
    {
        inc(s, s.regs.pc, offset);
    }
}