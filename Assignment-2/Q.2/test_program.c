/*Tony Thomas -2021360- CSD*/

#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

#define SYS_kernel_2d_memcpy 448

int main(int argc, const char** argv) {

    float test_matrix[2][3]={{7.89, 3.89, 8.89},{4.567, 7.8, 9.0}};
    float copy_matrix[2][3];

    long ret =syscall(SYS_kernel_2d_memcpy, test_matrix, copy_matrix, 2,3);
    printf("Sys call return value :%ld\n",ret);
    printf("Copied Matrix : \n");
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++){
            printf("%d",copy_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
