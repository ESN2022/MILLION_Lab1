library ieee;
use ieee.std_logic_1164.all;

entity Lab1 is
	port(
		clk, reset   : in  std_logic;
		pio_external : out std_logic_vector(7 downto 0)
	);
end entity;

architecture rtl of Lab1 is
	component Lab1_sys is
		port (
			clk_clk                          : in  std_logic                    := 'X'; -- clk
			pio_0_external_connection_export : out std_logic_vector(7 downto 0);        -- export
			reset_reset_n                    : in  std_logic                    := 'X'  -- reset_n
		);
	end component Lab1_sys;
	
begin
	u0 : component Lab1_sys
		port map (
			clk_clk                          => clk,                          --                       clk.clk
			pio_0_external_connection_export => pio_external, -- pio_0_external_connection.export
			reset_reset_n                    => reset                     --                     reset.reset_n
		);
end rtl;
