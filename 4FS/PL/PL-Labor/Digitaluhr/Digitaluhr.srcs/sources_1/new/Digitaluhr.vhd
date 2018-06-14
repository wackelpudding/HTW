----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 22.05.2018 08:55:20
-- Design Name: 
-- Module Name: Digitaluhr - Behavioral
-- Project Name: 
-- Target Devices: 
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
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Digitaluhr is
    Port ( Clock : in STD_LOGIC;
           Reset : in STD_LOGIC;
           Driver_7Seg : out STD_LOGIC_VECTOR (7 downto 0);
           Selector_7Seg : out STD_LOGIC_VECTOR (3 downto 0));
end Digitaluhr;

architecture Behavioral of Digitaluhr is
COMPONENT Min10_Count
    PORT(
          Clock  : IN  STD_LOGIC;
          Reset  : IN  STD_LOGIC;
          Enable_In: IN  STD_LOGIC;
          Enable_Out: OUT STD_LOGIC;
          BCD_Out: OUT STD_LOGIC_VECTOR(3 downto 0)
          );
end COMPONENT Min10_Count;

COMPONENT Hour10_Count is
    Port ( Clock : in STD_LOGIC;
           Reset : in STD_LOGIC;
           Enable_In : in STD_LOGIC;
           Enable_Out : out STD_LOGIC;
           BCD_Out : out STD_LOGIC_VECTOR (3 downto 0));
end COMPONENT Hour10_Count;

COMPONENT Hour1_Count is
    Port ( Clock : in STD_LOGIC;
           Reset : in STD_LOGIC;
           Enable_In : in STD_LOGIC;
           BCD_Hour_10 : in STD_LOGIC_VECTOR (3 downto 0);
           Enable_Out : out STD_LOGIC;
           BCD_Out : out STD_LOGIC_VECTOR (3 downto 0));
end COMPONENT Hour1_Count;

COMPONENT Min1_Count is
    Port ( Clock : in STD_LOGIC;
           Reset : in STD_LOGIC;
           Enable_In : in STD_LOGIC;
           Enable_Out : out STD_LOGIC;
           BCD_Out : out STD_LOGIC_VECTOR (3 downto 0));
end COMPONENT Min1_Count;

Component Decoder_7Seg is
    Port ( Clock : in STD_LOGIC;
           Reset : in STD_LOGIC;
           BCD_0 : in STD_LOGIC_VECTOR (3 downto 0);
           BCD_1 : in STD_LOGIC_VECTOR (3 downto 0);
           BCD_2 : in STD_LOGIC_VECTOR (3 downto 0);
           BCD_3 : in STD_LOGIC_VECTOR (3 downto 0);
           Dec_Point : in STD_LOGIC_VECTOR (3 downto 0);
           Seg_Driver : out STD_LOGIC_VECTOR (7 downto 0);
           Dev_Select : out STD_LOGIC_VECTOR (3 downto 0));
end Component Decoder_7Seg;

COMPONENT Sec_Count is
   Port (
   Clock : in STD_LOGIC;
   Reset : in STD_LOGIC;
   Enable_In : in STD_LOGIC;
   Enable_Out : out STD_LOGIC;           
   Sec_Blink : out STD_LOGIC);
END COMPONENT Sec_Count;

component Freq_Divider is
    Port ( Clock : in STD_LOGIC;
           Reset : in STD_LOGIC;
           Enable_Out : out STD_LOGIC);
end component Freq_Divider;

SIGNAL Enable_Sec : STD_LOGIC;
SIGNAL Enable_Min1 : STD_LOGIC;
SIGNAL Enable_Min10 : STD_LOGIC;
SIGNAL Enable_Hour1 : STD_LOGIC;
SIGNAL Enable_Hour10 : STD_LOGIC;
SIGNAL BCD_Min1 : STD_LOGIC_VECTOR (3 downto 0);
SIGNAL BCD_Min10 : STD_LOGIC_VECTOR (3 downto 0);
SIGNAL BCD_Hour1 : STD_LOGIC_VECTOR (3 downto 0);
SIGNAL BCD_Hour10 : STD_LOGIC_VECTOR (3 downto 0);
SIGNAL DEC_Point : STD_LOGIC;

begin

Min1_Count_inst: Min1_Count PORT MAP (
    Clock => Clock,
    Reset => Reset,
    Enable_In => ENABLE_Min1,
    Enable_Out => ENABLE_Min10,           
    BCD_Out => BCD_Min1      
);
   
Min10_Count_inst: Min10_Count PORT MAP (
    Clock => Clock,
    Reset => Reset,
    Enable_In => ENABLE_Min10,
    Enable_Out => ENABLE_Hour1,           
    BCD_Out => BCD_Min10      
);

Hour1_Count_inst: Hour1_Count PORT MAP (
    Clock => Clock,
    Reset => Reset,
    Enable_In => ENABLE_Hour1,
    BCD_Hour_10 => BCD_Hour10,
    Enable_Out => ENABLE_Hour10,           
    BCD_Out => BCD_Hour1      
);

Hour10_Count_inst: Hour10_Count PORT MAP (
    Clock => Clock,
    Reset => Reset,
    Enable_In => ENABLE_Min10,
    Enable_Out => open,           
    BCD_Out => BCD_Hour10      
);
      
Sec_Count_inst: Sec_Count PORT MAP (
   Clock => Clock,
   Reset => Reset,
   Enable_In => Enable_Sec,
   Enable_Out => ENABLE_Min1,           
   Sec_Blink => DEC_Point      
);          
                        
Decoder_7Seg_inst: Decoder_7Seg PORT MAP (
    Clock => Clock,
    Reset => Reset,
    BCD_0 => BCD_Min1,
    BCD_1 => BCD_Min10,
    BCD_2 => BCD_Hour1,
    BCD_3 => BCD_Hour10,
    Dec_Point(0) => Dec_Point,
    Dec_Point(1) => Dec_Point,
    Dec_Point(2) => Dec_Point,
    Dec_Point(3) => Dec_Point,
    Seg_Driver => Driver_7Seg,
    Dev_Select => Selector_7Seg
);

Freq_Divider_inst: Freq_Divider PORT MAP (
    Clock => Clock,
    Reset => Reset,
    enable_out => Enable_Sec
);        
      
end Behavioral;
