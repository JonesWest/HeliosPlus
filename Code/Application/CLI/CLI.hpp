#pragma once

#include "Framework.hpp"
#include "Debug.hpp"

#define NO_CLI_COMMANDS 5

class CLI;

struct CLI_Command
{
    CLI_Command(char* s, void (CLI::*h)(void))
    {
        command_string = s;
        handler = h;
    }

    char* command_string;
    void (CLI::*handler)(void);

    void raise( CLI* the_cli ) { return (the_cli->*handler)(); }
};

class CLI : public ApplicationModule {
	public:
		CLI(const char* name, uint32_t stackSize, uint8_t priority, uint32_t eeprom_size,
			ApplicationModule* communications_,
			ApplicationModule* controlinput_,
			ApplicationModule* flightcontrol_,
			ApplicationModule* flightdynamics_,
			ApplicationModule* flightnavigation_,
			ApplicationModule* systemstatus_);


	protected:
		void task(void);
		void handle_message(Message& msg);

	private:
		ApplicationModule* flightdynamics;
		ApplicationModule* controlinput;
		ApplicationModule* flightcontrol;
		ApplicationModule* flightnavigation;
		ApplicationModule* communications;
		ApplicationModule* systemstatus;


		uint8_t input_buffer[256] = {0};
		uint8_t buffer_index = 0;
		uint8_t last_buffer_index = 0;
		uint8_t compare_index = 0;

		bool streaming = false;
		ApplicationModule* streaming_module;

		char run_time_stats[40*10];

		void process_buffer();
		bool compare_buffer_and_cli_command(uint8_t);
		bool compare_rest_of_buffer_to(char*);

        CLI_Command cli_table[NO_CLI_COMMANDS] = {
          { "stream",   &CLI::handle_stream },
          { "print run_time_stats",   &CLI::handle_print_run_time_stats },
          { "print stack_stats",      &CLI::handle_print_stack_stats },
          { "print frequency_stats",  &CLI::handle_print_frequency_stats},
          { "print duration_stats",  &CLI::handle_print_duration_stats}
        };

        void handler1();
        void handler2();

		void handle_buffer_full(){};


		void handle_stream(void);
		void handle_print_run_time_stats(void);
		void handle_print_stack_stats(void);
		void handle_print_frequency_stats(void);
		void handle_print_duration_stats(void);
};