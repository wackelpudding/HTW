create_clock -period 10 [get_ports clock]
set_property IOSTANDARD LVCMOS33 [get_ports clock]
set_property PACKAGE_PIN Y9 [get_ports clock]

#create_clock -period 10 [get_ports reset]
set_property IOSTANDARD LVCMOS33 [get_ports reset]
set_property PACKAGE_PIN T18 [get_ports reset]

#create_clock -period 10 [get_ports direction]
set_property IOSTANDARD LVCMOS33 [get_ports direction]
set_property PACKAGE_PIN M15 [get_ports direction]

#create_clock -period 10 [get_ports count_out[0]]
set_property IOSTANDARD LVCMOS33 [get_ports count_out[0]]
set_property PACKAGE_PIN T22 [get_ports count_out[0]]

#create_clock -period 10 [get_ports count_out[1]]
set_property IOSTANDARD LVCMOS33 [get_ports count_out[1]]
set_property PACKAGE_PIN T21 [get_ports count_out[1]]

#create_clock -period 10 [get_ports count_out[2]]
set_property IOSTANDARD LVCMOS33 [get_ports count_out[2]]
set_property PACKAGE_PIN U22 [get_ports count_out[2]]

#create_clock -period 10 [get_ports count_out[3]]
set_property IOSTANDARD LVCMOS33 [get_ports count_out[3]]
set_property PACKAGE_PIN U21 [get_ports count_out[3]]
        
# PMODS (Bank 13)
# JA PMOD 
set_property PACKAGE_PIN Y11  [get_ports Driver_7Seg[6]];  # JA1
set_property PACKAGE_PIN AA11 [get_ports Driver_7Seg[5]];  # JA2
set_property PACKAGE_PIN Y10  [get_ports Driver_7Seg[4]];  # JA3
set_property PACKAGE_PIN AA9  [get_ports Driver_7Seg[3]];  # JA4
set_property PACKAGE_PIN AB11 [get_ports Driver_7Seg[2]];  # JA7
set_property PACKAGE_PIN AB10 [get_ports Driver_7Seg[1]];  # JA8
set_property PACKAGE_PIN AB9  [get_ports Driver_7Seg[0]];  # JA9

# JB PMOD
set_property PACKAGE_PIN W12 [get_ports CA];  # JB1

# 3.3V für alle PMOD-Pins (Bank 13) setzen
set_property IOSTANDARD LVCMOS33 [get_ports -of_objects [get_iobanks 13]];