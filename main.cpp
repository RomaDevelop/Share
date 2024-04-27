
#include <iostream>
using namespace std;

#include <QDomDocument>
#include <QDebug>

int main()
{
	QDomDocument doc;

	QDomElement root = doc.createElement("root");
	doc.appendChild(root);

	QDomElement root2 = doc.createElement("root2");
	doc.appendChild(root2);

	QDomElement tag = doc.createElement("tag");
	root.appendChild(tag);
	tag.setAttribute("11","22\"sdvsdv\"fvdfbdfb\n");
	tag.setAttribute("111","22");
	tag.setAttribute("1111","22");

	QDomElement tag2 = doc.createElement("tag2");
	root.appendChild(tag2);

	QDomElement tag3 = doc.createElement("tag3");
	root.appendChild(tag3);

	QDomElement tag4 = doc.createElement("tag4");
	root2.appendChild(tag4);

	QDomText t = doc.createTextNode("tag text");
	tag.appendChild(t);

	//QDomAttr attr;
	root.setAttribute("1","2");

	cout << doc.toString().toStdString() << endl;

	QString errMsg;
	int errLine, errCol;
	cout << doc.setContent(doc.toString(), &errMsg, &errLine, &errCol) << endl;
	cout << QString("ConfigFile::Constructor errMsg: " + errMsg).toStdString() << endl;
	cout << QString("ConfigFile::Constructor errLine: " + QString::number(errLine)).toStdString() << endl;
	cout << QString("ConfigFile::Constructor errCol: " + QString::number(errCol)).toStdString() << endl;

	return 0;
}
