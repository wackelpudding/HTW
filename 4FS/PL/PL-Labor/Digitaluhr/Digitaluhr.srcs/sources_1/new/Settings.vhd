----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 09.06.2018 15:59:45
-- Design Name: 
-- Module Name: Settings - Behavioral
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

entity Settings is
    Port (clock : in STD_LOGIC;
          reset : in STD_LOGIC;
          mode : in STD_LOGIC;
          sel : in STD_LOGIC;
          inc : in STD_LOGIC;
          enable_M1_src : in STD_LOGIC;
          enable_M10_src : in STD_LOGIC;
          enable_H1_src : in STD_LOGIC;
          enable_H10_src : in STD_LOGIC;
          enable_M1_dest : out STD_LOGIC;
          enable_M10_dest : out STD_LOGIC;
          enable_H1_dest : out STD_LOGIC;
          enable_H10_dest : out STD_LOGIC;
          DP_M1 : out  STD_LOGIC;
          DP_M10 : out STD_LOGIC;
          DP_H1 : out STD_LOGIC;
          DP_H10 : out STD_LOGIC;
          Einstellmodus : out STD_LOGIC
          );
end Settings;
architecture Behavioral of Settings is
TYPE STATE_TYPE IS (Uhrenmodus, M1,M10,H1,H10);
SIGNAL Aktueller_Zustand : STATE_TYPE;
SIGNAL Naechster_Zustand : STATE_TYPE;
begin
Zustandsregister : PROCESS(clock, reset)
BEGIN
    IF (reset = '1') THEN
        Aktueller_Zustand <= Uhrenmodus;
    ELSIF (clock'event AND clock = '1') THEN
        Aktueller_Zustand <= Naechster_Zustand;
    END IF;
END PROCESS Zustandsregister;
Ueberfuehrungsnetzwerk : PROCESS(Aktueller_Zustand, enable_M1_src, enable_M10_src,enable_H1_src,enable_H10_src,clock,mode,sel,inc,reset)
BEGIN
Naechster_Zustand <= Aktueller_Zustand;
CASE Aktueller_Zustand IS
WHEN Uhrenmodus =>
    IF (mode ='1') THEN
    Naechster_Zustand <= M1;
    ELSE
    Naechster_Zustand <= Aktueller_Zustand;
    END IF;
WHEN M1 =>
    IF (mode = '1') THEN
        Naechster_Zustand <= Uhrenmodus;
    ElSIF (sel = '1') THEN
         Naechster_Zustand <= M10;
    ELSE 
        Naechster_Zustand <= Aktueller_Zustand;
    END IF;
WHEN M10 =>
       IF (mode = '1') THEN
           Naechster_Zustand <= Uhrenmodus;
       ElSIF (sel= '1') THEN
            Naechster_Zustand <= H1;
       ELSE 
           Naechster_Zustand <= Aktueller_Zustand;
       END IF;
WHEN H1 =>
          IF (mode = '1') THEN
              Naechster_Zustand <= Uhrenmodus;
          ElSIF (sel = '1') THEN
               Naechster_Zustand <= H10;
          ELSE 
              Naechster_Zustand <= Aktueller_Zustand;
          END IF;
WHEN H10 =>
          IF (mode = '1') THEN
                 Naechster_Zustand <= Uhrenmodus;
          ElSIF (sel = '1') THEN
                 Naechster_Zustand <= M1;
          ELSE 
                 Naechster_Zustand <= Aktueller_Zustand;
          END IF;
WHEN OTHERS => NULL;
END CASE;
END PROCESS Ueberfuehrungsnetzwerk;
Ausgabenetzwerk : PROCESS(Aktueller_Zustand,clock)
BEGIN
CASE Aktueller_Zustand IS
    WHEN Uhrenmodus =>
        Einstellmodus <= '0';
        enable_M1_dest <= enable_M1_src;
        enable_M10_dest <= enable_M10_src;
        enable_H1_dest <= enable_H1_src;
        enable_H10_dest <= enable_H10_src;
        DP_M1 <= '0';
        DP_M10 <= '0';
        DP_H1 <= '0';
        DP_H10 <= '0';
    WHEN M1 =>
         Einstellmodus <= '1';
         enable_M1_dest <= inc;
         enable_M10_dest <= '0';
         enable_H1_dest <= '0';
         enable_H10_dest <= '0';
         DP_M1 <= '1';
         DP_M10 <= '0';
         DP_H1 <= '0';
         DP_H10 <= '0';
    WHEN M10 =>            
         Einstellmodus <= '1';                 
         enable_M1_dest <= '0';            
         enable_M10_dest <= inc;
         enable_H1_dest <= '0';  
         enable_H10_dest <= '0';
         DP_M1 <= '0';
         DP_M10 <= '1';
         DP_H1 <= '0';
         DP_H10 <= '0';
    WHEN H1 =>
          Einstellmodus <= '1';              
          enable_M1_dest <= '0';           
          enable_M10_dest <= '0';
          enable_H1_dest <= inc;  
          enable_H10_dest <= '0';
          DP_M1 <= '0';
          DP_M10 <= '0';
          DP_H1 <= '1';
          DP_H10 <= '0';
    WHEN H10 =>     
          Einstellmodus <= '1';                        
          enable_M1_dest <= '0';           
          enable_M10_dest <= '0';
          enable_H1_dest <= '0';
          enable_H10_dest <= inc;   
          DP_M1 <= '0';
          DP_M10 <= '0';
          DP_H1 <= '0';
          DP_H10 <= '1';
    WHEN OTHERS => NULL;
END CASE;
END PROCESS Ausgabenetzwerk;

end Behavioral;
