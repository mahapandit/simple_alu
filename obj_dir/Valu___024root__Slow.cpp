// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu.h for the primary calling header

#include "Valu__pch.h"

void Valu___024root___ctor_var_reset(Valu___024root* vlSelf);

void Valu___024root__ctor(Valu___024root* vlSelf, Valu__Syms* symsp, const char* namep) {
    vlSelf->vlSymsp = symsp;
    vlSelf->vlNamep = strdup(namep);
    // Construct members
    // Reset structure values
    Valu___024root___ctor_var_reset(vlSelf);
}

Valu___024root::Valu___024root(Valu__Syms* symsp, const char* namep) {
    Valu___024root__ctor(this, symsp, namep);
}

void Valu___024root__dtor(Valu___024root* vlSelf) {
    // Destroy members
    VL_DO_DANGLING(std::free(const_cast<char*>(vlSelf->vlNamep)), vlSelf->vlNamep);
}

Valu___024root::~Valu___024root() {
    Valu___024root__dtor(this);
}
