----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 22.05.2018 08:55:20
-- Design Name: 
-- Module Name: Freq_Divider - Behavioral
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

entity Freq_Divider is
    Port ( Clock : in STD_LOGIC;
           Reset : in STD_LOGIC;
           Enable_Out : out STD_LOGIC);
end Freq_Divider;

architecture Behavioral of Freq_Divider is

--constant Divider : integer := 10;
constant Divider : integer := 100000;
signal freq_counter: integer:= 10;

begin

frequency_divider: process (Clock,Reset)
  begin
    if (reset='1') then
      freq_counter<=Divider;
    elsif (Clock='1' and Clock'event) then
      if (freq_counter=0) then
        freq_counter <= Divider;
        enable_out <= '1';
      else
        freq_counter <= freq_counter-1;
        enable_out <='0';
      end if;
    end if;
  end process;


end Behavioral;
