#--coding:utf-8--#
import  pyOF as of
import numpy as np
# from openframeworks import  *
# import inspect
class Circle(of.BaseEvent):
    "Can't define __init__"
    # def __init__(self):
    #     super(Circle, self).__init__()

    def setup(self):
        self.radius=100
        self.x = of.ofGetWidth()/2
        self.y = of.ofGetHeight()/2

        a = of.ofColor(100,200,50)
        # print -a
        a= of.ofPoint(1,2,3)
        r = of.ofRectangle(10,10,200,100)
        r = r + a
        r = r - a
        q = of.ofQuaternion(1,2,3,4)
        q.y = 8
        m = of.ofMatrix4x4()
        n = m.newIdentityMatrix()
        n = m.newScaleMatrix(5,6,7)
        del n, m
        i = of.ofShortImage()
        del i
        print of.ofToHex( of.ofHexToChar("f") )
        print of.ofToHex( of.ofHexToInt("bbee") )
        print of.ofToHex( -127 )
        print of.ofToHex( -128 )

    def draw(self):
        of.ofPushStyle()
        # of.ofSetColor( of.ofColor(20,30,80,100) )
        of.ofSetColor( of.ofColor.lightCoral )
        of.ofDrawCircle(self.x, self.y, self.radius)
        of.ofPopStyle()

    def mouseReleased(self, args):
        if self.inside(args.x, args.y):
            print "inside me!"

    def inside(self, _x, _y):
        return of.ofVec2f(_x, _y).distance(of.ofVec2f(self.x, self.y)) < self.radius





class ArduinoUNO(of.hd.ArduinoDevice):
    def setup(self, device):
        self.connect( device, 57600)
        # aa  = of.hd.ofSerial().getDeviceList()
        # for device in aa:
        #     if self.connect( device.getDevicePath(), 57600):
        #         break
    def setupArduino(self):
        self.ard.sendDigitalPinMode(13, of.hd.arduinoUNO.ARD_OUTPUT);
    def loopArduino(self):
        pass
        # self.ard.sendDigital(13, ARD_HIGH);
    def onDigitalPinChanged(self, pin):
        print "Digital pin: ",pin, "changed."
    def onAnalogPinChanged(self, pin):
        print "Analog pin: ",pin, "changed."
    def onStringReceived(self, data):
        pass
    def onSysExReceived(self, msg):
        pass




