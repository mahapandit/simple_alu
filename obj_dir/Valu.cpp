// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Valu__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Valu::Valu(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Valu__Syms(contextp(), _vcname__, this)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , indata1{vlSymsp->vlInst.TOP.__VprimaryPorts.indata1}
    , indata2{vlSymsp->vlInst.TOP.__VprimaryPorts.indata2}
    , opcode{vlSymsp->vlInst.TOP.__VprimaryPorts.opcode}
    , intrupts{vlSymsp->vlInst.TOP.__VprimaryPorts.intrupts}
    , outdata{vlSymsp->vlInst.TOP.__VprimaryPorts.outdata}
    , flag_bus{vlSymsp->vlInst.TOP.__VprimaryPorts.flag_bus}
    , rootp{&(vlSymsp->vlInst.TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Valu::Valu(const char* _vcname__)
    : Valu(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Valu::~Valu() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Valu___024root___eval_debug_assertions(Valu___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Valu___024root___eval_static(Valu___024root* vlSelf);
VL_ATTR_COLD void Valu___024root___eval_initial(Valu___024root* vlSelf);
VL_ATTR_COLD bool Valu___024root___eval_stl(Valu___024root* vlSelf, ::CData/*0:0*/ firstIteration);
void Valu___024root___eval_sample(Valu___024root* vlSelf);
bool Valu___024root___eval_ico(Valu___024root* vlSelf, ::CData/*0:0*/ firstIteration);
bool Valu___024root___eval_act(Valu___024root* vlSelf);
bool Valu___024root___eval_inact(Valu___024root* vlSelf);
bool Valu___024root___eval_nba(Valu___024root* vlSelf);
bool Valu___024root___eval_obs(Valu___024root* vlSelf);
bool Valu___024root___eval_react(Valu___024root* vlSelf);
void Valu___024root___eval_postponed(Valu___024root* vlSelf);
VL_ATTR_COLD void Valu___024root___eval_final(Valu___024root* vlSelf);
VL_ATTR_COLD void Valu___024root___eval_dump_triggers__stl(Valu___024root* vlSelf);
VL_ATTR_COLD void Valu___024root___eval_dump_triggers__ico(Valu___024root* vlSelf);
VL_ATTR_COLD void Valu___024root___eval_dump_triggers__act(Valu___024root* vlSelf);
VL_ATTR_COLD void Valu___024root___eval_dump_triggers__nba(Valu___024root* vlSelf);
VL_ATTR_COLD void Valu___024root___eval_dump_triggers__obs(Valu___024root* vlSelf);
VL_ATTR_COLD void Valu___024root___eval_dump_triggers__react(Valu___024root* vlSelf);

void Valu::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Valu::eval_step\n"); );
    m_evalLoop.eval();
}

void Valu::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Valu___024root___eval_debug_assertions(&(vlSymsp->vlInst.TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
}

void Valu::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Valu::evalStatic() {
    Valu___024root___eval_static(&(vlSymsp->vlInst.TOP));
}

void Valu::evalInitial() {
    Valu___024root___eval_initial(&(vlSymsp->vlInst.TOP));
}

bool Valu::evalStl(bool firstIteration) {
    return Valu___024root___eval_stl(&(vlSymsp->vlInst.TOP), firstIteration);
}

void Valu::evalSample() {
    Valu___024root___eval_sample(&(vlSymsp->vlInst.TOP));
}

bool Valu::evalIco(bool firstIteration) {
    return Valu___024root___eval_ico(&(vlSymsp->vlInst.TOP), firstIteration);
}

bool Valu::evalAct() {
    return Valu___024root___eval_act(&(vlSymsp->vlInst.TOP));
}

bool Valu::evalInact() {
    return Valu___024root___eval_inact(&(vlSymsp->vlInst.TOP));
}

bool Valu::evalNba() {
    return Valu___024root___eval_nba(&(vlSymsp->vlInst.TOP));
}

bool Valu::evalObs() {
    return Valu___024root___eval_obs(&(vlSymsp->vlInst.TOP));
}

bool Valu::evalReact() {
    return Valu___024root___eval_react(&(vlSymsp->vlInst.TOP));
}

void Valu::evalPostponed() {
    Valu___024root___eval_postponed(&(vlSymsp->vlInst.TOP));
}

void Valu::evalFinal() {
    Valu___024root___eval_final(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Valu::dumpTriggersStl() {
    Valu___024root___eval_dump_triggers__stl(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Valu::dumpTriggersIco() {
    Valu___024root___eval_dump_triggers__ico(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Valu::dumpTriggersAct() {
    Valu___024root___eval_dump_triggers__act(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Valu::dumpTriggersNba() {
    Valu___024root___eval_dump_triggers__nba(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Valu::dumpTriggersObs() {
    Valu___024root___eval_dump_triggers__obs(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Valu::dumpTriggersReact() {
    Valu___024root___eval_dump_triggers__react(&(vlSymsp->vlInst.TOP));
}

//============================================================
// Events and timing
bool Valu::eventsPending() { return false; }

uint64_t Valu::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Valu::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Valu::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Valu::hierName() const { return vlSymsp->name(); }
const char* Valu::modelName() const { return "Valu"; }
unsigned Valu::threads() const { return 1; }
void Valu::prepareClone() const { contextp()->prepareClone(); }
void Valu::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Valu::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void Valu___024root__trace_decl_types(VerilatedFst* tracep);

void Valu___024root__trace_init_top(Valu___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Valu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Valu___024root*>(voidSelf);
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Valu___024root__trace_decl_types(tracep);
    Valu___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Valu___024root__trace_register(Valu___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Valu::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Valu::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->vlInst.TOP), name(), false, 6);
    Valu___024root__trace_register(&(vlSymsp->vlInst.TOP), stfp->spTrace());
}
