#ifndef WEBSERVER_HPP_
# define WEBSERVER_HPP_

# include <cpprest/http_listener.h>
# include <string>

namespace WebServer
{
	class WebServer final
	{
	public:
		WebServer(std::wstring &&ip, std::wstring &&port) noexcept;
		~WebServer() noexcept;

	private:
		void GetRequest(web::http::http_request message) const noexcept;
		web::http::experimental::listener::http_listener _listener;
	};
}

#endif //! WEBSERVER_HPP_
