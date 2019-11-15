#include <iostream>
using namespace std;

/**
 * The algorithm asks for input of a natural number n,
 * then it calculates smallest natural number m that
 * is bigger or equal to n and that is also a power of
 * some natural number m (that is m = k ^ l), where
 * k and l are natural numbers bigger or equal to 2 
*/

int main() {

    int n, m, base, exponent;

    /**
     * base = k
     * exponent = l
    */

    do {
        cout << "Enter a natural number: ";
        cin >> n;
    } while (n <= 0);

    /**
     * For loop starts at an assumtption that m is equal to n
     * then it increments m until it is proven that it
     * can be represented as power of two natural numbers
    */
    bool mFound = false;
    for (m = n; !mFound; m++) {
        
        /**
         * the potential base k starts from 2 and then it
         * increments until as long as it cant represent m
        */
        for (base = 2; base <= sqrt(m); base++) {
            
            int potentialM = base * base;
            /**
             * exponent is initialised to 2 
             * because of the previous operation
            */
            exponent = 2; 

            while(potentialM < m) {
                potentialM *= base;
                exponent++;
            }

            if (potentialM == m) {
                mFound = true;
                break;
            }
        }
    }

    cout << base << "^" << exponent << "=" << m-1 << endl;

    return 0;
}