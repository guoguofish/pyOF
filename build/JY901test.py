#--coding:utf-8--#
# from collections import deque
import pyOF as of


class App(of.BaseApp):
    def setup(self):
        of.ofSetWindowTitle("九轴陀螺仪测试")
        of.ofBackground(80,100,150, 255)
        of.ofEnableSmoothing()
        of.ofEnableAlphaBlending()
        of.ofSetCircleResolution(50)
        of.ofEnableDepthTest()

        self.d = of.hd.ofJY901()
        self.d.connect("/dev/tty.usbserial", 115200)
        self.tempData = []
        self.tempLineX = of.ofPolyline()
        self.tempLineY = of.ofPolyline()
        self.tempLineZ = of.ofPolyline()
        
        self.airplane = of.ofBoxPrimitive(100,50,180)
        self.airplane.setPosition(0,80,0)
        # self.airplane.setPosition(of.ofGetWidth()/2.0, of.ofGetHeight()/2.0, 10)
        self.mod = of.assimp.ofxAssimpModelLoader()
        self.mod.loadModel("/Users/my/Documents/dev/cython/pyOF/build/data/Plane.3DS")
        self.mod.enableColors()
        self.mod.setPosition(0,-50,0)

        self.light1 = of.ofLight()
        self.light1.setup()
        self.light1.setDiffuseColor( of.ofFloatColor.red)
        self.light1.setPosition( 200, 200, 0)

        self.material = of.ofMaterial()
        self.material.setDiffuseColor( of.ofFloatColor.gray )

        self.cam = of.ofEasyCam()
        # self.airplane.loadModel("/Users/my/Documents/dev/cython/pyOF/data/Plane.3DS")
        # self.airplane.enableColors()
        # self.airplane.enableMaterials()
        # self.airplane.enableTextures()
        # self.airplane.setPosition(of.ofGetWidth()/2.0, of.ofGetHeight()/2.0, 10)

    def updateLine(self, baseY, count=20):
        self.tempLineX.clear()
        self.tempLineY.clear()
        self.tempLineZ.clear()
        self.tempData.append( self.d.getAngle() )
        if len(self.tempData)==count+1:
                self.tempData.pop(0)

        step = (of.ofGetWidth()-20)*1.0 / count;
        x=10;
        for i in range(0, len(self.tempData)):
            self.tempLineX.curveTo( x, self.tempData[i][0]+ baseY-100, 0)
            self.tempLineY.curveTo( x, self.tempData[i][1]+ baseY,    0)
            self.tempLineZ.curveTo( x, self.tempData[i][2]+ baseY+100, 0)
            x+= step

    def update(self):

        if self.d.isReady():
            self.d.update()
            self.updateLine(of.ofGetHeight()/2, 100)
            ang = self.d.getAngle()
            self.airplane.setOrientation(of.ofVec3f( ang[0], ang[2], -ang[1]))
            # print ang
            # self.airplane.setRotation( 0, ang[0], 1,0,0)
            # self.airplane.setRotation( 1, ang[1], 0,1,0)
            # self.airplane.setRotation( 2, ang[2], 0,0,1)

            # print "Year:{0} Month:{1} Day:{2} Hour:{3} Minute:{4} Second:{5} miliSecond:{6}".format(self.d.getYear(), self.d.getMonth(), self.d.getDay(), self.d.getHour(), self.d.getMinute(), self.d.getSecond(), self.d.getMiliSecond())
            # print "加速度:{0} {1} {2}".format(*self.d.getAcc())
            # print "角速度:{0} {1} {2}".format(*self.d.getAngularVel())
            # print " 角度:{0} {1} {2}".format(*self.d.getAngle())
            # print " 磁场:{0} {1} {2}".format(*self.d.getMag())
            # print "四元数:{0} {1} {2} {3}".format(*self.d.getQuat())
            # print "温度:{0} ".format(self.d.getTemperature())
            # print "压力:{0} Pa {1} m".format( *self.d.getPress() )
            # print "GPS:{0} {1} {2}".format( *self.d.getGPS() )
            # print "经纬度:{0} {1}".format( *self.d.getLonLat() )
            # print buffer
    def draw(self):
        of.ofNoFill()
        self.tempLineX.draw()
        self.tempLineY.draw()
        self.tempLineZ.draw()

        self.cam.begin()
        of.ofDrawGrid(50, 10, False, False, True, False)
        self.material.begin()
        self.airplane.draw()
        # of.ofRotate(180, 1,0,0)
        # of.ofRotate(90, 0,1,0)
        # self.mod.drawFaces()
        # self.airplane.draw( of.OF_MESH_WIREFRAME )
        self.material.end()
        of.ofDrawAxis(50)
        self.cam.end()

app = App()
app.runGL(800,600, of.OF_WINDOW)