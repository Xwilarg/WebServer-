#include <cpprest/http_listener.h>
#include <iostream>

void getRequest(web::http::http_request message)
{
	message.reply(web::http::status_codes::OK, web::json::value::string(U("OK")));
}

int main()
{
	web::http::experimental::listener::http_listener listener(L"http://localhost:8082");
	listener.support(web::http::methods::GET, std::bind(&getRequest, std::placeholders::_1));
	listener.open().wait();
	std::cout << "Listening..." << std::endl << "Press enter to exit" << std::endl;
	std::cin.ignore();
	listener.close().wait();
}