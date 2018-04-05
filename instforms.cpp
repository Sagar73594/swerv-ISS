#include <assert.h>
#include "instforms.hpp"

using namespace WdRiscv;

bool
RFormInst::encodeAdd(unsigned rdv, unsigned rs1v, unsigned rs2v)
{
  if (rdv > 31 or rs1v > 31 or rs2v > 31)
    return false;
  opcode = 0x33;
  rd = rdv;
  funct3 = 0;
  rs1 = rs1v;
  rs2 = rs2v;
  funct7 = 0;
  return true;
}


bool
RFormInst::encodeSub(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeAdd(rd, rs1, rs2))
    return false;
  funct7 = 0x20;
  return true;
}


bool
RFormInst::encodeSll(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeAdd(rd, rs1, rs2))
    return false;
  funct3 = 0x1;
  return true;
}


bool
RFormInst::encodeSlt(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeAdd(rd, rs1, rs2))
    return false;
  funct3 = 0x2;
  return true;
}


bool
RFormInst::encodeSltu(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeAdd(rd, rs1, rs2))
    return false;
  funct3 = 0x3;
  return true;
}


bool
RFormInst::encodeXor(unsigned rdv, unsigned rs1v, unsigned rs2v)
{
  if (not encodeAdd(rdv, rs1v, rs2v))
    return false;
  funct3 = 4;
  return true;
}


bool
RFormInst::encodeSrl(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeAdd(rd, rs1, rs2))
    return false;
  funct3 = 5;
  return true;
}


bool
RFormInst::encodeSra(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeAdd(rd, rs1, rs2))
    return false;
  funct7 = 0x20;
  funct3 = 5;
  return true;
}


bool
RFormInst::encodeOr(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeAdd(rd, rs1, rs2))
    return false;
  funct3 = 0x6;
  return true;
}


bool
RFormInst::encodeAnd(unsigned rdv, unsigned rs1v, unsigned rs2v)
{
  if (not encodeAdd(rdv, rs1v, rs2v))
    return false;
  funct3 = 7;
  return true;
}


bool
RFormInst::encodeAddw(unsigned rdv, unsigned rs1v, unsigned rs2v)
{
  opcode = 0x3b;
  rd = rdv;
  funct3 = 0;
  rs1 = rs1v;
  rs2 = rs2v;
  funct7 = 0;
  return true;
}


bool
RFormInst::encodeSubw(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeAddw(rd, rs1, rs2))
    return false;
  funct7 = 0x20;
  return true;
}


bool
RFormInst::encodeSllw(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeAddw(rd, rs1, rs2))
    return false;
  funct3 = 1;
  return true;
}


bool
RFormInst::encodeSrlw(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeAddw(rd, rs1, rs2))
    return false;
  funct3 = 5;
  return true;
}


bool
RFormInst::encodeSraw(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeAddw(rd, rs1, rs2))
    return false;
  funct3 = 5;
  funct7 = 0x20;
  return true;
}


bool
RFormInst::encodeMul(unsigned rdv, unsigned rs1v, unsigned rs2v)
{
  opcode = 0x33;
  rd = rdv;
  funct3 = 0;
  rs1 = rs1v;
  rs2 = rs2v;
  funct7 = 0x01;
  return true;
}


bool
RFormInst::encodeMulh(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeMul(rd, rs1, rs2))
    return false;
  funct3 = 1;
  return true;
}


bool
RFormInst::encodeMulhsu(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeMul(rd, rs1, rs2))
    return false;
  funct3 = 2;
  return true;
}


bool
RFormInst::encodeMulhu(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeMul(rd, rs1, rs2))
    return false;
  funct3 = 3;
  return true;
}


bool
RFormInst::encodeDiv(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeMul(rd, rs1, rs2))
    return false;
  funct3 = 4;
  return true;
}


bool
RFormInst::encodeDivu(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeMul(rd, rs1, rs2))
    return false;
  funct3 = 5;
  return true;
}


bool
RFormInst::encodeRem(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeMul(rd, rs1, rs2))
    return false;
  funct3 = 6;
  return true;
}


bool
RFormInst::encodeRemu(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeMul(rd, rs1, rs2))
    return false;
  funct3 = 7;
  return true;
}


bool
RFormInst::encodeMulw(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeAddw(rd, rs1, rs2))
    return false;
  funct3 = 0;
  funct7 = 1;
  return true;
}


bool
RFormInst::encodeDivw(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeMulw(rd, rs1, rs2))
    return false;
  funct3 = 4;
  return true;
}


bool
RFormInst::encodeDivuw(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeMulw(rd, rs1, rs2))
    return false;
  funct3 = 5;
  return true;
}


bool
RFormInst::encodeRemw(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeMulw(rd, rs1, rs2))
    return false;
  funct3 = 6;
  return true;
}


bool
RFormInst::encodeRemuw(unsigned rd, unsigned rs1, unsigned rs2)
{
  if (not encodeMulw(rd, rs1, rs2))
    return false;
  funct3 = 7;
  return true;
}


bool
BFormInst::encodeBeq(unsigned rs1v, unsigned rs2v, int imm)
{
  if (imm & 0x1)
    return false;  // Least sig bit must be 0.

  if (rs1 > 31 or rs2 > 31)
    return false;  // Register(s) out of bound.

  if (imm >= (1 << 12) or imm < (-1 << 12))
    return false;  // Immediate must fit in 13 bits.

  opcode = 0x63;
  imm11 = (imm >> 11) & 1;
  imm4_1 = (imm >> 1) & 0xf;
  imm10_5 = (imm >> 5) & 0x3f;
  imm12 = (imm >> 12) & 0x1;
  funct3 = 0;
  rs1 = rs1v;
  rs2 = rs2v;
  return true;
}


