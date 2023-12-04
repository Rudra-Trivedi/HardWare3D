#include "RudraException.h"
#include <sstream>


RudraException::RudraException(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* RudraException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* RudraException::GetType() const noexcept
{
	return "Rudra Exception";
}

int RudraException::GetLine() const noexcept
{
	return line;
}

const std::string& RudraException::GetFile() const noexcept
{
	return file;
}

std::string RudraException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}