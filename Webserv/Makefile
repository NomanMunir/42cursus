# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/03 10:00:00 by nmunir            #+#    #+#              #
#    Updated: 2025/08/03 10:00:00 by nmunir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================
# PROJECT CONFIGURATION
# =============================================================================

NAME		= webserv
VERSION		= 1.0.0

# =============================================================================
# COMPILER CONFIGURATION
# =============================================================================

CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror
DEBUGFLAGS	= -g3 -fsanitize=address -DDEBUG=1
INCLUDES	= -I./include

# Debug mode
ifdef DEBUG
	CXXFLAGS += $(DEBUGFLAGS)
endif

# =============================================================================
# DIRECTORIES
# =============================================================================

SRCDIR		= src
OBJDIR		= build/obj
BINDIR		= bin
INCDIR		= include
CONFIGDIR	= config
WWWDIR		= www
LOGDIR		= logs
TESTDIR		= tests
DOCSDIR		= docs
SCRIPTSDIR	= scripts
EXAMPLESDIR	= examples

# =============================================================================
# SOURCE FILES
# =============================================================================

CORE_SRCS	= $(SRCDIR)/main.cpp

SERVER_SRCS	= $(SRCDIR)/server/Server.cpp \
			  $(SRCDIR)/server/ServerManager.cpp

PARSING_SRCS = $(SRCDIR)/parsing/Parser.cpp \
			   $(SRCDIR)/parsing/Validation.cpp

REQUEST_SRCS = $(SRCDIR)/request/Request.cpp \
			   $(SRCDIR)/request/Headers.cpp \
			   $(SRCDIR)/request/Body.cpp

RESPONSE_SRCS = $(SRCDIR)/response/Response.cpp \
				$(SRCDIR)/response/HttpResponse.cpp

UTILS_SRCS	= $(SRCDIR)/utils/utils.cpp \
			  $(SRCDIR)/utils/Logs.cpp \
			  $(SRCDIR)/utils/MimeTypes.cpp

CLIENT_SRCS	= $(SRCDIR)/client/Client.cpp

CGI_SRCS	= $(SRCDIR)/cgi/Cgi.cpp

# Platform-specific event handling
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	EVENTS_SRCS = $(SRCDIR)/events/EpollPoller.cpp
else
	EVENTS_SRCS = $(SRCDIR)/events/KQueuePoller.cpp
endif

# Combine all source files
SRCS		= $(CORE_SRCS) \
			  $(SERVER_SRCS) \
			  $(PARSING_SRCS) \
			  $(REQUEST_SRCS) \
			  $(RESPONSE_SRCS) \
			  $(UTILS_SRCS) \
			  $(CLIENT_SRCS) \
			  $(CGI_SRCS) \
			  $(EVENTS_SRCS)

# =============================================================================
# OBJECT FILES
# =============================================================================

OBJS		= $(SRCS:%.cpp=$(OBJDIR)/%.o)
DEPS		= $(OBJS:.o=.d)

# =============================================================================
# COLORS FOR OUTPUT
# =============================================================================

RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m
WHITE		= \033[0;37m
RESET		= \033[0m
BOLD		= \033[1m

# =============================================================================
# MAIN TARGETS
# =============================================================================

.PHONY: all clean fclean re debug test install uninstall help

all: header $(BINDIR)/$(NAME)
	@echo "$(GREEN)$(BOLD)✓ $(NAME) compiled successfully!$(RESET)"

$(BINDIR)/$(NAME): $(OBJS)
	@mkdir -p $(BINDIR)
	@echo "$(CYAN)Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(BINDIR)/$(NAME) $(OBJS)

# =============================================================================
# OBJECT COMPILATION
# =============================================================================

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

# Include dependency files
-include $(DEPS)

# =============================================================================
# UTILITY TARGETS
# =============================================================================

header:
	@echo "$(MAGENTA)$(BOLD)"
	@echo "╔══════════════════════════════════════════════════════════════╗"
	@echo "║                          WEBSERV                             ║"
	@echo "║                  HTTP/1.1 Web Server v$(VERSION)                  ║"
	@echo "║                      42 Abu Dhabi                            ║"
	@echo "╚══════════════════════════════════════════════════════════════╝"
	@echo "$(RESET)"

debug: CXXFLAGS += $(DEBUGFLAGS)
debug: header $(BINDIR)/$(NAME)
	@echo "$(GREEN)$(BOLD)✓ Debug version compiled successfully!$(RESET)"

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)Cleaning executable...$(RESET)"
	@rm -rf $(BINDIR)/$(NAME)

re: fclean all

# =============================================================================
# TESTING TARGETS
# =============================================================================

test: $(BINDIR)/$(NAME)
	@echo "$(BLUE)Running tests...$(RESET)"
	@if [ -f $(TESTDIR)/run_tests.sh ]; then \
		chmod +x $(TESTDIR)/run_tests.sh && $(TESTDIR)/run_tests.sh; \
	else \
		echo "$(YELLOW)No test script found at $(TESTDIR)/run_tests.sh$(RESET)"; \
	fi

stress: $(BINDIR)/$(NAME)
	@echo "$(BLUE)Running stress tests...$(RESET)"
	@if [ -f $(TESTDIR)/stress_test.sh ]; then \
		chmod +x $(TESTDIR)/stress_test.sh && $(TESTDIR)/stress_test.sh; \
	else \
		echo "$(YELLOW)No stress test script found$(RESET)"; \
	fi

# =============================================================================
# INSTALLATION TARGETS
# =============================================================================

install: $(BINDIR)/$(NAME)
	@echo "$(CYAN)Installing $(NAME)...$(RESET)"
	@mkdir -p /usr/local/bin
	@cp $(BINDIR)/$(NAME) /usr/local/bin/
	@chmod +x /usr/local/bin/$(NAME)
	@echo "$(GREEN)$(NAME) installed to /usr/local/bin/$(RESET)"

uninstall:
	@echo "$(RED)Uninstalling $(NAME)...$(RESET)"
	@rm -f /usr/local/bin/$(NAME)
	@echo "$(GREEN)$(NAME) uninstalled$(RESET)"

# =============================================================================
# DEVELOPMENT TARGETS
# =============================================================================

run: $(BINDIR)/$(NAME)
	@echo "$(CYAN)Starting $(NAME)...$(RESET)"
	@./$(BINDIR)/$(NAME) $(CONFIGDIR)/webserv.conf

dev: debug
	@echo "$(CYAN)Starting $(NAME) in development mode...$(RESET)"
	@./$(BINDIR)/$(NAME) $(CONFIGDIR)/webserv.conf

# =============================================================================
# ANALYSIS TARGETS
# =============================================================================

valgrind: $(BINDIR)/$(NAME)
	@echo "$(MAGENTA)Running Valgrind memory check...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(BINDIR)/$(NAME)

cppcheck:
	@echo "$(MAGENTA)Running static analysis with cppcheck...$(RESET)"
	@cppcheck --enable=all --std=c++98 --language=c++ $(SRCDIR) $(INCDIR)

norm:
	@echo "$(MAGENTA)Checking coding standards...$(RESET)"
	@if command -v norminette > /dev/null 2>&1; then \
		norminette $(SRCDIR) $(INCDIR) *.cpp; \
	else \
		echo "$(YELLOW)norminette not found, skipping...$(RESET)"; \
	fi

# =============================================================================
# DOCUMENTATION TARGETS
# =============================================================================

docs:
	@echo "$(CYAN)Generating documentation...$(RESET)"
	@if command -v doxygen > /dev/null 2>&1; then \
		doxygen Doxyfile; \
	else \
		echo "$(YELLOW)doxygen not found, cannot generate documentation$(RESET)"; \
	fi

# =============================================================================
# HELP TARGET
# =============================================================================

help:
	@echo "$(BOLD)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)       - Build the project"
	@echo "  $(GREEN)debug$(RESET)     - Build with debug flags"
	@echo "  $(GREEN)clean$(RESET)     - Remove object files"
	@echo "  $(GREEN)fclean$(RESET)    - Remove object files and executable"
	@echo "  $(GREEN)re$(RESET)        - Rebuild the project"
	@echo "  $(GREEN)test$(RESET)      - Run test suite"
	@echo "  $(GREEN)stress$(RESET)    - Run stress tests"
	@echo "  $(GREEN)run$(RESET)       - Build and run the server"
	@echo "  $(GREEN)dev$(RESET)       - Build debug version and run"
	@echo "  $(GREEN)install$(RESET)   - Install to system"
	@echo "  $(GREEN)uninstall$(RESET) - Remove from system"
	@echo "  $(GREEN)valgrind$(RESET)  - Run with Valgrind"
	@echo "  $(GREEN)cppcheck$(RESET)  - Run static analysis"
	@echo "  $(GREEN)norm$(RESET)      - Check coding standards"
	@echo "  $(GREEN)docs$(RESET)      - Generate documentation"
	@echo "  $(GREEN)help$(RESET)      - Show this help message"

# =============================================================================
# INFORMATION TARGETS
# =============================================================================

info:
	@echo "$(BOLD)Project Information:$(RESET)"
	@echo "  Name:        $(NAME)"
	@echo "  Version:     $(VERSION)"
	@echo "  Compiler:    $(CXX)"
	@echo "  Flags:       $(CXXFLAGS)"
	@echo "  Platform:    $(UNAME_S)"
	@echo "  Sources:     $(words $(SRCS)) files"
	@echo "  Objects:     $(OBJDIR)/"