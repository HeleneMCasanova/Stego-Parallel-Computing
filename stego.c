#include <stdio.h>
#include <string.h>
#include <stdlib.h>

<<<<<<< HEAD
typedef int bool;
#define true 1
#define false 0

extern int** imageToMat(char* name,int* dims);
extern void matToImage(char* name, int** mat, int* dims);
=======
extern int** imageToMat(char* name,int* dims);
extern void matToImage(char* name, int** mat, int* dims);

char *int2bin(int n);
int check(int x, int size);
>>>>>>> 2f77dd30a3ba1e58ac8cc15b7a0192b842748c15

char *int2bin(int n);
int check(int x, int size);
int **embedMessage(char **mBits, char **sBits, int **mat, int **holder, int width, int height);


int main(int argc, char** argv) {
    int **mat;
    int *dims=(int*) malloc(sizeof(*dims)*2);
<<<<<<< HEAD
    char *name="m.jpeg";
    mat = imageToMat(name,dims);
=======
    char *name="lenna.png";
    mat = imageToMat(name,dims);
	
>>>>>>> 2f77dd30a3ba1e58ac8cc15b7a0192b842748c15
    int width = dims[1];
    int height = dims[0];


    int **holder;
    holder = imageToMat(name,dims);

<<<<<<< HEAD
    char secret[] = "message";
    char **sBits = (char**) malloc(sizeof(secret)*sizeof(secret));
    for(int i = 0; i < sizeof(secret); i++) {
	char *s = int2bin(secret[i]);
        sBits[i] = s;
    }

    char message[] = "hello this is a test";
    char **mBits = (char**) malloc(sizeof(message)*sizeof(message));
    for(int i = 0; i < sizeof(message); i++) {
	char *s = int2bin(message[i]);
	mBits[i] = s;
    }

   holder = embedMessage(mBits, sBits, mat, holder, width, height);
   matToImage("m_out.jpeg", holder, dims);
   return 0;
}


int **embedMessage(char **mBits, char **sBits, int **mat, int **holder, int width, int height) {
    int size = sizeof(mBits);
    int bitX = 0; //largest we want is sizeof(mBits[bitY])
    int bitY = 0; //largest we want is sizeof(mBits)
    
    bool done = true;

    for(int i=0 ;i<height; i++) {
        for(int j=0; j<width; j++) {
		for(int k = 0; k < 3; k++) {
			if(done) {
				bitX = check(bitX, sizeof(mBits[bitY]));
                                printf("BitX: %d, BitY: %d \n", bitX, bitY);
                                int num = mat[i*width+j][k];
                                int lsb = num & 1;

				if((lsb == 1) && (sBits[bitY][bitX] == 48)) {
                                        printf("if\n");
                                        holder[i*width+j][k] -= 1;
                                }
                                else if((lsb == 0) && (sBits[bitY][bitX] == 49)) {
                                        printf("elseif\n");
                                        holder[i*width+j][k] += 1;
                                }

                                bitX++;
                                if(bitX == sizeof(mBits[bitY])) {
                                        done = false;
					bitX=0;bitY=0;
					printf("\n");
				}
			}
			else if(bitY != size) {
=======
//    char secret[] = "message";
//    char *sBits = int2bin(secret);

    unsigned char message[] = "hello this is a test";
    unsigned char **mBits = (unsigned char**) malloc(sizeof(message)*sizeof(message));
    for(int i = 0; i < sizeof(message); i++) {
	unsigned char *s = int2bin(message[i]);
	//printf("%s\n", s);
	mBits[i] = s;
    }

    int size = sizeof(message);
    int bitX = 0; //largest we want is sizeof(mBits[bitY])
    int bitY = 0; //largest we want is sizeof(mBits)

    for(int i=0 ;i<height; i++){
        for(int j=0; j<width; j++){
		for(int k = 0; k < 3; k++){
			if(bitY != size) {
>>>>>>> 2f77dd30a3ba1e58ac8cc15b7a0192b842748c15
				bitX = check(bitX, sizeof(mBits[bitY]));
				printf("BitX: %d, BitY: %d \n", bitX, bitY);
				int num = mat[i*width+j][k];
				int lsb = num & 1;
<<<<<<< HEAD

=======
			
				//printf("%d \n", mBits[bitY][bitX]);
>>>>>>> 2f77dd30a3ba1e58ac8cc15b7a0192b842748c15
				if((lsb == 1) && (mBits[bitY][bitX] == 48)) {
					printf("if\n");
					holder[i*width+j][k] -= 1;
				}
				else if((lsb == 0) && (mBits[bitY][bitX] == 49)) {
					printf("elseif\n");
					holder[i*width+j][k] += 1;
				}
<<<<<<< HEAD

				bitX++;
=======
				bitX++;
			
>>>>>>> 2f77dd30a3ba1e58ac8cc15b7a0192b842748c15
				if(bitX == sizeof(mBits[bitY])) {
					printf("\n");bitY++;}
			}

		}
	   }
	}
<<<<<<< HEAD
//    	matToImage("lenna_out.png", holder, dims);

    return holder;
=======
    	matToImage("lenna_out.png", holder	, dims);

    return 0;
>>>>>>> 2f77dd30a3ba1e58ac8cc15b7a0192b842748c15
}

int check(int x, int size) {
	if(x == size) return 0;
	return x;
}

char *int2bin(int n) {
    
    int nbits = sizeof(n) * 2;
    char *s = malloc(nbits+1);  
    s[nbits] = '\0';
  
    unsigned int u = *(unsigned int*)&n;
    int i;
    unsigned int mask = 1 << (nbits-1); 
    for (i = 0; i < nbits; i++, mask >>= 1)
        s[i] = ((u & mask) != 0) + '0';
    return s;
}
