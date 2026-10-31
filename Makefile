TOP_MODULE = alu
RTL_SRC    = alu.sv
TB_SRC     = tb_alu.cpp
OBJ_DIR    = obj_dir
SIM_BIN    = $(OBJ_DIR)/V$(TOP_MODULE)

VERILATOR_FLAGS = --cc --exe --build -j 0 -Wall -Wno-fatal --trace-fst

.PHONY: all sim wave clean

all: sim

sim: $(RTL_SRC) $(TB_SRC)
	verilator $(VERILATOR_FLAGS) --top-module $(TOP_MODULE) $(RTL_SRC) $(TB_SRC)
	./$(SIM_BIN)

wave: sim.fst
	gtkwave sim.fst &

clean:
	rm -rf $(OBJ_DIR) sim.fst