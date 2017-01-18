MODULENAME = pyOF
OFDIR=/Users/my/dev/of0.9.8
# 编译相关
INCLUDE0  = -I/System/Library/Frameworks/Python.framework/Versions/2.7/include/python2.7
INCLUDE1a = -I${OFDIR}/libs
INCLUDE1  = -I${OFDIR}/libs/openFrameworks
INCLUDE2  = -I${OFDIR}/libs/openFrameworks/3d
INCLUDE3  = -I${OFDIR}/libs/openFrameworks/app
INCLUDE4  = -I${OFDIR}/libs/openFrameworks/communication
INCLUDE5  = -I${OFDIR}/libs/openFrameworks/events
INCLUDE6  = -I${OFDIR}/libs/openFrameworks/gl
INCLUDE7  = -I${OFDIR}/libs/openFrameworks/graphics
INCLUDE8  = -I${OFDIR}/libs/openFrameworks/math
INCLUDE9  = -I${OFDIR}/libs/openFrameworks/sound
INCLUDE10 = -I${OFDIR}/libs/openFrameworks/types
INCLUDE11 = -I${OFDIR}/libs/openFrameworks/utils
INCLUDE12 = -I${OFDIR}/libs/openFrameworks/video
INCLUDE13 = -I${OFDIR}/libs/boost/include
INCLUDE14 = -I${OFDIR}/libs/cairo/include/cairo
INCLUDE15 = -I${OFDIR}/libs/fmodex/include
INCLUDE16 = -I${OFDIR}/libs/FreeImage/include
INCLUDE17 = -I${OFDIR}/libs/freetype/include
INCLUDE18 = -I${OFDIR}/libs/freetype/include/freetype2
INCLUDE19 = -I${OFDIR}/libs/glew/include
INCLUDE20 = -I${OFDIR}/libs/glfw/include
INCLUDE21 = -I${OFDIR}/libs/glut/include
INCLUDE22 = -I${OFDIR}/libs/openssl/include
INCLUDE23 = -I${OFDIR}/libs/poco/include
INCLUDE24 = -I${OFDIR}/libs/rtAudio/include
INCLUDE25 = -I${OFDIR}/libs/tess2/include
INCLUDE26 = -I${OFDIR}/libs/utf8cpp/include
INCLUDE27 = -I${OFDIR}/addons/ofxGui/src
INCLUDE28 = -I${OFDIR}/addons/ofxAssimpModelLoader/libs/assimp/include
INCLUDE29 = -I${OFDIR}/addons/ofxAssimpModelLoader/src
INCLUDE30 = -I${OFDIR}/addons/ofxOpenCv/libs/opencv/include
INCLUDE31 = -I${OFDIR}/addons/ofxOpenCv/src

INCLUDES  = -I.. ${INCLUDE31} ${INCLUDE30} ${INCLUDE29} ${INCLUDE28} ${INCLUDE0} ${INCLUDE1a} ${INCLUDE1} ${INCLUDE2} \
            ${INCLUDE3} ${INCLUDE4} ${INCLUDE5} ${INCLUDE6} ${INCLUDE7} ${INCLUDE8} ${INCLUDE9} ${INCLUDE10} ${INCLUDE11} \
            ${INCLUDE12} ${INCLUDE13} ${INCLUDE14} ${INCLUDE15} ${INCLUDE16} ${INCLUDE17} ${INCLUDE18} ${INCLUDE19} \
            ${INCLUDE20} ${INCLUDE21} ${INCLUDE22} ${INCLUDE23} ${INCLUDE24} ${INCLUDE25} ${INCLUDE26} ${INCLUDE27}

CFLAGS    = -std=c++14 -mmacosx-version-min=10.7  -w -Os -rdynamic -undefined -DNDEBUG -dynamic_lookup -fvisibility=hidden \
            -mtune=native -stdlib=libc++ -Wall -fexceptions -fpascal-strings  -D__MACOSX_CORE__ -x objective-c++ -MMD -MP -MF