class App(of.BaseApp):
    # 注意不能定义__init__， setup就相当于__init__
    def setup(self):
        # pass
        of.ofSetWindowTitle("Hello openFrameworks")
        # of.ofBackground(80,100,150)
        of.ofBackgroundHex(0x113366)

        of.ofEnableSmoothing()
        of.ofEnableAlphaBlending()
        of.ofSetCircleResolution(50)
        of.ofSetRectMode(of.OF_RECTMODE_CENTER);
        of.ofSetFrameRate(60);
        self.mxPercent=0.5
        self.myPercent=0.5
        self.cc = Circle()
        self.cc.setup()
        self.testFont = of.ofTrueTypeFont()
        self.testFont.load("/Users/my/Documents/dev/cython/pyOF/build/data/Batang.ttf", 40, True, True, True, 0.3, 0)
        self.testFont2 = of.ofTrueTypeFont()
        self.testFont2.load("/Users/my/Documents/dev/cython/pyOF/build/data/cooperBlack.ttf", 20, True, True, True, 0.3, 0)
        a = of.ofPolyline([of.ofPoint(1,2,3), of.ofPoint(10,20,30), of.ofPoint(50,60,80)])
        b = a.getClosestPoint(of.ofPoint( 1,20,4))
        self.img1 = of.ofImage()
        self.img2 = of.ofImage()
        self.img3 = of.ofImage()
        self.img4 = of.ofImage("/Users/my/Documents/dev/cython/pyOF/build/data/images/gears.gif")
        self.img5 = of.ofImage("/Users/my/Documents/dev/cython/pyOF/build/data/images/tdf_1972_poster.jpg")
        self.img6 = of.ofImage("/Users/my/Documents/dev/cython/pyOF/build/data/images/transparency.png")
        self.img1.load("/Users/my/Documents/dev/cython/pyOF/build/data/images/bike_icon.gif")
        self.img2.load("/Users/my/Documents/dev/cython/pyOF/build/data/images/bike_icon.png")
        self.img3.load("/Users/my/Documents/dev/cython/pyOF/build/data/images/bikers.jpg")
        self.img2.setImageType(of.OF_IMAGE_GRAYSCALE)
        self.plane = of.ofIcoSpherePrimitive(200, 3)
        # self.plane.set(640,480)
        self.plane.setPosition(320,240,0)
        self.plane.enableNormals()
        self.a = of.gui.ofxPanel()
        self.a.setup("panel","/Users/my/Documents/dev/cython/pyOF/data/settings.xml")
        # self.b = of.gui.ofxButton()
        # c =  self.b.setup("ok", 200,18)
        a0= of.gui.ofxToggle()

        a = of.gui.ofxButton()
        # print a0.getWidth()
        # print a0.getHeight()
        # print a.getWidth()
        # print a.getHeight()
        b = of.gui.ofxIntSlider()
        c = of.gui.ofxPointSlider()
        d = of.gui.ofxColorSlider()
        # b = a.setup("intaa",5,0,10,200,18)
        # self.a.add( a0.setup("toggle",True,200,18) )
        # print a0.parent
        a0.setParent( self.a);
        a0.parent.add( a.setup("button") )
        a0.parent.add( b.setup("int",5,0,10) )
        self.a.add( c.setup("point",of.ofPoint(2,5,8),of.ofPoint(0,0,0), of.ofPoint(10,10,10)) )
        self.a.add( d.setup("color",of.ofColor(87,152,186,255),of.ofColor(0,0,0,0), of.ofColor(255,255,255,255)) )
        self.videoGrab = of.ofVideoGrabber()
        self.videoGrab.setup(640, 480)
        self.ocv1 = of.opencv.ofxCvFloatImage()
        self.ocv1.allocate(3, 4)
        self.np1 = np.array([1,2,3,4,5,6,7,8,9,10,11,12], dtype=np.float32)
        self.np1.shape = 4,3
        self.ocv1.assign( self.np1 )
        # a0.parent = self.a
        # print a0.getParameter()
        # a0.draw()
        # self.arduino1 = ArduinoUNO()
        # self.arduino1.setup("/dev/tty.usbserial-A600f471")
        # self.arduino2 = ArduinoUNO()
        # self.arduino2.setup("/dev/tty.wchusbserial1a1230")  
    def update(self):
        self.plane.rotate(2, 1.0, 0.0, 0.0);
        self.plane.rotate(2, 0, 1.0, 0.0);
        self.videoGrab.update()
        # self.arduino1.update()
        # self.arduino2.update()

    def draw(self):
        of.ofBackgroundGradient(of.ofColor.azure, of.ofColor.lightSlateGray, of.OF_GRADIENT_CIRCULAR)
        # of.ofClear(80,100,150,255)
        self.img5.draw(200,200)
        # self.img4.draw(600,0)
        # self.img5.draw(600,300)
        of.ofSetColor(220,50, 50)
        self.img6.draw(200,300)
        of.ofFill()
        self.cc.draw()
        of.ofSetColor(255, 255, 255, 255)
        of.ofDrawBitmapString("fps: "+ str(of.ofGetFrameRate()), 10, 10)
        of.ofDrawBitmapString("press a key to see it as a texture and as a vector.", 10, 24)

        self.testFont2.drawString("Hello - I am bitmap", 15, 400)
        self.testFont2.drawStringAsShapes("Hello - I am vector", 15, 480)
        of.ofNoFill()
        self.testFont2.drawStringAsShapes("Hello - I am vector", 15, 550)

        of.ofDrawCircle(30, 30, 30);
        of.ofDrawRectangle(5, 70, 50, 100);
        of.ofDrawCircle(95, 30, 30);
        of.ofDrawRectangle(70, 70, 50, 100);
        of.ofDrawCircle(45, 90, 15);
        of.ofDrawRectangle(30, 110, 30, 60);
        of.ofDrawCircle(80, 90, 15);
        of.ofDrawRectangle(65, 110, 30, 60);

        self.plane.drawWireframe()
        self.a.draw()

        self.videoGrab.draw(of.ofGetWidth()/2,of.ofGetHeight()/4,320,240)
        # self.ocv1.draw(800,200)
        
        # self.plane.draw()
        # print self.mouseX
        # pass
        # hue = of.ofGetElapsedTimef()*10 % 255
        # step =5
        # for i in range(0, of.ofGetWidth(), step):
        #     for j in range(0, of.ofGetHeight(), step):
        #         # print i,j
        #         c = of.ofColor()
        #         c.setHsb( hue, 
        #             of.ofMap(i, 0, of.ofGetWidth(),    0,    255,    False), 
        #             of.ofMap(j,   of.ofGetHeight(), 0, 0,    255,    False),
        #             255)
        #         of.ofSetColor( c );
        #         of.ofDrawRectangle( i, j, step-1, step-1 );

        # color = of.ofColor()
        # color = of.ofColor.fromHsb(hue, of.ofMap( self.mouseX, 0,of.ofGetWidth(), 0,255,False ), of.ofMap( self.mouseY, of.ofGetHeight(),0, 0,255,False ),255)
        # of.ofSetColor( color );
        # of.ofFill();
        # of.ofDrawRectangle( self.mouseX, self.mouseY, 100, 100 );

        # of.ofNoFill();
        # of.ofSetColor(255);
        # of.ofDrawRectangle( self.mouseX, self.mouseY, 100, 100 );
        # of.ofFill();
        # # txt = "HSB: {0} {1} {2}".format( int(hue), color.getSaturation(), color.getBrightness())
        # txt = "HSB: %d %d %d" % ( int(hue) , color.getSaturation(), color.getBrightness() )
        # of.ofDrawBitmapString(txt ,10,  of.ofGetHeight()-13)
        # # # txt = "RGB: {0} {1} {2}".format( color.r, color.g, color.b)
        # txt = "RGB: %d %d %d" % (color.r ,color.g , color.b)
        # of.ofDrawBitmapString(txt, 200, of.ofGetHeight()-13)

    def exit(self):
        pass

    def keyPressed(self, key):
        pass
        # arduino1 =  self.arduino1.ard
        # arduino2 =  self.arduino2.ard
        # if arduino1.isArduinoReady() and arduino2.isArduinoReady():
        #     arduino1.sendDigital(10, of.hd.arduinoUNO.ARD_HIGH, False);
        #     arduino2.sendDigital(10, of.hd.arduinoUNO.ARD_LOW, False);
        # print "Key Pressed ",key
        
    def keyReleased(self, key):
        pass
        # arduino1 =  self.arduino1.ard
        # arduino2 =  self.arduino2.ard
        # if arduino1.isArduinoReady() and arduino2.isArduinoReady():
        #     arduino1.sendDigital(10, of.hd.arduinoUNO.ARD_LOW, False);
        #     arduino2.sendDigital(10, of.hd.arduinoUNO.ARD_HIGH, False);
        # print "Key Released ",key
      
    def mouseMoved(self, x, y):
        self.mxPercent = x / of.ofGetWidth();
        self.myPercent = y / of.ofGetHeight();
        pass
        # print "mouse Moved: [ x={0}, y={1}]".format(x,y)
    def mousePressed(self, x, y, button):
        pass
        # print "frame rate: ",of.ofGetFrameRate()
        # print "mouse pressed: [ x={0}, y={1}, button={2}]".format(x,y,button)
    def mouseDragged(self, x, y, button):
        pass
        # print "mouse dragged: [ x={0}, y={1}, button={2}]".format(x,y,button)
    def mouseReleased(self, x, y, button):
        pass
        # print "mouse released: [ x={0}, y={1}, button={2}]".format(x,y,button)
    def mouseEntered(self, x, y):
        pass
        # print "mouse enter: [ x={0}, y={1}]".format(x,y)
    def mouseExited(self, x, y):
        pass

    def windowResized(self, w, h):
        pass
        # print "windowResized: [ w={0}, h={1}]".format(w,h)
    def dragEvent(self, dragInfo):
        pass
    def gotMessage(self, msg):
        pass
    def touchDown(self, x, y, id):
        pass
    def touchMoved(self, x, y, id):
        pass
    def touchUp(self, x, y, id):
        pass
    def touchDoubleTap(self, x, y, id):
        pass
    def touchCancelled(self, x, y, id):
        pass

app = App()
# app.run(1024,600, of.OF_WINDOW)
app.runGL(1024,600, of.OF_WINDOW,3,2)  #底层API运行OpenGL3.2
# 窗口模式还可以设置为 of.OF_FULLSCREEN  of.OF_GAME_MODE