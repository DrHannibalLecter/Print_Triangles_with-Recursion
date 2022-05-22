#include <stdio.h>
#include <math.h>

// Ardacan Özener 150120026
void binary(int row);
int f();
void printrow(int row, int a[]);
double pow(double x, double y);

//This variable determines map's size
//If it becomes 10 or more, programme cannot show right answer(I do not know why)
const int N = 5;
//This array is needed for row's binary value
char bin[4];
//This variable is height of the smallest triangle
int height;
//We take its value from user
int iteration=-1;

int x;
int y;
int gap;





//int to binary method
void binary(int row){
    //Reset the array
    for (int i = 0; i<(N-1);i++){
        bin[i]='0';
    }
    //int to binary
    for (int i = 0;row>0;i++){
        bin[i]=(row%2)+'0';
        row/=2;
    }
}

//Finds log(2,gap number+1) using binary value
int f(){
    int da=0;
    for (int i = 0; i < iteration ; i++){
        if (bin[i]=='1'){
            da++;
        }
    }
    return da;
}

//Searches gap width with given parameter
void search(int index, int num, int a[], int gap){
    if(bin[num-1]=='1'){
        a[index]=pow(2,num-1)*height;
            if((index%2==1)||(gap>2)) {
                search(index - pow(2, gap - 2), num - 1, a, gap - 1);
                search(index + pow(2, gap - 2), num - 1, a, gap - 1);
            }
    }
    else{
        search(index,num-1, a,gap);
    }
}



//Calculates and prints given row
void printrow(int row, int a[]) {
    int i = 0;
    int p;
    int temp;
    int u = 0;
    int numb = (2 * (row % height)) + 1;
    while ( i < ((x - 1) / 2 - row)) {
        printf("_");
        i++;
    }
    //This value switches output (1 or _)
    int count = 1;
    while (i < x) {
        if (count == 1) {
            for (int j = 0; j < numb; j++) {
                printf("1");
            }
            i += numb  ;
            count = 0;
        }
        else {
            if (u < (pow(2,gap)-1)) {
                p=a[u];
                //printf("%d",p);
                temp=2*(p-(row%p))-1;
                for (int k = 0;k<temp;k++){
                    printf("_");
                }
                u++;
                count=1;
                i+=temp;
            }
            else{
                printf("_");
                i++;
            }
        }
    }
    printf("\n");
}


int main() {
    //Takes valid iteration value
    while((iteration > N) || (iteration < 0)) {
        printf("a number between 0-%d",N);
        scanf("%d", &iteration);
    }
    //Calculates width and height of area that surrounds triangles
    y = pow(2,N);
    x = pow(2,N+1)-1;
    //Height of the smallest triangle
    height=pow(2, N - iteration);
    gap=0;
    int gap_array[(int)pow(2, iteration) - 1];


    for (int i=0;i<y;i++){
        if (i%height==0 && i!=0){

            binary(i/height);
            gap = f();
            search(pow(2,gap-1)-1, iteration, gap_array, gap);
        }
        printrow(i, gap_array);
    }
    return 0;
}


