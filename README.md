Librería para leer archivos json: libjsoncpp-dev
Documentacion: https://github.com/open-source-parsers/jsoncpp


TO DO (ordenados de más nuevo a más viejo):
- Terminar las colisiones en LayoutManager.cpp, en particular los métodos willCollide() y solveCollition()
-- Estoy tomando como únicos rebotadores a los objetos Ball. Debería hacer una clase padre Bouncer y redefinir los parámetros en LayoutManager.h y .cpp
- Completar clase Drawable para que, en lo posible, unifique el criterio de creación de la textura de sus componentes.
- Hacerle un getter para su *Texture así se resuelve el problema en Jueguito::render y en ::update
