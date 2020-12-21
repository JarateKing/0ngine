#include <string>
#include <map>
#include <vector>

namespace utility {
	std::string format(const std::string& line, const std::map<std::string, std::string>& dict);
	void lowercase(std::string& s);
	void uppercase(std::string& s);
	void trim(std::string &s);
	std::vector<std::string> split(std::string& s, char token);
}
