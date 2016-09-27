#include <stdio.h>
#include <math.h>

typedef union {
  float f;
  struct {
    unsigned int fraction : 23;
    unsigned int exp : 8;
    unsigned int sign : 1;
  } p;
} float_converter;

int computeFP(float f) {
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
  float_converter fp;
  fp.f = f;
  printf("sign = %x\n",fp.p.sign);
  printf("exponent = %x\n",fp.p.exp);
  printf("mantisa = %x\n",fp.p.fraction);
  
  int e = fp.p.exp - 127;

  if (e > 14)
  {
    return -1;
  }

  if (e < 1)
  {
    return 0;
  }

  // new exponent is sub bias and we'll only take the lower
  // five bits.
  int new_exp = (e + 15) & 0x1F;
//  printf("E is: %d\n", e);
//  printf("newExp is: %d\n", new_exp);

//  printf("The fractional bits are %d\n", ((fp.p.fraction >> 16)));
  int retVal = 0;
  retVal |= new_exp;
  retVal <<= 7;
  retVal |= (fp.p.fraction >> 16);
  return retVal;
}


float getFP(int val) {
// Using the defined representation, compute the floating point
//    value
// For denormalized values (including 0), simply return 0.
// For special values, return -1;

  unsigned int fraction = val & 0x7F;
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

//  printf("-------\n");
//  printf("fraction is %d\n", fraction);
//  printf("exponent is %d\n", exponent);

  int e = exponent - 15;

  int i = 0;
  printf("e is %d\n", e);
  unsigned int wholeNumber = 1;
  while (i < e)
  {
    // extract the whole number
    wholeNumber <<= 1;
    wholeNumber |= (fraction >> (6 - i)) & 0x01;
    ++i;
  }
//  printf("Whole number %d\n", wholeNumber);

  // build the decimal portion
  // there are 7 minus e bits left in the mantissa to be the decimal portion
  unsigned int upperBound = 7 - e;
  unsigned int decimalNumber = 0;
  float f = 0;
  i = 0;
  while (i < upperBound)
  {
    int digit = ((fraction >> (upperBound - i - 1)) & 0x01);
//    printf("Digit is %d\n", digit);
    float val = digit * (float)(pow(2, -(i + 1)));
    f += val;
//    printf("f after digit %f\n", f);
    ++i;;
  }
  
  f += wholeNumber;
  return f;
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

  if (e3 > 14)
  {
    return -1;
  } 

  if (e3 < 1)
  {
    return 0;
  }
 
  float frac1 = ((float) (source1 & 0x7f));
  float frac2 = ((float) (source2 & 0x7f));

  frac1 = (frac1 / ((float)pow(2, 7))) + 1;
  frac2 = (frac2 / ((float)pow(2, 7))) + 1;

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

  printf("E1 minus E2 %d\n", e1 - e2);
  
  if (e1 != e2)
  {
    if (e1 - e2 > 0)
    {
      printf("****Shifting\n");
      frac2 = frac2 / (float)pow(2, e1 - e2);
    }
    else if (e1 - e2 < 0)
    {
      printf("****Shifting\n");
      frac2 = frac2 / (float)pow(2, e2 - e1);
    }
    // we normalize e2
    e2 = e2 + (e1 - e2);
  }

  printf("frac1: %f frac2 %f\n", frac1, frac2);
  float frac = frac2 + frac1;

  printf("frac %f\n", frac);
//  if (frac > 2)
//  {
//    frac /= 2;
//    ++e1;
//  printf("frac div  %f\n", frac);
//  }

  int new_exp = 15 + e1;
  printf("New exponent %d\n", new_exp);
  frac -= 1;
  printf("frac minus 1 %f\n", frac);
  frac *= (float)pow(2, 7);

  printf("frac times 2^7 %f\n", frac);
  int newFrac = (int) frac;

  printf("new frac %d\n", newFrac);
  int retVal = 0;
  retVal |= new_exp;
  retVal <<=  7;
  retVal |= newFrac; 
  return retVal;
}

int main()
{
  int a = computeFP(18.113);
  int b = computeFP(4.5);
  printf("%d\n", a);

  float g = getFP(a);
  float h = getFP(b);
  printf("First %f : second %f\n", g, h);

  int mult = multVals(a, b);
  
  float f = getFP(mult);
  printf("Multiplication %f\n", f);

  int add = addVals(a, b);
  float q = getFP(add);
  printf("Addition %d\n", add);
  printf("Addition %f\n", q);
}
