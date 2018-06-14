----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 22.05.2018 08:55:20
-- Design Name: 
-- Module Name: Hour1_Count - Behavioral
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

entity Hour1_Count is
    Port ( --inputs
           Clock : in STD_LOGIC;
           Reset : in STD_LOGIC;
           Enable_In : in STD_LOGIC;
           BCD_Hour_10 : in STD_LOGIC_VECTOR (3 downto 0);
           --outputs
           Enable_Out : out STD_LOGIC;
           BCD_Out : out STD_LOGIC_VECTOR (3 downto 0));
end Hour1_Count;

architecture Behavioral of Hour1_Count is

signal count_int :  UNSIGNED (3 downto 0) := "0000";

begin

up_down_counter : process (Clock,Reset)
  begin
    if (Reset='1') then
     count_int<="0000";
    elsif (Clock='1' and Clock'event) then
      if enable_in='1' then
          if (count_int = "1001" OR (BCD_Hour_10 = "0010" AND count_int = "0011")) then
            count_int <= "0000";
            Enable_Out <= '1'; 
          else 
            count_int <= count_int + 1;
          end if;
          else
              Enable_Out <= '0';
      end if;
    end if;
  end process;

  BCD_Out <= STD_LOGIC_VECTOR(count_int);


end Behavioral;
