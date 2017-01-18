#-- coding:utf-8--#
import pyOF as of

class App(of.BaseApp):
    def setup(self):
        of.ofSetWindowTitle("OpenGL01")
        of.ofBackground(80,100,150,255)
        of.ofEnableSmoothing()
        of.ofEnableAlphaBlending()
        of.ofSetCircleResolution(50)
        of.ofSetRectMode(of.OF_RECTMODE_CENTER)

        self.a = of.ofPolyline()
        self.c = of.ofPolyline()
        self.a.addVertex(100, 100,0 )
        self.a.addVertex(150, 150, 0)
        self.a.addVertex(200, 100, 0)
        self.a.addVertex(250, 150, 0)
        self.a.addVertex(300, 100, 0)
        self.b = of.ofPolyline()
        self.b.curveTo(350, 100, 0)
        self.b.curveTo(350, 100, 0)
        self.b.curveTo(400, 150, 0)
        self.b.curveTo(450, 100, 0)
        self.b.curveTo(500, 150, 0)
        self.b.curveTo(550, 100, 0)
        self.b.curveTo(550, 100, 0)
        # of.ofEnableAntiAliasing()
    def update(self):
        pass
    def draw(self):
        # a =  of.ofRandom(50,250)
        of.ofSetColor( 250 )
        of.ofFill()
        of.ofSetLineWidth(1)
        of.ofDrawRectangle(100,100,100,100)
        of.ofDrawCircle(250,100, 50)
        of.ofDrawEllipse(400,100, 80,100)
        of.ofDrawTriangle(500, 150, 550, 50, 600, 150)
        of.ofDrawLine(700, 50, 700, 150)

        of.ofNoFill()
        of.ofSetLineWidth(10)
        of.ofDrawRectangle(100,250,100,100)
        of.ofDrawCircle(250,250, 50)
        of.ofDrawEllipse(400,250, 80,100)
        of.ofDrawTriangle(500, 300, 550, 200, 600, 300)
        of.ofDrawLine(700, 200, 700, 300)

        of.ofSetColor( 170,100,40 )
        self.a.draw()
        self.b.draw()

app = App()
# app.run(800, 600, of.OF_WINDOW)
app.runGL(800, 600, of.OF_WINDOW)