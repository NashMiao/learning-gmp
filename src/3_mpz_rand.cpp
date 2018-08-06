#include<stdio.h>
#include<gmp.h>
#include<boost/random/random_device.hpp>

int main( int argc, char *argv[]){

    unsigned min_digits = 30;
    unsigned max_digits = 50;
    unsigned quantity = 1000;   // How many numbers do you want?
    unsigned sequence = 10;     // How many numbers before reseeding?

    mpz_t rmin;
    mpz_init(rmin);
    mpz_ui_pow_ui(rmin, 10, min_digits-1);

    mpz_t rmax;
    mpz_init(rmax);
    mpz_ui_pow_ui(rmax, 10, max_digits);

    gmp_randstate_t rstate;
    gmp_randinit_mt(rstate);

    mpz_t rnum;
    mpz_init(rnum);

    boost::random::random_device rdev;

    for( unsigned i = 0; i < quantity; i++){

        if(!(i % sequence)) 
            gmp_randseed_ui(rstate, rdev.operator ()());

        do{
            mpz_urandomm(rnum, rstate, rmax);
        }while(mpz_cmp(rnum, rmin) < 0);

        gmp_printf("%Zd\n", rnum);
    }

    return 0;
}