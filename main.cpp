// MIT License Copyright (c) 2021 seaweed843
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT
#include <memory>
#include <iostream>
struct Garage;
struct Apartment {
    std::shared_ptr<Garage> mGarage;
    Apartment(){
        std::cout << "Apartment ctor" << std::endl;
    }
    ~Apartment(){
        std::cout << "Apartment dtor" << std::endl;
    }
  };
  
struct Car;
struct Garage {
      std::shared_ptr<Car> mCar;
      Garage(){
           std::cout << "Garage ctor" << std::endl;
      }
      ~Garage(){
          std::cout << "Garage dtor" << std::endl;
      }
  };

struct Car {
      std::shared_ptr<Apartment> mApartment;
      Car(){
           std::cout << "Car ctor" << std::endl;
      }
      ~Car(){
          std::cout << "Car dtor" << std::endl;
      }
  };

void buildCycle(){
    auto apartment = std::make_shared<Apartment>();
    auto garage = std::make_shared<Garage>();
    auto car = std::make_shared<Car>();

    apartment->mGarage=garage;
    garage->mCar = car;
    car->mApartment = apartment;
}
int main(int argc, char* argv[]){
    buildCycle();
    return 0;
}