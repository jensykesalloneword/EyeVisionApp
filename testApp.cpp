#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    framerate =0.0;

    
    red = 233; blue = 52; green = 27;
    hideGUI = false;
    bdrawGrid = false;
    bdrawGridWave = false;
    bdrawGridNoise = false;
	bdrawPadding = false;
    bdrawCircleEasy =false;
    bdrawCircleMedium =false;
    bdrawCircleHard =false;
    bclear =false;
    
  
    
    

    

    buffer = new float[256];
    for(int i = 0; i < 256; i++) { buffer[i] = ofNoise(i/100.0); }
   
	nCurveVertices = 7;
	
	curveVertices[0].x = 326;
	curveVertices[0].y = 209;
	curveVertices[1].x = 306;
	curveVertices[1].y = 279;
	curveVertices[2].x = 265;
	curveVertices[2].y = 331;
	curveVertices[3].x = 304;
	curveVertices[3].y = 383;
	curveVertices[4].x = 374;
	curveVertices[4].y = 383;
	curveVertices[5].x = 418;
	curveVertices[5].y = 309;
	curveVertices[6].x = 345;
	curveVertices[6].y = 279;
	
	for (int i = 0; i < nCurveVertices; i++){
		curveVertices[i].bOver 			= false;
		curveVertices[i].bBeingDragged 	= false;
		curveVertices[i].radius = 4;
	}
    
	setGUI1();
	setGUI2();
    setGUI3();
    setGUI4();
    setGUI5();


    
}

//--------------------------------------------------------------
void testApp::update(){

	
}

//--------------------------------------------------------------
void testApp::draw(){


    ofBackground(red,green, blue,255);
    
  
    ofSetRectMode(OF_RECTMODE_CENTER);
    
   // ofPushStyle();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
  
//    if (bdrawLetters)
//    {
//        ofSetColor(255,200,0);
//        drawLetters();
//    }
    
	if(bdrawCircleEasy)
	{
		ofSetColor(255,200,200);
		drawCircleEasy();
       
	}

	//ofPopStyle();

    ofPushStyle();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    
//	if(bdrawCircleMedium)
//	{
//		ofSetColor(255,0,200);
//		drawCircleMedium();
//     
//	}
    
	ofPopStyle();

    ofPushStyle();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    
	if(bdrawCircleHard)
	{
		ofSetColor(255,200,0);
		drawCircleHard();
   
	}
    
	ofPopStyle();
//    ofPushStyle();
	//ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    ofPushStyle();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	if(bdrawGrid)
	{
		ofSetColor(0);
		drawGrid(512,384);
	}
    ofPopStyle();
    
    ofPushStyle();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    if(bdrawGridWave)
    {
        //ofSetColor(0);
        drawGridWave(50,50);
    }
    ofPopStyle();
    
    ofPushStyle();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    if(bdrawGridNoise)
    {
        //ofSetColor(0);
        drawGridNoise(50,50);
    }
    

	ofPopStyle();


}

