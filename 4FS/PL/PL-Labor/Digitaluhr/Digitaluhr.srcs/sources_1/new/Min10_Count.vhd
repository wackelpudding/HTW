----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02.06.2018 12:57:42
-- Design Name: 
-- Module Name: Min10_Count - Behavioral
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

entity Min10_Count is
    Port ( Clock : in STD_LOGIC;
           Reset : in STD_LOGIC;
           Enable_In : in STD_LOGIC;
           Enable_Out : out STD_LOGIC;
           BCD_Out : out STD_LOGIC_VECTOR (3 downto 0)
           );
end Min10_Count;

architecture Behavioral of Min10_Count is
signal count_int :  UNSIGNED (3 downto 0) := "0000";
begin
up_down_counter: process (clock,reset) -- Zählprozess
begin
  if (reset='1') then
   count_int <= "0000";
  elsif (clock='1' and clock'event) then
    if (enable_in='1') then
        if (count_int = "0101") then
        count_int <= "0000";
        enable_out <= '1';
        else
        count_int <= count_int + 1;
        enable_out <='0';
        end if;
     else
     enable_out <='0';
     end if;
  end if;
end process;
BCD_Out <= STD_LOGIC_VECTOR(count_int);
end Behavioral;
