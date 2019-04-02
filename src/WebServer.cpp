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
		auto colors = web::json::value::array(100);
		auto red = web::json::value::string(L"255000000");
		for (int i = 0; i < 100; i++)
		{
			colors.at(i) = red;
		}
		web::http::http_response response;
		response.set_status_code(web::http::status_codes::OK);
		response.set_body(colors);
		response.headers().add(L"Access-Control-Allow-Origin", "*");
		message.reply(response);
	}
}