void testApp::guiEvent(ofxUIEventArgs &e)
{
	/*
     Background colour
     */
    string name = e.getName();
	int kind = e.getKind();
	cout << "got event from: " << name << endl;
	
	if(name == "RED")
	{
		ofxUISlider *slider = (ofxUISlider *) e.getSlider();
		cout << "RED " << slider->getScaledValue() << endl;
		red = slider->getScaledValue();
	}
	else if(name == "GREEN")
	{
		ofxUISlider *slider = (ofxUISlider *) e.getSlider();
		cout << "GREEN " << slider->getScaledValue() << endl;
		green = slider->getScaledValue();
	}
	else if(name == "BLUE")
	{
		ofxUISlider *slider = (ofxUISlider *) e.getSlider();
		cout << "BLUE " << slider->getScaledValue() << endl;
		blue = slider->getScaledValue();
	}


	/*
     Circles and grids
     */
   
      else  if(name == "EASY")
       {
           ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
           bdrawGrid = toggle->getValue();
            bdrawGridNoise = toggle->getValue()==false;
           bdrawGridWave = toggle->getValue()==false;
           
           
           bdrawCircleEasy = toggle->getValue();
           bdrawCircleMedium = toggle->getValue()==false;
           bdrawCircleHard = toggle->getValue()==false;
        toggle->setValue(false);
           
       }
        else if(name == "MEDIUM")
            	{
            		ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
            		bdrawGridNoise = toggle->getValue();
                    bdrawGrid = toggle->getValue()==false;
                    bdrawCircleMedium = toggle->getValue();
                    bdrawCircleEasy = toggle->getValue();
                    bdrawCircleHard = toggle->getValue()==false;
                     toggle->setValue(false);
            	}
            
                else if(name == "HARD")
            	{
            		ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
            		bdrawGridWave = toggle->getValue();
                    bdrawGridNoise = toggle->getValue()==false;
                    bdrawGrid = toggle->getValue();
                    bdrawCircleHard = toggle->getValue();
                    bdrawCircleEasy = toggle->getValue()==false;
                    bdrawCircleMedium = toggle->getValue()==false;
                    toggle->setValue(false);
            	}

    
    else if( name == "CLEAR" )
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
        
       	bdrawGrid = toggle->getValue()== false;
        bdrawCircleEasy = toggle->getValue()==false;
        bdrawCircleMedium = toggle->getValue()==false;
        bdrawCircleHard = toggle->getValue()==false;
        toggle->setValue(false);
            }
    
    
    
//    
//    else if(name == "LETTERS")
//    {
//        ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
//        bdrawLetters = toggle->getValue();
//        toggle->setValue(false);
//    }
   }

       //button->setValue(true);




//    else if(name == "TEXT INPUT")
//    {
//        ofxUITextInput *textinput = (ofxUITextInput *) e.widget;
//        if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_ENTER)
//        {
//            cout << "ON ENTER: ";
//        }
//        else if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_FOCUS)
//        {
//            cout << "ON FOCUS: ";
//        }
//        else if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_UNFOCUS)
//        {
//            cout << "ON BLUR: ";
//        }
//        string output = textinput->getTextString();
//        cout << output << endl;
//    }


//--------------------------------------------------------------
void testApp::exit()
{
	delete gui1;
	delete gui2;
    delete gui3;
    delete gui4;
    delete gui5;
	delete[] buffer;
    delete img;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(gui1->hasKeyboardFocus())
    {
        return;
    }
	switch (key)
	{
		case 'f':
			ofToggleFullscreen();
			break;
            
		case 'h':
            gui1->toggleVisible();
//            gui2->toggleVisible();
//            gui3->toggleVisible();
//            gui4->toggleVisible();
			break;
            
		case 'p':
			bdrawPadding = !bdrawPadding;
			gui1->setDrawWidgetPaddingOutline(bdrawPadding);
			gui2->setDrawWidgetPaddingOutline(bdrawPadding);
			gui3->setDrawWidgetPaddingOutline(bdrawPadding);
			gui4->setDrawWidgetPaddingOutline(bdrawPadding);
			break;
            
		case '[':
			gui1->setDrawWidgetPadding(false);
			gui2->setDrawWidgetPadding(false);
			gui3->setDrawWidgetPadding(false);
			gui4->setDrawWidgetPadding(false);
			break;
            
		case ']':
			gui1->setDrawWidgetPadding(true);
			gui2->setDrawWidgetPadding(true);
			gui3->setDrawWidgetPadding(true);
			gui4->setDrawWidgetPadding(true);
			break;
			
        case '1':
            gui1->toggleVisible();
            break;
            
        case '2':
            gui2->toggleVisible();
            break;
            
        case '3':
            gui3->toggleVisible();
            break;
            
        case '4':
            gui4->toggleVisible();
            break;
            
		default:
			break;
	}
}
void testApp::drawBackground(){
    ofBackground(red,green, blue,255);

}
void testApp::drawCircleEasy()
{
    
    
    radius = 30;
    position = ofPoint(ofGetWidth(), ofGetHeight());
    ofSetFrameRate(framerate/2);
    //ofSetColor(255);
    ofCircle(ofRandom(position.x),ofRandom(position.y),ofRandom(radius));
    
    
}
void testApp::drawNumbers()
{
    
  
    
    
}


