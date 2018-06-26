----------------------------------------------------------------------------------
-- Engineers : Reinhard Scheuer, Ricardo Jimenez Tuero
-- Create Date: 02.06.2018 12:53:30 
-- Design Name: Digitaluhr
-- Module Name: Digitaluhr - Behavioral
-- Project Name: Programmierbare Logic: Digitaluhr
-- Target Devices: ZED-Board
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Digitaluhr is
    Port ( clock : in STD_LOGIC;
           reset : in STD_LOGIC;
           Driver_7Seg : out STD_LOGIC_VECTOR (7 downto 0);
           Selector_7Seg : out STD_LOGIC_VECTOR (5 downto 0);
           Sec_Blink : out STD_LOGIC;
           AM_LED : out STD_LOGIC;
           PM_LED : out STD_LOGIC;
           sel_btn : in STD_LOGIC;
           inc_btn : in STD_LOGIC;
           mode_btn : in STD_LOGIC
           );
end Digitaluhr;

architecture Behavioral of Digitaluhr is

COMPONENT PulseGenerator is 
    Port (
          clock : in STD_LOGIC;    
          reset : in STD_LOGIC;    
          taster_in : in STD_LOGIC;
          pulse_out : out STD_LOGIC
          );
end Component;

COMPONENT Settings is
    Port (
           clock : in STD_LOGIC;
           reset : in STD_LOGIC;
           mode : in STD_LOGIC;
           sel : in STD_LOGIC;
           inc : in STD_LOGIC;
           enable_M1_src : in STD_LOGIC;
           enable_M10_src : in STD_LOGIC;
           enable_H1_src : in STD_LOGIC;
           enable_H10_src : in STD_LOGIC;
           enable_M1_dest : out STD_LOGIC;
           enable_M10_dest : out STD_LOGIC;
           enable_H1_dest : out STD_LOGIC;
           enable_H10_dest : out STD_LOGIC;
           DP_M1 : out  STD_LOGIC;
           DP_M10 : out STD_LOGIC;
           DP_H1 : out STD_LOGIC;
           DP_H10 : out STD_LOGIC;
           Einstellmodus : out STD_LOGIC
           );
end COMPONENT;

COMPONENT Min10_Count is
       PORT(
             clock  : IN  STD_LOGIC;
             reset  : IN  STD_LOGIC;
             Enable_In: IN  STD_LOGIC;
             Enable_Out: OUT STD_LOGIC;
             BCD_Out: OUT STD_LOGIC_VECTOR(3 downto 0)
       );
END COMPONENT;

COMPONENT Min1_Count is
        Port(
             clock : in STD_LOGIC;
             reset : in STD_LOGIC;
             Enable_In : in STD_LOGIC;
             Enable_Out : out STD_LOGIC;
             BCD_Out : out STD_LOGIC_VECTOR (3 downto 0)
        );
END Component;

COMPONENT Hour1_Count is
        Port(
           clock : in STD_LOGIC;
           reset : in STD_LOGIC;
           Enable_In : in STD_LOGIC;
           Enable_Out : out STD_LOGIC;
           BCD_Out : out STD_LOGIC_VECTOR (3 downto 0);
           BCD_Hour_10 : in STD_LOGIC_VECTOR (3 downto 0)
        );
END COMPONENT;

COMPONENT Hour10_Count is
        Port(
           clock : in STD_LOGIC;
           reset : in STD_LOGIC;
           Enable_In : in STD_LOGIC;
           BCD_Hour_1 : in STD_LOGIC_VECTOR (3 downto 0);
           Einstellmodus : in STD_LOGIC;
           Enable_Out : out STD_LOGIC;
           BCD_Out : out STD_LOGIC_VECTOR (3 downto 0);
           AM_Signal: out STD_LOGIC;
           PM_Signal: out STD_LOGIC
           );
END COMPONENT;

COMPONENT Sec_Count is
        Port(
           clock : in STD_LOGIC;
           reset : in STD_LOGIC;
           Enable_In : in STD_LOGIC;
           Enable_Out : out STD_LOGIC;
           Sec_Blink : out STD_LOGIC;
           Dec_Blink : out STD_LOGIC
        );
end COMPONENT;

COMPONENT Decoder_7Seg is
        Port(
           clock : in STD_LOGIC;
           reset : in STD_LOGIC;
           BCD_0 : in STD_LOGIC_VECTOR (3 downto 0);
           BCD_1 : in STD_LOGIC_VECTOR (3 downto 0);
           BCD_2 : in STD_LOGIC_VECTOR (3 downto 0);
           BCD_3 : in STD_LOGIC_VECTOR (3 downto 0);
           Dec_Point : in STD_LOGIC_VECTOR (3 downto 0);
           Seg_Driver : out STD_LOGIC_VECTOR (7 downto 0);
           Dev_Select : out STD_LOGIC_VECTOR (5 downto 0)
        );
end COMPONENT;

COMPONENT Freq_Divider is
        Port(
           clock : in STD_LOGIC;
           reset : in STD_LOGIC;
           Enable_Out : out STD_LOGIC
        );
end COMPONENT;

