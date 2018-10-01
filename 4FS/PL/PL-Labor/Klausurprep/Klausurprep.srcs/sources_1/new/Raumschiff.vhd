----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 27.06.2018 12:04:08
-- Design Name: 
-- Module Name: Raumschiff - Behavioral
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

entity Raumschiff is
    Port ( 
           -- process 1 in/out
           a : in STD_LOGIC;
           b : in STD_LOGIC;
           c : in STD_LOGIC;
           d : in STD_LOGIC;
           e : in STD_LOGIC;
           x : out STD_LOGIC;
           
           -- process 2 in/out
           f : in STD_LOGIC_VECTOR (3 downto 0);
           y : out STD_LOGIC_VECTOR (7 downto 0);
           
           -- process 3 in/out
           g : in STD_LOGIC_VECTOR (3 downto 0);
           h : in STD_LOGIC_VECTOR (3 downto 0);
           j : in STD_LOGIC_VECTOR (3 downto 0);
           sel : in STD_LOGIC;
           clk : in STD_LOGIC;
           reset : in STD_LOGIC;
           z : out STD_LOGIC_VECTOR (7 downto 0)
           );        
end Raumschiff;

architecture Behavioral of Raumschiff is
--signale p1
--keine ;)

--signale p2
--keine ;)

--signale p3
SIGNAL DFF1_2_MULT : UNSIGNED (3 downto 0) := "0000";
SIGNAL DFF2_2_DFF3 : UNSIGNED (7 downto 0) := "00000000";

SIGNAL z1 : STD_LOGIC;
SIGNAL x1 : STD_LOGIC_VECTOR (3 downto 0);

COMPONENT COMP1
    PORT(
        x : in STD_LOGIC;
        y : in STD_LOGIC;
        z : out STD_LOGIC
    );
END COMPONENT COMP1;

COMPONENT COMP2
    PORT(
        u : in STD_LOGIC_VECTOR (3 downto 0);
        v : in STD_LOGIC_VECTOR (3 downto 0);
        x : out STD_LOGIC_VECTOR (3 downto 0)
    );
END COMPONENT COMP2;

COMPONENT COMP3
    PORT(
        a : in STD_LOGIC;
        c : in STD_LOGIC_VECTOR (3 downto 0);
        y : out STD_LOGIC_VECTOR (3 downto 0)
    );
END COMPONENT COMP3;


begin

COMP1_inst : COMP1
    PORT MAP (
    x => a,
    y => b,
    z => z1
    );


COMP2_inst : COMP2
    PORT MAP (
    u => h,
    v => j,
    x => x1
    );

COMP3_inst : COMP3
    PORT MAP (
    a => z1,
    c => x1,
    y => u
    );




p1: process (a,b,c,d,e,sel)

begin
--multiplexer
case sel is
    WHEN '0' => x <= ((a and b) NOR c);
    WHEN '1' => x <= (d XOR e);
    WHEN others => x <= '0';
end case;

end process;

p2: process (f)
begin

case f is
    WHEN "000" => y <= "00000001";
    WHEN "001" => y <= "00000010";
    WHEN "010" => y <= "00000100";
    WHEN "011" => y <= "00001000";
    WHEN "100" => y <= "00010000";
    WHEN "101" => y <= "00100000";
    WHEN "110" => y <= "01000000";
    WHEN "111" => y <= "10000000";
    WHEN others => y <= "00000000";
end case;
end process;

p3_ADD_DFF1: process(clk,reset)
begin
    if (reset='1') then
        DFF1_2_MULT <= "0000";
    elsif (clk='1' and clk'event) then
        DFF1_2_MULT <= unsigned(h) + unsigned(j);
    end if;
end process;

p3_MULT_DFF2: process (clk,reset)

begin
    if (reset='1') then
        DFF2_2_DFF3 <= "00000000";
    elsif (clk='1' and clk'event) then
        DFF2_2_DFF3 <= (DFF1_2_MULT * unsigned(g));
    end if;
end process;

p3_DFF3: process (clk,reset)
begin
    if (reset='1') then
        z <= "00000000";
    elsif (clk='1' and clk'event) then
        z <= std_logic_vector(DFF2_2_DFF3);
    end if;
end process;
end Behavioral;