//void testApp::drawLetters()
//{
//    
//    ofSetColor(225);
//	//franklinBook14.drawString("franklin book 14pt - ", 30, 338);
////	textinput.drawString(typeStr, 30, 358);
//    
//    
//}

void testApp::drawCircleHard()
{
    
    
    radius = 15;
    position = ofPoint(ofGetWidth(), ofGetHeight());
    ofSetFrameRate(6);
    //ofSetColor(255);
    ofCircle(ofRandom(position.x),ofRandom(position.y),ofRandom(radius));
    
    
}


void testApp::drawGrid(float x, float y)
{
    float w = ofGetWidth();
    float h = ofGetHeight();
    
    for(int i = 0; i < h; i+=y)
    {
        
        ofSetLineWidth(1.0);
       
        ofLine(0,i,w,i);
        //ofLine(w,50,w,350);
    }
    
    for(int j = 0; j < w; j+=x)
    {
        ofSetLineWidth(1.0);
       ofLine(j,0,j,h);
      //  ofLine(50,h,350,h);
    }
}
void testApp::drawGridNoise(float x, float y)
{
    float w = ofGetWidth();
    float h = ofGetHeight();
    //------(d)--------------------------------------
	//
	// 		poylgon of random points
	//
	// 		lots of self intersection, 500 pts is a good stress test
	//
	//
	ofSetColor(100,150);
	ofSetPolyMode(OF_POLY_WINDING_ODD);
	
    ofBeginShape();
	for (int i = 0; i < 60; i++){
		ofLine(ofRandom(ofGetWidth()*2), ofRandom(ofGetHeight()*2),ofRandom(1200),ofRandom(200));
	}
	ofEndShape();
	//-------------------------------------
	

    
}
void testApp::drawGridWave(float x, float y){

    
    for (int i = 0; i < ofGetWidth(); i++) {
        r = ofRandom(250-255);
       
        ofSetLineWidth(0.4);
        ofSetColor(r,50);
        ofLine(i, 0, i, ofGetHeight());
    }
}


void testApp::setGUI1()
{
   
  
    
    
	
    gui1 = new ofxUISuperCanvas("EYE VISION");
    gui1->addSpacer();
    gui1->addLabel("Press 'h' to Hide Controls", OFX_UI_FONT_SMALL);
    
    gui1->addSpacer();
	gui1->addLabel("COLOUR CHANGE");
	gui1->addSlider("RED", 0.0, 255.0, red);
	gui1->addSlider("GREEN", 0.0, 255.0, green);
	gui1->addSlider("BLUE", 0.0, 255.0, blue);
    gui1->addSlider("SPEED",0.0,255.0,&framerate);
//    gui1->addSpacer();
//    gui1->addLabel("V SLIDERS");
//	gui1->addSlider("0", 0.0, 255.0, 150, 17, 160);
//	gui1->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);
//	gui1->addSlider("1", 0.0, 255.0, 150, 17, 160);
//	gui1->addSlider("2", 0.0, 255.0, 150, 17, 160);
//	gui1->addSlider("3", 0.0, 255.0, 150, 17, 160);
//	gui1->addSlider("4", 0.0, 255.0, 150, 17, 160);
//	gui1->addSlider("5", 0.0, 255.0, 150, 17, 160);
//	gui1->addSlider("6", 0.0, 255.0, 150, 17, 160);
//	gui1->addSlider("7", 0.0, 255.0, 150, 17, 160);
//	gui1->addSlider("8", 0.0, 255.0, 150, 17, 160);
//	gui1->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN);
    
    gui1->addSpacer();
	//gui1->addRadio("RADIO HORIZONTAL", names, OFX_UI_ORIENTATION_HORIZONTAL);


    gui1->addSpacer();
    gui1->setWidgetFontSize(OFX_UI_FONT_SMALL);
    gui1->setGlobalButtonDimension(32);
	
	gui1->addToggle( "LETTERS", false);
    gui1->addToggle( "EASY", false);
    gui1->addToggle( "MEDIUM", false);
    gui1->addToggle( "HARD", false);
    gui1->addToggle( "CLEAR", false);
//    
    string textString =  "CHANGE THE COLOUR, SPEED AND BACKGROUND INTERFERENCE.";
    gui1->addSpacer();
    gui1->addTextArea("CONTROL", textString, OFX_UI_FONT_MEDIUM);
    
    gui1->autoSizeToFitWidgets();
	ofAddListener(gui1->newGUIEvent,this,&testApp::guiEvent);
}

