----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 11.06.2018 14:10:48
-- Design Name: 
-- Module Name: PulseGenerator - Behavioral
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
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity PulseGenerator is
    Port ( clock : in STD_LOGIC;
           reset : in STD_LOGIC;
           taster_in : in STD_LOGIC;
           pulse_out : out STD_LOGIC
          );
end PulseGenerator;

architecture Behavioral of PulseGenerator is

constant MAX_WERT : integer := 1000000; --10ns auf 10ms faktor 1mio
Signal counter: integer:= 0;
Signal out_debounced : STD_LOGIC := '0';
Signal reg1 : STD_LOGIC := '0';
Signal reg2 : STD_LOGIC := '0';
begin

Zaehlerprozess: process (clock,reset)--Zählprozess (Überbrückung)
begin
  if (reset='1') then
    counter <= 0;
  elsif (clock='1' and clock'event) then
    if (taster_in='0') then
      counter <= 0;
    elsif (counter = MAX_WERT) then
      counter <= MAX_WERT;
    elsif (taster_in ='1') then 
      counter <= counter + 1;
    else
    null;
    end if;
  end if;
end process;

Ausgabe_process: process (counter) --Ausgabe
begin
  if (counter = MAX_WERT) then
    out_debounced <= '1';
  else 
    out_debounced <= '0';
  end if;
end process;

RegisterFlipFlopzwei: process (clock, out_debounced) --Flankenerkennung (High-Impuls 1Takt lang)
begin
  if (clock='1' and clock'event) then
    reg1 <= out_debounced;
    reg2 <= reg1;
  end if;
end process;

pulse_out <= (reg1 and not(reg2));

end Behavioral;
