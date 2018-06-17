@echo off
set xv_path=C:\\Xilinx\\Vivado\\2015.2\\bin
call %xv_path%/xelab  -wto 8e1f7cc52aed49c48b0b13f961ebed22 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot Testbench_Digitaluhr_behav xil_defaultlib.Testbench_Digitaluhr -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
