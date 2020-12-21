#include "strings.h"

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

