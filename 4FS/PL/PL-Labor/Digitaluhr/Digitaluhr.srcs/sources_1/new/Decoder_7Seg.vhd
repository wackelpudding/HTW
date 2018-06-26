----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02.06.2018 13:01:09
-- Design Name: 
-- Module Name: Decoder_7Seg - Behavioral
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

entity Decoder_7Seg is
    Port ( Clock : in STD_LOGIC;
           Reset : in STD_LOGIC;
           BCD_0 : in STD_LOGIC_VECTOR (3 downto 0);
           BCD_1 : in STD_LOGIC_VECTOR (3 downto 0);
           BCD_2 : in STD_LOGIC_VECTOR (3 downto 0);
           BCD_3 : in STD_LOGIC_VECTOR (3 downto 0);
           Dec_Point : in STD_LOGIC_VECTOR (3 downto 0);
           Seg_Driver : out STD_LOGIC_VECTOR (7 downto 0);
           Dev_Select : out STD_LOGIC_VECTOR (5 downto 0)
           );
end Decoder_7Seg;

architecture Behavioral of Decoder_7Seg is
Signal BCD_int: STD_LOGIC_VECTOR (3 downto 0) := "0000";
Signal DP : STD_LOGIC :='0';
constant Divider : integer := 1000; --Signale für div prozess
Signal freq_counter: integer:= 10;
Signal enable_1khz : STD_LOGIC :='0';
Signal counter : UNSIGNED (1 downto 0) :="00";
begin
Decoder_prozess: process (BCD_int,DP)
begin
 CASE BCD_int IS
    WHEN "0000" => Seg_Driver <= "1111110" & DP; --0
    WHEN "0001" => Seg_Driver <= "0110000" & DP; --1
    WHEN "0010" => Seg_Driver <= "1101101" & DP; --2
    WHEN "0011" => Seg_Driver <= "1111001" & DP; --3
    WHEN "0100" => Seg_Driver <= "0110011" & DP; --4
    WHEN "0101" => Seg_Driver <= "1011011" & DP; --5
    WHEN "0110" => Seg_Driver <= "1011111" & DP; --6
    WHEN "0111" => Seg_Driver <= "1110010" & DP; --7 
    WHEN "1000" => Seg_Driver <= "1111111" & DP; --8   
    WHEN "1001" => Seg_Driver <= "1111011" & DP; --9       
    WHEN OTHERS => Seg_Driver <= "1001111" & DP; --E
  END CASE;
end process;

freq_divider_1khz: process (clock,reset) -- Frequenzteiler
begin
  if (reset='1') then
    freq_counter<=Divider;
  elsif (clock='1' and clock'event) then
    if (freq_counter=0) then
      freq_counter <= Divider;
      enable_1khz <='1';
    else
      freq_counter <= freq_counter-1;
      enable_1khz <='0';
    end if;
  end if;
end process;

counter_zaehlen: process (clock,reset,enable_1khz) --Zähleprozess 0-3
begin
if (reset='1') then
counter <="00";
elsif (clock='1' and clock'event) then
    if (enable_1khz='1') then
        if (counter = "11") then
        counter <= "00";
        else 
        counter <= counter+1;
        end if;
    end if;
end if;
end process;

counter_select: process (counter,clock,reset) -- Auswahl der Anzeige
begin
if (clock='1' and clock'event) then
    CASE counter IS
                WHEN "00" => 
                    Dev_Select <= "111110";
                    BCD_int    <= BCD_0;
                    DP         <= Dec_Point(0);
                WHEN "01" => 
                    Dev_Select <= "111101";
                    BCD_int    <= BCD_1;
                    DP         <= Dec_Point(1);
                WHEN "10" =>                   
                    Dev_Select <= "111011";      
                    BCD_int    <= BCD_2;       
                    DP         <= Dec_Point(2); 
                WHEN "11" =>                   
                    Dev_Select <= "110111";      
                    BCD_int    <= BCD_3;       
                    DP         <= Dec_Point(3);   
                WHEN OTHERS => null; 
    END CASE;
end if;
end process;
end Behavioral;
