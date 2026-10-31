// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu.h for the primary calling header

#include "Valu__pch.h"

void Valu___024root___eval_sample(Valu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_sample\n"); );
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
bool Valu___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in);
void Valu___024root___ico_comb__TOP__0(Valu___024root* vlSelf);

bool Valu___024root___eval_ico(Valu___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_ico\n"); );
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VicoExecute;
    // Body
    vlSelfRef.__VicoTriggered[1U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[1U]) 
                                     | (::IData)((::IData)(firstIteration)));
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[0U] = (::QData)((::IData)(
                                                            (((((::IData)(vlSelfRef.__VprimaryPorts.intrupts) 
                                                                != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__intrupts__0)) 
                                                               << 3U) 
                                                              | (((::IData)(vlSelfRef.__VprimaryPorts.opcode) 
                                                                  != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__opcode__0)) 
                                                                 << 2U)) 
                                                             | (((vlSelfRef.__VprimaryPorts.indata2 
                                                                  != vlSelfRef.__Vtrigprevexpr___TOP__indata2__0) 
                                                                 << 1U) 
                                                                | (vlSelfRef.__VprimaryPorts.indata1 
                                                                   != vlSelfRef.__Vtrigprevexpr___TOP__indata1__0)))));
        vlSelfRef.__Vtrigprevexpr___TOP__indata1__0 
            = vlSelfRef.__VprimaryPorts.indata1;
        vlSelfRef.__Vtrigprevexpr___TOP__indata2__0 
            = vlSelfRef.__VprimaryPorts.indata2;
        vlSelfRef.__Vtrigprevexpr___TOP__opcode__0 
            = vlSelfRef.__VprimaryPorts.opcode;
        vlSelfRef.__Vtrigprevexpr___TOP__intrupts__0 
            = vlSelfRef.__VprimaryPorts.intrupts;
        if (VL_UNLIKELY(((1U & (~ (::IData)(vlSelfRef.__VicoDidInit)))))) {
            vlSelfRef.__VicoDidInit = 1U;
            vlSelfRef.__VicoTriggered[0U] = (1ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (2ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (4ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (8ULL | vlSelfRef.__VicoTriggered[0U]);
        }
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Valu___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Valu___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_body__ico
            if ((((0x000000000000000fULL & vlSelfRef.__VicoTriggered[0U])) != 0ULL)) {
                Valu___024root___ico_comb__TOP__0(vlSelf);
            }
        }
    }
    return (__VicoExecute);
}

