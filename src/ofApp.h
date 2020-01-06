#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxMarkovChain.h"
#include "ofxTextSuite.h"

class Mark {
    string markType;
    int state;
    ofImage markIcon;
    
public:
    Mark(int state){
        switch(state){
            case 0:
                markType = "a line up,";
                markIcon.load("images/lineup.png");
                break;
                
            case 1:
                markType = "a line down,";
                markIcon.load("images/linedown.png");
                break;
                
            case 2:
                markType = "a line left,";
                markIcon.load("images/lineleft.png");
                break;
                
            case 3:
                markType = "a line right,";
                markIcon.load("images/lineright.png");
                break;
                
            case 4:
                markType = "an arc up,";
                markIcon.load("images/arcup.png");
                break;
                
            case 5:
                markType = "an arc down,";
                markIcon.load("images/arcdown.png");
                
                break;
                
            case 6:
                markType = "an arc left,";
                markIcon.load("images/arcleft.png");
                
                break;
                
            case 7:
                markType = "an arc right,";
                markIcon.load("images/arcright.png");
                
                break;
                
            default:
                break;
        }
    }
    
    int getState(){
        return state;
    }
    
    string getMarkType(){
        return markType;
    }
    
    void draw(int x, int y, int w, int h){
        markIcon.draw(x, y, w, h);
    }
    
};


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void addDrawingStep();
    void reset();
    
    bool b_drawGui;
    int iconWidth;
    ofParameter<int> cycle;
    
    ofxMC::MarkovChain markov;
    
    ofxLabel fps;
    ofxPanel gui;
    
    vector<Mark> marks;
    
    ofxTextBlock instructionText;
    
};
