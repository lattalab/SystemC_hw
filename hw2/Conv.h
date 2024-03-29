#include "systemc.h"
#include <iostream>
#include <fstream>

using namespace std;

SC_MODULE( Conv ) {	
	sc_in < bool > rst;
	sc_in_clk clk;
	sc_out < bool > rom_rd;
	sc_out < sc_uint<7> > rom_addr;
	sc_in < float > data_in;
	sc_out < sc_int<19> > data_out;
	sc_out < bool > data_out_signal;
	
	void run();
	
    // vvvvv put your code here vvvvv
	float input[100]={0.0},weight[9]={0.0},bias;
  float output[64]={0};
  int state=0,index=0;
	// ^^^^^ put your code here ^^^^^

	SC_CTOR( Conv )
	{	
		SC_METHOD( run );
		sensitive << rst.pos() << clk.pos();
	}
};


