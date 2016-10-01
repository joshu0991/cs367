#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fp.h"

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

  if (val == 0)
  {
    return 0;
  }

  float temp = val;
  int e = 0;
  int retVal = 0;
  
  // calculate the exponent.
  if (val >= 2)
  {
    while (val >= 2)
    {
      val = val / 2;
      ++e;
    }
  }
  else if (val < 1)
  {
    while (val < 1)
    {
      val = val * 2;
      ++e;
    }
    e *= -1;
  }

  val -= 1;

  int biasedExponent = e + 15;
   
  int mantissa = 0;
  // get the mantissa.
  float sevenBits = val * (pow(2, 7));
  mantissa = (int)sevenBits;

  if (biasedExponent > 30)
  {
    return -1;
  }

  if (biasedExponent < 1)
  {
    return 0;
  }

  retVal |= biasedExponent;
  retVal <<= 7;
  retVal |= mantissa;
  return retVal;
}

float getFP(int val) {
// Using the defined representation, compute the floating point
//    value
// For denormalized values (including 0), simply return 0.
// For special values, return -1;

  float fraction = ((val & 0x7F) / (float)pow(2, 7)) + 1;
  int exponent = ((val >> 7) & 0x1F);

  // denormalized or zero
  if (exponent == 0)
  {
    return 0;
  }

  // special number
  if (exponent == 0x1F)
  {
    return -1;
  }

  int e = exponent - 15;
  
  if (e < 0)
  {
    int i;
    for (i = e; i < 0; ++i)
    {
      // extract the whole number
      fraction = fraction / 2;
    }
  }
  else // e > 0
  {
    int i;
    for (i = 0; i < e; ++i)
    {
      fraction = fraction * 2;
    }

  } 
  return fraction;
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

  int exponent1 = ((source1 >> 7) & 0x1F);
  int exponent2 = ((source2 >> 7) & 0x1F);

  int e1 = exponent1 - 15;
  int e2 = exponent2 - 15;
  int e3 = e1 + e2;

 
  float frac1 = ((float) (source1 & 0x7f));
  float frac2 = ((float) (source2 & 0x7f));

  frac1 = (frac1 / ((float)pow(2, 7))) + 1;
  frac2 = (frac2 / ((float)pow(2, 7))) + 1;

  if ((e3 + 15) > 30)
  {
    return -1;
  } 

  if ((e3 + 15) < 1)
  {
    return 0;
  }

  float frac = frac1 * frac2;
  if (frac >= 2)
  {
    frac /= 2;
    ++e3;
  }

  if (e3 > 14)
  {
    return -1;
  }

  int new_exp = 15 + e3;
  frac -= 1;
  frac *= (float)pow(2, 7);

  int newFrac = (int) frac;

  int retVal = 0;
  retVal |= new_exp;
  retVal <<=  7;
  retVal |= newFrac; 
  return retVal;;
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
  int exponent1 = ((source1 >> 7) & 0x1F);
  int exponent2 = ((source2 >> 7) & 0x1F);

  int e1 = exponent1 - 15;
  int e2 = exponent2 - 15;
    
  float frac1 = ((float) (source1 & 0x7f));
  float frac2 = ((float) (source2 & 0x7f));
  
  // the fractions with the leading 1
  frac1 = (frac1 / ((float)pow(2, 7))) + 1;
  frac2 = (frac2 / ((float)pow(2, 7))) + 1;

  if (e1 > e2)
  {
    int i;
    int delta = e1 - e2;
    for (i = 0; i < delta; ++i)
    {
      frac2 = frac2 / 2;
      ++e2;
    }
  }
  else if (e1 < e2)
  {
    int i;
    int delta = e2 - e1;
    for ( i = 0; i < delta; ++i)
    {
      frac1 = frac1 / 2;
      ++e1;
    }
  }

  float frac = frac2 + frac1;

  while (frac >= 2)
  {
    frac = frac / 2;
    ++e1;
  }

  while (frac < 1)
  {
    frac = frac * 2;
    --e1;
  }

  if ((e1 + 15) > 30)
  {
    return -1;
  }
 
  int new_exp = (15 + e1) * (pow(2, 7));
  frac -= 1;
  frac *= (float)pow(2, 7);

  int newFrac = (int) frac;
  return new_exp + newFrac;
}

