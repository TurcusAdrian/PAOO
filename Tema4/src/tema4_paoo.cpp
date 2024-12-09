#include <iostream>
#include <string>
#include <memory>

  
class Car{

protected: 
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
    virtual void toString(){
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
    virtual ~Car(){
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
 
};

class Mercedes : public Car{

private :
  std::string* class_type;

 public:
  Mercedes(float width, float height, int fabrication_year, std::string model_name, std::string class_type) : Car(width, height, fabrication_year, model_name){
    this->class_type = new std::string(class_type);
    std::cout<<"Mercedes constructor executed"<<std::endl;
  }

  Mercedes(const Mercedes& other) : Car(other){
    class_type = new std::string(*other.class_type);
    std::cout<<"Mercedes copy constructor executed"<<std::endl;
  }

  Mercedes& operator=(const Mercedes& other){
        
        if(this == &other){
	  return *this;
	}

	Car :: operator=(other);
	delete class_type;

	class_type = new std::string(*class_type);
	std::cout<<"Mercedes copy assignment operator used"<<std::endl;
      return *this;
    }

  ~Mercedes() override{
    delete class_type;
    std::cout<<"Mercedes destructor executed"<<std::endl;
  }

  void toString() override{
    Car::toString();
    std::cout<< "Class type: "<<*class_type<<std::endl;
  }

  std::auto_ptr<Car> createCar(bool isMercedes){
    if(isMercedes){
      return std::auto_ptr<Car>(new Mercedes(2.0f, 1.8f, 2024, "Mercedes-Benz S-Class", "Luxury Car"));
	}
    else {return std::auto_ptr<Car>(new Car(1.2f, 1.4f, 2007, "Fiat Punto"));}
  }

  std::shared_ptr<Car> createCar2(bool isMercedes){
     if(isMercedes){
      return std::shared_ptr<Car>(new Mercedes(2.0f, 1.8f, 2014, "Mercedes-Benz E-Class", "Electric Car"));
	}
    else {return std::shared_ptr<Car>(new Car(2.2f, 1.9f, 2025, "Koenigsegg Jesko"));}
  }
  
  void with_auto_pointer(){
    std::auto_ptr<Car> car = createCar(true);
    car->toString();
  }

   void with_shared_pointer(){
    std::shared_ptr<Car> car = createCar(false);
    car->toString();
  }

};

 Car* createCarRaw(bool isMercedes){
    if (isMercedes) {
        return new Mercedes(2.0f, 1.8f, 2024, "Mercedes-Benz S-Class", "Luxury Car");
    } else {
        return new Car(1.2f, 1.4f, 2007, "Fiat Punto");
    }
  }


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

    std::cout<<"-------------------------------------"<<std::endl;

    Mercedes m1(1.5, 1.3, 2022, "Mercedes C-Class", "Sedan");
    std::cout<<"First Mercedes car detail:"<<std::endl;
    m1.toString();

    std::cout<<"Copy m1 to m2:"<<std::endl;

    Mercedes m2 = m1;
    std::cout<<"Second Mercedes car detail:"<<std::endl;
    m2.toString();

    std::cout<<"-------------------------------------"<<std::endl;

    Car* car_raw = createCarRaw(false);
    std::cout<<"Raw car detail:"<<std::endl;
    car_raw->toString();
    delete car_raw;

    std::cout<<"-------------------------------------"<<std::endl;

   
    
    return 0;
}
