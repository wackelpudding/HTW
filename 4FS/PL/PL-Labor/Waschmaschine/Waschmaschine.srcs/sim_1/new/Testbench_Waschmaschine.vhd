----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 11.12.2017 23:04:18
-- Design Name: 
-- Module Name: testbench_waschmaschine - Behavioral
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

entity testbench_waschmaschine is
--  Port ( );
end testbench_waschmaschine;

architecture Behavioral of testbench_waschmaschine is

component Waschmaschine is
 Port ( 
 clk : in STD_LOGIC;
 reset : in STD_LOGIC;
 start : in STD_LOGIC;
 wasser : in STD_LOGIC;
 temperature : in STD_LOGIC;
 pumpe : out STD_LOGIC;
 ventil : out STD_LOGIC;
 heizung : out STD_LOGIC;
 motor : out STD_LOGIC
  );
end component;

signal clk   : STD_LOGIC := '0';
signal reset : STD_LOGIC := '1';
signal temperature  : STD_LOGIC := '0';
signal wasser : STD_LOGIC := '0';
signal start : STD_LOGIC := '0';
signal motor : STD_LOGIC := '0';
signal ventil : STD_LOGIC := '0';
signal heizung : STD_LOGIC := '0';
signal pumpe : STD_LOGIC := '0';

   -- Clock period definitions
constant clock_period : time := 10 ns;
   
begin


 Blub : waschmaschine 
 Port map ( 
    clk => clk,
    reset => reset,
    temperature => temperature,
    wasser => wasser,
    start => start,
    motor => motor,
    ventil => ventil,
    heizung => heizung,
    pumpe => pumpe
  );

  clk <= not clk after clock_period/2;

   stimulus_proc: process
   begin		
		wait for 30 ns;
		reset <= '0';

        -- Zustand: Idle

        -- start der Waschmaschine
		wait for 50 ns;
		start <= '1';
       
        -- Zustand: Zulauf
       
        -- Wasser voll
		wait for 50 ns;
        wasser <= '1';

        -- Zustand: Heizen
        
        -- Wasser warm
		wait for 50 ns;
        temperature <= '1';

        -- Zustand: waschen

        -- Waschzeit abwarten 
		wait for 120 ns;

        -- Zustand: abpumpen

		wait for 50 ns;
        wasser <= '0';

        -- Zustand: Idle

        start <= '0';
        temperature  <= '0';

        wait ;	

      wait;
   end process;

end Behavioral;
