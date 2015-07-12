#ifndef __JSONREADER__
#define __JSONREADER__
#include <iostream>
#include <jsoncpp/json/json.h>
#include <string>
#include <fstream>

/* Lector de archivos JSON http://jsoncpp.sourceforge.net/old.html
 * Leer la configuración en load() con un método similar a loadWindowConfig()
 * Almacenar en una estructura de datos y crear getters públicos
 */
 
class JsonReader {
public:
	static JsonReader* Instance() {
		if ( !pInstance) {
			pInstance = new JsonReader();
			pInstance->load();
		}
		return pInstance;
	}

	//Métodos para acceder a la configuración guardada
	int getWindowValue(std::string property);

private:
	JsonReader(){}
	~JsonReader(){}
	static JsonReader* pInstance;
	Json::Value root;
	Json::Reader reader;
	std::ifstream file;
	
	//Métodos para levantar la información del JSON
	bool load();
	void loadWindowConfig();
	
	//Las opciones pueden venir en distinto formato, por ahora uso una estructura de datos única por item
	std::map<std::string,int> windowConfig;
};

#endif