void testApp::setGUI2()
{
//    gui2 = new ofxUISuperCanvas("PANEL 2: ADVANCED");
//    
//    gui2->addSpacer();
//	gui2->addLabel("TEXT INPUT", OFX_UI_FONT_SMALL);
//	gui2->setWidgetFontSize(OFX_UI_FONT_LARGE);
//	gui2->addTextInput("TEXT INPUT", "Input Text");
//    gui2->addLabel("AUTO CLEAR DISABLED", OFX_UI_FONT_SMALL);
//    gui2->addTextInput("TEXT INPUT2", "Input Text")->setAutoClear(false);
//	gui2->setWidgetFontSize(OFX_UI_FONT_MEDIUM);
//    
//    gui2->addSpacer();
//    gui2->addLabel("WAVEFORM DISPLAY");
//	gui2->addWaveform("WAVEFORM", buffer, 256, 0.0, 1.0);
//    gui2->addLabel("SPECTRUM DISPLAY");
//    gui2->addSpectrum("SPECTRUM", buffer, 256, 0.0, 1.0);
//    
//    gui2->addSpacer();
//    gui2->addLabel("IMAGE DISPLAY");
//	gui2->addImage("IMAGE CAPTION", img);
//    
//    gui2->addSpacer();
//    gui2->addLabel("FPS LABEL");
//    gui2->addFPS();
    
//    gui2->addSpacer();
//    gui2->addLabel("NUMBER DIALER");
//    gui2->addNumberDialer("NUMBER DIALER", -10000, 10000, 5000, 1);
    
//    gui2->addSpacer();
//    gui2->addLabel("LABEL BUTTON", OFX_UI_FONT_MEDIUM);
//    gui2->addLabelButton("LABEL BUTTON", false);
//    
//    gui2->addSpacer();
//    gui2->addLabel("LABEL TOGGLES", OFX_UI_FONT_MEDIUM);
//    gui2->addLabelToggle("LABEL TOGGLE", false);
//    
//    gui2->setPosition(212, 0);
//    gui2->autoSizeToFitWidgets();
//    
//	ofAddListener(gui2->newGUIEvent,this,&testApp::guiEvent);
}

void testApp::setGUI3()
{
//	gui3 = new ofxUISuperCanvas("PANEL 3: ADVANCED");
//    
//    gui3->addSpacer();
//    gui3->setGlobalButtonDimension(32);
//    gui3->addLabel("MATRIX", OFX_UI_FONT_MEDIUM);
//    gui3->addToggleMatrix("MATRIX1", 4, 4);
//    gui3->addToggleMatrix("MATRIX2", 3, 6);
//    gui3->addToggleMatrix("MATRIX3", 1, 4);
    
//    gui3->addSpacer();
//    gui3->setGlobalButtonDimension(64);
//    gui3->addImageButton("IMAGEBTN", "GUI/images/App.png", false);
//	gui3->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);
//    gui3->addImageToggle("IMAGETGL", "GUI/images/Preview.png", false);
//    gui3->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN);
//    
//    gui3->addSpacer();
//    gui3->addLabel("DROP DOWN", OFX_UI_FONT_MEDIUM);
//    
//    vector<string> items;
//    items.push_back("FIRST ITEM");
//    items.push_back("SECOND ITEM");
//    items.push_back("THIRD ITEM WHATS UP DOG");
//    items.push_back("FOURTH ITEM");
//    items.push_back("FIFTH ITEM");
//    items.push_back("SIXTH ITEM");
    
//    gui3->addDropDownList("DROP DOWN LIST", items, 200);
//    gui3->setPosition(212*2, 0);
//    gui3->autoSizeToFitWidgets();
//    
//	ofAddListener(gui3->newGUIEvent,this,&testApp::guiEvent);
}

