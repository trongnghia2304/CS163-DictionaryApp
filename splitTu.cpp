#include "splitTu.h"
#include <sstream>

std::vector<std::string> split(std::string str, std::string delimiter) {
	//str: chuỗi cần tách
	//delimiter: ký tự phân cách
	std::vector<std::string> hello;
	size_t pos = 0;
	std::string token;
	while ((pos = str.find(delimiter)) != std::string::npos) {
		token = str.substr(0, pos);
		hello.push_back(token);
		str.erase(0, pos + delimiter.length());
	}
	hello.push_back(str);
	return hello;
}
std::vector < std::string> cumTu(std::string str, int limit)
{
	std::vector<std::string> haha;
	std::vector<std::string> hello = split(str, " ");
	std::string newT = hello[0];
	for (int i = 1; i < hello.size(); i++)
	{
		if (newT.length() + hello[i].length() > limit)
		{
			haha.push_back(newT);
			newT = hello[i];
		}
		else
			newT += " " + hello[i];

	}
	haha.push_back(newT);
	return haha;
}
//std::vector<std::string> split(std::string str, std::string delimeter) {
//	std::stringstream ss;
//
//	ss << str;
//	std::vector <std::string> v;
//	std::string token;
//	while (getline(ss, token, delimeter))
//		v.push_back(token);
//	return v;
//}