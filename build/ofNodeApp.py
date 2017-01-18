import pyOF as of

class Car:
    def __init__(self):
        self.acc=0
        self.vel=0
        self.geo = of.ofBoxPrimitive()
        self.material = of.ofMaterial()
        self.lightL = of.ofLight()
        self.lightR = of.ofLight()

    def setup(self):
        self.material.setDiffuseColor( of.ofFloatColor.white )
        self.lightL.setParent( self.geo )
        self.lightR.setParent( self.geo )
        self.lightL.move(-45,20, -51)
        self.lightR.move(45, 20, -51)
        self.lightL.tilt(-20)
        self.lightR.tilt(-20)
        self.lightL.setSpotlight()
        self.lightR.setSpotlight()
        self.lightL.setDiffuseColor( of.ofFloatColor.yellow)
        self.lightR.setDiffuseColor( of.ofFloatColor.yellow)
        self.lightL.setup()
        self.lightR.setup()

    def draw(self):
        self.material.begin()
        self.geo.draw()
        self.material.end()
        # self.lightR.draw()
        # self.lightL.draw()

    def update(self):
        self.vel += self.acc
        self.vel *= 0.9
        self.acc *= 0.99
        velVector = self.geo.getZAxis() * -1*self.vel
        self.geo.move( velVector )

    def brake(self):
        self.acc -= 0.1
    def accellerate(self):
        self.acc += 0.1
    def steer(self, dir):
        self.geo.rotate(dir, 0,1,0)

class App(of.BaseApp):
    def setup(self):
        of.ofSetWindowTitle("ofNode Example01")
        of.ofBackground(80,100,150,255)
        of.ofEnableSmoothing()
        of.ofEnableDepthTest()
        # of.ofEnableAlphaBlending()
        # of.ofSetCircleResolution(50)

        self.light1 = of.ofLight()
        self.light1.setup()
        self.light1.setDiffuseColor( of.ofFloatColor.red)
        self.light1.setPosition(-100, 300, 100)

        self.light2 = of.ofLight()
        self.light2.setup()
        self.light2.setDiffuseColor( of.ofFloatColor.blue)
        self.light2.setPosition(100, 100, -100)

        self.cam = of.ofEasyCam()
        self.plane = of.ofPlanePrimitive()
        self.plane.set(10000, 10000)
        self.plane.rotate(270, 1,0,0)
        self.plane.move(0, -49, 0)

        self.roadMaterial = of.ofMaterial()
        self.roadMaterial.setDiffuseColor( of.ofFloatColor.gray )
        self.roadMaterial.setShininess(0.01)
        self.car = Car()
        self.car.setup()

    def update(self):
        self.car.update()

    def draw(self):
        of.ofBackgroundGradient(of.ofColor.azure, of.ofColor.lightSlateGray, of.OF_GRADIENT_CIRCULAR)
        self.cam.begin()
        self.roadMaterial.begin()
        self.plane.draw()
        self.roadMaterial.end()
        self.car.draw()
        self.cam.end()



app = App()
app.runGL(1024, 768, of.OF_WINDOW)