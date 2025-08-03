/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 10:00:00 by nmunir            #+#    #+#             */
/*   Updated: 2025/08/03 10:00:00 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HPP
# define WEBSERV_HPP

// =============================================================================
// SYSTEM INCLUDES
// =============================================================================

# include <iostream>
# include <string>
# include <vector>
# include <map>
# include <set>
# include <algorithm>
# include <fstream>
# include <sstream>
# include <cstring>
# include <cstdlib>
# include <ctime>
# include <exception>

// POSIX includes
# include <sys/socket.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>

// Platform-specific includes
# ifdef __linux__
#  include <sys/epoll.h>
# else
#  include <sys/event.h>
# endif

// =============================================================================
// PROJECT CONFIGURATION
// =============================================================================

# define WEBSERV_VERSION "1.0.0"
# define WEBSERV_NAME "Webserv"
# define WEBSERV_BANNER "HTTP/1.1 Web Server"

// =============================================================================
// NETWORKING CONSTANTS
// =============================================================================

# define BUFFER_SIZE 8192
# define MAX_URI_LENGTH 8000
# define MAX_HEADER_SIZE 8192
# define DEFAULT_TIMEOUT 30
# define MAX_CONNECTIONS 1000

// =============================================================================
// HTTP CONSTANTS
// =============================================================================

# define HTTP_VERSION "HTTP/1.1"
# define CRLF "\r\n"
# define SP " "
# define HTAB "\t"

// HTTP Status Codes
# define HTTP_OK 200
# define HTTP_CREATED 201
# define HTTP_NO_CONTENT 204
# define HTTP_MOVED_PERMANENTLY 301
# define HTTP_NOT_MODIFIED 304
# define HTTP_BAD_REQUEST 400
# define HTTP_FORBIDDEN 403
# define HTTP_NOT_FOUND 404
# define HTTP_METHOD_NOT_ALLOWED 405
# define HTTP_REQUEST_TIMEOUT 408
# define HTTP_LENGTH_REQUIRED 411
# define HTTP_PAYLOAD_TOO_LARGE 413
# define HTTP_URI_TOO_LONG 414
# define HTTP_INTERNAL_SERVER_ERROR 500
# define HTTP_NOT_IMPLEMENTED 501
# define HTTP_BAD_GATEWAY 502
# define HTTP_SERVICE_UNAVAILABLE 503

// =============================================================================
// PROJECT HEADERS
// =============================================================================

// Core server headers
# include "server/Server.hpp"
# include "server/ServerManager.hpp"

// Configuration parsing headers
# include "parsing/Parser.hpp"
# include "parsing/Validation.hpp"

// HTTP request handling headers
# include "request/Request.hpp"
# include "request/Headers.hpp"
# include "request/Body.hpp"

// HTTP response handling headers
# include "response/Response.hpp"
# include "response/HttpResponse.hpp"

// Event handling headers
# include "events/EventPoller.hpp"
# ifdef __linux__
#  include "events/EpollPoller.hpp"
# else
#  include "events/KQueuePoller.hpp"
# endif

// Client management headers
# include "client/Client.hpp"

// CGI execution headers
# include "cgi/Cgi.hpp"

// Utility headers
# include "utils/utils.hpp"
# include "utils/Logs.hpp"
# include "utils/MimeTypes.hpp"

// =============================================================================
// GLOBAL UTILITY FUNCTIONS
// =============================================================================

namespace webserv {
	// Version information
	std::string getVersion();
	std::string getBanner();
	
	// Signal handling
	void setupSignalHandlers();
	void signalHandler(int signal);
	
	// Utility functions
	std::string getCurrentTimestamp();
	std::string formatHttpDate(time_t timestamp);
	bool isValidHttpMethod(const std::string& method);
	bool isValidHttpVersion(const std::string& version);
}

#endif // WEBSERV_HPP
