QT += widgets

SOURCES += Database.cpp \
           	     globals.cpp \
                       mainwindow.cpp \
                       screenlogin.cpp \
                       titlegameboard.cpp \
	     screenloginai.cpp \
	     signupscreen.cpp \
	     main.cpp \
	     sqlite3.c

HEADERS += Database.h \
	     sqlite3.h \
           	     globals.h \
           	     mainwindow.h \
           	     screenlogin.h \
	     screenloginai.h \
	     signupscreen.h \
           	     titlegameboard.h

FORMS += mainwindow.ui \
                   screenlogin.ui \
	screenloginai.ui \
	signupscreen.ui \
         	titlegameboard.ui