bool
BFormInst::encodeBne(unsigned rs1, unsigned rs2, int imm)
{
  if (not encodeBeq(rs1, rs2, imm))
    return false;
  funct3 = 1;
  return true;
}


bool
BFormInst::encodeBlt(unsigned rs1, unsigned rs2, int imm)
{
  if (not encodeBeq(rs1, rs2, imm))
    return false;
  funct3 = 4;
  return true;
}


bool
BFormInst::encodeBge(unsigned rs1, unsigned rs2, int imm)
{
  if (not encodeBeq(rs1, rs2, imm))
    return false;
  funct3 = 5;
  return true;
}


bool
BFormInst::encodeBltu(unsigned rs1, unsigned rs2, int imm)
{
  if (not encodeBeq(rs1, rs2, imm))
    return false;
  funct3 = 6;
  return true;
}


bool
BFormInst::encodeBgeu(unsigned rs1, unsigned rs2, int imm)
{
  if (not encodeBeq(rs1, rs2, imm))
    return false;
  funct3 = 7;
  return true;
}


bool
IFormInst::encodeAddi(unsigned rdv, unsigned rs1v, int imm)
{
  if (rdv > 32 or rs1v > 32)
    return false;

  if (imm > (1 << 11) or imm < (-1 << 11))
    return false;

  fields.opcode = 0x13;
  fields.rd = rdv;
  fields.funct3 = 0;
  fields.rs1 = rs1v;
  fields.imm = imm;
  return true;
}


bool
IFormInst::encodeAndi(unsigned rdv, unsigned rs1v, int imm)
{
  if (not encodeAddi(rdv, rs1v, imm))
    return false;
  fields.funct3 = 7;
  return true;
}


bool
IFormInst::encodeEbreak()
{
  fields.opcode = 0x73;
  fields.rd = 0;
  fields.funct3 = 0;
  fields.rs1 = 0;
  fields.imm = 1;
  return true;
}


bool
IFormInst::encodeEcall()
{
  fields.opcode = 0x73;
  fields.rd = 0;
  fields.funct3 = 0;
  fields.rs1 = 0;
  fields.imm = 0;
  return true;
}


bool
IFormInst::encodeJalr(unsigned rdv, unsigned rs1v, int offset)
{
  if (rdv > 31 or rs1v > 31)
    return false;  // Register(s) out of bounds.

  if (offset >= (1<<11) or offset < (-1 << 11))
    return false;  // Offset out of bounds.

  fields.opcode = 0x67;
  fields.rd = rdv;
  fields.funct3 = 0;
  fields.rs1 = rs1v;
  fields.imm = offset;
  return true;
}


bool
IFormInst::encodeLb(unsigned rdv, unsigned rs1v, int offset)
{
  if (rdv > 31 or rs1v > 31)
    return false;  // Register(s) out of bounds.

  if (offset >= (1<<11) or offset < (-1 << 11))
    return false;  // Offset out of bounds.

 fields.opcode = 0x03;
 fields.rd = rdv;
 fields.funct3 = 0;
 fields.rs1 = rs1v;
 fields.imm = offset;
 return true;
}

bool
IFormInst::encodeLh(unsigned rd, unsigned rs1, int offset)
{
  if (not encodeLb(rd, rs1, offset))
    return false;
  fields.funct3 = 1;
  return true;
}


bool
IFormInst::encodeLw(unsigned rd, unsigned rs1, int offset)
{
  if (not encodeLb(rd, rs1, offset))
    return false;
  fields.funct3 = 2;
  return true;
}


bool
IFormInst::encodeLbu(unsigned rd, unsigned rs1, int offset)
{
  if (not encodeLb(rd, rs1, offset))
    return false;
  fields.funct3 = 4;
  return true;
}


bool
IFormInst::encodeLhu(unsigned rd, unsigned rs1, int offset)
{
  if (not encodeLb(rd, rs1, offset))
    return false;
  fields.funct3 = 5;
  return true;
}


bool
IFormInst::encodeLwu(unsigned rd, unsigned rs1, int offset)
{
  if (not encodeLb(rd, rs1, offset))
    return false;
  fields.funct3 = 6;
  return true;
}


bool
IFormInst::encodeLd(unsigned rd, unsigned rs1, int offset)
{
  if (not encodeLb(rd, rs1, offset))
    return false;
  fields.funct3 = 3;
  return true;
}


bool
IFormInst::encodeSlli(unsigned rd, unsigned rs1, unsigned shamt)
{
  if (rd > 31 or rs1 > 31)
    return false;  // Register(s) out of bounds.

  if (shamt > 31)
    return false;  // Shift amount out ofbounds.

  fields2.opcode = 0x13;
  fields2.rd = rd;
  fields2.funct3 = 1;
  fields2.rs1 = rs1;
  fields2.shamt = shamt;
  fields2.top7 = 0;
  return true;
}


bool
IFormInst::encodeSrli(unsigned rd, unsigned rs1, unsigned shamt)
{
  if (not encodeSlli(rd, rs1, shamt))
    return false;
  fields2.funct3 = 5;
  return true;
}


