#include <iostream>
#include <fstream>
using namespace std;

//this struct includes all the different parts of a car and their data types
struct carParts {
enum {MAX_CHAR_LEN = 500};
char carName[MAX_CHAR_LEN];
char Origin[MAX_CHAR_LEN];
double MPG;
int Cylinders;
double Displacement;
double Horsepower;
double Weight;
double Acceleration;
int Model;
bool ValidEntry;

carParts();
};

//void function with no output to hold car parts
void PrintcarParts(carParts x);

//default constructor which sets all values to 0, and the boolean to false
carParts::carParts() {
  for(int index = 0; index < MAX_CHAR_LEN; index++){
    carName[index] = 0;
    Origin[index] = 0;
    MPG = 0;
    Cylinders = 0;
    Displacement = 0;
    Horsepower = 0;
    Weight = 0;
    Acceleration = 0;
    Model = 0;
    ValidEntry = false;
}
  }

const int MAX_CARS = 500;
//gets each part and their values from cars.txt
carParts readCars(ifstream &inFile){
carParts car;
  
  inFile.get(car.carName, carParts::MAX_CHAR_LEN, ';');
    inFile.ignore(100,';');
  inFile >> car.Origin;
    inFile.ignore(100,';');
    inFile >> car.MPG;
    inFile.ignore(100,';');
    inFile >> car.Cylinders;
    inFile.ignore(100,';');
    inFile >> car.Displacement;
    inFile.ignore(100,';');
    inFile >> car.Horsepower;
    inFile.ignore(100,';');
    inFile >> car.Weight;
    inFile.ignore(100,';');
    inFile >> car.Acceleration;
    inFile.ignore(100,';');
    inFile >> car.Model;
    inFile.ignore(100,'\n');
  car.ValidEntry =! inFile.eof();

  return car;
  }

  //checks if the input is valid and tells the user if it isn't
int intVal(const char val[]){
  //x is just a temporary value
    int x = 0;
    cout << val;
    cin >> x;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << val;
        cin >> x;
    }
    return x;
}

//same as int val
double doubleVal(const char val[]){
    int x = 0;
    cout << val;
    cin >> x;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << val;
        cin >> x;
    }
    return x;
}

  //gets values from cars.txt using ifstream and adds to numCars after setting it equal to 0 while it is still less than 500
int readCarData(carParts cars[]){
ifstream carsFile("cars.txt");
    int numCars = 0;
    while(numCars < 500) {
        cars[numCars] = readCars(carsFile);
        numCars++;
    }
    return numCars;
}

  //prints the car parts
void PrintCar(carParts x) {
  cout << x.carName << ";" 
    << x.Origin << ";" 
    << x.MPG << ";" 
    << x.Cylinders << ";" 
    << x.Displacement << ";" 
    << x.Horsepower << ";" 
    << x.Weight << ";" 
    << x.Acceleration << ";" 
    << x.Model << endl;
  }

  //prints index if its a valid entry as long as the index is less than the possible number of max carss
  void printCars(carParts cars[]){
  for(int index = 0; index < 500; index++){
    if (cars[index].ValidEntry == true){
      cout << index;
        PrintCar(cars[index]);
      cout << endl;
    }
  }
}

//asks the user for the origin, prints in the same format as printCars, but only prints the cars that have the same origin as the one the user selected.
  void printCarsByOrigin(carParts cars[]) {
    string carOrigin;
    cout << "Enter car origin" << endl;
    cin >> carOrigin;
     for(int index = 0; index < 500; index++){
    if (cars[index].ValidEntry == true && cars[index].Origin == carOrigin){
       cout << index;
        PrintCar(cars[index]);
      cout << endl;
    }
  }
}
  //removes whatever car is in an index between 0-500 unless it is not in that range
void removeCar(carParts cars[]){
  int invalidIndex;
  do {
  invalidIndex = intVal("Enter index to remove");
  cars[invalidIndex].ValidEntry = false;
  }
    while(invalidIndex > 500 || invalidIndex < 0);
}

// the computer checks the if statement first for is ValidEntry is false
void addCar(carParts cars[]){
  for(int index = 0; index < 500; index ++){
    if (cars[index].ValidEntry == false){
      //it asks the user to enter the necessary parts of an engine and adds them to the carParts struct
      cin.ignore(100, '\n');
      cout << "Enter the name of the car you want to add:" << endl;
      cin.getline(cars[index].carName,carParts::MAX_CHAR_LEN);
      //checks if all entered values are ints/doubles as well for the origin
      cars[index].MPG = intVal("Enter the MPG: ");
      cars[index].Cylinders = intVal("Enter the cylinder count: ");
      cars[index].Displacement = intVal("Enter the displacement: ");
      cars[index].Horsepower = intVal("Enter the horsepower: ");
      cars[index].Weight = intVal("Enter the weight: ");
      cars[index].Acceleration = doubleVal("Enter the 0-60 time: ");
      cout << "Enter the origin: ";
      cin >> cars[index].Origin;  
      //valid set to true
      cars[index].ValidEntry = true;
      return;
    }
    }
  //after checking the if statement it comes down here
      cout << "The database is full" << endl;
  }

//shows options for user to choose
void displayMenu(carParts cars[]){
  int input = 0;  
  while(input !=5){
      cout << "Choose a number option to continue or type quit." << endl;
      cout << "1. Display the car list." << endl;
      cout << "2. Remove a car from the list." << endl;
      cout << "3. Add a car to the list." << endl;
      cout << "4. Display cars by origin." << endl;
      cout << "5. Quit" << endl;
      cin >> input;

    if(input == 1){
    printCars(cars);
    }
    if(input == 2){
    removeCar(cars);  
    }
    if(input == 3){
    addCar(cars);  
    }
    if(input == 4){
    printCarsByOrigin(cars);  
    }
    if(input == 5){
      cout << "You quit the program.";
      break;
        }
}
  }

//main, calls necessary functions 
int main(){
carParts list[MAX_CARS];
readCarData(list);
printCars(list);
displayMenu(list);
}