# 
# Synthesis run script generated by Vivado
# 

set_param xicom.use_bs_reader 1
debug::add_scope template.lib 1
<<<<<<< HEAD
=======
set_msg_config -id {Common-41} -limit 4294967295
>>>>>>> e8da86e9cd176b9e2736abcff44beaa767b934a1
set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
create_project -in_memory -part xc7z020clg484-1

set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_property webtalk.parent_dir {I:/HTW/4. FS/PL-Labor/Digitaluhr_ZWA/Digitaluhr.cache/wt} [current_project]
set_property parent.project_path {I:/HTW/4. FS/PL-Labor/Digitaluhr_ZWA/Digitaluhr.xpr} [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
set_property board_part em.avnet.com:zed:part0:1.3 [current_project]
read_vhdl -library xil_defaultlib {
  {I:/HTW/4. FS/PL-Labor/Digitaluhr_ZWA/Digitaluhr.srcs/sources_1/new/Decoder_7Seg.vhd}
  {I:/HTW/4. FS/PL-Labor/Digitaluhr_ZWA/Digitaluhr.srcs/sources_1/new/Sec_Count.vhd}
  {I:/HTW/4. FS/PL-Labor/Digitaluhr_ZWA/Digitaluhr.srcs/sources_1/new/Min1_Count.vhd}
  {I:/HTW/4. FS/PL-Labor/Digitaluhr_ZWA/Digitaluhr.srcs/sources_1/new/Min10_Count.vhd}
  {I:/HTW/4. FS/PL-Labor/Digitaluhr_ZWA/Digitaluhr.srcs/sources_1/new/Hour1_Count.vhd}
  {I:/HTW/4. FS/PL-Labor/Digitaluhr_ZWA/Digitaluhr.srcs/sources_1/new/Hour10_Count.vhd}
  {I:/HTW/4. FS/PL-Labor/Digitaluhr_ZWA/Digitaluhr.srcs/sources_1/new/Freq_Divider.vhd}
  {I:/HTW/4. FS/PL-Labor/Digitaluhr_ZWA/Digitaluhr.srcs/sources_1/new/Digitaluhr.vhd}
}
read_xdc {{I:/HTW/4. FS/PL-Labor/Digitaluhr_ZWA/Digitaluhr.srcs/constrs_1/new/Digitaluhr.xdc}}
set_property used_in_implementation false [get_files {{I:/HTW/4. FS/PL-Labor/Digitaluhr_ZWA/Digitaluhr.srcs/constrs_1/new/Digitaluhr.xdc}}]

synth_design -top Digitaluhr -part xc7z020clg484-1
write_checkpoint -noxdef Digitaluhr.dcp
catch { report_utilization -file Digitaluhr_utilization_synth.rpt -pb Digitaluhr_utilization_synth.pb }
