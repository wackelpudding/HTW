----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02.06.2018 14:02:08
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


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Testbench_Digitaluhr is
--  Port ( );
end Testbench_Digitaluhr;

architecture Behavioral of Testbench_Digitaluhr is

COMPONENT Digitaluhr
  PORT
  (
        clock : IN  std_logic;
        reset : IN  std_logic;
        sel_btn : IN STD_LOGIC;
        inc_btn : IN STD_LOGIC;
        mode_btn : IN STD_LOGIC;
        Driver_7Seg : OUT  std_logic_vector(7 downto 0);
        Selector_7Seg : OUT  std_logic_vector(5 downto 0)
   );
END COMPONENT;

--Inputs
signal clock : std_logic := '0';
signal reset : std_logic := '0';
signal sel_btn : STD_LOGIC :='0';
signal inc_btn : STD_LOGIC :='0';
signal mode_btn : STD_LOGIC :='0';


--Outputs
signal Driver_7Seg : std_logic_vector(7 downto 0);
signal Selector_7Seg : std_logic_vector(5 downto 0);

-- Clock period definitions
constant clock_period : time := 10 ns;
 
BEGIN
 
uut: Digitaluhr PORT MAP (
          clock => clock,
          reset => reset,
          mode_btn => mode_btn,
          sel_btn => sel_btn,
          inc_btn =>  inc_btn,
          Driver_7Seg => Driver_7Seg,
          Selector_7Seg => Selector_7Seg
        );

clock_process : process
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

end behavioral;
