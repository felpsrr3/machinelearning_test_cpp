#include <iostream>
#include <math.h>
#include <stdlib.h>

class Neural{
private:
  double* weights;
  double bias;
  
  int SIZE;
public:
  Neural(int size){
    this->SIZE = size;
    this->weights = (double*)malloc(sizeof(double)*size);
    
    for (int i=0; i<size; i++){
      this->weights[i]=(double)rand()/RAND_MAX;
      std::cout << this->weights[i] << std::endl;
    }
    
    this->bias = (double)rand() / RAND_MAX;
    std::cout << this->bias << std::endl;
  }
  
  double sigmoid(double x){
    return 1/(1+exp(-x));
  }
  
  double run(double* inputs){
    double sum = 0.0;
    
    for (int i=0; i < this->SIZE; i++){
      sum += (inputs[i] * this->weights[i]);
    }
    return this->sigmoid(sum);
  }
  
  double train(double* inputs, double desired){
    double y = this->run(inputs);
    
    for(int i=0; i < this->SIZE; i++){
      
      this->weights[i] += (desired - y) * inputs[i];
    }
    return this->bias += (desired - y);
  }
};
    
    
