
w
Command: %s
53*	vivadotcl2I
5synth_design -top Waschmaschine -part xc7z020clg484-12default:defaultZ4-113h px
7
Starting synth_design
149*	vivadotclZ4-321h px
�
@Attempting to get a license for feature '%s' and/or device '%s'
308*common2
	Synthesis2default:default2
xc7z0202default:defaultZ17-347h px
�
0Got license for feature '%s' and/or device '%s'
310*common2
	Synthesis2default:default2
xc7z0202default:defaultZ17-349h px
�
�The version limit for your license is '%s' and will expire in %s days. A version limit expiration means that, although you may be able to continue to use the current version of tools or IP with this license, you will not be eligible for any updates or new releases.
519*common2
2015.082default:default2
-9962default:defaultZ17-1223h px
�
%s*synth2�
rStarting Synthesize : Time (s): cpu = 00:00:03 ; elapsed = 00:00:20 . Memory (MB): peak = 260.887 ; gain = 83.820
2default:defaulth px
�
synthesizing module '%s'638*oasys2!
Waschmaschine2default:default2l
VI:/HTW/4. FS/PL-Labor/Waschmaschine/Waschmaschine.srcs/sources_1/new/Waschmaschine.vhd2default:default2
422default:default8@Z8-638h px
�
%done synthesizing module '%s' (%s#%s)256*oasys2!
Waschmaschine2default:default2
12default:default2
12default:default2l
VI:/HTW/4. FS/PL-Labor/Waschmaschine/Waschmaschine.srcs/sources_1/new/Waschmaschine.vhd2default:default2
422default:default8@Z8-256h px
�
%s*synth2�
sFinished Synthesize : Time (s): cpu = 00:00:04 ; elapsed = 00:00:21 . Memory (MB): peak = 295.254 ; gain = 118.188
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
~Finished Constraint Validation : Time (s): cpu = 00:00:04 ; elapsed = 00:00:21 . Memory (MB): peak = 295.254 ; gain = 118.188
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
S
%s*synth2>
*Start Loading Part and Timing Information
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
G
%s*synth22
Loading part: xc7z020clg484-1
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
�Finished Loading Part and Timing Information : Time (s): cpu = 00:00:04 ; elapsed = 00:00:21 . Memory (MB): peak = 295.254 ; gain = 118.188
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
S
Loading part %s157*device2#
xc7z020clg484-12default:defaultZ21-403h px
�
3inferred FSM for state register '%s' in module '%s'802*oasys2)
Aktueller_Zustand_reg2default:default2!
Waschmaschine2default:defaultZ8-802h px
�
[ROM "%s" won't be mapped to Block RAM because address size (%s) smaller than threshold (%s)3996*oasys2%
Naechster_Zustand2default:default2
42default:default2
52default:defaultZ8-5544h px
�
[ROM "%s" won't be mapped to Block RAM because address size (%s) smaller than threshold (%s)3996*oasys2
tstop2default:default2
32default:default2
52default:defaultZ8-5544h px
�
[ROM "%s" won't be mapped to Block RAM because address size (%s) smaller than threshold (%s)3996*oasys2
motor2default:default2
32default:default2
52default:defaultZ8-5544h px
�
[ROM "%s" won't be mapped to Block RAM because address size (%s) smaller than threshold (%s)3996*oasys2
heizung2default:default2
32default:default2
52default:defaultZ8-5544h px
�
[ROM "%s" won't be mapped to Block RAM because address size (%s) smaller than threshold (%s)3996*oasys2
ventil2default:default2
32default:default2
52default:defaultZ8-5544h px
�
[ROM "%s" won't be mapped to Block RAM because address size (%s) smaller than threshold (%s)3996*oasys2
pumpe2default:default2
32default:default2
52default:defaultZ8-5544h px
�
%s*synth2x
d---------------------------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2t
`                   State |                     New Encoding |                     Old Encoding 
2default:defaulth px
�
%s*synth2x
d---------------------------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2s
_                    idle |                              000 |                              000
2default:defaulth px
�
%s*synth2s
_            wasserzulauf |                              001 |                              001
2default:defaulth px
�
%s*synth2s
_                  heizen |                              010 |                              010
2default:defaulth px
�
%s*synth2s
_                 waschen |                              011 |                              011
2default:defaulth px
�
%s*synth2s
_                abpumpen |                              100 |                              100
2default:defaulth px
�
%s*synth2s
_                  iSTATE |                              101 |                              111
2default:defaulth px
+
%s*synth2
*
2default:defaulth px
�
%s*synth2x
d---------------------------------------------------------------------------------------------------
2default:defaulth px
�
Gencoded FSM with state register '%s' using encoding '%s' in module '%s'3353*oasys2)
Aktueller_Zustand_reg2default:default2

sequential2default:default2!
Waschmaschine2default:defaultZ8-3354h px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
�Finished RTL Optimization Phase 2 : Time (s): cpu = 00:00:04 ; elapsed = 00:00:21 . Memory (MB): peak = 311.633 ; gain = 134.566
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
B
%s*synth2-

Report RTL Partitions: 
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
I
%s*synth24
 Start RTL Component Statistics 
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
H
%s*synth23
Detailed RTL Component Info : 
2default:defaulth px
7
%s*synth2"
+---Adders : 
2default:defaulth px
W
%s*synth2B
.	   2 Input      4 Bit       Adders := 1     
2default:defaulth px
:
%s*synth2%
+---Registers : 
2default:defaulth px
W
%s*synth2B
.	                4 Bit    Registers := 1     
2default:defaulth px
6
%s*synth2!
+---Muxes : 
2default:defaulth px
W
%s*synth2B
.	   2 Input      4 Bit        Muxes := 1     
2default:defaulth px
W
%s*synth2B
.	   7 Input      3 Bit        Muxes := 1     
2default:defaulth px
W
%s*synth2B
.	   2 Input      1 Bit        Muxes := 1     
2default:defaulth px
W
%s*synth2B
.	   6 Input      1 Bit        Muxes := 6     
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
L
%s*synth27
#Finished RTL Component Statistics 
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
V
%s*synth2A
-Start RTL Hierarchical Component Statistics 
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
L
%s*synth27
#Hierarchical RTL Component report 
2default:defaulth px
?
%s*synth2*
Module Waschmaschine 
2default:defaulth px
H
%s*synth23
Detailed RTL Component Info : 
2default:defaulth px
7
%s*synth2"
+---Adders : 
2default:defaulth px
W
%s*synth2B
.	   2 Input      4 Bit       Adders := 1     
2default:defaulth px
:
%s*synth2%
+---Registers : 
2default:defaulth px
W
%s*synth2B
.	                4 Bit    Registers := 1     
2default:defaulth px
6
%s*synth2!
+---Muxes : 
2default:defaulth px
W
%s*synth2B
.	   2 Input      4 Bit        Muxes := 1     
2default:defaulth px
W
%s*synth2B
.	   7 Input      3 Bit        Muxes := 1     
2default:defaulth px
W
%s*synth2B
.	   2 Input      1 Bit        Muxes := 1     
2default:defaulth px
W
%s*synth2B
.	   6 Input      1 Bit        Muxes := 6     
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
X
%s*synth2C
/Finished RTL Hierarchical Component Statistics
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
E
%s*synth20
Start Part Resource Summary
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2k
WPart Resources:
DSPs: 220 (col length:60)
BRAMs: 280 (col length: RAMB18 60 RAMB36 30)
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
H
%s*synth23
Finished Part Resource Summary
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
�Start Parallel Synthesis Optimization  : Time (s): cpu = 00:00:06 ; elapsed = 00:00:23 . Memory (MB): peak = 452.047 ; gain = 274.980
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
K
%s*synth26
"Start Cross Boundary Optimization
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
�Finished Cross Boundary Optimization : Time (s): cpu = 00:00:06 ; elapsed = 00:00:23 . Memory (MB): peak = 453.305 ; gain = 276.238
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
~Finished Parallel Reinference  : Time (s): cpu = 00:00:06 ; elapsed = 00:00:23 . Memory (MB): peak = 453.305 ; gain = 276.238
2default:defaulth px
B
%s*synth2-

Report RTL Partitions: 
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
A
%s*synth2,
Start Area Optimization
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
zFinished Area Optimization : Time (s): cpu = 00:00:06 ; elapsed = 00:00:24 . Memory (MB): peak = 471.910 ; gain = 294.844
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
�Finished Parallel Area Optimization  : Time (s): cpu = 00:00:06 ; elapsed = 00:00:24 . Memory (MB): peak = 471.910 ; gain = 294.844
2default:defaulth px
B
%s*synth2-

Report RTL Partitions: 
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
�
%s*synth2�
�Finished Parallel Synthesis Optimization  : Time (s): cpu = 00:00:06 ; elapsed = 00:00:24 . Memory (MB): peak = 471.910 ; gain = 294.844
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
C
%s*synth2.
Start Timing Optimization
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
|Finished Timing Optimization : Time (s): cpu = 00:00:06 ; elapsed = 00:00:24 . Memory (MB): peak = 471.910 ; gain = 294.844
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
B
%s*synth2-

Report RTL Partitions: 
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
B
%s*synth2-
Start Technology Mapping
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
{Finished Technology Mapping : Time (s): cpu = 00:00:06 ; elapsed = 00:00:24 . Memory (MB): peak = 471.910 ; gain = 294.844
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
B
%s*synth2-

Report RTL Partitions: 
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
<
%s*synth2'
Start IO Insertion
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
E
%s*synth20
Start Final Netlist Cleanup
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
H
%s*synth23
Finished Final Netlist Cleanup
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
uFinished IO Insertion : Time (s): cpu = 00:00:06 ; elapsed = 00:00:24 . Memory (MB): peak = 471.910 ; gain = 294.844
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
A
%s*synth2,

Report Check Netlist: 
2default:defaulth px
r
%s*synth2]
I+------+------------------+-------+---------+-------+------------------+
2default:defaulth px
r
%s*synth2]
I|      |Item              |Errors |Warnings |Status |Description       |
2default:defaulth px
r
%s*synth2]
I+------+------------------+-------+---------+-------+------------------+
2default:defaulth px
r
%s*synth2]
I|1     |multi_driven_nets |      0|        0|Passed |Multi driven nets |
2default:defaulth px
r
%s*synth2]
I+------+------------------+-------+---------+-------+------------------+
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
L
%s*synth27
#Start Renaming Generated Instances
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
�Finished Renaming Generated Instances : Time (s): cpu = 00:00:06 ; elapsed = 00:00:24 . Memory (MB): peak = 471.910 ; gain = 294.844
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
B
%s*synth2-

Report RTL Partitions: 
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
I
%s*synth24
 Start Rebuilding User Hierarchy
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
�Finished Rebuilding User Hierarchy : Time (s): cpu = 00:00:06 ; elapsed = 00:00:24 . Memory (MB): peak = 471.910 ; gain = 294.844
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
~Start Renaming Generated Ports : Time (s): cpu = 00:00:06 ; elapsed = 00:00:24 . Memory (MB): peak = 471.910 ; gain = 294.844
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
�Finished Renaming Generated Ports : Time (s): cpu = 00:00:06 ; elapsed = 00:00:24 . Memory (MB): peak = 471.910 ; gain = 294.844
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
H
%s*synth23
Start Writing Synthesis Report
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
>
%s*synth2)

Report BlackBoxes: 
2default:defaulth px
G
%s*synth22
+-+--------------+----------+
2default:defaulth px
G
%s*synth22
| |BlackBox name |Instances |
2default:defaulth px
G
%s*synth22
+-+--------------+----------+
2default:defaulth px
G
%s*synth22
+-+--------------+----------+
2default:defaulth px
>
%s*synth2)

Report Cell Usage: 
2default:defaulth px
?
%s*synth2*
+------+-----+------+
2default:defaulth px
?
%s*synth2*
|      |Cell |Count |
2default:defaulth px
?
%s*synth2*
+------+-----+------+
2default:defaulth px
?
%s*synth2*
|1     |BUFG |     1|
2default:defaulth px
?
%s*synth2*
|2     |LUT2 |     1|
2default:defaulth px
?
%s*synth2*
|3     |LUT3 |     6|
2default:defaulth px
?
%s*synth2*
|4     |LUT4 |     2|
2default:defaulth px
?
%s*synth2*
|5     |LUT5 |     3|
2default:defaulth px
?
%s*synth2*
|6     |LUT6 |     3|
2default:defaulth px
?
%s*synth2*
|7     |FDCE |     7|
2default:defaulth px
?
%s*synth2*
|8     |IBUF |     5|
2default:defaulth px
?
%s*synth2*
|9     |OBUF |     4|
2default:defaulth px
?
%s*synth2*
+------+-----+------+
2default:defaulth px
B
%s*synth2-

Report Instance Areas: 
2default:defaulth px
K
%s*synth26
"+------+---------+-------+------+
2default:defaulth px
K
%s*synth26
"|      |Instance |Module |Cells |
2default:defaulth px
K
%s*synth26
"+------+---------+-------+------+
2default:defaulth px
K
%s*synth26
"|1     |top      |       |    32|
2default:defaulth px
K
%s*synth26
"+------+---------+-------+------+
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
�Finished Writing Synthesis Report : Time (s): cpu = 00:00:06 ; elapsed = 00:00:24 . Memory (MB): peak = 471.910 ; gain = 294.844
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
o
%s*synth2Z
FSynthesis finished with 0 errors, 0 critical warnings and 0 warnings.
2default:defaulth px
�
%s*synth2�
~Synthesis Optimization Runtime : Time (s): cpu = 00:00:04 ; elapsed = 00:00:06 . Memory (MB): peak = 471.910 ; gain = 262.016
2default:defaulth px
�
%s*synth2�
Synthesis Optimization Complete : Time (s): cpu = 00:00:06 ; elapsed = 00:00:24 . Memory (MB): peak = 471.910 ; gain = 294.844
2default:defaulth px
?
 Translating synthesized netlist
350*projectZ1-571h px
b
-Analyzing %s Unisim elements for replacement
17*netlist2
52default:defaultZ29-17h px
g
2Unisim Transformation completed in %s CPU seconds
28*netlist2
02default:defaultZ29-28h px
H
)Preparing netlist for logic optimization
349*projectZ1-570h px
r
)Pushed %s inverter(s) to %s load pin(s).
98*opt2
02default:default2
02default:defaultZ31-138h px
{
!Unisim Transformation Summary:
%s111*project29
%No Unisim elements were transformed.
2default:defaultZ1-111h px
R
Releasing license: %s
83*common2
	Synthesis2default:defaultZ17-83h px
�
G%s Infos, %s Warnings, %s Critical Warnings and %s Errors encountered.
28*	vivadotcl2
202default:default2
02default:default2
02default:default2
02default:defaultZ4-41h px
[
%s completed successfully
29*	vivadotcl2 
synth_design2default:defaultZ4-42h px
�
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2"
synth_design: 2default:default2
00:00:052default:default2
00:00:252default:default2
531.9452default:default2
325.4922default:defaultZ17-268h px
�
sreport_utilization: Time (s): cpu = 00:00:00 ; elapsed = 00:00:00.047 . Memory (MB): peak = 531.945 ; gain = 0.000
*commonh px
}
Exiting %s at %s...
206*common2
Vivado2default:default2,
Wed May 23 12:55:07 20182default:defaultZ17-206h px