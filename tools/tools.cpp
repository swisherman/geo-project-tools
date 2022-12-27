// tools.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <string>

class Tokenizer
{
private:
    std::vector<std::wstring, std::allocator<std::wstring > > argumentVector;
    std::wstring _cmdLine;
public:
    Tokenizer(std::wstring comandLine);
    const std::vector<std::wstring > * Split(wchar_t c=' ',  std::wstring currentString = L"");
 };
Tokenizer::Tokenizer(std::wstring commandLine) : _cmdLine(commandLine)
{
}
const std::vector<std::wstring>* Tokenizer::Split(wchar_t c, std::wstring currentString)
{
	wchar_t separator = c;
	std::wstring::size_type offset = L'\0';

	if (currentString.length() == 0)
	{
		currentString = _cmdLine;
	}
	auto res = currentString.find(separator, offset);
	if (res != std::wstring::npos)
	{
		std::wstring argument = currentString.substr(offset, res);
		argumentVector.push_back(argument);
		std::wstring nextArg = currentString.substr(res + 1);
		Split(separator, nextArg);
	}
	else {
		std::wstring argument = currentString.substr(offset);
		argumentVector.push_back(argument);
	}
	return &argumentVector;
}
int main()
{
    auto cmdline=GetCommandLine();
    Tokenizer tokenizer(cmdline);
    wchar_t separator = L' ';
	const std::vector<std::wstring >*  myVector=tokenizer.Split(separator);
	for (auto argument : *myVector)
	{
		std::wcout << L"Argument " << argument << std::endl;

   }

}

