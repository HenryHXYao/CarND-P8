#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {
  prev_cte_is_initialized = false;
  i_error = 0.0;
}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  p_error = cte;
  i_error += cte;  
  if (prev_cte_is_initialized == false){
    prev_cte = cte;
    d_error = 0;
    prev_cte_is_initialized = true;
  }
  else {
    d_error = cte - prev_cte;
  }
}

double PID::TotalError() {
  /**
   * Calculate and return the total error
   */
  double total_error = -Kp * p_error - Kd * d_error - Ki * i_error;
  if (total_error > 0.1) {
    total_error = 0.1;
  }
  else if (total_error < -0.1) {
    total_error = -0.1;
  }
  return total_error;  // TODO: Add your total error calc here!
}