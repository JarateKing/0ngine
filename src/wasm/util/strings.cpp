#include "strings.h"
#include <sstream>
#include <algorithm>

std::string utility::format(const std::string& line, const std::map<std::string, std::string>& dict) {
    std::string ans;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == '\\') {
            if (i + 1 < line.size()) {
                if (line[i + 1] == 'n') ans += '\n';
                else if (line[i + 1] == 't') ans += '\t';
                else ans.push_back(line[i + 1]);
                i++;
            }
        }
        else if (line[i] == '$') {
            std::string key;
            bool ongoing = true;
            for (int j = i + 1; j < line.size() && ongoing; j++) {
                if (line[j] != '$') {
                    key.push_back(line[j]);
                }
                else {
                    auto it = dict.find(key);
                    if (it != dict.end()) {
                        ans += it->second;
                    }
                    else {
                        ans.push_back('$');
                        ans += key;
                        ans.push_back('$');
                    }
                    i = j;
                    ongoing = false;
                }
            }
            if (ongoing) {
                ans.push_back('$');
                return ans + key;
            }
        }
        else {
            ans.push_back(line[i]);
        }
    }
    
    return ans;
}

void utility::lowercase(std::string& s) {
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
}

void utility::uppercase(std::string& s) {
	std::transform(s.begin(), s.end(), s.begin(), ::toupper);
}

void utility::trim(std::string &s) {
	s.erase(s.begin(),find_if_not(s.begin(),s.end(),[](int c){return isspace(c);}));
	s.erase(find_if_not(s.rbegin(),s.rend(),[](int c){return isspace(c);}).base(),s.end());
}

std::vector<std::string> utility::split(std::string& s, char token) {
    std::vector<std::string> v; std::stringstream ss(s);
    for (std::string e;getline(ss,e,token);)
        v.push_back(e);
    return v;
}
