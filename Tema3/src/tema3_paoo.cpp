#include <iostream>
#include <string>



class Car{

private: 
    float* width;
    float* height;
    int* fabrication_year;
    std::string* model_name;

  
public:

    //constructorul unui obiect Car:
   Car(float width, float height, int fabrication_year, std::string model_name){
        std::cout<<"Car constructor executed"<<std::endl;
        this->width=new float(width);
        this->height=new float(height);
        this->fabrication_year=new int(fabrication_year);
        this->model_name=new std::string(model_name);
    }

    // Metoda toString sa vizualizam atributele 
    void toString(){
      if(width && height && fabrication_year && model_name){
            std::cout<<"Car details:\n"<<
                       "width: " << *width <<
                       "\nheight: " << *height <<
                       "\nfabrication_year: " << *fabrication_year << 
                       "\ncar model: " << *model_name <<std::endl;
        }
      else{ std::cout<<"Car empty or moved"<<std::endl;}
    }

    //Destructorul unui obiect Car
    ~Car(){
      delete width;
      delete height;
      delete fabrication_year;
      delete model_name;
        std::cout<<"Car destructor executed"<<std::endl;
    }
    
   
    //Move constructor 
    Car(Car&& move_car) noexcept{
        width = move_car.width;
        height = move_car.height;
        fabrication_year = move_car.fabrication_year;
        model_name = move_car.model_name;


	move_car.width = nullptr;
        move_car.height = nullptr;
        move_car.fabrication_year = nullptr;
        move_car.model_name= nullptr;
        std::cout<<"Move constructor executed"<<std::endl;
    }

   //copy constructor al unui obiect Car 
  Car(const Car& other_car){
      width = new float(*other_car.width);
      height = new float(*other_car.height);
      fabrication_year = new int(*other_car.fabrication_year);
      model_name = new std::string(*other_car.model_name);
      std::cout<<"Copy constructor executed"<<std::endl;
    }

    //Copy assignment operator care sa returneze *this:
    Car& operator=(const Car& car){
        std::cout<<"Copy assignment operator used"<<std::endl;
        if(this == &car){
	  return *this;
	}

      delete width;
      delete height;
      delete fabrication_year;
      delete model_name;

      width = new float(*car.width);
      height = new float(*car.height);
      fabrication_year = new int(*car.fabrication_year);
      model_name = new std::string(*car.model_name);

      return *this;
    }

  Car& operator=(const Car& car){
    *model_name = *car.model_name;
    return *this;
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
    //delete car2; //eliberam obiectul din heap folosindu-ne de destructor
    
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
