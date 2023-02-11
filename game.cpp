#include <iostream>
#include <ctime>
using namespace std;

int main() {
  int distance = 1000; // starting distance from Earth
  int fuel = 500; // starting amount of fuel
  int consume; // fuel consumed per turn
  int turn = 1; // turn counter
  
  srand(time(0)); // seed the random number generator
  
  cout << "Welcome to the spaceship game!" << endl;
  cout << "Your goal is to reach the end of your journey with as much fuel as possible." << endl;
  
  while (distance > 0) {
    cout << "Turn " << turn << ": " << distance << " km to go, " << fuel << " fuel left." << endl;
    cout << "How much fuel would you like to consume this turn (1-50)? ";
    cin >> consume;
    
    if (consume >= 1 && consume <= 50) {
      distance -= 100;
      fuel -= consume;
      turn++;
      
      if (fuel < 0) {
        cout << "You have run out of fuel and failed to reach your destination." << endl;
        break;
      }
      
      if (distance < 0) {
        cout << "Congratulations! You have reached your destination with " << fuel << " units of fuel left." << endl;
        break;
      }
    } else {
      cout << "Invalid input. Please enter a number between 1 and 50." << endl;
    }
  }
  
  return 0;
}
