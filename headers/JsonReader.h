#ifndef __JSONREADER__
#define __JSONREADER__
#include <iostream>
#include <jsoncpp/json/json.h>
#include <string>
#include <fstream>

class JsonReader {
public:
	static JsonReader* Instance() {
		if ( !pInstance) pInstance = new JsonReader();
		return pInstance;
	}
	bool load();
private:
	JsonReader(){}
	~JsonReader(){}
	static JsonReader* pInstance;
	void loadWindowConfig();
	std::map<std::string,int> windowConfig;
	int getWindowValue(std::string property);
	Json::Value root;
	Json::Reader reader;
	std::ifstream file;
};

#endif