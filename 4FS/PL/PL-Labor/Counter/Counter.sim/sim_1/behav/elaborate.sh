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
ExecStep $xv_path/bin/xelab -wto 7e80ea43e75f4448a1e24f25bb6c8c42 -m64 --debug typical --relax --mt 8 -L xil_defaultlib -L secureip --snapshot testbench_counter_behav xil_defaultlib.testbench_counter -log elaborate.log
