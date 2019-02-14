#include "Star.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Planet::Planet(int distance, int id){
	this->id = id;
	this->distance = distance;
    	this->pos = 0;
}

int Planet::getID(){
	return this->id;
}
int Planet::getDistance(){
	return this->distance;
}
int Planet::getPos(){
	return this->pos;
}
int Planet::orbit(){
	if ((pos >= 0) && (pos < 359)) {
		pos++;
	}
	else{
		pos=0;
	}	
	return this->pos;
}

Star::Star(int max_planets){
	this->max_planets = max_planets;
	this->current_planets = current_planets;
	this->next_id = next_id;
}
bool Star::addPlanet(){
	if (this->max_planets == this->current_planets){
		return false;	
	}
	
	int random = rand() % 360;//random number between 0 and 359
	int currentplan = current_planets;
	Planet p = Planet(random, currentplan);
	planets[current_planets] = p;
	current_planets++;
	return true;
	
	
}
Planet Star::getFurthest(){
	if (this->current_planets == 0){
		Planet p;
		return p;
	}
	Planet retval = planets[0];
	for (int i = 0; i < this->current_planets; i++){
		if (this->planets[i].getDistance() > retval.getDistance()){
			retval = this->planets[i];
		
		}
	}
	return retval;
	
}
int Star::getCurrentNumPlanets(){
	return this->current_planets;
}
int Star::getMaxPlanets(){
	return this->max_planets;
}
void Star::printStarInfo(){
	cout<<"The star currently has "<< current_planets << "."<<endl;		
	cout<<"The star can support up to "<< max_planets<<"." << endl;
	cout<< "Planets:" << endl;
	for (int i = 0; i < this->current_planets; i++){
		cout << "Planet " << planets[i].getID() <<  " is "  << planets[i].getDistance() << " million miles away at position " << planets[i].getPos() << " around the star." << endl;
	}	

}
void Star::orbit(){
	for(int i = 0; i < current_planets; i++){
		planets[i].orbit();
	}
}
