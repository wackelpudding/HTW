@echo off
set xv_path=C:\\Xilinx\\Vivado\\2015.2\\bin
call %xv_path%/xelab  -wto 38550b6138e1428d8dfe1044bde8d492 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot testbench_waschmaschine_behav xil_defaultlib.testbench_waschmaschine -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
