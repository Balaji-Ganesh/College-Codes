/*
    steps: 183.82.46.36
    kmit
    udaan@123$
    cd ngit_demo
    cd KMIT_20BD5a0502
    Open editor and write the code...
*/

// Addition of vectors..
// CASE-1: n blocks and one thread..
#include <stdio.h>
#define N 10

__global__ void addVectors(int *a, int *b, int *c){
    for(int tid=0; tid<N; tid++)
        c[tid] = a[tid] + b[tid];
}

int main(){
    // Declare the arrays.. and fill with the default values..
    int a[N] = {}, b[N] = {}, c[N] = {};
    int *dev_a, *dev_b, *dev_c;

    // allocate memory on device..
    cudaMalloc((void**) &dev_a, N*sizeof(int));
    cudaMalloc((void**) &dev_b, N*sizeof(int));
    cudaMalloc((void**) &dev_c, N*sizeof(int));

    // Fill with some values..
    for(int i=0; i<N; i++){
        a[i] = i;
        b[i] = N-i;
    }

    // copy the arrays to the device..
    cudaMemcpy(dev_a, a, N*sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(dev_b, b, N*sizeof(int), cudaMemcpyHostToDevice);

    // launch the kernel
    addVectors<<<1, 1>>>(dev_a, dev_b, dev_c);

    // copy the results back..
    cudaMemcpy(c, dev_c, N*sizeof(int), cudaMemcpyDeviceToHost);

    // printing the results..
    for(int i=0; i<N; i++)
        printf("%d + %d = %d\n", a[i], b[i], c[i]);
}
