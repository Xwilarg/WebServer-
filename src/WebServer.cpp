#include "WebServer.hpp"

namespace WebServer
{
	WebServer::WebServer(std::wstring &&ip, std::wstring &&port) noexcept
		: _listenerGet(L"http://" + ip + L":" + port + L"/get"),
		_listenerUpdate(L"http://" + std::move(ip) + L":" + std::move(port) + L"/update"),
		_allcolors()
	{
		auto white = std::wstring(L"255255255");
		for (int i = 0; i < 100; i++)
		{
			_allcolors[i] = white;
		}
		_listenerGet.support(web::http::methods::GET, std::bind(&WebServer::GetColors, this, std::placeholders::_1));
		_listenerUpdate.support(web::http::methods::POST, std::bind(&WebServer::UpdateColors, this, std::placeholders::_1));
		_listenerGet.open().wait();
		_listenerUpdate.open().wait();
	}

	WebServer::~WebServer() noexcept
	{
		_listenerGet.close().wait();
		_listenerUpdate.close().wait();
	}

	void WebServer::GetColors(web::http::http_request message) const noexcept
	{
		auto colors = web::json::value::array(100);
		for (int i = 0; i < 100; i++)
			colors.at(i) = web::json::value::string(_allcolors[i]);
		web::http::http_response response;
		response.set_status_code(web::http::status_codes::OK);
		response.set_body(colors);
		response.headers().add(L"Access-Control-Allow-Origin", "*");
		message.reply(response);
	}

	void WebServer::UpdateColors(web::http::http_request message) noexcept
	{
		auto body = message.extract_string().get();
		std::wstring str(body.begin(), body.end());
		size_t pos;
		pos = str.find(L";");
		int posX = std::stoi(str.substr(0, pos));
		str.erase(0, pos + 1);
		pos = str.find(L";");
		int posY = std::stoi(str.substr(0, pos));
		str.erase(0, pos + 1);
		_allcolors[posX * 10 + posY] = str;
		GetColors(message);
	}
}