----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 04/17/2018 08:50:31 AM
-- Design Name: 
-- Module Name: testbench_counter - Behavioral
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

entity testbench_counter is
--  Port ( );
end testbench_counter;

architecture Behavioral of testbench_counter is

  component counter
    Port ( clock : in STD_LOGIC;
             reset : in STD_LOGIC;
             direction : in STD_LOGIC;
             count_out : out STD_LOGIC_VECTOR (3 downto 0);
             Driver_7Seg : out  STD_LOGIC_VECTOR(6 downto 0);
             CA : out STD_LOGIC := 1);
  end component; 

  -- This has been copied from the language templates
  -- Simulation Constructs -> Clock Stimulus -> Constants
  constant PERIOD : time := 10 ns;
 
  signal sig_clock: STD_LOGIC := '0';
  signal sig_reset: STD_LOGIC := '1';
  signal sig_direction: STD_LOGIC := '1';
  signal sig_count_out: STD_LOGIC_VECTOR(3 downto 0) := (OTHERS => '0');

begin
 
  counter_inst : counter
    port map(
      clock => sig_clock,
      reset => sig_reset,
      direction => sig_direction,
      count_out => sig_count_out
    );

  -- This has been copied from the language templates
  -- Simulation Constructs -> Clock Stimulus -> 50 % Duty Cycle
  sig_clock <= not sig_clock after PERIOD/2;

  process
  begin
       wait for 30 ns;
       sig_reset <= '0';

       wait for 300 ns;    
       sig_direction <= '0';
       wait for 500 ns;
       
       wait;
  end process;

end Behavioral;
