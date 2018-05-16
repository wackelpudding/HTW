# 
# Synthesis run script generated by Vivado
# 

debug::add_scope template.lib 1
set_msg_config -id {Common-41} -limit 4294967295
set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
create_project -in_memory -part xc7z020clg484-1

set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_property webtalk.parent_dir {I:/HTW/4. FS/PL-Labor/Segment/Segment.cache/wt} [current_project]
set_property parent.project_path {I:/HTW/4. FS/PL-Labor/Segment/Segment.xpr} [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
set_property board_part em.avnet.com:zed:part0:1.3 [current_project]
read_vhdl -library xil_defaultlib {{I:/HTW/4. FS/PL-Labor/Segment/Segment.srcs/sources_1/new/counter.vhd}}
synth_design -top counter -part xc7z020clg484-1
write_checkpoint -noxdef counter.dcp
catch { report_utilization -file counter_utilization_synth.rpt -pb counter_utilization_synth.pb }
