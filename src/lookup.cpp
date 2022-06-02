
#include "types.hpp"
#include "ops.hpp"

#include <string>
#include <vector>

using namespace modes;

std::vector<entry> db = 
{
//     0             1             2             3             4             5             6             7             8             9             a             b             c             d             e             f
/*0*/ {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {asl, accum}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, // 16
/*1*/ {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {clc, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, // 32
/*2*/ {jsr, abslt}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, // 48
/*3*/ {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, // 64
/*4*/ {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {eor, immed}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, // 80
/*5*/ {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, // 96
/*6*/ {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {adc, immed}, {noi, impld}, {noi, impld}, {noi, impld}, {adc, abslt}, {noi, impld}, {noi, impld}, //112
/*7*/ {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {adc, abiwx}, {noi, impld}, {noi, impld}, //128
/*8*/ {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {sta, zrpag}, {noi, impld}, {noi, impld}, {dey, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {sta, abslt}, {noi, impld}, {noi, impld}, //144
/*9*/ {bcc, pcrlr}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {tya, impld}, {sta, abiwy}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, //160
/*a*/ {ldy, immed}, {noi, impld}, {ldx, immed}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {tay, impld}, {lda, immed}, {tax, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, //176
/*b*/ {bcs, pcrlr}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, //192
/*c*/ {cpy, immed}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {iny, impld}, {noi, impld}, {dex, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, //208
/*d*/ {bne, pcrlr}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, //224
/*e*/ {cpx, immed}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {inx, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, //240
/*f*/ {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, {noi, impld}, //256
};


std::vector<std::string> names = 
{
//     0             1             2             3             4             5             6             7             8             9             a             b             c             d             e             f
/*0*/ "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "asl", "noi", "noi", "noi", "noi", "noi", // 16
/*1*/ "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "clc", "noi", "noi", "noi", "noi", "noi", "noi", "noi", // 32
/*2*/ "jsr", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", // 48
/*3*/ "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", // 64
/*4*/ "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "eor", "noi", "noi", "noi", "noi", "noi", "noi", // 80
/*5*/ "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", // 96
/*6*/ "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "adc", "noi", "noi", "noi", "adc", "noi", "noi", //112
/*7*/ "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "adc", "noi", "noi", //128
/*8*/ "noi", "noi", "noi", "noi", "noi", "sta", "noi", "noi", "dey", "noi", "noi", "noi", "noi", "sta", "noi", "noi", //144
/*9*/ "bcc", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "tya", "sta", "noi", "noi", "noi", "noi", "noi", "noi", //160
/*a*/ "ldy", "noi", "ldx", "noi", "noi", "noi", "noi", "noi", "tay", "lda", "tax", "noi", "noi", "noi", "noi", "noi", //176
/*b*/ "bcs", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", //192
/*c*/ "cpy", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "iny", "noi", "dex", "noi", "noi", "noi", "noi", "noi", //208
/*d*/ "bne", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", //224
/*e*/ "cpx", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "inx", "noi", "noi", "noi", "noi", "noi", "noi", "noi", //240
/*f*/ "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi", "noi"  //256
};