void testApp::setGUI4()
{
//	gui4 = new ofxUISuperCanvas("PANEL 4: ADVANCED");
//    
//    gui4->addSpacer();
//    gui4->addLabel("BILABEL SLIDER");
//    gui4->addBiLabelSlider("BILABEL", "HOT", "COLD", 0, 100, 50);
//    
//    gui4->addLabel("MINIMAL SLIDER");
//    gui4->addMinimalSlider("MINIMAL", 0, 100, 50.0);
//    
//    gui4->addSpacer();
//    gui4->addLabel("FPS SLIDER", OFX_UI_FONT_MEDIUM);
//    gui4->addFPSSlider("FPS SLIDER");
//    
//    vector<float> buffer;
//    for(int i = 0; i < 256; i++)
//    {
//        buffer.push_back(0.0);
//    }
//    
//    gui4->addLabel("MOVING GRAPH", OFX_UI_FONT_MEDIUM);
//    mg = (ofxUIMovingGraph *) gui4->addMovingGraph("MOVING GRAPH", buffer, 256, 0, 1.0);
//    
//    gui4->addSpacer();
//    gui4->addLabel("IMAGE SAMPLER", OFX_UI_FONT_MEDIUM);
//    gui4->addImageSampler("SAMPLER", img);
//    gui4->setGlobalButtonDimension(64);
//    gui4->addMultiImageButton("IMAGE BUTTON", "GUI/toggle.png", false);
//    gui4->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);
//    gui4->addMultiImageToggle("IMAGE BUTTON", "GUI/toggle.png", false);
//    gui4->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN);
//    
//    vector<std::string> items;
//    items.push_back("FIRST ITEM"); items.push_back("SECOND ITEM"); items.push_back("THIRD ITEM");
//    items.push_back("FOURTH ITEM"); items.push_back("FIFTH ITEM"); items.push_back("SIXTH ITEM");
//    gui4->setWidgetFontSize(OFX_UI_FONT_SMALL);
//    gui4->addSortableList("SORTABLE LIST", items);
//    
//    gui4->setPosition(212*3,0);
//    gui4->autoSizeToFitWidgets();
//    
//	ofAddListener(gui4->newGUIEvent,this,&testApp::guiEvent);
}

void testApp::setGUI5()
{
//	gui5 = new ofxUISuperCanvas("PANEL 5: ADVANCED");
//    gui5->addSpacer();
//    
//	gui5->addLabel("2D PAD");
//	gui5->add2DPad("PAD", ofPoint(-100, 100), ofPoint(-100,100), ofPoint(0,0));
//    
//    gui5->addSpacer();
//    gui5->addLabel("ROTARY SLIDER", OFX_UI_FONT_MEDIUM);
//    gui5->addRotarySlider("R2SLIDER", 0, 100, 50);
//    
//    gui5->addSpacer();
//    gui5->addLabel("CIRCLE SLIDER", OFX_UI_FONT_MEDIUM);
//    gui5->addCircleSlider("NORTH SOUTH", 0, 100, 50.0);
//    
//    gui5->setPosition(212*4,0);
//    gui5->autoSizeToFitWidgets();
//    
//	ofAddListener(gui5->newGUIEvent,this,&testApp::guiEvent);
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}