Signal Enable_Sec : STD_LOGIC;
Signal Enable_Min1 : STD_LOGIC;
Signal Enable_Min10 : STD_LOGIC;
Signal Enable_Hour1 : STD_LOGIC;
Signal Enable_Hour10 : STD_LOGIC;
Signal BCD_Min1 : STD_LOGIC_VECTOR (3 downto 0);
Signal BCD_Min10 : STD_LOGIC_VECTOR (3 downto 0);
Signal BCD_Hour1 : STD_LOGIC_VECTOR (3 downto 0);
Signal BCD_Hour10 : STD_LOGIC_VECTOR (3 downto 0);
Signal DEC_Point : STD_LOGIC;

Signal enable_M1_src : STD_LOGIC;
Signal enable_M10_src : STD_LOGIC;
Signal enable_M1_dest : STD_LOGIC;
Signal enable_M10_dest : STD_LOGIC;
Signal enable_H1_src : STD_LOGIC;
Signal enable_H10_src : STD_LOGIC;
Signal enable_H1_dest : STD_LOGIC;
Signal enable_H10_dest : STD_LOGIC;

Signal mode_pulse : STD_LOGIC;
Signal sel_pulse : STD_LOGIC;
Signal inc_pulse : STD_LOGIC;

Signal DP_M1_s : STD_LOGIC;
Signal DP_M10_s : STD_LOGIC;
Signal DP_H1_s : STD_LOGIC;
Signal DP_H10_s : STD_LOGIC;

Signal Einstellmodus_Aktiv : STD_LOGIC;

begin

Min1_Count_inst: Min1_Count PORT MAP (
         clock => clock,
         reset => reset,
         Enable_In => enable_M1_dest,
         Enable_Out => enable_M10_src,           
         BCD_Out => BCD_Min1      
);

Min10_Count_inst: Min10_Count PORT MAP (
         clock => clock,
         reset => reset,
         Enable_In => enable_M10_dest,
         Enable_Out => enable_H1_src,           
         BCD_Out => BCD_Min10      
);

Hour1_Count_inst: Hour1_Count PORT MAP (
         clock => clock,
         reset => reset,
         Enable_In => enable_H1_dest,
         Enable_Out => enable_H10_src,        
         BCD_Out => BCD_Hour1,
         BCD_Hour_10 => BCD_Hour10  
);

Hour10_Count_inst: Hour10_Count PORT MAP (
         clock => clock,
         reset => reset,
         Enable_In => enable_H10_dest,
         Enable_Out => open,           
         BCD_Out => BCD_Hour10,
         BCD_Hour_1 => BCD_Hour1,
         AM_Signal => AM_LED,
         PM_Signal => PM_LED,
         Einstellmodus => Einstellmodus_aktiv
);

Sec_Count_inst: Sec_Count PORT MAP (
          clock => clock,
          reset => reset,
          Enable_In => Enable_Sec,
          Enable_Out => enable_M1_src,
          Sec_Blink => Sec_Blink,
          Dec_Blink => DEC_Point
);

Decoder_7Seg_inst: Decoder_7Seg PORT MAP (
           clock => clock,
           reset => reset,
           BCD_0 => BCD_Min1,
           BCD_1 => BCD_Min10,
           BCD_2 => BCD_Hour1,
           BCD_3 => BCD_Hour10,
           Dec_Point(0) => DP_M1_s,
           Dec_Point(1) => DP_M10_s,
           Dec_Point(2) => DP_H1_s,
           Dec_Point(3) => DP_H10_s,
           Seg_Driver => Driver_7Seg,
           Dev_Select => Selector_7Seg
);

Freq_Divider_inst: Freq_Divider PORT MAP (
           clock => clock,
           reset => reset,
           Enable_Out => Enable_Sec
);

Settings_inst: Settings PORT MAP (
          clock => clock,
          reset => reset,
          mode => mode_pulse,
          sel => sel_pulse,
          inc => inc_pulse,
          enable_M1_src => enable_M1_src,
          enable_M10_src => enable_M10_src,
          enable_H1_src => enable_H1_src,
          enable_H10_src => enable_H10_src,
          enable_M1_dest => enable_M1_dest,
          enable_M10_dest => enable_M10_dest,
          enable_H1_dest => enable_H1_dest,
          enable_H10_dest => enable_H10_dest,
          DP_M1 => DP_M1_s,
          DP_M10 => DP_M10_s,
          DP_H1 => DP_H1_s,
          DP_H10 => DP_H10_s,
          Einstellmodus => Einstellmodus_Aktiv
);

mode_PulseGenerator: PulseGenerator PORT MAP (
        clock => clock,
        reset => reset,
        taster_in => mode_btn,        
        pulse_out => mode_pulse    
);
sel_PulseGenerator: PulseGenerator PORT MAP (
        clock => clock,
        reset => reset,
        taster_in => sel_btn,        
        pulse_out => sel_pulse    
);
inc_PulseGenerator: PulseGenerator PORT MAP (
        clock => clock,
        reset => reset,
        taster_in => inc_btn,        
        pulse_out => inc_pulse    
);

end Behavioral;
