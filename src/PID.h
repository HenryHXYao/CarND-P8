#ifndef PID_H
#define PID_H
#include <queue>

class PID {
 public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   * IMPORTANT: Kp_, Ki_, Kd_ must be 0 or positive to guarantee stability
   */
  void Init(double Kp_, double Ki_, double Kd_);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double cte);

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError();

 private:
  /**
   * previous cte & flag for prev_cte initialization
   */  
  bool prev_cte_is_initialized;
  double prev_cte;
  
  /**
   * PID Errors
   */
  double p_error;
  double i_error;
  double d_error;

  /**
   * PID Coefficients
   */ 
  double Kp;
  double Ki;
  double Kd;
};

class MovingAverage {
 public:
  MovingAverage(int num):max_num_element(num) {}
  void UpdateMean(double input_data);
  
  double mean = 0;
 private:
  int max_num_element;
  std::queue<double> data;
};

#endif  // PID_H
