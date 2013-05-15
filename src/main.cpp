/*
 * mannequin - MeeGo placeholder application
 * Copyright (c) 2009, 2010 Intel Corporation.
 *
 * This program is licensed under the terms and conditions of the
 * Apache License, version 2.0.  The full text of the Apache License is at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 */

#include <QtGui>
#include <MApplication>
#include <MApplicationWindow>
#include <MApplicationPage>
#include <MTextEdit>

int main(int argc, char *argv[])
{

    MApplication a(argc, argv, QString("mannequin"));

    QString s = "";
    QString name = a.arguments().at(0);
    if (a.arguments().size() > 1) {
        int idx = 0;
        if (a.arguments().size() > 2)
            idx = 1;
        name = a.arguments().at(idx);

        QStringList msg;
        for (int i=idx+1; i<a.arguments().size(); i++)
            msg << a.arguments().at(i);
        s = msg.join(" ");
    }
    else
        s = QString("This is a placeholder for the %1 Application.").arg(name);

    MApplicationWindow w;
    w.setObjectName("MannequinWindow");
    w.show();

    MApplicationPage *p = new MApplicationPage();
    p->setObjectName("MannequinPage");
    MTextEdit  *n = new MTextEdit(MTextEditModel::MultiLine,s);
    n->setObjectName("MannequinMessage");
    n->setReadOnly(true);
    n->setEnabled(false);

    p->setTitle(name);
    p->setCentralWidget(n);

    p->appear();

    return a.exec();
}
