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
    str(s, s.regs.a, bus[to_uint16(a, b)]);
    // I am not sure is it is only lda that does this
    s.flags |=  flags::negative & s.regs.a;
    s.flags |=  flags::zero * (not s.regs.a);
}

inline auto ldx(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
   str(s, s.regs.x, bus[to_uint16(a, b)]);
}

inline auto ldy(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    str(s, s.regs.y, bus[to_uint16(a, b)]);
}

inline auto sta(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    str(s, bus[to_uint16(a, b)], s.regs.a);
}

inline auto stx(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    str(s, bus[to_uint16(a, b)], s.regs.x);
}

inline auto sty(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    bus[to_uint16(a, b)] = s.regs.y;
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

inline auto jmp(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    s.regs.pc = to_uint16(a, b) - 3;
}

inline auto beq(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    branch(s, (s.flags & flags::zero), a, b);
}

inline auto bne(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    branch(s, not (s.flags & flags::zero), a, b);
}

inline auto bcs(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    branch(s, (s.flags & flags::carry), a, b);
}

inline auto bmi(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    branch(s, (s.flags & flags::negative), a, b);
}


inline auto bpl(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    branch(s, not (s.flags & flags::negative), a, b);
}


inline auto bcc(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    branch(s, not (s.flags & flags::carry), a, b);
}

inline auto bvs(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    branch(s, (s.flags & flags::overflow), a, b);
}

inline auto bvc(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    branch(s, not (s.flags & flags::overflow), a, b);
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
}

inline auto clv(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    s.flags &= ~flags::overflow;
}

inline auto sec(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    s.flags |= flags::carry;
}

inline auto adc(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
   add(s, s.regs.a, bus[to_uint16(a, b)]);
}

inline auto sbc(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
   add(s, s.regs.a, -bus[to_uint16(a, b)]);
}

inline auto cmp(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    compare(s, s.regs.a, bus[to_uint16(a, b)]);
}

inline auto cpx(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    compare(s, s.regs.x, bus[to_uint16(a, b)]);
}

inline auto cpy(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    compare(s, s.regs.y, bus[to_uint16(a, b)]);
}


inline auto eor(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    s.regs.a ^= bus[to_uint16(a, b)];
    set_zero_flag(s, s.regs.a);
    set_negt_flag(s, s.regs.a);
}

inline auto ora(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    s.regs.a |= bus[to_uint16(a, b)];
    set_zero_flag(s, s.regs.a);
    set_negt_flag(s, s.regs.a);
}

inline auto anD(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    s.regs.a &= bus[to_uint16(a, b)];
    set_zero_flag(s, s.regs.a);
    set_negt_flag(s, s.regs.a);
}

inline auto bit(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    auto value = bus[to_uint16(a, b)];
    s.regs.a &= value;
    
    s.flags &= ~(flags::negative | flags::zero | flags::overflow);
    s.flags |=  (flags::negative | flags::overflow) & value;
    set_zero_flag(s, s.regs.a);
    
}

inline auto jsr(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    push(s, bus, uint16_t(s.regs.pc + 2));
    // need to remove tree since it will be added again
    s.regs.pc = to_uint16(a, b) - 3;
}

inline auto pha(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    push(s, bus, s.regs.a);
}

inline auto php(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    push(s, bus, s.flags);
}

inline auto pla(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    pull(s, bus, s.regs.a);
}

inline auto plp(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    pull(s, bus, s.flags);
}

inline auto rts(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    s.regs.sp += 2;
    s.regs.pc = to_uint16(bus[s.regs.sp], bus[s.regs.sp - 1]);
}

inline auto nop(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{

}

inline auto sei(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    s.flags |= flags::interrupt;
}

inline auto sed(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    s.flags |= flags::decimal;
}

inline auto cld(status& s, uint8_t* bus, uint8_t a, uint8_t b)
{
    s.flags &= ~flags::decimal;
}