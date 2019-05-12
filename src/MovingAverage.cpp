#include "MovingAverage.h"

void MovingAverage::UpdateMean(double input_data){
  if (data.size() < max_num_element) {
    mean = (mean * data.size() + input_data)/(data.size() + 1);
    data.push(input_data);
  }
  else {
    double pop_data = data.front();
    mean = (mean * max_num_element - pop_data + input_data)/max_num_element;  
    data.pop();
    data.push(input_data);
  }
}
