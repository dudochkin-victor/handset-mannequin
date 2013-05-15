include (common.pri)
TEMPLATE = subdirs
SUBDIRS = src

# Theme files
theme.files = ./theme/*
theme.path = $$M_THEME_DIR/$$TARGET/
theme.CONFIG += no_check_exist

INSTALLS += \
    theme
