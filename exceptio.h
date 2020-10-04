#pragma once
#include <exception>
#include <string>

class FileError : _exception
{
private:
	std::string filename;
public:
	FileError(const std::string& file) :
		filename(file) { };
	std::string getName() const { return filename; }
};

class OpenError : public FileError
{
public:
	OpenError(const std::string& file) :
		FileError(file) { };
};

class ReadError : public FileError
{
public:
	ReadError(const std::string& file) : 
		FileError(file) { };
};

class WriteError : public FileError
{
public:
	WriteError(const std::string& file) :
		FileError(file) { };
};
