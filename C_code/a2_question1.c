#include <stdio.h>
// haoran miao
//301541289
//hma98@sfu.ca
unsigned int insert_digit_recursive(unsigned int digit, unsigned int number) {
    if( number == 0) {
       return digit;//return the first digit
    }else{
      return (number%10)*10+digit + insert_digit_recursive(digit,number/10)*100;//layer the number from bottom to top, by times 100
    }
    
}