bool
IFormInst::encodeSrai(unsigned rd, unsigned rs1, unsigned shamt)
{
  if (not encodeSlli(rd, rs1, shamt))
    return false;
  fields2.funct3 = 5;
  fields2.top7 = 0x20;
  return true;
}


bool
IFormInst::encodeSlti(unsigned rd, unsigned rs1, int imm)
{
  if (not encodeAddi(rd, rs1, imm))
    return false;
  fields.funct3 = 2;
  return true;
}


bool
IFormInst::encodeSltiu(unsigned rd, unsigned rs1, int imm)
{
  if (not encodeAddi(rd, rs1, imm))
    return false;
  fields.funct3 = 3;
  return true;
}


bool
IFormInst::encodeXori(unsigned rd, unsigned rs1, int imm)
{
  if (not encodeAddi(rd, rs1, imm))
    return false;
  fields.funct3 = 4;
  return true;
}


bool
IFormInst::encodeOri(unsigned rd, unsigned rs1, int imm)
{
  if (not encodeAddi(rd, rs1, imm))
    return false;
  fields.funct3 = 6;
  return true;
}


bool
IFormInst::encodeAddiw(unsigned rd, unsigned rs1, int imm)
{
  if (not encodeAddi(rd, rs1, imm))
    return false;
  fields.opcode = 0x033;
  fields.funct3 = 0;
  return true;
}


bool
IFormInst::encodeSlliw(unsigned rd, unsigned rs1, unsigned shamt)
{
  if (rd > 31 or rs1 > 31)
    return false;  // Register(s) out of bounds.

  if (shamt > 63)
    return false;  // Shift amount out ofbounds.

  fields2.opcode = 0x033;
  fields2.rd = rd;
  fields2.funct3 = 1;
  fields2.rs1 = rs1;
  fields2.shamt = shamt;
  fields2.top7 = 0;
  return true;
}


bool
IFormInst::encodeSrliw(unsigned rd, unsigned rs1, unsigned shamt)
{
  if (not encodeSlliw(rd, rs1, shamt))
    return false;
  fields2.funct3 = 5;
  return true;
}


bool
IFormInst::encodeSraiw(unsigned rd, unsigned rs1, unsigned shamt)
{
  if (not encodeSlliw(rd, rs1, shamt))
    return false;
  fields2.funct3 = 5;
  fields2.top7 = 0x20;
  return true;
}


bool
IFormInst::encodeFencei()
{
  fields.opcode = 0x0f;
  fields.rd = 0;
  fields.funct3 = 1;
  fields.rs1 = 0;
  fields.imm = 0;
  return true;
}


bool
IFormInst::encodeFence(uint32_t pred, uint32_t succ)
{
  if (pred > 0xf or succ > 0xf)
    return false;

  fields.opcode = 0x0f;
  fields.rd = 0;
  fields.funct3 = 0;
  fields.rs1 = 0;

  fields.imm = (pred << 4) | succ;

  return true;
}


bool
IFormInst::encodeCsrrw(uint32_t rd, uint32_t rs1, uint32_t csr)
{
  if (rd > 31 or rs1 > 31)
    return false;

  if (csr >= (1 << 12))
    return false;

  fields.opcode = 0x7f;
  fields.rd = rd;
  fields.funct3 = 1;
  fields.rs1 = rs1;
  fields.imm = csr;
  return true;
}


bool
IFormInst::encodeCsrrs(uint32_t rd, uint32_t rs1, uint32_t csr)
{
  if (not encodeCsrrw(rd, rs1, csr))
    return false;
  fields.funct3 = 2;
  return true;
}


bool
IFormInst::encodeCsrrc(uint32_t rd, uint32_t rs1, uint32_t csr)
{
  if (not encodeCsrrw(rd, rs1, csr))
    return false;
  fields.funct3 = 3;
  return true;
}


bool
IFormInst::encodeCsrrwi(uint32_t rd, uint32_t imm, uint32_t csr)
{
  if (not encodeCsrrw(rd, imm, csr))
    return false;
  fields.funct3 = 5;
  return true;
}


bool
IFormInst::encodeCsrrsi(uint32_t rd, uint32_t imm, uint32_t csr)
{
  if (not encodeCsrrw(rd, imm, csr))
    return false;
  fields.funct3 = 6;
  return true;
}


bool
IFormInst::encodeCsrrci(uint32_t rd, uint32_t imm, uint32_t csr)
{
  if (not encodeCsrrw(rd, imm, csr))
    return false;
  fields.funct3 = 7;
  return true;
}


bool
SFormInst::encodeSb(unsigned rs1v, unsigned rs2v, int imm)
{
  if (rs1v > 31 or rs2v > 31)
    return false;  // Register(s) out of bounds.

  if (imm >= (1<<11) or imm < (-1<<11))
    return false;  // Immediate out of bounds.

  opcode = 0x23;
  imm4_0 = imm & 0x1f;
  funct3 = 0;
  rs1 = rs1v;
  rs2 = rs2v;
  imm11_5 = (imm >> 5) & 0x7f;
  return true;
}


bool
SFormInst::encodeSh(unsigned rs1, unsigned rs2, int imm)
{
  if (not encodeSb(rs1, rs2, imm))
    return false;
  funct3 = 1;
  return true;
}


bool
SFormInst::encodeSw(unsigned rs1, unsigned rs2, int imm)
{
  if (not encodeSb(rs1, rs2, imm))
    return false;
  funct3 = 2;
  return true;
}