# 链接相关
LIBDIRS = -L/usr/local/lib -L/Users/my/lib -L${OFDIR}/libs/glut/lib/osx/GLUT.framework/Versions/A
LIBS    = -lc++ -lSystem -lopenframeworks -lboost -lboost_system -lboost_filesystem  -lcairo-script-interpreter \
		  -lpixman-1 -lcairo -lpng -lfmodex -lfreeimage -lfreetype -lglew -lglfw3 -lssl -lcrypto -lPocoData \
		  -lPocoDataSQLite -lPocoUtil -lPocoFoundation -lPocoCrypto -lPocoJSON -lPocoMongoDB -lPocoNet \
		  -lPocoNetSSL -lPocoXML -lPocoZip -lrtAudio -ltess2

OPENCVLIB = ${OFDIR}/addons/ofxOpenCv/libs/opencv/lib/osx/opencv.a
ASSIMPLIB = ${OFDIR}/addons/ofxAssimpModelLoader/libs/assimp/lib/osx/assimp.a
OFXLIBS = ${OPENCVLIB} ${ASSIMPLIB}

# -framework QuickTime 只支持32位系统 i386
FRAMES  = -framework Accelerate -framework AGL -framework AppKit -framework ApplicationServices -framework AudioToolbox \
          -framework AVFoundation -framework Cocoa -framework CoreAudio -framework CoreFoundation -framework CoreMedia \
          -framework CoreServices -framework CoreVideo -framework IOKit -framework OpenGL -framework QuartzCore \
          -framework QTKit -framework GLUT

# LDFLAGS = -arch x86_64 -dynamiclib
LDFLAGS = -arch x86_64 -dynamiclib
# LDFLAGS = -shared 
BINs = ofxBaseGui.o ofxButton.o ofxGuiGroup.o ofxLabel.o ofxPanel.o ofxSlider.o ofxSliderGroup.o ofxToggle.o \
       ofxAssimpModelLoader.o ofxAssimpTexture.o ofxAssimpMeshHelper.o ofxAssimpAnimation.o \
       ofxCvImage.o ofxCvShortImage.o ofxCvFloatImage.o ofxCvColorImage.o ofxCvGrayscaleImage.o ofxCvHaarFinder.o ofxCvContourFinder.o


# all:
# 	cython ./queue.pyx
# 	gcc -g -O2       -fpic `python-config --cflags` -c ./queue.c       -o queue.o
# 	gcc -dynamiclib -lcalg `python-config --libs`   -L/usr/local/lib      queue.o  -o queue.dylib 
# 	ln -s ./queue.dylib queue.so
# linux:
# 	cython ./queue.pyx
# 	gcc -g -O2 -fpic   `python-config --cflags` -c ./queue.c -o queue.o
# 	gcc -shared -lcalg `python-config --libs` -L/usr/local/lib queue.o -o queue.so 
maxosx: ${BINs}
	# cython --cplus ./${MODULENAME}.pyx
	# g++ ${CFLAGS}  ${INCLUDES} -c ./ofApp.cpp -o ofApp.o
	g++ ${CFLAGS}  ${INCLUDES} -c ../${MODULENAME}.cpp  -o ${MODULENAME}.o
	g++ ${LDFLAGS} ${LIBS} ${OFXLIBS} `python-config --libs` ${LIBDIRS} ${FRAMES} ${MODULENAME}.o ${BINs} -o ${MODULENAME}.so
	# g++ ${CFLAGS}  ${INCLUDES} -c ./main.cpp            -o main.o 
	# g++ -arch x86_64 ${LIBS} `python-config --libs` ${LIBDIRS} ${FRAMES} ofApp.o main.o -o ${MODULENAME}
ofxBaseGui.o: 
	g++ ${CFLAGS}  ${INCLUDES} -c ${OFDIR}/addons/ofxGui/src/ofxBaseGui.cpp     -o ofxBaseGui.o
ofxButton.o: 
	g++ ${CFLAGS}  ${INCLUDES} -c ${OFDIR}/addons/ofxGui/src/ofxButton.cpp      -o ofxButton.o
