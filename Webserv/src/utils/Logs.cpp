/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logs.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:07:42 by nmunir            #+#    #+#             */
/*   Updated: 2025/08/03 12:30:00 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logs.hpp"

// =============================================================================
// STATIC MEMBER DEFINITIONS
// =============================================================================

std::ofstream Logs::file;

// =============================================================================
// PRIVATE CONSTANTS
// =============================================================================

namespace {
    const size_t TIMESTAMP_BUFFER_SIZE = 100;
    const size_t MIN_TYPE_WIDTH = 5;
    const size_t FUNCTION_FIELD_WIDTH = 30;
    const char TAB_DELIMITER = '\t';
    const size_t MIN_PARTS_FOR_STRUCTURED_LOG = 3;
}

// =============================================================================
// CONSTRUCTOR / DESTRUCTOR
// =============================================================================

/**
 * @brief Private constructor - Logs is a singleton utility class
 */
Logs::Logs() 
{
    // Private constructor - no implementation needed
}

// =============================================================================
// PUBLIC STATIC METHODS
// =============================================================================

/**
 * @brief Initialize the logging system
 * 
 * Opens the log file for writing. If the file is already open, this function
 * does nothing. The log file is truncated on initialization.
 * 
 * @note This function should be called before any logging operations
 */
void Logs::init()
{
    if (!file.is_open())
    {
        file.open(LOG_FILE, std::ios::trunc);
        if (!file.is_open())
        {
            std::cerr << "[ERROR] Failed to open log file: " << LOG_FILE << std::endl;
            std::cerr << "[ERROR] Logging will be disabled" << std::endl;
        }
    }
}

/**
 * @brief Append a log entry to the log file
 * 
 * This function writes a formatted log entry to the log file. It supports
 * two message formats:
 * 1. Simple messages: Plain text that will be logged as-is
 * 2. Structured messages: Tab-separated format (function\t\tmessage)
 * 
 * The log format is: [timestamp] [type] [function_field] message
 * 
 * @param type The log level/type (INFO, DEBUG, ERROR, WARN, etc.)
 * @param message The message to log (can be simple or tab-separated)
 * 
 * @note If the log file is not open, this function silently returns
 * @note Function names are padded to 30 characters for alignment
 * @note Log types shorter than 5 characters get extra spacing
 */
void Logs::appendLog(const std::string& type, const std::string& message)
{
    // Early return if log file is not available
    if (!file.is_open()) 
    {
        return;
    }
    
    // Generate timestamp
    std::time_t now = std::time(0);
    char timeStr[TIMESTAMP_BUFFER_SIZE];
    std::strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    
    // Initialize formatting variables
    std::string typeSpacing = "";
    std::string functionSpacing = "";
    std::string functionName = "";
    std::string logMessage = message;
    
    // Parse message format (check for tab-separated structure)
    std::vector<std::string> messageParts = split(message, TAB_DELIMITER);
    
    if (messageParts.size() >= MIN_PARTS_FOR_STRUCTURED_LOG)
    {
        // Structured format: function\t\tmessage
        functionName = messageParts[0];
        logMessage = messageParts[2];
    }
    else if (messageParts.size() == 1)
    {
        // Simple format: treat entire message as log content
        logMessage = messageParts[0];
        // functionName remains empty for simple messages
    }
    
    // Apply formatting for professional alignment
    if (type.size() < MIN_TYPE_WIDTH)
    {
        typeSpacing = " ";
    }
    
    if (!functionName.empty() && functionName.size() < FUNCTION_FIELD_WIDTH)
    {
        functionSpacing.append(FUNCTION_FIELD_WIDTH - functionName.size(), ' ');
    }
    
    // Write formatted log entry
    file << "[" << timeStr << "] "
         << "[" << type << "] " 
         << typeSpacing 
         << functionName 
         << functionSpacing 
         << logMessage 
         << std::endl;
    
    // Ensure immediate write (important for crash scenarios)
    file.flush();
}

/**
 * @brief Close the logging system and release resources
 * 
 * This function closes the log file if it's currently open. It should be
 * called during application shutdown to ensure proper cleanup.
 * 
 * @note It's safe to call this function multiple times
 * @note After calling this, logging operations will be disabled until init() is called again
 */
void Logs::close()
{
    if (file.is_open())
    {
        // Flush any remaining data before closing
        file.flush();
        file.close();
    }
}
