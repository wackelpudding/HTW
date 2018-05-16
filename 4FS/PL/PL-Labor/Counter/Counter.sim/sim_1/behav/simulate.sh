#!/bin/bash -f
xv_path="/opt/Xilinx/Vivado/2017.2"
ExecStep()
{
"$@"
RETVAL=$?
if [ $RETVAL -ne 0 ]
then
exit $RETVAL
fi
}
ExecStep $xv_path/bin/xsim testbench_counter_behav -key {Behavioral:sim_1:Functional:testbench_counter} -tclbatch testbench_counter.tcl -log simulate.log
