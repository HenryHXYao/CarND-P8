#include <queue>

class MovingAverage
{
public:
  MovingAverage(int num) : max_num_element(num) {}
  void UpdateMean(double input_data);

  double mean = 0;

private:
  int max_num_element;
  std::queue<double> data;
};