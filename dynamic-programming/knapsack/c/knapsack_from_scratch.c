#include <stdio.h>
#define LEN 3

// NOTE: since there is no good way to tell how long an array is in C, we define the constant here

// REQUIREMENTS
// list of values (int[])
// list of weights (int[])
// maxium weight capacity for knapsack (int)
//
// WE WANT
// the maximum profit by fitting the most amount in the sack for the most amount of profit (int)

int max(int a, int b){ return (a > b) ? a : b; }

int knapsack(int W, int values[], int weights[], int size){
    // W <- Max weight
    // values <- possible values that each item can be (used as indexers)
    // weights <- the weight of each object (used to decrement the overall capacity counter)
    // size <- the amount of elements in the two arrays (used for the "y" axis in the M x N cache matrix)

    // create a cache to increase efficiency
    int cache[size+1][W+1];
    
    for(int i = 0; i <= size; ++i){
        for(int j = 0; j <= W;  ++j){
            // if there are 0 items
            if(i == 0 || j == 0){
                cache[i][j] = 0;
            }
            // if the weight index is leq than the inner index, do a comparision
            else if(weights[i-1] <= j){
                cache[i][j] = max(
                    // current value plus the furthermost index
                    values[i-1] + cache[i-1][j-weights[i-1]],
                    // previous index
                    cache[i-1][j]
                );
                // put the biggest one in the cache
            }
            else{
                // place it in the cache if there are no problems
                cache[i][j] = cache[i-1][j];
            }
            printf("%d ", cache[i][j]);
        }
        printf("\n");
    }
    return cache[size][W];
}


int main(int argc, const char* argv[]){
    // indexers
    int values[] = {4, 5, 6};
    // these values will be seen in the cache matrix 
    int weights[] = {1, 2, 3};

    int max_weight = 5;


    int m = knapsack(max_weight, values, weights, LEN);

    // visualization

    /*0  0  0  0  0  0 */
    /*0  4  4  4  4  4 */
    /*0  4  5  9  9  9 */
    /*0  4  5  9  10 11 */

    printf("%d\n", m);
    return 0;
}
