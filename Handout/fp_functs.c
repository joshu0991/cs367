#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fp.h"

typedef union {
  float v;
  struct {
    unsigned fraction : 23;
    unsigned exp : 8;
    unsigned sign : 1;
  } p;
} float_to_parts;


int
computeFP(float val) {
// input: float value to be represented
// output: integer version in our representation
//
// Perform this the same way we did in class -
//    either dividing or multiplying the value by 2
//    until it is in the correct range (between 1 and 2).
//    Your exponent is the number of times this operation
//    was performed.   
// Deal with rounding by simply truncating the number.
// Check for overflow and underflow - 
//    with 4 exponent bits, we have overflow if the number to be 
//       stored is > 14
//    for overflow (E > 14), return -1
//    For underflow (E < 1), return 0 
  
  // extract the exponent.
  // int exponent = val & 0x7F800000;
  // exponent >>= 23; 
  //int 
  float_to_parts floatParts;
  floatParts.v = val;
  
  //bias for 32 bit is 2^k-1 -1 = 127
  // e = exp - bias 
  int e = floatParts.p.exp - 127;

  // new biased exponent is to 5 bias = 15
  int new_exp = e - 15;
  
  int retVal = 0;

  // pack in the new exponent.
  retVal |= new_exp;
  retVal <<= 23;
  // pack in the fraction portion.
  retVal |= floatParts.p.fraction;
  return retVal;
}

float getFP(int val) {
// Using the defined representation, compute the floating point
//    value
// For denormalized values (including 0), simply return 0.
// For special values, return -1;

 return 2.0;
}

int
multVals(int source1, int source2) {
// You must implement this by using the algorithm
//    described in class:
//    Add the exponents:  E = E1+E2 
//    multiply the fractional values: M = M1*M2
//    if M too large, divide it by 2 and increment E
//    save the result
// Be sure to check for overflow - return -1 in this case
// Be sure to check for underflow - return 0 in this case

 return 2;
}

int
addVals(int source1, int source2) {
// Do this function last - it is the most difficult!
// You must implement this as described in class:
//     If needed, adjust one of the two number so that 
//        they have the same exponent E
//     Add the two fractional parts:  F1' + F2 = F
//              (assumes F1' is the adjusted F1)
//     Adjust the sum F and E so that F is in the correct range
//     
// As described in the handout, you only need to implement this for
//    positive, normalized numbers
// Also, return -1 if the sum overflows
  return 2;
}

