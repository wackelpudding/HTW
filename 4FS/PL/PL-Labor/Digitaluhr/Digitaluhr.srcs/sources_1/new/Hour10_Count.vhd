----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02.06.2018 12:57:42
-- Design Name: 
-- Module Name: Hour10_Count - Behavioral
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

entity Hour10_Count is
    Port ( Clock : in STD_LOGIC;
           Reset : in STD_LOGIC;
           Enable_In : in STD_LOGIC;
           BCD_Hour_1 : in STD_LOGIC_VECTOR (3 downto 0);
           Einstellmodus : in STD_LOGIC;
           Enable_Out : out STD_LOGIC;
           BCD_Out : out STD_LOGIC_VECTOR (3 downto 0);
           AM_Signal: out STD_LOGIC;
           PM_Signal: out STD_LOGIC
           );
end Hour10_Count;

architecture Behavioral of Hour10_Count is
signal count_int :  UNSIGNED (3 downto 0) := "0000";
begin
up_down_counter: process (clock,reset)
begin
  if (reset='1') then
   count_int <= "0000";
  elsif (clock='1' and clock'event) then
    if (enable_in ='1') then
        if (count_int = "0010" OR (Einstellmodus ='1' AND count_int = "0001" AND BCD_Hour_1 >= "0100"))then
        count_int <= "0000";
        else
        count_int <= count_int +1;
        end if;
     else
     null;
    end if;
  end if;
end process;

ampm: process (clock,reset)
begin 
if (clock='1' and clock'event) then
    if (count_int = "0000") then
    AM_Signal <='1';
    PM_Signal <='0';
    elsif (count_int = "0001") then
        if (BCD_Hour_1 >= "0010") then
        AM_Signal <='0';
        PM_Signal <='1';
        else
        AM_Signal <='1';
        PM_Signal <='0';
        end if;
    elsif (count_int = "010") then
    AM_Signal <='0';    
    PM_Signal <='1';
    else
    null;
    end if;
end if;
end process;
BCD_Out <= STD_LOGIC_VECTOR(count_int);
end Behavioral;
