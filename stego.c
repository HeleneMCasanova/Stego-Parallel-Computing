#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <omp.h>



typedef int bool;
#define true 1
#define false 0

extern int** imageToMat(char* name,int* dims);
extern void matToImage(char* name, int** mat, int* dims);


char *int2bin(int n);
int check(int x, int size);
int **embedMessage(char **mBits, char **sBits, int **mat, int **holder, int width, int height, int size);
int **extractMessege(char **mBits, char **sBits, int **holder, int width, int height, int size);

int main(int argc, char argv[]) {
    int **mat;
    int *dims=(int*) malloc(sizeof(*dims)*2);
    char *name="m.jpeg";
    mat = imageToMat(name,dims);
    int width = dims[1];
    int height = dims[0];


    int **holder;
    holder = imageToMat(name,dims);
   

    char secret[] = "message";
    char **sBits = (char**) malloc(sizeof(secret)*sizeof(secret));
    for(int i = 0; i < sizeof(secret); i++) { 
	char *s = int2bin(secret[i]);
        sBits[i] = s;
    }

    //char *message = getMessege();
    char message[] ="Lorem ipsum dolor sit amet, consectetur adipiscing elit. Morbi varius lectus turpis, non suscipit lacus dictum at. Morbi id lorem ac metus blandit pretium. Cras eleifend ultricies elit, vitae elementum lectus varius vitae. Aenean ut diam feugiat, ornare ipsum quis, placerat sapien. Sed ac ipsum justo. Ut dignissim ipsum magna, id dignissim nibh pellentesque eu. Sed egestas neque in enim tincidunt, eget sodales nisi convallis. Pellentesque viverra ultricies nibh, id aliquet ante tincidunt eu. Morbi sed ullamcorper nisi, ac semper erat. Fusce accumsan id tellus in commodo. Maecenas tempus, arcu ac iaculis rhoncus, neque felis iaculis mauris, id suscipit mauris sapien sit amet leo. Nulla nibh tortor, vulputate non purus at, vestibulum pellentesque odio. In laoreet est magna, vel congue dolor egestas ut. Fusce euismod placerat metus, eget iaculis nisi consequat id. Curabitur pharetra orci lectus, nec egestas tellus vestibulum eget. Vivamus rutrum placerat velit sed rhoncus. Aliquam cursus nisi id velit feugiat, non convallis nisl tincidunt. Curabitur tincidunt justo lectus, in ullamcorper ante eleifend id. Integer quis hendrerit ipsum. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Etiam arcu libero, pretium sed accumsan non, ultrices at urna. Proin eleifend justo porta lacus consectetur commodo nec non enim. Aliquam non efficitur elit. Mauris ac nisl porttitor, gravida nisl vitae, aliquet quam. Quisque ornare urna sed tortor tempor posuere vel vitae odio. Nulla vel ornare velit, eu commodo lacus. Integer ut tempor nibh, volutpat elementum nisi. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Sed suscipit ornare metus. Maecenas gravida, sem id iaculis gravida, sem quam pulvinar odio, vel mollis tellus risus ut eros. Maecenas purus lorem, pulvinar at purus at, suscipit sagittis sem. Proin convallis sem ac dolor sagittis tristique. Phasellus feugiat scelerisque quam, et sagittis lectus congue sed. Duis ultrices tincidunt arcu non laoreet. Aenean varius placerat lacinia. Cras facilisis a diam eu consectetur. Donec euismod magna in turpis hendrerit dignissim. Phasellus efficitur massa sed varius porta. Maecenas aliquet sodales quam, in auctor libero hendrerit non. Maecenas enim justo, suscipit vel dolor elementum, laoreet sodales dui. Suspendisse in rutrum metus. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Morbi et risus eu velit tempus vehicula et et libero. Donec finibus magna ac feugiat dignissim. Maecenas eget mollis leo. Etiam eu vehicula tellus. Donec ac tortor tristique, pellentesque sem vitae, pretium est. Quisque efficitur lectus in fringilla elementum. Praesent vel elit enim. Cras elementum sapien dolor, at pretium nibh porttitor eget. Duis arcu sapien, bibendum sit amet orci a, tempus facilisis mauris. Morbi dapibus rutrum orci, eget tincidunt lorem. Vestibulum consequat interdum nunc, a facilisis arcu blandit et. Pellentesque condimentum sit amet nisl eu scelerisque. Morbi justo lacus, semper ultrices tempus et, consequat a augue. Praesent arcu lorem, vehicula posuere bibendum vitae, fringilla eget nisl. Aenean nec metus dui. Nulla quis velit felis. Proin tincidunt fringilla tincidunt. Proin in urna sit amet libero ullamcorper tincidunt. Aliquam ipsum orci, facilisis sed viverra et, consequat ac lorem. Fusce interdum eros quis dui eleifend hendrerit. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Sed nec pretium purus, et commodo libero. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Morbi sodales faucibus tortor ac facilisis. Integer et efficitur urna, in finibus odio. In id varius nisl, sed pretium dolor. Aenean luctus rhoncus ex sed laoreet. Nunc tempus dolor hendrerit nunc ullamcorper, eu tincidunt justo iaculis. Aliquam erat urna, elementum vel nisl ac, gravida fermentum diam. Vivamus finibus vulputate ligula venenatis rhoncus. Nulla ultrices odio sit amet sem molestie, nec mollis orci accumsan. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Integer vitae facilisis ex. Fusce pharetra porttitor cursus. Nam a massa sapien. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Integer finibus libero sit amet luctus elementum. Donec posuere et eros ut accumsan. In hac habitasse platea dictumst. Aenean mollis vitae elit at egestas. Aliquam eget magna pharetra, gravida nunc id, tempus erat. Nam fermentum volutpat justo, non tempus erat mollis sed. Donec et aliquet lacus, eget pretium lorem. Nulla facilisi. Sed auctor massa ac nunc luctus, ac auctor neque rhoncus. Nulla in turpis mi. Fusce vitae mattis lorem, et mollis quam. Integer sollicitudin suscipit lacus, id mattis erat placerat vel. Aliquam tempus viverra ipsum volutpat rhoncus. Donec felis dui, mollis ac maximus non, egestas et mauris. Proin consectetur mi orci, vel vulputate mauris ornare ac. Vestibulum vitae nibh et nisl egestas convallis id eu enim. Mauris lorem tortor, faucibus sed diam et, sollicitudin efficitur erat. Integer molestie enim tristique neque lobortis, at tempor risus mattis. Proin eget varius neque. Aenean tristique urna et interdum sagittis. Nulla laoreet, turpis ut consequat egestas, justo neque suscipit ipsum, et posuere odio urna a mi. Maecenas efficitur ex quis elit molestie, et ornare odio accumsan. Nam maximus sit amet nulla ut facilisis. Mauris nec felis massa. Phasellus eget lorem quis tellus tristique dignissim. Fusce a nisl pretium ante tempor gravida. Cras molestie tortor et felis imperdiet dignissim at id arcu. Nulla fermentum finibus magna, nec tempus lectus varius eu. Vestibulum ut ultrices dui. Nunc at laoreet ex, id hendrerit tortor. Nullam congue augue massa, id dapibus ante faucibus sit amet. Quisque ullamcorper fringilla ligula, vel ultricies elit semper quis. Nunc suscipit purus ipsum, vitae venenatis augue luctus eu. Integer dignissim rhoncus mi vitae sagittis. Sed eget tortor lectus. Quisque vehicula risus et neque varius, a tempus metus rhoncus. Nunc interdum interdum est, quis commodo justo vehicula tincidunt. Quisque vel enim non nisi pretium dapibus. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Nulla facilisi. Sed venenatis, leo et commodo ultrices, dolor mi congue tellus, vitae vestibulum sapien arcu id nunc. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Cras ullamcorper nisl sed augue ullamcorper vulputate. Aliquam bibendum mattis lacus, ultrices ultrices tortor venenatis a. Quisque a volutpat metus. Aenean molestie augue neque, vitae dictum massa varius vitae. Quisque vel eros sed felis vulputate commodo in in odio. Vestibulum auctor elit tellus, ut ultricies libero malesuada sed. Duis tristique turpis a quam tincidunt hendrerit. Quisque vitae fermentum massa. Sed arcu erat, cursus nec vestibulum nec, viverra eu augue. Praesent mi purus, auctor et cursus nec, porttitor non neque. Sed cursus nisl quis lacus eleifend, quis suscipit tellus sodales. Pellentesque ac odio vitae nunc facilisis iaculis at ac arcu. Nulla id leo eu ipsum posuere pulvinar. Sed bibendum metus ac consequat vulputate. Fusce accumsan dolor sit amet lorem porta, nec imperdiet tellus pretium. Phasellus eu vestibulum elit. Curabitur ultrices, odio a volutpat vestibulum, risus elit fermentum lorem, non pretium dolor nunc id nibh. Aliquam quis nisi tellus. Suspendisse ut libero augue. Pellentesque a mattis quam. Pellentesque interdum massa ut sapien malesuada molestie. Ut eu ligula tellus. Sed blandit massa sit amet diam ultrices tristique. Cras pellentesque pulvinar velit, in fermentum magna placerat sit amet. Phasellus dictum tortor turpis, ac imperdiet est mattis at. Praesent volutpat convallis ex in viverra. Nam rhoncus a sem at aliquam. Interdum et malesuada fames ac ante ipsum primis in faucibus. Vivamus sed aliquet elit. Pellentesque nec quam pellentesque, congue sapien sit amet, dictum arcu. Integer aliquam sodales sodales. Ut imperdiet egestas viverra. Maecenas hendrerit faucibus lectus sed tincidunt. Nulla blandit ultricies vulputate. Suspendisse auctor hendrerit mauris, vestibulum pharetra ligula porta a. Sed sed pellentesque elit. Maecenas faucibus dui nec suscipit fringilla. Nunc id nunc at mauris tempus maximus. Ut vel nibh tincidunt, lobortis erat ac, hendrerit nisl. Morbi in ullamcorper nisl. Sed quam sem, viverra sit amet tincidunt nec, aliquam et massa. Pellentesque vel purus at purus pretium gravida. Curabitur ut tortor vel nulla viverra pharetra. Nulla facilisi. Nunc nunc justo, porta consequat erat non, molestie luctus felis. Vivamus vestibulum sapien non odio sagittis, eget blandit dui finibus. Proin sodales justo ac massa vehicula, dapibus cursus nisi rhoncus. Nulla varius pulvinar arcu ut vehicula. Phasellus fringilla pellentesque pharetra. Nullam pharetra aliquam egestas. Duis sit amet molestie augue. Suspendisse maximus, lacus sed vulputate faucibus, dui metus porta sem, in placerat odio lorem non mi. Nulla vel ullamcorper risus. Suspendisse potenti. Vestibulum sed sapien sed odio iaculis eleifend. Aenean aliquet metus sed sapien lacinia, at ultrices magna consectetur. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec quam enim, facilisis eleifend lacus et, lobortis tristique erat. In sollicitudin, enim et faucibus ullamcorper, nisi neque semper mi, sed pharetra turpis est ac sem. Aenean ac nisi posuere, luctus diam semper, pharetra lorem. In eget volutpat turpis. Fusce ultricies dui sit amet tincidunt tristique. Proin risus augue, consequat at libero ut, dapibus varius est. Aenean laoreet aliquam augue et varius. Aliquam at placerat mauris. Mauris at fringilla sem. Nunc eu nunc faucibus nunc fermentum ultricies. Nam interdum purus id aliquam faucibus. Ut eu magna augue. Aenean dapibus dui in ligula consequat laoreet. Proin non amet. aliquam et massa. Pellentesque vel purus at purus pretium gravida. Curabitur ut tortor vel nulla viverra pharetra. Nulla facilisi. Nunc nuncjusto, porta consequat erat non, molestie luctus felis. Vivamus vestibulum sapien non odio sagittis, eget blandit dui finibus. Proin sodales justo ac massa vehicula, dapibus cursus nisi rhoncus. Nulla varius pulvinar arcu ut vehicula. Phasellus fringilla pellentesque pharetra. Nullam pharetra aliquam egestas. Duis sit amet molestie augue. Suspendisse maximus, lacus sed vulputate faucibus, dui metus porta sem, in placerat odio lorem non mi. Nulla vel ullamcorper risus. Suspendisse potenti. Vestibulum sed sapien sed odio iaculis eleifend. Aenean aliquet metus sed sapien lacinia, at ultrices magna consectetur. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec quam enim, facilisis eleifend lacus et, lobortis tristique erat. In sollicitudin, enim et faucibus ullamcorper, nisi neque semper mi, sed pharetra turpis est ac sem. Aenean ac nisi posuere, luctus diam semper, pharetra lorem. In eget volutpat turpis. Fusce ultricies dui sit amet tincidunt tristique. Proin risus augue, consequat at libero ut, dapibus varius est. Aenean laoreet aliquam augue et varius. Aliquam atplacerat mauris. Mauris at fringilla sem. Nunc eu nunc faucibus nunc fermentum ultricies. Nam interdum purus id aliquam faucibus. Ut eu magna augue. Aeneandapibus dui in ligula consequat laoreet. Proin non amet. rper, nisi neque semper mi, sed pharetra turpis est ac sem. Aenean ac nisi posuere, luctus diam semper, pharetra lorem. In eget volutpat turpis. Fusce ultri cies dui sit amet tincidunt tristique. Proin risus augue, consequat at libero ut, dapibus varius est. Aenean laoreet aliquam augue et varius. Aliquam at pla cerat mauris. Mauris at fringilla sem. Nunc eu nunc faucibus nunc fermentum ultricies. Nam interdum purus id aliquam faucibus. Ut eu magna augue. Aenean dapibus dui in ligula consequat laoreet. Proin non amet. aliquam et massa. Pellentesque vel purus at purus pretium gravida. Curabitur ut tortor vel nulla viverra pharetra. Nulla facilisi. Nunc nuncjusto, porta consequat erat non, molestie luctus felis. Vivamus vestibulum sapien non odio sagittis, eget blandit dui finibus. Proin sodales justo ac massa vehicula, dapibus cursus nisi rhoncus. Nulla varius pulvinar arcu ut vehicula. Phasellus fringilla pellentesque pharet ra. Nullam pharetra aliquam egestas. Duis sit amet molestie augue. Suspendisse maximus, lacus sed vulputate faucibus, dui metus porta sem, in placerat odio lorem non mi. Nulla vel ullamcorper risus. Suspendisse potenti. Vestibulum sed sapien sed odio iaculis eleifend. Aenean aliquet metus sed sapien lacinia, at ultrices magna consectetur. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec quam enim, facilisis eleifend lacus et, lobortis tristique erat. In sollicitudin, enim et faucibus ullamcorper, nisi neque semper mi, sed pharetra turpis est ac sem. Aenean ac nisi posuere, luctus diam semper, pharetra lorem. In eget volutpat turpis. Fusce ultricies dui sit amet tincidunt tristique. Proin risus augue, consequat at libero ut, dapibus varius est. Aenean laoreet aliquam augue et varius. Aliquam atplacerat mauris. Mauris at fringilla sem. Nunc eu nunc faucibus nunc fermentum ultricies. Nam interdum purus id aliquam faucibus. Ut eu magna augue. Aeneandapibus dui in ligula consequat laoreet. Proin non amet.";
    //char message[] = "This is a small message";
	
    char **mBits = (char**) malloc(sizeof(message)*sizeof(mBits));
	int size = 0;
    for(int i = 0; i < sizeof(message); i++) {
		char *s = int2bin(message[i]);
		mBits[i] = s;
		size++;
    }   
	printf("%d\n", size);
	double start = omp_get_wtime();
   holder = embedMessage(mBits, sBits, mat, holder, width, height, size);
	double end = omp_get_wtime();
	printf("%f", end-start);
   matToImage("m_out.jpg", holder, dims);
   //extractMessege(mBits, sBits, holder, width, height, size);

   return 0;
}

