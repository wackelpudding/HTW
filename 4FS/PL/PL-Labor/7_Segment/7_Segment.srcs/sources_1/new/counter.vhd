----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 04/17/2018 08:40:44 AM
-- Design Name: 
-- Module Name: counter - Behavioral
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

entity counter is
    Port ( clock : in STD_LOGIC;
           reset : in STD_LOGIC;
           direction : in STD_LOGIC;
           count_out : out STD_LOGIC_VECTOR (3 downto 0);
           Driver_7Seg : out  STD_LOGIC_VECTOR(6 downto 0);
           CA : out STD_LOGIC);
end counter;

architecture Behavioral of counter is


--constant Divider : integer := 100000000;  
constant Divider : integer := 9;
signal freq_counter: integer:= 9;    
signal enable_count :  STD_LOGIC;
signal count_int :  UNSIGNED (3 downto 0);

begin

frequency_divider : process (clock,reset)
  begin
    if (reset='1') then
      freq_counter<=Divider;
    elsif (clock='1' and clock'event) then
      if (freq_counter=1) then
        freq_counter <= Divider;
        enable_count <= '1';
      else
        freq_counter <= freq_counter-1;
        enable_count <='0';
      end if;
    end if;
  end process;

  up_down_counter : process (clock,reset)
  begin
    if (reset='1') then
     count_int<="0000";
    elsif (clock='1' and clock'event) then
      if enable_count='1' then
        if DIRECTION='1' then  
          count_int <= count_int + 1;
        else
          count_int <= count_int - 1;
        end if;
      end if;
    end if;
  end process;
  
  decoder : process (count_int)
  begin
  if (clock='1' and clock'event) then
  case  count_int is
  when "0000"=> Driver_7Seg <="1111110";  -- '0'
  when "0001"=> Driver_7Seg <="0110000";  -- '1'
  when "0010"=> Driver_7Seg <="1101101";  -- '2'
  when "0011"=> Driver_7Seg <="1111001";  -- '3'
  when "0100"=> Driver_7Seg <="0110011";  -- '4' 
  when "0101"=> Driver_7Seg <="1011011";  -- '5'
  when "0110"=> Driver_7Seg <="1011111";  -- '6'
  when "0111"=> Driver_7Seg <="1110000";  -- '7'
  when "1000"=> Driver_7Seg <="1111111";  -- '8'
  when "1001"=> Driver_7Seg <="1111011";  -- '9'
  when others=> Driver_7Seg <="1001111";  -- 'E'
  end case;
  end if;
  end process;
  
  CA <= '1';
  COUNT_OUT <= STD_LOGIC_VECTOR(count_int);


end Behavioral;
