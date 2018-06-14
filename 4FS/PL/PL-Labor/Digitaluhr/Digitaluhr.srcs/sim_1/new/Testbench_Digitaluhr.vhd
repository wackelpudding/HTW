----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 22.05.2018 09:35:46
-- Design Name: 
-- Module Name: Testbench_Digitaluhr - Behavioral
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

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY Testbench_Digitaluhr IS
END Testbench_Digitaluhr;
 
ARCHITECTURE behavior OF Testbench_Digitaluhr IS 

    COMPONENT Digitaluhr
    PORT(
         clock : IN  std_logic;
         reset : IN  std_logic;
         Driver_7Seg : OUT  std_logic_vector(7 downto 0);
         Selector_7Seg : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    
   --Inputs
   signal clock : std_logic := '0';
   signal reset : std_logic := '0';


     --Outputs
   signal Driver_7Seg : std_logic_vector(7 downto 0);
   signal Selector_7Seg : std_logic_vector(3 downto 0);

   -- Clock period definitions
   constant clock_period : time := 10 ns;
 
BEGIN
 
   uut: Digitaluhr PORT MAP (
          clock => clock,
          reset => reset,
          Driver_7Seg => Driver_7Seg,
          Selector_7Seg => Selector_7Seg
        );

   clock_process :process
   begin
        clock <= '0';
        wait for clock_period/2;
        clock <= '1';
        wait for clock_period/2;
   end process;
 
   stim_proc: process
   begin        
      -- hold reset state for 100 ns.
        wait for 100 ns;
        reset <= '1';
        wait for 30 ns;
        reset <= '0';

      -- add further stimuli here

      wait for clock_period*1000;

      wait;
   end process;

END;