int **extractMessege(char **mBits, char **sBits, int **holder, int width, int height, int size) {
   
    

    int bitX = 0;
    int bitY = 0; 

    bool done = true;
    int i, j, k;

//    #pragma omp parallel for private(i, j, k)
    for(i=0;i<height; i++) {
        for(j=0; j<width; j++) {
		for(k = 0; k < 3; k++) {
			if(done) {
				bitX = check(bitX, sizeof(sBits[bitY]));
                                //printf("BitX: %d, BitY: %d \n", bitX, bitY);
                                int num = holder[i*width+j][k];
                                int lsb = num & 1;

		//		printf("%d", lsb);
				bitX++;
				if(bitX > 7) {
					bitY++;
		//			printf("\n");
				}
				
				
                                if(bitY >= sizeof(sBits)) {
                                        done = false;
					bitX=0;bitY=0;
		//			printf("\n");
				}
			}
			else if(bitY != size) {
				bitX = check(bitX, sizeof(mBits[bitY]));
				
				int num = holder[i*width+j][k];
				int lsb = num & 1;

		//		printf("%d", lsb);

				bitX++;
				if(bitX > 7){ 
		//			printf("\n");
					bitY++;
				}
			}

		}
	   }
	
	}
	
	return holder;
}


int **embedMessage(char **mBits, char **sBits, int **mat, int **holder, int width, int height, int size) {
  
    //int bitX = 0; //largest we want is sizeof(mBits[bitY])
    //int bitY = 0; 

    bool done = true;
    int i, j, k;

    #pragma omp parallel 
    {
    int bitX = 0;
    int bitY = 0; 
    #pragma omp for schedule(dynamic) private(i, j, k)
    for(i=0;i<height; i++) {
        for(j=0; j<width; j++) {
		for(k = 0; k < 3; k++) {
			
			if(done) {
				bitX = check(bitX, sizeof(sBits[bitY]));
                                //printf("%lu", sizeof(sBits));
                                
				int num = mat[i*width+j][k];
                                int lsb = num & 1;
				
				if((lsb == 1) && (sBits[bitY][bitX] == 48)) {
                                        //printf("if\n");
                                        holder[i*width+j][k] -= 1;
                                }
                                else if((lsb == 0) && (sBits[bitY][bitX] == 49)) {
                                        //printf("elseif\n");
                                        holder[i*width+j][k] += 1;
                                }

                                bitX++;
				if(bitX >= sizeof(sBits[bitY])) {
					bitY++;
				}
                                if(bitY == sizeof(sBits)) {
                                        done = false;
					bitX=0;bitY=0;
					printf("\n");
				}
				
			}
			
			else if(bitY < size) {
				bitX = check(bitX, sizeof(mBits[bitY]));
				//printf("BitX: %d, BitY: %d \n", bitX, bitY);
			
				int num = mat[i*width+j][k];
				int lsb = num & 1;
				
				if((lsb == 1) && (mBits[bitY][bitX] == 48)) {
				//	printf("if\n");
					holder[i*width+j][k] -= 1;
				}
				else if((lsb == 0) && (mBits[bitY][bitX] == 49)) {
				//	printf("elseif\n");
					
					holder[i*width+j][k] += 1;
				}

				bitX++;

				if(bitX >= sizeof(mBits[bitY])) {
					bitY++;				
				}
			
			}

		}
	   }
	}

}
    //matToImage("lenna_out.png", holder, dims);

    return holder;
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


