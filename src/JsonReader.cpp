#include "../headers/JsonReader.h"

JsonReader* JsonReader::pInstance = 0;

bool JsonReader::load() {

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

	/*
	 * Al agregar nuevas configuraciones al config.json, crear métodos para levantarlos como loadWindowConfig()
	 */

	loadWindowConfig();
	loadStageConfig();
	
	file.close();
}


void JsonReader::loadStageConfig() {
	int stage_width = root["stage"].get("width",640).asInt();
	int stage_height = root["stage"].get("height",480).asInt();
	int stage_x = root["stage"].get("x",0).asInt();
	int stage_y = root["stage"].get("y",0).asInt();

	stageConfig["width"] = stage_width;
	stageConfig["height"] = stage_height;

	stageConfig["x"] = stage_x;
	stageConfig["y"] = stage_y;
}

void JsonReader::loadWindowConfig() {
	int window_width = root["window"].get("width",640).asInt();
	int window_height = root["window"].get("height",480).asInt();
	windowConfig["width"] = window_width;
	windowConfig["height"] = window_height;
}

int JsonReader::getStageValue(std::string property) {
	if ( stageConfig.find(property) == stageConfig.end()) {
		std::cout << "No se encuentra el valor de configuración para " << property << std::endl;
		// Debería encontrar algún valor por defecto
	}
	return stageConfig[property];
}

int JsonReader::getWindowValue(std::string property) {
	if ( windowConfig.find(property) == windowConfig.end()) {
		std::cout << "No se encuentra el valor de configuración para " << property << std::endl;
		// Debería encontrar algún valor por defecto
	}
	return windowConfig[property];
}
