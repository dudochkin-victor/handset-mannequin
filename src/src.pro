include (../common.pri)
TEMPLATE = app
QT += opengl
MOC_DIR = .moc
OBJECTS_DIR = .obj
MGEN_OUTDIR = .gen

target.path = $$M_INSTALL_BIN

SOURCES += main.cpp

# HEADERS += \

MAKE_CLEAN += $$OBJECTS_DIR/*.o
MAKE_DISTCLEAN += \
    $$MOC_DIR/* $$MOC_DIR \
    $$OBJECTS_DIR/* $$OBJECTS_DIR \
    $$MGEN_OUTDIR/* $$MGEN_OUTDIR \

# Install
INSTALLS += target
