/*
Author: Alex Agudelo
Class: ECE 6122
Last date modified: 10/29/19
Description: 
*/
#include <iostream>
#include <cmath>

#include "ship.hpp"


void handleYellowJacket();
double calculateYellowJacketForce(double position, double vel, double dest);
Ship yellowJacket{};
Coordinate destination{-5000,5000, 3000};

int main()
{
    std::cout << "Hello World" << std::endl;

    // Read in files

    // Determine stating positions

    // On Buzzy just calculate new position
    Ship buzzy{};

    for(int i=0; i< 500; i++)
    {
        handleYellowJacket();
    }

    // For each jacket
    // 1. Determine the force necessary
    //      Determine how many time steps to reach goal location at max speed
    //      Calculate the position of buzz at that time step
    //      Determine number of time steps to slow down to necessary speed
    //          When the number of steps of steps is 4 then start slowing down at 4 + 4

    //  If mag of distance is less than 1000 then stop and wait turn
    //      The closest person who is less than 1000 will proceed to dock
    // 2. Evolve the system
    return 1;
}


void evolveSystem(Ship& currShip)
{
    currShip.position.x = currShip.position.x + currShip.velocity.x + (currShip.force.x/yellowJacketMass)/2;
    currShip.position.y = currShip.position.y + currShip.velocity.y + (currShip.force.y/yellowJacketMass)/2;
    currShip.position.z = currShip.position.z + currShip.velocity.z + (currShip.force.z/yellowJacketMass)/2;

    currShip.velocity.x = currShip.velocity.x + currShip.force.x/yellowJacketMass;
    currShip.velocity.y = currShip.velocity.y + currShip.force.y/yellowJacketMass;
    currShip.velocity.z = currShip.velocity.z + currShip.force.z/yellowJacketMass;
}

void handleYellowJacket()
{
    yellowJacket.force.x = calculateYellowJacketForce(yellowJacket.position.x, yellowJacket.velocity.x, destination.x);
    yellowJacket.force.y = calculateYellowJacketForce(yellowJacket.position.y, yellowJacket.velocity.y, destination.y);
    yellowJacket.force.z = calculateYellowJacketForce(yellowJacket.position.z, yellowJacket.velocity.z, destination.z);

    evolveSystem(yellowJacket);
}

void calculateTimeToDest(const Coordinate& dest)
{

}

double calculateYellowJacketForce(double position, double vel, double dest)
{
    double force{0};
    double timeDif{0};
    if(yellowJacket.timeToStop(vel) > 0)
    {
        timeDif = static_cast<double>(yellowJacket.timeToDest(position, dest, vel))/yellowJacket.timeToStop(vel);
    }
    if(timeDif > 3)
    {
        force = yellowJacket.maxForce*yellowJacket.getDistanceUnitVec(position, dest);
    }
    else if(timeDif > 1.5)
    {
        force = -yellowJacket.maxForce*(-(timeDif-1.5) + 1)*yellowJacket.getDistanceUnitVec(position, dest);
    }
    else if (timeDif > .1)
    {
        force = yellowJacket.stopForce(vel);
    }
    else
    {
        if(yellowJacket.getDistance(position, dest) > 2000)
        {
            force = yellowJacket.maxForce*.2*yellowJacket.getDistanceUnitVec(position, dest);
        }
        else
        {
            std::cout << "2000 away" << std::endl;
        }
    }

    return force;
}