bool
SFormInst::encodeSd(unsigned rs1, unsigned rs2, int imm)
{
  if (not encodeSb(rs1, rs2, imm))
    return false;
  funct3 = 3;
  return true;
}


bool
UFormInst::encodeLui(unsigned rdv, int immed)
{
  if (rdv > 31)
    return false;  // Register out of bounds.

  if (immed >= (1 << 19) or immed < (-1 << 19))
    return false;  // Immediate out of bounds.

  opcode = 0x37;
  rd = rdv;
  imm = (immed >> 12);
  return true;
}


bool
UFormInst::encodeAuipc(unsigned rd, int immed)
{
  if (not encodeLui(rd, immed))
    return false;
  opcode = 0x17;
  return true;
}


bool
JFormInst::encodeJal(uint32_t rdv, int offset)

{
  if (rdv > 31)
    return false; // Register out of bounds.

  if (offset >= (1 << 20) or offset < (-1 << 20))
    return false;  // Offset out of bounds.

  opcode = 0x6f;
  rd = rdv;
  imm20 = (offset >> 20) & 1;
  imm19_12 = (offset >> 12) & 0xff;
  imm11 = (offset >> 11) & 1;
  imm10_1 = (offset >> 1) & 0x3ff;
  return true;
}


bool
CbFormInst::encodeCbeqz(unsigned rs1pv, int imm)
{
  if ((imm & 1) != 0)
    return false;  // Least sig bit must be zero.

  if (rs1pv > 7)
    return false;  // Register out of bounds.

  if (imm >= (1<<8) or imm < (-1<<8))
    return false;  // Immediate out of bounds,

  opcode = 1;
  ic0 = (imm >> 5) & 1;
  ic1 = (imm >> 1) & 1;
  ic2 = (imm >> 2) & 1;
  ic3 = (imm >> 6) & 1;
  ic4 = (imm >> 7) & 1;
  rs1p = rs1pv;
  ic5 = (imm >> 3) & 1;
  ic6 = (imm >> 4) & 1;
  ic7 = (imm >> 8) & 1;
  funct3 = 6;
  return true;
}


bool
CbFormInst::encodeCbnez(unsigned rs1p, int imm)
{
  if (not encodeCbeqz(rs1p, imm))
    return false;
  funct3 = 7;
  return true;
}


bool
CaiFormInst::encodeCsrli(unsigned rdpv, unsigned imm)
{
  if (rdpv > 7)
    return false;  // Register out of bounds.

  if (imm >= (1 << 6))
    return false;  // Immediate out of bounds.

  opcode = 1;
  ic0 = imm & 1;
  ic1 = (imm >> 1) & 1;
  ic2 = (imm >> 2) & 1;
  ic3 = (imm >> 3) & 1;
  ic4 = (imm >> 4) & 1;
  rdp = rdpv;
  funct2 = 0;
  ic5 = (imm >> 5) & 1;
  funct3 = 4;
  unused = 0;
  return true;
}


bool
CaiFormInst::encodeCsrai(unsigned rdpv, unsigned imm)
{
  if (not encodeCsrli(rdpv, imm))
    return false;
  funct2 = 1;
  return true;
}


bool
CaiFormInst::encodeCandi(unsigned rdpv, int imm)
{
  if (rdpv > 7)
    return false;  // Register out of bounds.

  if (imm >= (1 << 5) or imm < (-1 << 5))
    return false;  // Immediate out of bounds.

  opcode = 1;
  ic0 = imm & 1;
  ic1 = (imm >> 1) & 1;
  ic2 = (imm >> 2) & 1;
  ic3 = (imm >> 3) & 1;
  ic4 = (imm >> 4) & 1;
  rdp = rdpv;
  funct2 = 2;
  ic5 = (imm >> 5) & 1;
  funct3 = 4;
  unused = 0;
  return true;
}


bool
CaiFormInst::encodeCsub(unsigned rdpv, unsigned rs2pv)
{
  if (rdpv > 7 or rs2pv > 7)
    return false;  // Register(s) out of bounds.

  opcode = 1;
  ic0 = rs2pv & 1;
  ic1 = (rs2pv >> 1) & 1;
  ic2 = (rs2pv >> 2) & 1;
  ic3 = 0;
  ic4 = 0;
  rdp = rdpv;
  funct2 = 3;
  ic5 = 0;
  funct3 = 4;
  unused = 0;
  return true;
}


bool
CaiFormInst::encodeCxor(unsigned rdpv, unsigned rs2pv)
{
  if (not encodeCsub(rdpv, rs2pv))
    return false;
  ic3 = 1;
  return true;
}


bool
CaiFormInst::encodeCor(unsigned rdpv, unsigned rs2pv)
{
  if (not encodeCsub(rdpv, rs2pv))
    return false;
  ic4 = 1;
  return true;
}


bool
CaiFormInst::encodeCand(unsigned rdpv, unsigned rs2pv)
{
  if (not encodeCsub(rdpv, rs2pv))
    return false;
  ic3 = 1;
  ic4 = 1;
  return true;
}


