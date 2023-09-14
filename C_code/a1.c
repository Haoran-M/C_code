#ifndef A1_Q1_H
#define A1_Q1_H

//haoran miao 
// hma98@sfu.ca
// sfu id = 301542189

unsigned int insert_digit(unsigned int digit, unsigned int number) {
    unsigned int result = digit;
    unsigned int k = 1;
    unsigned int i = 0;
    unsigned int num = number;
    while( num > 0) {
        unsigned int numl = num %10;//getting the last digit of number
        k = k*10;
        result += numl * k;// add it to result, and increase by power of 10 for each place
        i += 1;
        k *= 10;
        result += digit * k;// the new num has it's last digit removed
        num = num / 10;

    }
    return result;

    
}


#endif