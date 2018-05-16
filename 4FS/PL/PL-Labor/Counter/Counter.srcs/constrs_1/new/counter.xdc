create_clock -period 10 [get_ports clock]
set_property IOSTANDARD LVCMOS33 [get_ports clock]
set_property PACKAGE_PIN Y9 [get_ports clock]

create_clock -period 10 [get_ports reset]
set_property IOSTANDARD LVCMOS33 [get_ports reset]
set_property PACKAGE_PIN T18 [get_ports reset]

create_clock -period 10 [get_ports direction]
set_property IOSTANDARD LVCMOS33 [get_ports direction]
set_property PACKAGE_PIN M15 [get_ports direction]

create_clock -period 10 [get_ports count_out[0]]
set_property IOSTANDARD LVCMOS33 [get_ports count_out[0]]
set_property PACKAGE_PIN T22 [get_ports count_out[0]]

create_clock -period 10 [get_ports count_out[1]]
set_property IOSTANDARD LVCMOS33 [get_ports count_out[1]]
set_property PACKAGE_PIN T21 [get_ports count_out[1]]

create_clock -period 10 [get_ports count_out[2]]
set_property IOSTANDARD LVCMOS33 [get_ports count_out[2]]
set_property PACKAGE_PIN U22 [get_ports count_out[2]]

create_clock -period 10 [get_ports count_out[3]]
set_property IOSTANDARD LVCMOS33 [get_ports count_out[3]]
set_property PACKAGE_PIN U21 [get_ports count_out[3]]
        
        