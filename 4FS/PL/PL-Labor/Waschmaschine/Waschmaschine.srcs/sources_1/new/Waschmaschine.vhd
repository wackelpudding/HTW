----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 23.05.2018 11:46:34
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

--libaries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

-- entity
entity Waschmaschine is
Port ( 
clk : in STD_LOGIC;
reset : in STD_LOGIC;
start : in STD_LOGIC;
wasser : in STD_LOGIC;
temperature : in STD_LOGIC;
pumpe : out STD_LOGIC;
ventil : out STD_LOGIC;
heizung : out STD_LOGIC;
motor : out STD_LOGIC);

end Waschmaschine;


ARCHITECTURE beh OF Waschmaschine IS

--Deklarationen
TYPE STATE_TYPE IS (Idle, Wasserzulauf, Heizen, Waschen, Abpumpen);
SIGNAL Aktueller_Zustand : STATE_TYPE;
SIGNAL Naechster_Zustand : STATE_TYPE;

SIGNAL t: unsigned (3 downto 0);
SIGNAL tstop: STD_LOGIC;



BEGIN


Zustandsregister : PROCESS(clk, reset)
BEGIN
    IF (reset = '1') THEN
        Aktueller_Zustand <= Idle;
    ELSIF (clk'event AND clk = '1') THEN
        Aktueller_Zustand <= Naechster_Zustand;
    END IF;
END PROCESS Zustandsregister;


-- Netzwerk für das Wechseln der Zustände
Ueberfuehrungsnetzwerk : PROCESS (Aktueller_Zustand, wasser, temperature, t, start)
BEGIN
    Naechster_Zustand <= Aktueller_Zustand;
    CASE Aktueller_Zustand IS
        
        WHEN Idle =>
            IF (start = '1') THEN
                Naechster_Zustand <= Wasserzulauf;
            END IF;
        
        WHEN Wasserzulauf =>
            IF (wasser = '1') THEN
                Naechster_Zustand <= Heizen;
            END IF;
        
        WHEN Heizen =>
            IF ( temperature = '1' ) THEN
                Naechster_Zustand <= Waschen;
            END IF;
        WHEN Waschen =>
            IF ( t = "1010" ) THEN
                Naechster_Zustand <= Abpumpen;
            END IF;      
        WHEN Abpumpen =>
            IF ( wasser = '0' ) THEN
                Naechster_Zustand <= Idle;
            END IF;
        WHEN OTHERS => 
            Naechster_Zustand <= Idle;
    END CASE;
END PROCESS Ueberfuehrungsnetzwerk;

-- Netzwerk für die Abarbeitung innerhalb der Zustände

Ausgabenetzwerk : PROCESS (Aktueller_Zustand)
BEGIN
 -- Erstmal alle outputs auf 0 setzen, damit klare Zustände vorhanden sind.
 
    motor <= '0';
    pumpe <= '0';
    ventil <= '0';
    heizung <= '0';
    tstop <= '1';
    
    CASE Aktueller_Zustand IS
        WHEN  Idle => 
            Null;
        WHEN Wasserzulauf =>
            ventil <= '1';
        WHEN Heizen =>
            heizung <= '1';
        WHEN Waschen =>
            motor <= '1';
            tstop <= '0';
        WHEN Abpumpen =>
            pumpe <= '1';
        WHEN OTHERS => 
            NULL;
    END CASE;
END PROCESS Ausgabenetzwerk;

-- der zaehler soll nur aktiv sein, 
-- wenn im Zustand waschen der Timer gestartet wird.
zaehler : process (clk, reset)
begin
    if (reset = '1') then
        t <= "0000";
    elsif (clk'event AND clk = '1') then
        if tstop = '1' then
            t <= "0000";
        else
            t <= t + 1;
        end if;
    end if;
end process zaehler;


END beh;
        
