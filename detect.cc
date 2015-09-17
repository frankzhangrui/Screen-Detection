/**
 * @file objectDetection2.cpp
 * @author A. Huaman ( based in the classic facedetect.cpp in samples/c )
 * @brief A simplified version of facedetect.cpp, show how to load a cascade classifier and how to find objects (Face + eyes) in a video stream - Using LBP here
 */
 #include "opencv2/objdetect/objdetect.hpp"
 #include "opencv2/highgui/highgui.hpp"
 #include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

/** Function Headers */
void detectAndDisplay( Mat frame , CascadeClassifier& face_cascade );

int main( void )
{
    Mat frame = imread("/Users/ruizhang/desktop/screen_detection/1.jpg");
    //-- 1. Load the cascade
    String face_cascade_name = "/Users/ruizhang/desktop/screen_detection/data/cascade.xml";
    CascadeClassifier face_cascade;
    if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading face cascade\n"); return -1; };
    detectAndDisplay(frame,face_cascade);
    return 0;
}

/**
 * @function detectAndDisplay
 */
void detectAndDisplay( Mat frame, CascadeClassifier& face_cascade)
{
    std::vector<Rect> faces;
    Mat frame_gray;

    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    //-- Detect faces
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0, Size(30, 30) );
    cout<<faces.size()<<endl;
    for( size_t i = 0; i < faces.size(); i++ )
    {
            Mat faceROI = frame_gray( faces[i] );
            //-- Draw the face
            Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
            ellipse( frame, center, Size( faces[i].width/2, faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 0 ), 2, 8, 0 );
    }

    //-- Show what you got
    imshow( "TVDetection", frame );
}