ofxGuiGroup.o: 
	g++ ${CFLAGS}  ${INCLUDES} -c ${OFDIR}/addons/ofxGui/src/ofxGuiGroup.cpp    -o ofxGuiGroup.o
ofxLabel.o: 
	g++ ${CFLAGS}  ${INCLUDES} -c ${OFDIR}/addons/ofxGui/src/ofxLabel.cpp       -o ofxLabel.o
ofxPanel.o: 
	g++ ${CFLAGS}  ${INCLUDES} -c ${OFDIR}/addons/ofxGui/src/ofxPanel.cpp       -o ofxPanel.o
ofxSlider.o: 
	g++ ${CFLAGS}  ${INCLUDES} -c ${OFDIR}/addons/ofxGui/src/ofxSlider.cpp      -o ofxSlider.o
ofxSliderGroup.o: 
	g++ ${CFLAGS}  ${INCLUDES} -c ${OFDIR}/addons/ofxGui/src/ofxSliderGroup.cpp -o ofxSliderGroup.o
ofxToggle.o: 
	g++ ${CFLAGS}  ${INCLUDES} -c ${OFDIR}/addons/ofxGui/src/ofxToggle.cpp      -o ofxToggle.o
	
ofxAssimpModelLoader.o:
	g++ ${CFLAGS}  ${INCLUDES} -c ${OFDIR}/addons/ofxAssimpModelLoader/src/ofxAssimpModelLoader.cpp  -o ofxAssimpModelLoader.o
ofxAssimpTexture.o:
	g++ ${CFLAGS}  ${INCLUDES} -c ${OFDIR}/addons/ofxAssimpModelLoader/src/ofxAssimpTexture.cpp      -o ofxAssimpTexture.o
ofxAssimpMeshHelper.o:
	g++ ${CFLAGS}  ${INCLUDES} -c ${OFDIR}/addons/ofxAssimpModelLoader/src/ofxAssimpMeshHelper.cpp   -o ofxAssimpMeshHelper.o
ofxAssimpAnimation.o:
	g++ ${CFLAGS}  ${INCLUDES} -c ${OFDIR}/addons/ofxAssimpModelLoader/src/ofxAssimpAnimation.cpp   -o ofxAssimpAnimation.o

ofxCvImage.o:
	g++ ${CFLAGS}  ${INCLUDES} -c ${OFDIR}/addons/ofxOpenCv/src/ofxCvImage.cpp          -o ofxCvImage.o
ofxCvShortImage.o:
	g++ ${CFLAGS}  ${INCLUDES} -c ${OFDIR}/addons/ofxOpenCv/src/ofxCvShortImage.cpp     -o ofxCvShortImage.o
ofxCvFloatImage.o:
	g++ ${CFLAGS}  ${INCLUDES} -c ${OFDIR}/addons/ofxOpenCv/src/ofxCvFloatImage.cpp     -o ofxCvFloatImage.o
ofxCvColorImage.o:
	g++ ${CFLAGS}  ${INCLUDES} -c ${OFDIR}/addons/ofxOpenCv/src/ofxCvColorImage.cpp     -o ofxCvColorImage.o
ofxCvGrayscaleImage.o:
	g++ ${CFLAGS}  ${INCLUDES} -c ${OFDIR}/addons/ofxOpenCv/src/ofxCvGrayscaleImage.cpp -o ofxCvGrayscaleImage.o
ofxCvHaarFinder.o:
	g++ ${CFLAGS}  ${INCLUDES} -c ${OFDIR}/addons/ofxOpenCv/src/ofxCvHaarFinder.cpp     -o ofxCvHaarFinder.o
ofxCvContourFinder.o:
	g++ ${CFLAGS}  ${INCLUDES} -c ${OFDIR}/addons/ofxOpenCv/src/ofxCvContourFinder.cpp  -o ofxCvContourFinder.o

clean:
	rm ./*.o ./*.so ./*.dylib