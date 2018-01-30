#include "arch.h"
#include "ecp_NUMS512E.h"

/*  NUMS 512-bit Curve - Edwards */

#if CHUNK==16

#error Not supported

#endif

#if CHUNK==32
const int CURVE_A_NUMS512E= 1;
const int CURVE_B_I_NUMS512E= -78296;
const BIG_512_29 CURVE_B_NUMS512E= {0x1FFECBEF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x7FFFF};
const BIG_512_29 CURVE_Order_NUMS512E= {0x1BEED46D,0x1A3467A8,0x1BFB3FD9,0xC0AF0DB,0x86F52A4,0xC64B85B,0x6EA78FF,0xDA5F9F2,0x1FB4F063,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFF};
const BIG_512_29 CURVE_Gx_NUMS512E= {0x19EC57FE,0xDCD594C,0x113C0571,0xA4A84F9,0x104AD0FE,0x4C92B44,0xC3DE2F7,0x9DDC8CE,0x74621C1,0x1139DC0A,0x9E85FAF,0x1B894704,0x1D1E79F4,0x9E29997,0x32DE223,0x16D38F43,0x116D128D,0x6FC71};
const BIG_512_29 CURVE_Gy_NUMS512E= {0x1E2F5E1,0x136EF606,0x1C7407CC,0xDA71537,0xC1FD026,0x3431576,0x15898068,0x1E5D32C6,0x120CA53,0xC84F41A,0xA4ADAE5,0x104B3A45,0x76F726D,0x1512B772,0x3D5DEA0,0x194E3316,0x1FF39D49,0x3684D};
#endif

#if CHUNK==64
const int CURVE_A_NUMS512E= 1;
const int CURVE_B_I_NUMS512E= -78296;
const BIG_512_56 CURVE_B_NUMS512E= {0xFFFFFFFFFECBEFL,0xFFFFFFFFFFFFFFL,0xFFFFFFFFFFFFFFL,0xFFFFFFFFFFFFFFL,0xFFFFFFFFFFFFFFL,0xFFFFFFFFFFFFFFL,0xFFFFFFFFFFFFFFL,0xFFFFFFFFFFFFFFL,0xFFFFFFFFFFFFFFL,0xFFL};
const BIG_512_56 CURVE_Order_NUMS512E= {0x468CF51BEED46DL,0x5786DEFECFF67L,0xC970B686F52A46L,0x2FCF91BA9E3FD8L,0xFFFFFFB4F0636DL,0xFFFFFFFFFFFFFFL,0xFFFFFFFFFFFFFFL,0xFFFFFFFFFFFFFFL,0xFFFFFFFFFFFFFFL,0x3FL};
const BIG_512_56 CURVE_Gx_NUMS512E= {0xB9AB2999EC57FEL,0x25427CC4F015C5L,0x92568904AD0FE5L,0xEE46730F78BDC9L,0x3B81474621C14EL,0xA38227A17EBE27L,0x332FD1E79F4DC4L,0x7A18CB7888D3C5L,0x8E316D128DB69CL,0xDFL};
const BIG_512_56 CURVE_Gy_NUMS512E= {0x6DDEC0C1E2F5E1L,0xD38A9BF1D01F32L,0x862AECC1FD0266L,0xE9963562601A06L,0x9E834120CA53F2L,0x9D22A92B6B9590L,0x6EE476F726D825L,0x98B0F577A82A25L,0x9BFF39D49CA71L,0x6DL};
#endif