bool
CiFormInst::encodeCadd(unsigned rdv, unsigned rs2v)
{
  if (rdv > 31 or rs2v > 31)
    return false;  // Register(s) out of bounds.

  if (rs2v == 0)
    return false;  // Illegal register number.

  opcode = 2;
  ic0 = rs2v & 0x1;
  ic1 = (rs2v >> 1) & 1;
  ic2 = (rs2v >> 2) & 1;
  ic3 = (rs2v >> 3) & 1;
  ic4 = (rs2v >> 4) & 1;
  ic5 = 1;
  rd = rdv;
  funct3 = 4;
  unused = 0;
  return true;
}


bool
CiFormInst::encodeCaddi(unsigned rdv, int imm)
{
  if (rdv > 31)
    return false;  // Register out of bounds.

  if (imm < (-1 << 5) or imm > (1 << 5))
    return false;  // Immediate out of bounds.

  opcode = 1;
  ic0 = imm & 0x1;
  ic1 = (imm >> 1) & 1;
  ic2 = (imm >> 2) & 1;
  ic3 = (imm >> 3) & 1;
  ic4 = (imm >> 4) & 1;
  rd = rdv;
  ic5 = (imm >> 5) & 1;
  funct3 = 0;
  unused = 0;
  return true;
}


bool
CiFormInst::encodeCaddi16sp(int imm)
{
  if (imm >= (1 << 5) or imm < (-1 << 5))
    return false;  // Immediate out of bounds.

  imm = imm * 16;

  opcode = 1;
  ic0 = (imm >> 5) & 1;
  ic1 = (imm >> 7) & 1;
  ic2 = (imm >> 8) & 1;
  ic3 = (imm >> 6) & 1;
  ic4 = (imm >> 4) & 1;
  rd = 2;
  ic5 = (imm >> 9) & 1;
  funct3 = 1;
  unused = 0;
  return true;
}


bool
CiFormInst::encodeClui(unsigned rdv, int imm)
{
  if (rd == 2)
    return false;  // Illegal register number.

  opcode = 1;
  ic0 = (imm >> 12) & 1;
  ic1 = (imm >> 13) & 1;
  ic2 = (imm >> 14) & 1;
  ic3 = (imm >> 15) & 1;
  ic4 = (imm >> 16) & 1;
  rd = rdv;
  ic5 = (imm >> 17) & 1;
  funct3 = 3;
  unused = 0;
  return true;
}


bool
CiFormInst::encodeClwsp(unsigned rdv, unsigned imm)
{
  if (imm >= (1 << 7))
    return false;  // Immediate out of bounds.

  imm = imm << 2;  // Scale by 4.

  opcode = 2;
  ic0 = (imm >> 6) & 1;
  ic1 = (imm >> 7) & 1;
  ic2 = (imm >> 2) & 1;
  ic3 = (imm >> 3) & 1;
  ic4 = (imm >> 4) & 1;
  ic5 = (imm >> 5) & 1;
  rd = rdv;
  funct3 = 2;
  unused = 0;
  return true;
}


bool
CiFormInst::encodeCslli(unsigned rdv, unsigned shift)
{
  if (shift > 31)
    return false;  // Bad shift amount.

  opcode = 2;
  ic0 = shift & 1; ic1 = (shift >> 1) & 1; ic2 = (shift >> 2) & 1;
  ic3 = (shift >> 3) & 1; ic4 = (shift >> 4) & 1; ic5 = (shift >> 5) & 1;
  rd = rdv;
  funct3 = 0;
  unused = 0;
  return true;
}


bool
CiFormInst::encodeCebreak()
{
  opcode = 2;
  ic0 = ic1 = ic2 = ic3 = ic4 = 0;
  rd = 0;
  ic5 = 1;
  funct3 = 4;
  unused = 0;
  return true;
}


bool
CiFormInst::encodeCjalr(unsigned rs1)
{
  if (rs1 == 0 or rs1 > 31)
    return false;  // Invalid register number.

  opcode = 2;
  ic0 = ic1 = ic2 = ic3 = ic4 = 0;
  rd = rs1;
  ic5 = 1;
  funct3 = 4;
  unused = 0;
  return true;
}


bool
CiFormInst::encodeCjr(unsigned rs1)
{
  if (not encodeCjalr(rs1))
    return false;
  ic5 = 0;
  return true;
}


bool
CiwFormInst::encodeCaddi4spn(unsigned rdpv, unsigned immed)
{
  if (immed == 0 or immed >= (1 << 8))
    return false;  // Immediate out of bounds.

  immed = immed << 2;  // Times 4
  opcode = 0;
  rdp = rdpv;
  ic0 = (immed >> 3) & 1;
  ic1 = (immed >> 2) & 1;
  ic2 = (immed >> 6) & 1;
  ic3 = (immed >> 7) & 1;
  ic4 = (immed >> 8) & 1;
  ic5 = (immed >> 9) & 1;
  ic6 = (immed >> 4) & 1;
  ic7 = (immed >> 5) & 1;
  funct3 = 0;
  unused = 0;
  return true;
}


bool
CjFormInst::encodeCjal(int imm)
{
  if (imm >= (1 << 11) or imm < (-1 << 11))
    return false;  // Immediate out of bounds.

  opcode = 1;
  ic0 = (imm >> 5) & 1;
  ic1 = (imm >> 1) & 1;
  ic2 = (imm >> 2) & 1;
  ic3 = (imm >> 3) & 1;
  ic4 = (imm >> 7) & 1;
  ic5 = (imm >> 6) & 1;
  ic6 = (imm >> 10) & 1;
  ic7 = (imm >> 8) & 1;
  ic8 = (imm >> 9) & 1;
  ic9 = (imm >> 4) & 1;
  ic10 = (imm >> 11) & 1;
  funct3 = 1;
  unused = 0;
  return true;
}

 
bool
CjFormInst::encodeCj(int imm)
{
  if (not encodeCjal(imm))
    return false;
  funct3 = 5;
  return true;
}


