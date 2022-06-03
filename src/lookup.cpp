
#include "types.hpp"
#include "ops.hpp"

#include <string>
#include <vector>

using namespace modes;

std::vector<entry> db = 
{
//     0             1             2             3             4             5             6             7             8             9             a             b             c             d             e             f
/*0*/ {noi, impld}, {ora, zpiwx}, {noi, impld}, {noi, impld}, {noi, impld}, {ora, zrpag}, {noi, impld}, {noi, impld}, {php, stack}, {ora, immed}, {asl, accum}, {noi, impld}, {noi, impld}, {ora, abslt}, {noi, impld}, {noi, impld}, // 16
/*1*/ {bpl, pcrlr}, {ora, zpsiy}, {noi, impld}, {noi, impld}, {noi, impld}, {ora, zpiwx}, {noi, impld}, {noi, impld}, {clc, impld}, {ora, abiwy}, {noi, impld}, {noi, impld}, {noi, impld}, {ora, abiwx}, {noi, impld}, {noi, impld}, // 32
/*2*/ {jsr, abslt}, {anD, zpiss}, {noi, impld}, {noi, impld}, {bit, zrpag}, {anD, zrpag}, {noi, impld}, {noi, impld}, {plp, impld}, {anD, immed}, {noi, impld}, {noi, impld}, {noi, impld}, {anD, abslt}, {noi, impld}, {noi, impld}, // 48
/*3*/ {bmi, pcrlr}, {anD, zpsiy}, {noi, impld}, {noi, impld}, {noi, impld}, {anD, zpiwx}, {noi, impld}, {noi, impld}, {sec, impld}, {anD, abiwy}, {noi, impld}, {noi, impld}, {noi, impld}, {anD, abiwx}, {noi, impld}, {noi, impld}, // 64
/*4*/ {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {pha, impld}, {eor, immed}, {lar, accum}, {noi, impld}, {jmp, abslt}, {noi, impld}, {noi, impld}, {noi, impld}, // 80
/*5*/ {bvc, pcrlr}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, // 96
/*6*/ {rts, stack}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {adc, zrpag}, {noi, impld}, {noi, impld}, {pla, stack}, {adc, immed}, {noi, impld}, {noi, impld}, {noi, impld}, {adc, abslt}, {noi, impld}, {noi, impld}, //112
/*7*/ {bvs, pcrlr}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {sei, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {adc, abiwx}, {noi, impld}, {noi, impld}, //128
/*8*/ {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {sty, zrpag}, {sta, zrpag}, {stx, zrpag}, {noi, impld}, {dey, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {sta, abslt}, {noi, impld}, {noi, impld}, //144
/*9*/ {bcc, pcrlr}, {sta, zpsiy}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {tya, impld}, {sta, abiwy}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, //160
/*a*/ {ldy, immed}, {noi, impld}, {ldx, immed}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {tay, impld}, {lda, immed}, {tax, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, //176
/*b*/ {bcs, pcrlr}, {lda, zpsiy}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {clv, immed}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, //192
/*c*/ {cpy, immed}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {iny, impld}, {cmp, immed}, {dex, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, //208
/*d*/ {bne, pcrlr}, {cmp, zpsiy}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {cld, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, //224
/*e*/ {cpx, immed}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {sbc, zrpag}, {noi, impld}, {noi, impld}, {inx, impld}, {noi, impld}, {nop, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, //240
/*f*/ {beq, pcrlr}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {sed, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, //256
};


std::vector<std::string> names = 
{
//     0      1      2      3      4      5      6      7      8      9      a      b      c      d      e      f
/*0*/ "noi", "ora", "noi", "noi", "noi", "ora", "noi", "noi", "php", "ora", "asl", "noi", "noi", "ora", "noi", "noi", // 16
/*1*/ "bpl", "ora", "noi", "noi", "noi", "ora", "noi", "noi", "clc", "ora", "noi", "noi", "noi", "ora", "noi", "noi", // 32
/*2*/ "jsr", "and", "noi", "noi", "bit", "and", "noi", "noi", "plp", "and", "noi", "noi", "noi", "anD", "noi", "noi", // 48
/*3*/ "bmi", "and", "noi", "noi", "noi", "and", "noi", "noi", "sec", "and", "noi", "noi", "noi", "and", "noi", "noi", // 64
/*4*/ "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "pha", "eor", "lsr", "noi", "jmp", "noi", "noi", "noi", // 80
/*5*/ "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", // 96
/*6*/ "rts", "noi", "noi", "noi", "noi", "adc", "noi", "noi", "pla", "adc", "noi", "noi", "noi", "adc", "noi", "noi", //112
/*7*/ "bvs", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "sei", "noi", "noi", "noi", "noi", "adc", "noi", "noi", //128
/*8*/ "noi", "noi", "noi", "noi", "sty", "sta", "stx", "noi", "dey", "noi", "noi", "noi", "noi", "sta", "noi", "noi", //144
/*9*/ "bcc", "sta", "noi", "noi", "noi", "noi", "noi", "noi", "tya", "sta", "noi", "noi", "noi", "noi", "noi", "noi", //160
/*a*/ "ldy", "noi", "ldx", "noi", "noi", "noi", "noi", "noi", "tay", "lda", "tax", "noi", "noi", "noi", "noi", "noi", //176
/*b*/ "bcs", "lda", "noi", "noi", "noi", "noi", "noi", "noi", "clv", "noi", "noi", "noi", "noi", "noi", "noi", "noi", //192
/*c*/ "cpy", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "iny", "cmp", "dex", "noi", "noi", "noi", "noi", "noi", //208
/*d*/ "bne", "cmp", "noi", "noi", "noi", "noi", "noi", "noi", "cld", "noi", "noi", "noi", "noi", "noi", "noi", "noi", //224
/*e*/ "cpx", "noi", "noi", "noi", "noi", "sbc", "noi", "noi", "inx", "noi", "nop", "noi", "noi", "noi", "noi", "noi", //240
/*f*/ "beq", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "sed", "noi", "noi", "noi", "noi", "noi", "noi", "noi"  //256
};