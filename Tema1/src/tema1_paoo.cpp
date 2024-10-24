#include <iostream>
#include <string>

class Car{
private: 
    float width;
    float height;
    int fabrication_year;
    std::string model_name;

public:

    //constructorul unui obiect Car:
   Car(float width, float height, int fabrication_year, std::string model_name){
        std::cout<<"Car constructor executed"<<std::endl;
        this->width=width;
        this->height=height;
        this->fabrication_year=fabrication_year;
        this->model_name=model_name;
    }

    void toString(){
            std::cout<<"Car details:\n"<<
                       "width: " << this->width <<
                       "\nheight: " << this->height <<
                       "\nfabrication_year: " << this->fabrication_year << 
                       "\ncar model: " << this->model_name <<std::endl;
        }

    //Destructorul unui obiect Car
    ~Car(){
        std::cout<<"Car destructor executed"<<std::endl;
    }
    
    //copy constructor al unui obiect Car: 
    Car(const Car& other_car):
        width(other_car.width),
        height(other_car.height),
        fabrication_year(other_car.fabrication_year),
        model_name(other_car.model_name){
            std::cout<<"Copy constructor executed"<<std::endl;
    }

    Car(Car&& move_car) noexcept{
        width = move_car.width;
        height = move_car.height;
        fabrication_year = move_car.fabrication_year;
        model_name = move_car.model_name;

        move_car.width = 0.0f;
        move_car.height = 0.0f;
        move_car.fabrication_year = 0;
        move_car.model_name= "";
        std::cout<<"Move constructor executed"<<std::endl;
    }
    
};

int main(void){
    
    std::cout<<"First car (stack car) details:"<<std::endl;

    Car car(1.48,1.345,1986,"Toyota Sprinter"); //obiect creat pe Stiva
    car.toString();
    
    std::cout<<"-------------------------------------"<<std::endl;
    
    std::cout<<"Second car (heap car) details:"<<std::endl;

    Car* car2 = new Car(1.49,1.40,1968,"Dacia 1100"); //Obiect creat in zona Heap
    car2->toString();
    delete car2; //eliberam obiectul din heap folosindu-ne de destructor
    
    std::cout<<"-------------------------------------"<<std::endl;

    std::cout<<"Third car (copy car) details:"<<std::endl;

    Car car3 = car; //ne folosim aici de copy constructor pentru a avea in car3 atributele lui car (shallow copy)
    car3.toString();
    
    std::cout<<"-------------------------------------"<<std::endl;

    std::cout<<"Fourth car (move car) details:"<<std::endl;
    
    Car car4 = std::move(car);
    car4.toString();
    
    std::cout<<"-------------------------------------"<<std::endl;

    std::cout<<"First car after move detail:"<<std::endl;

    car.toString();

    return 0;
}