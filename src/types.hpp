#pragma once

#include <cstdint>


struct mode
{
    uint8_t code;     // mode unique identifier
    uint8_t cycles; // default number of clock cycles
    uint8_t size;     // instrucion size (1, 2, or 3)
    bool operator==(const mode&) const = default;
};



namespace modes
{
    constexpr mode absla = { 1, 4, 3}; // absolute a
    constexpr mode abiwx = { 3, 4, 3}; // absolute indexed with X a,x
    constexpr mode abiwy = { 4, 4, 3}; // absolute indexed with Y a,y
    constexpr mode abind = { 5, 6, 3}; // absolute indirect (a)
    constexpr mode accua = { 6, 2, 1}; // accumulator A
    constexpr mode immed = { 7, 2, 2}; // immidiate #
    constexpr mode impld = { 8, 2, 1}; // implied i
    constexpr mode pcrlr = { 9, 2, 2}; // program counter relative r
    constexpr mode stcks = {10, 3, 1}; // stack s
    constexpr mode zrpag = {11, 3, 2}; // zero page zp
    constexpr mode zpiss = {12, 6, 2}; // zero page indexed indirect
    constexpr mode zpiwx = {13, 4, 2}; // zero page indexed with X zp, x 
    constexpr mode zpiwy = {14, 4, 2}; // zero page indexed with Y zp, y
    constexpr mode zpsiy = {16, 5, 2}; // zero page indirect indexed with Y (zp), y
};

namespace flags
{
    constexpr uint8_t carry    = 1 << 0;
    constexpr uint8_t zero     = 1 << 1;
    constexpr uint8_t iqrdis   = 1 << 2;
    constexpr uint8_t dec      = 1 << 3;
    constexpr uint8_t brk      = 1 << 4;
    constexpr uint8_t empty    = 1 << 5;
    constexpr uint8_t overflow = 1 << 6;
    constexpr uint8_t negative = 1 << 7;
};

struct registers
{
    uint8_t  a;
    uint8_t  x;
    uint8_t  y;
    uint8_t  sp;
    uint8_t  status;
    uint16_t pc = 0;
};

struct status
{
    uint8_t   flags = 0;
    registers regs;
};


using operation = void (*)(status& s, uint8_t* bus, uint8_t a, uint8_t b);

struct entry
{
    operation op;
    mode m;
};
