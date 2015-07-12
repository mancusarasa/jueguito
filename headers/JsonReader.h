#ifndef __JSONREADER__
#define __JSONREADER__
#include <iostream>
#include <jsoncpp/json/json.h>
#include <string>
#include <fstream>

class JsonReader {
public:
	static JsonReader* Instance() {
		if ( !pInstance) {
			pInstance = new JsonReader();
			pInstance->load();
		}
		return pInstance;
	}
	bool load();
	int getWindowValue(std::string property);
private:
	JsonReader(){}
	~JsonReader(){}
	static JsonReader* pInstance;
	void loadWindowConfig();
	std::map<std::string,int> windowConfig;
	Json::Value root;
	Json::Reader reader;
	std::ifstream file;
};

#endif