bool
CswspFormInst::encodeCswsp(unsigned rs2v, unsigned imm)
{
  if (imm >= (1 << 6))
    return false;  // Immediate out of bounds.

  imm = imm * 4;
  opcode = 2;
  rs2 = rs2;
  ic0 = (imm >> 6) & 1;
  ic1 = (imm >> 7) & 1;
  ic2 = (imm >> 2) & 1;
  ic3 = (imm >> 3) & 1;
  ic4 = (imm >> 4) & 1;
  ic5 = (imm >> 5) & 1;
  funct3 = 6;
  unused = 0;
  return true;
}


bool
CsFormInst::encodeCsw(unsigned rs1pv, unsigned rs2pv, unsigned imm)
{
  if (rs1pv > 7 or rs2pv > 7)
    return false;  // Register number out of bounds.

  if (imm >= (1 << 7))
    return false;   // Immediate out of bounds.

  opcode = 0;
  rs2p = rs2pv;
  ic0 = (imm >> 6) & 1;
  ic1 = (imm >> 2) & 1;
  rs1p = rs1pv;
  ic2 = (imm >> 3) & 1;
  ic3 = (imm >> 4) & 1;
  ic4 = (imm >> 5) & 1;
  funct3 = 6;
  unused = 0;
  return true;
}


bool
CsFormInst::encodeCsd(unsigned rs1pv, unsigned rs2pv, unsigned imm)
{
  if (rs1pv > 7 or rs2pv > 7)
    return false;  // Register number out of bounds.

  if (imm >= (1 << 7))
    return false;  // Immediate out of bounds.

  opcode = 0;
  rs2p = rs2pv;
  ic0 = (imm >> 6) & 1;
  ic1 = (imm >> 7) & 1;
  rs1p = rs1pv;
  ic2 = (imm >> 3) & 1;
  ic3 = (imm >> 4) & 1;
  ic4 = (imm >> 5) & 1;
  funct3 = 7;
  unused = 0;
  return true;
}


///////////////////////////////////////////////////////////////////////////

bool
WdRiscv::encodeLui(uint32_t rd, uint32_t immed, uint32_t, uint32_t& inst)
{
  UFormInst uf(0);
  if (not uf.encodeLui(rd, immed))
    return false;
  inst = uf.code;
  return true;
}


bool
WdRiscv::encodeAuipc(uint32_t rd, uint32_t immed, uint32_t, uint32_t& inst)
{
  UFormInst uf(0);
  if (not uf.encodeAuipc(rd, immed))
    return false;
  inst = uf.code;
  return true;
}


bool
WdRiscv::encodeJal(uint32_t rd, uint32_t offset, uint32_t, uint32_t& inst)
{
  JFormInst jf(0);
  if (not jf.encodeJal(rd, offset))
    return false;
  inst = jf.code;
  return true;
}


bool
WdRiscv::encodeJalr(uint32_t rd, uint32_t rs1, uint32_t offset, uint32_t& inst)
{
  IFormInst ifs(0);
  if (not ifs.encodeJalr(rd, rs1, offset))
    return false;
  inst = ifs.code;
  return true;
}


bool
WdRiscv::encodeBeq(uint32_t rs1, uint32_t rs2, uint32_t imm, uint32_t& inst)
{
  BFormInst bf(0);
  if (not bf.encodeBeq(rs1, rs2, imm))
    return false;
  inst = bf.code;
  return true;
}


bool
WdRiscv::encodeBne(uint32_t rs1, uint32_t rs2, uint32_t imm, uint32_t& inst)
{
  BFormInst bf(0);
  if (not bf.encodeBne(rs1, rs2, imm))
    return false;
  inst = bf.code;
  return true;
}


bool
WdRiscv::encodeBlt(uint32_t rs1, uint32_t rs2, uint32_t imm, uint32_t& inst)
{
  BFormInst bf(0);
  if (not bf.encodeBlt(rs1, rs2, imm))
    return false;
  inst = bf.code;
  return true;
}

bool
WdRiscv::encodeBge(uint32_t rs1, uint32_t rs2, uint32_t imm, uint32_t& inst)
{
  BFormInst bf(0);
  if (not bf.encodeBge(rs1, rs2, imm))
    return false;
  inst = bf.code;
  return true;
}


bool
WdRiscv::encodeBltu(uint32_t rs1, uint32_t rs2, uint32_t imm, uint32_t& inst)
{
  BFormInst bf(0);
  if (not bf.encodeBltu(rs1, rs2, imm))
    return false;
  inst = bf.code;
  return true;
}

bool
WdRiscv::encodeBgeu(uint32_t rs1, uint32_t rs2, uint32_t imm, uint32_t& inst)
{
  BFormInst bf(0);
  if (not bf.encodeBgeu(rs1, rs2, imm))
    return false;
  inst = bf.code;
  return true;
}


bool
WdRiscv::encodeLb(uint32_t rd, uint32_t rs1, uint32_t offset, uint32_t& inst)
{
  IFormInst ifi(0);
  if (not ifi.encodeLb(rd, rs1, offset))
    return false;
  inst = ifi.code;
  return true;
}


