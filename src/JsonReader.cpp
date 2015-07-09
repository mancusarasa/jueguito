#include "../headers/JsonReader.h"

JsonReader* JsonReader::pInstance = 0;

bool JsonReader::load() {
/*
	Json::Value root;
	Json::Reader reader;
	std::ifstream file;
*/
	const char* path = "config.json";
	file.open(path,std::fstream::in);


	if (!file.is_open()) {
		std::cout << "Error abriendo el archivo de configuración" << std::endl; 
		return false;
	}

	bool parsingSuccessful = reader.parse(file, root);  
	if (!parsingSuccessful) {
		std::cout << "Error leyendo el archivo de configuración: " << file << std::endl;
		return false;
	}

//el 2do parametro del get() es el valor por defecto si no lo encuentra en el json
	loadWindowConfig();
	file.close();
}

void JsonReader::loadWindowConfig() {
	int window_width = root["ventana"].get("ancho",640).asInt();
	int window_height = root["ventana"].get("alto",480).asInt();
	windowConfig["width"] = window_width;
	windowConfig["height"] = window_height;
}

int JsonReader::getWindowValue(std::string property) {
	if ( windowConfig.find(property) == windowConfig.end()) {
		std::cout << "No se encuentra el valor de configuración para " << property << std::endl;
		// Debería encontrar algún valor por defecto
	}
	return windowConfig[property];
}
