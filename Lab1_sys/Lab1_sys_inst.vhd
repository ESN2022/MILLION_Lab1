	component Lab1_sys is
		port (
			clk_clk                          : in  std_logic := 'X'; -- clk
			pio_0_external_connection_export : out std_logic;        -- export
			reset_reset_n                    : in  std_logic := 'X'  -- reset_n
		);
	end component Lab1_sys;

	u0 : component Lab1_sys
		port map (
			clk_clk                          => CONNECTED_TO_clk_clk,                          --                       clk.clk
			pio_0_external_connection_export => CONNECTED_TO_pio_0_external_connection_export, -- pio_0_external_connection.export
			reset_reset_n                    => CONNECTED_TO_reset_reset_n                     --                     reset.reset_n
		);

