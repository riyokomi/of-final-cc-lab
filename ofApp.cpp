#include "ofApp.h"

#define NUM_STARS 1500 //1500 flowstars' rgb colors, positions(coordinates), and radius...


//declare all the variables, they are all numbers here
float StarX[NUM_STARS];
float StarY[NUM_STARS];
float StarRad[NUM_STARS];
int StarR[NUM_STARS];
int StarG[NUM_STARS];
int StarB[NUM_STARS];

float lastdistance = 0;


//Function of drawing Stars of npts/2 vertex angles(or npts vertexs)
//npts/2 = the angles everytime the stars rotating= 360/(npts)
void drawStar(float xpos, float ypos, float radius, int npts)
{
    bool useInner=false; //boolin, use this to do some judgement
    ofBeginShape(); //start drawing, link dots
    for(int l=0; l<360; l +=360/npts) //transfer degree to radius
    {
        int r = useInner ? radius*.6 : radius; //useInner? give a negative value
        int x = xpos + cos( ofDegToRad(l) ) * r; //coordinates
        int y = ypos + sin( ofDegToRad(l) ) * r; //coor
        ofVertex(x, y); //give dots
        useInner = !useInner;//判断半径，true- radius/0.6, false=radius
    }
    ofEndShape();
}

//--------------------------------------------------------------
void ofApp::setup(){ //initialization, intialize 1500 stars' x,y and radius and rgb
    
    
    ofSetFrameRate(24);
    
    for(int i=0; i<NUM_STARS; i++)
    {
        StarX[i] = ofRandom(0, ofGetWidth());
        StarY[i] = ofRandom(0, ofGetHeight());
        StarRad[i] = ofRandom(5, 15);
        
        StarR[i] = ofRandom(0, 255);
        StarG[i] = ofRandom(0, 255);
        StarB[i] = ofRandom(0, 255);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //this part controls star move randomly when I dont use mouse to control it
    //the range of random value = [-2, 2]

    int angle = 0;
    for(int i=0; i<NUM_STARS; i++)
    {
//        StarX[i] += cos( ofDegToRad(angle) ) * ofRandom(0, 2);
//        StarY[i] += sin( ofDegToRad(angle) ) * ofRandom(0, 2);
        StarX[i] += ofRandom(-2, 2);
        StarY[i] += ofRandom(-2, 2);
        angle += 10; //if 1st star's angle=0, then the second's = 0+10,
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
//    ofBackgroundGradient(ofColor::yellowGreen, ofColor(255,255,255), OF_GRADIENT_CIRCULAR);
    
    ofSetBackgroundAuto(false);
    drawStar(mouseX, mouseY, 20, 10); //use the function we wrote in the voidDrawstar section
    ofEnableAlphaBlending();
    
    for(int i=0; i<NUM_STARS; i++)//draw 1500 stars, looping
    {
        ofSetColor(StarR[i], StarG[i], StarB[i]);
        drawStar(StarX[i], StarY[i], StarRad[i], 10);//draw the single star moving with your mouse
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){ //use mouse move to make animation of the flowing stars when you are not clicking the mouse/ press the mouse, everytime you move the mouse, this initialize all the values
    

    
    for(int i=0; i<NUM_STARS; i++)
    {
        StarX[i] = ofRandom(0, ofGetWidth());
        StarY[i] = ofRandom(0, ofGetHeight());
        StarRad[i] = ofRandom(5, 15);
        
        StarR[i] = ofRandom(0, 255);
        StarG[i] = ofRandom(0, 255);
        StarB[i] = ofRandom(0, 255);
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){ // when drag/ press down mouse- change the size of stars
    
    float distance = ofDist(ofGetWidth(), ofGetHeight(), x, y);
    
    
    if(distance > lastdistance) 
    {
        for(int i=0; i<NUM_STARS; i++)
        {
            StarRad[i] += 2;
            
            StarB[i] += 4;
        }
    }
    else
    {
        for(int i=0; i<NUM_STARS; i++)
        {
            StarRad[i] -= 2;
            
            StarB[i] -= 4;
        }
    }
    
    lastdistance = distance;
}

//--------------------------------------------------------------


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
