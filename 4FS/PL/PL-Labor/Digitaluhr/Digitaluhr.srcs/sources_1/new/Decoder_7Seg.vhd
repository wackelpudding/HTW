----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 22.05.2018 08:55:20
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
    Port ( --input
           Clock : in STD_LOGIC;
           Reset : in STD_LOGIC;
           BCD_0 : in STD_LOGIC_VECTOR (3 downto 0);
           BCD_1 : in STD_LOGIC_VECTOR (3 downto 0);
           BCD_2 : in STD_LOGIC_VECTOR (3 downto 0);
           BCD_3 : in STD_LOGIC_VECTOR (3 downto 0);
           Dec_Point : in STD_LOGIC_VECTOR (3 downto 0);
           --output
           Seg_Driver : out STD_LOGIC_VECTOR (7 downto 0);
           Dev_Select : out STD_LOGIC_VECTOR (3 downto 0));
end Decoder_7Seg;

architecture Behavioral of Decoder_7Seg is

signal BCD_int :  STD_LOGIC_VECTOR (3 downto 0) := "0000";
signal DP :  STD_LOGIC := '0';
signal Enable_1kHz : STD_LOGIC := '0';
signal counter : UNSIGNED (1 downto 0) := "00";

constant Divider : integer := 1000;
--constant Divider : integer := 10000000;
signal freq_counter: integer:= 10;

begin

decoder : process (BCD_int,DP)
begin
  CASE BCD_int IS
    WHEN "0000" => Seg_Driver <= "1111110" & DP; --0
    WHEN "0001" => Seg_Driver <= "0110000" & DP; --1
    WHEN "0010" => Seg_Driver <= "1101101" & DP; --2
    WHEN "0011" => Seg_Driver <= "1111001" & DP; --3
    WHEN "0100" => Seg_Driver <= "0110011" & DP; --4
    WHEN "0101" => Seg_Driver <= "1011011" & DP; --5
    WHEN "0110" => Seg_Driver <= "1011111" & DP; --6
    WHEN "0111" => Seg_Driver <= "1110000" & DP; --7
    WHEN "1000" => Seg_Driver <= "1111111" & DP; --8
    WHEN "1001" => Seg_Driver <= "1111011" & DP; --9
    WHEN OTHERS => Seg_Driver <= "1001111" & DP; --E
  END CASE;
end process;


frequency_divider: process (Clock,Reset)
  begin
    if (reset='1') then
      freq_counter<=Divider;
    elsif (Clock='1' and Clock'event) then
      if (freq_counter=0) then
        freq_counter <= Divider;
        Enable_1kHz <= '1';
      else
        freq_counter <= freq_counter-1;
        Enable_1kHz <='0';
      end if;
    end if;
  end process;
  
Bounter: process (Enable_1kHz, clock, reset)
    begin
    if (reset='1') then
        counter <= "00";
    elsif (clock='1' and clock'event) then
        if (Enable_1kHz = '1') then
            if (counter = "11") then
                counter <= "00";
            else
                counter <= counter + 1;
            end if;
     end if;
     end if;
end process;
    
multiplexer: process (counter, clock, reset)
begin
    if (clock='1' and clock'event) then
        CASE counter IS
            WHEN "00" => 
                Dev_Select <= "1110";
                BCD_int    <= BCD_0;
                DP         <= Dec_Point(0);
            WHEN "01" => 
                Dev_Select <= "1101";
                BCD_int    <= BCD_1;
                DP         <= Dec_Point(1);
            WHEN "10" => 
                Dev_Select <= "1011";
                BCD_int    <= BCD_2;
                DP         <= Dec_Point(2);
            WHEN "11" => 
                Dev_Select <= "0111";
                BCD_int    <= BCD_3;
                DP         <= Dec_Point(3);
            WHEN OTHERS => NULL;
        END CASE;
    end if;
end process;



--BCD_int <= BCD_0; 
--Dev_Select <= "1110";
--DP <= Dec_Point(0);

end Behavioral;