bool Valu___024root___eval_act(Valu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_act\n"); );
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Valu___024root___eval_inact(Valu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_inact\n"); );
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Valu___024root___eval_nba(Valu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_nba\n"); );
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Valu___024root___eval_obs(Valu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_obs\n"); );
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Valu___024root___eval_react(Valu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_react\n"); );
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Valu___024root___eval_postponed(Valu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_postponed\n"); );
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Valu___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___trigger_anySet__ico\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((::IData)(1U) + n);
    } while ((2U > n));
    return (0U);
}

void Valu___024root___ico_comb__TOP__0(Valu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___ico_comb__TOP__0\n"); );
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VprimaryPorts.flag_bus = (((0x00000080U 
                                            & (::IData)(vlSelfRef.__VprimaryPorts.opcode))
                                            ? 0x80U
                                            : ((0x00000040U 
                                                & (::IData)(vlSelfRef.__VprimaryPorts.opcode))
                                                ? 0x80U
                                                : (
                                                   (0x00000020U 
                                                    & (::IData)(vlSelfRef.__VprimaryPorts.opcode))
                                                    ? 0x80U
                                                    : 
                                                   ((0x00000010U 
                                                     & (::IData)(vlSelfRef.__VprimaryPorts.opcode))
                                                     ? 0x80U
                                                     : 
                                                    ((8U 
                                                      & (::IData)(vlSelfRef.__VprimaryPorts.opcode))
                                                      ? 
                                                     ((4U 
                                                       & (::IData)(vlSelfRef.__VprimaryPorts.opcode))
                                                       ? 0x80U
                                                       : 
                                                      (0x80U 
                                                       & (- (::IData)(
                                                                      (1U 
                                                                       & ((::IData)(vlSelfRef.__VprimaryPorts.opcode) 
                                                                          >> 1U))))))
                                                      : 
                                                     (1U 
                                                      & ((- (::IData)(
                                                                      (1U 
                                                                       & (~ 
                                                                          ((::IData)(vlSelfRef.__VprimaryPorts.opcode) 
                                                                           >> 1U))))) 
                                                         & ((- (::IData)(
                                                                         (1U 
                                                                          & (~ 
                                                                             ((::IData)(vlSelfRef.__VprimaryPorts.opcode) 
                                                                              >> 2U))))) 
                                                            & ((1U 
                                                                & (::IData)(vlSelfRef.__VprimaryPorts.opcode))
                                                                ? (::IData)(
                                                                            (1ULL 
                                                                             & (((::QData)((::IData)(vlSelfRef.__VprimaryPorts.indata1)) 
                                                                                - (::QData)((::IData)(vlSelfRef.__VprimaryPorts.indata2))) 
                                                                                >> 0x00000020U)))
                                                                : (::IData)(
                                                                            (1ULL 
                                                                             & (((::QData)((::IData)(vlSelfRef.__VprimaryPorts.indata2)) 
                                                                                + (::QData)((::IData)(vlSelfRef.__VprimaryPorts.indata1))) 
                                                                                >> 0x00000020U)))))))))))) 
                                          & (- (::IData)(
                                                         (1U 
                                                          & (~ (::IData)(vlSelfRef.__VprimaryPorts.intrupts))))));
    vlSelfRef.__VprimaryPorts.outdata = ((- (::IData)(
                                                      (1U 
                                                       & (~ 
                                                          ((::IData)(vlSelfRef.__VprimaryPorts.opcode) 
                                                           >> 7U))))) 
                                         & ((- (::IData)(
                                                         (1U 
                                                          & (~ 
                                                             ((::IData)(vlSelfRef.__VprimaryPorts.opcode) 
                                                              >> 6U))))) 
                                            & ((- (::IData)(
                                                            (1U 
                                                             & (~ 
                                                                ((::IData)(vlSelfRef.__VprimaryPorts.opcode) 
                                                                 >> 5U))))) 
                                               & ((- (::IData)(
                                                               (1U 
                                                                & (~ 
                                                                   ((::IData)(vlSelfRef.__VprimaryPorts.opcode) 
                                                                    >> 4U))))) 
                                                  & (((8U 
                                                       & (::IData)(vlSelfRef.__VprimaryPorts.opcode))
                                                       ? 
                                                      ((- (::IData)(
                                                                    (1U 
                                                                     & (~ 
                                                                        ((::IData)(vlSelfRef.__VprimaryPorts.opcode) 
                                                                         >> 1U))))) 
                                                       & (((1U 
                                                            & (::IData)(vlSelfRef.__VprimaryPorts.opcode))
                                                            ? 
                                                           (vlSelfRef.__VprimaryPorts.indata1 
                                                            & vlSelfRef.__VprimaryPorts.indata2)
                                                            : 
                                                           (vlSelfRef.__VprimaryPorts.indata1 
                                                            | vlSelfRef.__VprimaryPorts.indata2)) 
                                                          & (- (::IData)(
                                                                         (1U 
                                                                          & (~ 
                                                                             ((::IData)(vlSelfRef.__VprimaryPorts.opcode) 
                                                                              >> 2U)))))))
                                                       : 
                                                      ((4U 
                                                        & (::IData)(vlSelfRef.__VprimaryPorts.opcode))
                                                        ? 
                                                       ((2U 
                                                         & (::IData)(vlSelfRef.__VprimaryPorts.opcode))
                                                         ? 
                                                        ((1U 
                                                          & (::IData)(vlSelfRef.__VprimaryPorts.opcode))
                                                          ? 
                                                         (vlSelfRef.__VprimaryPorts.indata1 
                                                          ^ vlSelfRef.__VprimaryPorts.indata2)
                                                          : 
                                                         (1U 
                                                          & (- (::IData)(
                                                                         (vlSelfRef.__VprimaryPorts.indata1 
                                                                          < vlSelfRef.__VprimaryPorts.indata2)))))
                                                         : 
                                                        ((1U 
                                                          & (::IData)(vlSelfRef.__VprimaryPorts.opcode))
                                                          ? 
                                                         (1U 
                                                          & (- (::IData)(
                                                                         VL_LTS_III(32, vlSelfRef.__VprimaryPorts.indata1, vlSelfRef.__VprimaryPorts.indata2))))
                                                          : 
                                                         VL_SHIFTRS_III(32,32,5, vlSelfRef.__VprimaryPorts.indata1, 
                                                                        (0x0000001fU 
                                                                         & vlSelfRef.__VprimaryPorts.indata2))))
                                                        : 
                                                       ((2U 
                                                         & (::IData)(vlSelfRef.__VprimaryPorts.opcode))
                                                         ? 
                                                        ((1U 
                                                          & (::IData)(vlSelfRef.__VprimaryPorts.opcode))
                                                          ? 
                                                         (vlSelfRef.__VprimaryPorts.indata1 
                                                          >> 
                                                          (0x0000001fU 
                                                           & vlSelfRef.__VprimaryPorts.indata2))
                                                          : 
                                                         (vlSelfRef.__VprimaryPorts.indata1 
                                                          << 
                                                          (0x0000001fU 
                                                           & vlSelfRef.__VprimaryPorts.indata2)))
                                                         : 
                                                        ((1U 
                                                          & (::IData)(vlSelfRef.__VprimaryPorts.opcode))
                                                          ? 
                                                         (vlSelfRef.__VprimaryPorts.indata1 
                                                          - vlSelfRef.__VprimaryPorts.indata2)
                                                          : 
                                                         (vlSelfRef.__VprimaryPorts.indata1 
                                                          + vlSelfRef.__VprimaryPorts.indata2))))) 
                                                     & (- (::IData)(
                                                                    (1U 
                                                                     & (~ (::IData)(vlSelfRef.__VprimaryPorts.intrupts))))))))));
}

#ifdef VL_DEBUG
void Valu___024root___eval_debug_assertions(Valu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_debug_assertions\n"); );
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
