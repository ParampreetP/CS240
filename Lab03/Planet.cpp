#include "Star.h"
#include "Planet.h"
#include <cstdlib>
#include <iostream>
using namespace std;
//Type ** obj = new type*[size];
Planet::Planet(int distance, int id){
	this->id = id;
	this->distance = distance;
    	this->pos = rand() % 360;
	//'h'=habitable
	//'r' = rocky
	//'g'= gaseous

	// Random number 0 - 3 inclusive
	int randomNum = rand() % 3;
	switch (randomNum){
		case 0: //'h'
			this->type = 'h';
		break;
		case 1: //'r'
			this->type = 'r';
		break;
		case 2: //'g'
			this->type = 'g';
		break;
	}
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
