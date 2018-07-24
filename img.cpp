#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/core/core.hpp"
//#include "opencv2/video/video.hpp"
//#include "opencv2/imgcodecs/imgcodecs.hpp"

using namespace cv;
using namespace std;

extern "C" int** imageToMat(char* filename,int* dims){
    Mat image;
    image=imread(filename,CV_LOAD_IMAGE_COLOR);

    //Mat gray_image;
    //cvtColor(image,gray_image,CV_BGR2GRAY);

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        int** temp;
        return temp;
    }

    int width=image.size().width;
    int height=image.size().height;
    dims[0]=height;
    dims[1]=width;

    cout << "Height: " << dims[0] << endl;
    cout << "Width : " << dims[1] << endl;
    //namedWindow( "Original Image", WINDOW_AUTOSIZE );// Create a window for display.
    //imshow( "Original Image", gray_image );                   // Show our image inside it.
 
 
    //allocate 2d array
    int** matrix;
    matrix=(int**) malloc(height*width*sizeof(*matrix));
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
	    int* imagemat = (int*)malloc(3);

            Vec3b intensity=image.at<Vec3b>(i,j);
	    if(intensity.val[0] > 255 || intensity.val[1] > 255 || intensity.val[2] > 255) {
			imagemat[0] = 255;
            		imagemat[1] = 255;
            		imagemat[2] = 255;
	    }
	    else if(intensity.val[0] < 0 || intensity.val[1] < 0 || intensity.val[2] < 0) {
			imagemat[0] = 0;
                        imagemat[1] = 0;
                        imagemat[2] = 0;
	    }
	    else {
	    		imagemat[0] = intensity.val[0];
	    		imagemat[1] = intensity.val[1];
	    		imagemat[2] = intensity.val[2];	
		}
            matrix[i*width+j]=imagemat;
//	    cout << imagemat[0]  << ", " << imagemat[3]  << ", " << imagemat[2]  << "\n" << endl;
        }
    }

    return matrix;
}


extern "C" void matToImage(char* filename, int** mat, int* dims){
    int height=dims[0];
    int width=dims[1];
    Mat image(height, width, CV_8UC3, Scalar(0,0,0));

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
		Vec3b imagemat;
		imagemat[0] = mat[i*width+j][0];
		imagemat[1] = mat[i*width+j][1];
		imagemat[2] = mat[i*width+j][2];
		//cout << mat[i*width+j][0] << "\n" << mat[i*width+j][1] << "\n" << mat[i*width+j][2] << "\n" << endl;
		//cout << imagemat.val[0]  << ", " << imagemat.val[1]  << ", " << imagemat.val[2]  << "\n" << endl;
		image.at<Vec3b>(i,j) = imagemat;
        }
    } 
    //namedWindow( "Processed Image", WINDOW_AUTOSIZE );// Create a window for display.

    //imshow( "Processed Image", image );                   // Show our image inside it.
    imwrite(filename,image);
    //waitKey(0);                                          // Wait for a keystroke in the window
    return;
}