bool
WdRiscv::encodeLh(uint32_t rd, uint32_t rs1, uint32_t offset, uint32_t& inst)
{
  IFormInst ifi(0);
  if (not ifi.encodeLh(rd, rs1, offset))
    return false;
  inst = ifi.code;
  return true;
}


bool
WdRiscv::encodeLw(uint32_t rd, uint32_t rs1, uint32_t offset, uint32_t& inst)
{
  IFormInst ifi(0);
  if (not ifi.encodeLw(rd, rs1, offset))
    return false;
  inst = ifi.code;
  return true;
}


bool
WdRiscv::encodeLbu(uint32_t rd, uint32_t rs1, uint32_t offset, uint32_t& inst)
{
  IFormInst ifi(0);
  if (not ifi.encodeLbu(rd, rs1, offset))
    return false;
  inst = ifi.code;
  return true;
}


bool
WdRiscv::encodeLhu(uint32_t rd, uint32_t rs1, uint32_t offset, uint32_t& inst)
{
  IFormInst ifi(0);
  if (not ifi.encodeLhu(rd, rs1, offset))
    return false;
  inst = ifi.code;
  return true;
}


bool
WdRiscv::encodeSb(uint32_t rs1, uint32_t rs2, uint32_t imm, uint32_t& inst)
{
  SFormInst sfi(0);
  if (not sfi.encodeSb(rs1, rs2, imm))
    return false;
  inst = sfi.code;
  return true;
}


bool
WdRiscv::encodeSh(uint32_t rs1, uint32_t rs2, uint32_t imm, uint32_t& inst)
{
  SFormInst sfi(0);
  if (not sfi.encodeSh(rs1, rs2, imm))
    return false;
  inst = sfi.code;
  return true;
}


bool
WdRiscv::encodeSw(uint32_t rs1, uint32_t rs2, uint32_t imm, uint32_t& inst)
{
  SFormInst sfi(0);
  if (not sfi.encodeSw(rs1, rs2, imm))
    return false;
  inst = sfi.code;
  return true;
}


bool
WdRiscv::encodeAddi(uint32_t rd, uint32_t rs1, uint32_t imm, uint32_t& inst)
{
  IFormInst ifs(0);
  if (not ifs.encodeAddi(rd, rs1,imm))
    return false;
  inst = ifs.code;
  return true;
}


bool
WdRiscv::encodeSlti(uint32_t rd, uint32_t rs1, uint32_t imm, uint32_t& inst)
{
  IFormInst ifi(0);
  if (not ifi.encodeSlti(rd, rs1, imm))
    return false;
  inst = ifi.code;
  return true;
}


bool
WdRiscv::encodeSltiu(uint32_t rd, uint32_t rs1, uint32_t imm, uint32_t& inst)
{
  IFormInst ifi(0);
  if (not ifi.encodeSltiu(rd, rs1, imm))
    return false;
  inst = ifi.code;
  return true;
}


bool
WdRiscv::encodeXori(uint32_t rd, uint32_t rs1, uint32_t imm, uint32_t& inst)
{
  IFormInst ifi(0);
  if (not ifi.encodeXori(rd, rs1, imm))
    return false;
  inst = ifi.code;
  return true;
}


bool
WdRiscv::encodeOri(uint32_t rd, uint32_t rs1, uint32_t imm, uint32_t& inst)
{
  IFormInst ifi(0);
  if (not ifi.encodeOri(rd, rs1, imm))
    return false;
  inst = ifi.code;
  return true;
}


bool
WdRiscv::encodeAndi(uint32_t rd, uint32_t rs1, uint32_t imm, uint32_t& inst)
{
  IFormInst ifs(0);
  if (not ifs.encodeAndi(rd, rs1, imm))
    return false;
  inst = ifs.code;
  return true;
}


bool
WdRiscv::encodeSlli(uint32_t rd, uint32_t rs1, uint32_t shamt, uint32_t& inst)
{
  IFormInst ifi(0);
  if (not ifi.encodeSlli(rd, rs1, shamt))
    return false;
  inst = ifi.code;
  return true;
}


bool
WdRiscv::encodeSrli(uint32_t rd, uint32_t rs1, uint32_t shamt, uint32_t& inst)
{
  IFormInst ifi(0);
  if (not ifi.encodeSrli(rd, rs1, shamt))
    return false;
  inst = ifi.code;
  return true;
}


bool
WdRiscv::encodeSrai(uint32_t rd, uint32_t rs1, uint32_t shamt, uint32_t& inst)
{
  IFormInst ifi(0);
  if (not ifi.encodeSrai(rd, rs1, shamt))
    return false;
  inst = ifi.code;
  return true;
}


