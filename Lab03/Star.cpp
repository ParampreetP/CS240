#include "Star.h"
#include <cstdlib>
#include <iostream>
#include "Planet.h"
using namespace std;
//Type ** obj = new type*[size];

Star::~Star(){//the destructor is a member function which destructs or deletes an object.
	// Delete the pointers inside of the array
	for(int i = 0; i < current_planets; i++){
		delete planets[i];
	}
	// Delete the array that held the pointers
	delete[] this->planets;
}

Star::Star(){
	this->current_planets = 0;
	this->planets = NULL;
}
bool Star::removePlanet(int id){
	bool retVal = false;
	int index = -1;
	//see if this planet we want to remove exist..
	 
	for (int i =0; i <this->current_planets;i++){
		if (this->planets[i]->getID() == id){
			retVal = true;
			index =i;		
			break;
		}
	}


	//now we need to remove an planet 
	if (retVal)
	{
		//allocate new array of size-1
		Planet **tmp = new Planet*[this->current_planets -1];

	//copy all pointers over except for the removed planet
	for(int i = 0, j =0; i < this->current_planets; i++){
		if (i == index){
			delete this->planets[i];
			
		}
		else
		{
			tmp[j] = this->planets[i];
			j++;
		}
	}
	//update current number of planets
	this->current_planets--;

	//then free old array and set that array to the new one
	delete[] this->planets;
	this->planets = tmp;

	}
	return retVal;
}

int Star::addPlanet(){

	// Allocate new array of size+1
	Planet **tmp = new Planet*[current_planets + 1];

	// Copy old array to new array
	for (int i = 0; i < current_planets; i++){
		tmp[i] = planets[i];
	}
	// New planet object
	int random = rand() % 3001;//random number between 0 and 359
	Planet *new_planet = new Planet(random,this->next_id);
	this->next_id++;
	
	// Resulting planet into new array
	tmp[current_planets] = new_planet;

	// Update current number of planets
	this->current_planets++;

	// Free old array and set that array to new array
	delete[] this->planets;
	this->planets = tmp;

	return new_planet->getID();
}


Planet * Star::getPlanet(int id){
	
	for (int i = 0; i < this->current_planets; i++){
		if (planets[i]->getID() == id) {return this->planets[i];}
	}
	return NULL;

}

void Star::printStarInfo(){
	cout<<"The star currently has "<< current_planets << " Planets."<<endl;		
	cout<< "Planets:" << endl;
	for (int i = 0; i < this->current_planets; i++){
		cout << "Planet " << planets[i]->getType() << planets[i]->getID() <<  " is "  << planets[i]->getDistance() << " million miles away at position " << planets[i]->getPos() << " around the star." << endl;
	}	

}
void Star::orbit(){
	for(int i = 0; i < current_planets; i++){
		this->planets[i]->orbit();
	}
}
