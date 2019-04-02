#include "WebServer.hpp"

namespace WebServer
{
	WebServer::WebServer(std::wstring &&ip, std::wstring &&port) noexcept
		: _listener(L"http://" + ip + L":" + port)
	{
		_listener.support(web::http::methods::GET, std::bind(&WebServer::GetRequest, this, std::placeholders::_1));
		_listener.open().wait();
	}

	WebServer::~WebServer() noexcept
	{
		_listener.close().wait();
	}

	void WebServer::GetRequest(web::http::http_request message) const noexcept
	{
		message.reply(web::http::status_codes::OK, web::json::value::string(U("OK")));
	}
}