bool
WdRiscv::encodeAdd(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeAdd(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeSub(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeSub(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeSll(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeSll(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeSlt(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeSlt(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeSltu(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeSltu(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeXor(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeXor(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeSrl(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeSrl(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeSra(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeSra(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeOr(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeOr(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeAnd(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeAnd(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeFence(uint32_t pred, uint32_t succ, uint32_t, uint32_t& inst)
{
  IFormInst ifi(0);
  if (not ifi.encodeFence(pred, succ))
    return false;
  inst = ifi.code;
  return true;
}


bool
WdRiscv::encodeFencei(uint32_t, uint32_t, uint32_t, uint32_t& inst)
{
  IFormInst ifi(0);
  if (not ifi.encodeFencei())
    return false;
  inst = ifi.code;
  return true;
}


bool
WdRiscv::encodeEcall(uint32_t, uint32_t, uint32_t, uint32_t& inst)
{
  IFormInst ifs(0);
  if (not ifs.encodeEcall())
    return false;
  inst = ifs.code;
  return true;
}


bool
WdRiscv::encodeEbreak(uint32_t, uint32_t, uint32_t, uint32_t& inst)
{
  IFormInst ifs(0);
  if (not ifs.encodeEbreak())
    return false;
  inst = ifs.code;
  return true;
}


bool
WdRiscv::encodeCsrrw(uint32_t rd, uint32_t rs1, uint32_t csr, uint32_t& inst)
{
  IFormInst ifs(0);
  if (not ifs.encodeCsrrw(rd, rs1, csr))
    return false;
  inst = ifs.code;
  return true;
}


bool
WdRiscv::encodeCsrrs(uint32_t rd, uint32_t rs1, uint32_t csr, uint32_t& inst)
{
  IFormInst ifs(0);
  if (not ifs.encodeCsrrs(rd, rs1, csr))
    return false;
  inst = ifs.code;
  return true;
}


bool
WdRiscv::encodeCsrrc(uint32_t rd, uint32_t rs1, uint32_t csr, uint32_t& inst)
{
  IFormInst ifs(0);
  if (not ifs.encodeCsrrc(rd, rs1, csr))
    return false;
  inst = ifs.code;
  return true;
}


bool
WdRiscv::encodeCsrrsi(uint32_t rd, uint32_t imm, uint32_t csr, uint32_t& inst)
{
  IFormInst ifs(0);
  if (not ifs.encodeCsrrsi(rd, imm, csr))
    return false;
  inst = ifs.code;
  return true;
}


bool
WdRiscv::encodeCsrrci(uint32_t rd, uint32_t imm, uint32_t csr, uint32_t& inst)
{
  IFormInst ifs(0);
  if (not ifs.encodeCsrrci(rd, imm, csr))
    return false;
  inst = ifs.code;
  return true;
}


bool
WdRiscv::encodeLwu(uint32_t rd, uint32_t rs1, uint32_t offset, uint32_t& inst)
{
  IFormInst ifi(0);
  if (not ifi.encodeLwu(rd, rs1, offset))
    return false;
  inst = ifi.code;
  return true;
}


bool
WdRiscv::encodeLd(uint32_t rd, uint32_t rs1, uint32_t offset, uint32_t& inst)
{
  IFormInst ifi(0);
  if (not ifi.encodeLd(rd, rs1, offset))
    return false;
  inst = ifi.code;
  return true;
}


bool
WdRiscv::encodeSd(uint32_t rs1, uint32_t rs2, uint32_t imm, uint32_t& inst)
{
  SFormInst sfi(0);
  if (not sfi.encodeSd(rs1, rs2, imm))
    return false;
  inst = sfi.code;
  return true;
}


bool
WdRiscv::encodeAddiw(uint32_t rd, uint32_t rs1, uint32_t imm, uint32_t& inst)
{
  IFormInst ifi(0);
  if (not ifi.encodeAddiw(rd, rs1, imm))
    return false;
  inst = ifi.code;
  return true;
}


bool
WdRiscv::encodeSlliw(uint32_t rd, uint32_t rs1, uint32_t imm, uint32_t& inst)
{
  IFormInst ifi(0);
  if (not ifi.encodeSlliw(rd, rs1, imm))
    return false;
  inst = ifi.code;
  return true;
}


bool
WdRiscv::encodeSrliw(uint32_t rd, uint32_t rs1, uint32_t imm, uint32_t& inst)
{
  IFormInst ifi(0);
  if (not ifi.encodeSrliw(rd, rs1, imm))
    return false;
  inst = ifi.code;
  return true;
}


bool
WdRiscv::encodeSraiw(uint32_t rd, uint32_t rs1, uint32_t imm, uint32_t& inst)
{
  IFormInst ifi(0);
  if (not ifi.encodeSraiw(rd, rs1, imm))
    return false;
  inst = ifi.code;
  return true;
}


bool
WdRiscv::encodeAddw(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeAddw(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeSubw(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeSubw(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeSllw(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeSllw(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeSrlw(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeSrlw(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeSraw(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeSraw(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeMul(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeMul(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeMulh(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeMulh(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeMulhsu(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeMulhsu(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeMulhu(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeMulhu(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;

}

bool
WdRiscv::encodeDiv(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeDiv(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeDivu(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeDivu(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeRem(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeRem(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeRemu(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeRemu(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeMulw(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeMulw(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeDivw(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeDivw(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeDivuw(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeDivuw(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeRemw(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeRemw(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeRemuw(uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t& inst)
{
  RFormInst rfi(0);
  if (not rfi.encodeRemuw(rd, rs1, rs2))
    return false;
  inst = rfi.code;
  return true;
}


bool
WdRiscv::encodeCbeqz(uint32_t rs1p, uint32_t imm, uint32_t, uint32_t& inst)
{
  CbFormInst cb(0);
  if (not cb.encodeCbeqz(rs1p, imm))
    return false;
  inst = cb.code;
  return false;
}


bool
WdRiscv::encodeCbnez(uint32_t rs1p, uint32_t imm, uint32_t, uint32_t& inst)
{
  CbFormInst cb(0);
  if (not cb.encodeCbnez(rs1p, imm))
    return false;
  inst = cb.code;
  return false;
}

