
#include <iostream>
#include "process.h"

void printSystemInfo()
{
	sys::process::ListProcesses processes = sys::process::getProcesses();

	std::cout << "\nWindows is running " << processes.size() << " processes.\n\n";

	for (const auto& proc : processes) {

		std::cout << "\nThe Process PID is " << proc.pid << std::endl;
		std::cout << "Parent PID is " << proc.parentPid << std::endl;
		std::wcout << "Process name is " << proc.exeName.c_str() << std::endl;

		if (proc.modules.empty()) {
			std::cout << "\thas no any dependecies." << std::endl;
		}
		else {
			std::cout << "Loaded modules (dependencies): " << std::endl;

			for (const auto& module : proc.modules) {
				std::wcout << "\t" << module.exePath.c_str() << std::endl;
				std::wcout << "\tloaded to " << module.pBase << " with size " << (module.memorySize / 1024) << "kb." << std::endl;
			}
		}

	}
}

int main(int argc, char* argv[])
{
	printSystemInfo();

	std::cout << "\n\nPress any key to exit...";
	getchar();
}

