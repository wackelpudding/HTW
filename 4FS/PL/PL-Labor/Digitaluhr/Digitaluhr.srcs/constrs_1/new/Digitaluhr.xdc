#===========================================================================
# Clock (Bank 13)
create_clock -period 10 [get_ports clock];
set_property PACKAGE_PIN Y9 [get_ports clock];  # 100 MHz clock
set_property IOSTANDARD LVCMOS33 [get_ports clock];

#===========================================================================
# LED
set_property PACKAGE_PIN T22 [get_ports Sec_Blink];  # LED LD0
set_property IOSTANDARD LVCMOS33 [get_ports Sec_Blink];
set_property PACKAGE_PIN U22 [get_ports AM_LED];  # LED LD2
set_property IOSTANDARD LVCMOS33 [get_ports AM_LED];
set_property PACKAGE_PIN U21 [get_ports PM_LED];  # LED LD3
set_property IOSTANDARD LVCMOS33 [get_ports PM_LED];

#===========================================================================
# PMODS (Bank 13)
# JA PMOD 
set_property PACKAGE_PIN Y11  [get_ports Driver_7Seg[7]];  # JA1
set_property PACKAGE_PIN AA11 [get_ports Driver_7Seg[6]];  # JA2
set_property PACKAGE_PIN Y10  [get_ports Driver_7Seg[5]];  # JA3
set_property PACKAGE_PIN AA9  [get_ports Driver_7Seg[4]];  # JA4
set_property PACKAGE_PIN AB11 [get_ports Driver_7Seg[3]];  # JA7
set_property PACKAGE_PIN AB10 [get_ports Driver_7Seg[2]];  # JA8
set_property PACKAGE_PIN AB9  [get_ports Driver_7Seg[1]];  # JA9
set_property PACKAGE_PIN AA8  [get_ports Driver_7Seg[0]];  # JA10
# JB PMOD
set_property PACKAGE_PIN W12 [get_ports Selector_7Seg[0]];  # JB1
set_property PACKAGE_PIN W11 [get_ports Selector_7Seg[1]];  # JB2
set_property PACKAGE_PIN V10 [get_ports Selector_7Seg[2]];  # JB3
set_property PACKAGE_PIN W8  [get_ports Selector_7Seg[3]];  # JB4
set_property PACKAGE_PIN V12 [get_ports Selector_7Seg[4]];  # JB7
set_property PACKAGE_PIN W10 [get_ports Selector_7Seg[5]];  # JB8

#set_property PACKAGE_PIN V9 [get_ports myJB9];  # JB9
#set_property PACKAGE_PIN V8 [get_ports myJB10];  # JB10

# 3.3V für alle PMOD-Pins (Bank 13) setzen
set_property IOSTANDARD LVCMOS33 [get_ports -of_objects [get_iobanks 13]];

#===========================================================================
# User Push Buttons  (Bank 34)
set_property PACKAGE_PIN R16 [get_ports reset];      # Button BTND
set_property PACKAGE_PIN T18 [get_ports sel_btn];    # BTNU
set_property PACKAGE_PIN R18 [get_ports inc_btn];    # BTNR
set_property PACKAGE_PIN N15 [get_ports mode_btn];   # BTNL

# 1.8V für alle Push Buttons (Bank 34) setzen
set_property IOSTANDARD LVCMOS18 [get_ports -of_objects [get_iobanks 34]];


