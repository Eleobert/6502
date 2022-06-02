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
    s.regs.a = bus[to_uint16(a, b)];
}

inline auto ldx(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
   s.regs.x = bus[to_uint16(a, b)];
}

inline auto ldy(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
   s.regs.y = bus[to_uint16(a, b)];
}

inline auto sta(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    bus[to_uint16(a, b)] = s.regs.a;
}

inline auto tax(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    s.regs.x = s.regs.a;
}

inline auto tay(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    s.regs.y = s.regs.a;
}

inline auto tya(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    s.regs.a = s.regs.y;
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
    s.regs.pc = not (s.flags & flags::zero)? to_uint16(a, b): s.regs.pc;
}

inline auto bcs(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    const auto offset = static_cast<int8_t>(a);

    s.regs.pc = (s.flags & flags::carry)? to_uint16(a, b): s.regs.pc;
}


inline auto asl(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    shift(s, s.regs.a, -1);
}

// lsr with accumulator
inline auto lar(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    shift(s, s.regs.a, 1);
}

inline auto clc(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    s.flags &= ~flags::carry;
    // does it set zero flag??
}

inline auto adc(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
   add(s, s.regs.a, bus[to_uint16(a, b)]);
}

inline auto sbc(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
   add(s, s.regs.a, -bus[to_uint16(a, b)]);
}


inline auto cpx(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    cmp(s, s.regs.x, bus[to_uint16(a, b)]);
}

inline auto cpy(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    cmp(s, s.regs.y, bus[to_uint16(a, b)]);
}


inline auto eor(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    s.regs.a ^= bus[to_uint16(a, b)];
    set_zero_flag(s, s.regs.a);
    set_negt_flag(s, s.regs.a);
}

inline auto jsr(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    push(s, bus, uint16_t(s.regs.pc + 2));
    // need to remove tree since it will be added again
    s.regs.pc = to_uint16(a, b) - 3;
}

inline auto bcc(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    s.regs.pc = not (s.flags & flags::carry)? to_uint16(a, b): s.regs.pc;
}

inline auto rts(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    s.regs.sp += 2;
    s.regs.pc = to_uint16(bus[s.regs.sp], bus[s.regs.sp - 1]);
}