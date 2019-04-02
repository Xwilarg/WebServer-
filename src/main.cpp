#include <iostream>
#include "WebServer.hpp"

int main()
{
	WebServer::WebServer server(L"localhost", L"8082");
	std::cout << "Listening..." << std::endl << "Press enter to exit" << std::endl;
	std::cin.ignore();
}