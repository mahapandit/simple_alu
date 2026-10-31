// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Valu.h for the primary calling header

#ifndef VERILATED_VALU___024ROOT_H_
#define VERILATED_VALU___024ROOT_H_  // guard

#include "verilated.h"


class Valu__Syms;

class alignas(VL_CACHE_LINE_BYTES) Valu___024root final {
  public:

    // TOP LEVEL PORTS
    union {
        struct {
            VL_IN(indata1,31,0);
            VL_IN(indata2,31,0);
            VL_IN8(opcode,7,0);
            VL_IN8(intrupts,7,0);
            VL_OUT(outdata,31,0);
            VL_OUT8(flag_bus,7,0);
        } __VprimaryPorts;
    };

    // TRIVIALLY CONSTRUCTIBLE STATE
    ::CData/*7:0*/ __Vtrigprevexpr___TOP__opcode__0;
    ::CData/*7:0*/ __Vtrigprevexpr___TOP__intrupts__0;
    ::CData/*0:0*/ __VicoDidInit;
    ::IData/*31:0*/ __Vtrigprevexpr___TOP__indata1__0;
    ::IData/*31:0*/ __Vtrigprevexpr___TOP__indata2__0;
    ::VlUnpacked<::QData/*63:0*/, 1> __VstlTriggered;
    ::VlUnpacked<::QData/*63:0*/, 2> __VicoTriggered;

    // INTERNAL VARIABLES
    Valu__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Valu___024root(Valu__Syms* symsp, const char* namep);
    ~Valu___024root();
    VL_UNCOPYABLE(Valu___024root);
    VL_UNMOVABLE(Valu___024root);

    // INTERNAL METHODS
};


#endif  // guard
