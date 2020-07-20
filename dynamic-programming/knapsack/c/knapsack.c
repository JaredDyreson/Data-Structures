#include <stdio.h>

#define LEN 9

int max(int a, int b) { return (a > b)? a : b; }

int knapsack(int W, int weights[], int values[], int size){
    int cache[size+1][W+1];
    for(int i = 0; i <= size; ++i){
        for(int j = 0; j <= W; ++j){
            // if there are zero candidates
            if(i == 0 || j == 0){
                cache[i][j] = 0;
            }

            // if it exceeds the max weight
            else if(weights[i-1] <= j){
                // since weights are just a range from start to finish, we can use them as indexers
                // weights are indexers and the values are placed in the N x M matrix
                // cache contains all these values
                cache[i][j] = max(values[i-1] + cache[i-1][j-weights[i-1]],
                                  cache[i-1][j]);
            }
            else{
                cache[i][j] = cache[i-1][j];
            }
            printf("%d ", cache[i][j]);
        }
        printf("\n");
    }
    /*for(int i = 0; i <= size; ++i){*/
        /*for(int j = 0; j <= W; ++j){*/
            /*printf("%d ", cache[i][j]);*/
        /*}*/
        /*printf("\n");*/
    /*}*/
    return cache[size][W];
}

int main(){
    // max profit will be the addition of the last two elements in sorted array
    // here the max weight to the max profit is 8 + 9 = 17
    int weights[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int values[] = {4, 5, 6, 7, 8, 9, 10, 11, 12};
    // therefore the max profit will be 32

    int result = knapsack(17, weights, values, LEN);
    printf("%d\n", result);
    return 0;
}
