#include <windows.h>
#include <iostream> 
#include <string>
int main() 
{
	int pid = GetCurrentProcessId();
	std::string process_information = "pid -> ";
	process_information += std::to_string(pid);
	uint64_t sys_addr = (uint64_t)&system;
	process_information += "      system addr -> ";
	process_information += std::to_string(sys_addr);
	SetConsoleTitleA(process_information.c_str());
	while (true) 
	{
		system("cls");
		system("color 0b");
		std::cout << "Blue" << std::endl;
		Sleep(1000);
		system("cls");
		system("color 0c");
		std::cout << "Red" << std::endl;
		Sleep(1000);
	}
}