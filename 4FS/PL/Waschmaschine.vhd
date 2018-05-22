----------------------------------------------------------------------------------
-- Company:
-- Engineer:
--
-- Create Date: 16.11.2017 12:53:48
-- Design Name:
-- Module Name: Waschmaschine - Behavioral
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

entity Waschmaschine is
 Port ( clk: in STD_LOGIC;
  reset: in STD_LOGIC;
  temp : in STD_LOGIC;
  wasser : in STD_LOGIC;
  start : in STD_LOGIC;
  motor : out STD_LOGIC;
  ventil : out STD_LOGIC;
  heizung : out STD_LOGIC;
  pumpe : out STD_LOGIC
  );
end Waschmaschine;


ARCHITECTURE beh OF Waschmaschine IS

TYPE STATE_TYPE IS (idle, zulauf, heizen, waschen, abpumpen);

SIGNAL Aktueller_Zustand: STATE_TYPE;
SIGNAL Naechster_Zustand: STATE_TYPE;
SIGNAL t: UNSIGNED(3 DOWNTO 0);
SIGNAL clear: STD_LOGIC;

BEGIN

Zustandsregister : PROCESS(clk, reset)
BEGIN
  IF (reset= '1') THEN
    Aktueller_Zustand<= idle;
  ELSIF (clk'event AND clk= '1') THEN
    Aktueller_Zustand<= Naechster_Zustand;
  END IF;
END PROCESS Zustandsregister;

Ueberfuehrungsnetzwerk: PROCESS (Aktueller_Zustand, temp, Wasser, start, t)
BEGIN
  Naechster_Zustand<= Aktueller_Zustand;
  CASE Aktueller_Zustand IS
    WHEN idle =>
      IF (start='1') THEN
         Naechster_Zustand <= zulauf;
      END IF;
    WHEN zulauf =>
      IF (wasser='1') THEN
         Naechster_Zustand <= heizen;
      END IF;
    WHEN heizen =>
      IF (temp='1') THEN
       Naechster_Zustand <= waschen;
      END IF;
    WHEN waschen =>
       if (t = "1010") then
         Naechster_Zustand <= abpumpen;
       END if;
    WHEN abpumpen =>
      IF (wasser='0') THEN
       Naechster_Zustand <= Idle;
      END IF;
    WHEN OTHERS => NULL;
  END CASE;
END PROCESS Ueberfuehrungsnetzwerk;


Ausgabenetzwerk : PROCESS (Aktueller_Zustand)
BEGIN
  motor    <= '0';
  heizung  <= '0';
  ventil   <= '0';
  pumpe    <= '0';
  clear    <= '0';
  CASE Aktueller_Zustand IS
    WHEN idle => NULL;
    WHEN zulauf =>
      ventil  <= '1';
    WHEN heizen =>
      heizung <= '1';
      clear   <= '1';
    WHEN Waschen =>
      motor   <='1';
    WHEN abpumpen =>
      pumpe   <= '1';
    WHEN OTHERS => NULL;
  END CASE;
END PROCESS Ausgabenetzwerk;


  up_down_counter : process (clk,reset)
  begin
    if (reset='1') then
     t <= "0000";
    elsif (clk='1' and clk'event) then
      if clear = '0' then
        t <= t + 1;
      else
        t <= "0000";
      end if;
    end if;
  end process;




END beh;
