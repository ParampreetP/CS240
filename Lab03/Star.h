#ifndef STAR_H
#define STAR_H
#include "Planet.h"

class Star{
	private:
        int current_planets;
        int next_id;
	public: 
        Star();//constructor
	~Star();//destructor
	Planet ** planets;
	int addPlanet();
        //bool addPlanet();
	bool removePlanet(int);
        Planet getFurthest();
        void orbit();
	Planet * getPlanet(int);
        void printStarInfo();
        int getCurrentNumPlanets(){return this->current_planets;}
        //you may add any additional methods you may need.
};
#endif
