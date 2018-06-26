----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02.06.2018 12:59:11
-- Design Name: 
-- Module Name: Sec_Count - Behavioral
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

entity Sec_Count is
    Port ( Clock : in STD_LOGIC;
           Reset : in STD_LOGIC;
           Enable_In : in STD_LOGIC;
           Enable_Out : out STD_LOGIC;
           Sec_Blink : out STD_LOGIC;
           Dec_Blink : out STD_LOGIC
           );
end Sec_Count;

architecture Behavioral of Sec_Count is

Signal count_int : UNSIGNED (5 downto 0) :="000000";

begin 

up_down_counter : process (clock,reset)
begin
  if (reset='1') then
   count_int <= "000000";
  elsif (clock='1' and clock'event) then
    if (enable_in='1') then
        if (count_int = "111011") then
        count_int <= "000000";
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

Sec_Blink <= STD_LOGIC(count_int(0));
Dec_Blink <= STD_LOGIC(count_int(0));
end Behavioral;
