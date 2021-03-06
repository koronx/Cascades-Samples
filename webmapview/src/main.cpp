/* Copyright (c) 2013 Research In Motion Limited.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#include "WebMaps.hpp"

#include <bb/cascades/AbstractPane>
#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>

#include <QLocale>
#include <QTranslator>

using namespace bb::cascades;

int main(int argc, char **argv)
{
    //! [0]
    qmlRegisterUncreatableType<WebMaps>("com.example.webmapview", 1, 0, "WebMaps", "Access to enums");
    //! [0]

    Application app(argc, argv);

    // localization support
    QTranslator translator;
    const QString filename = QString::fromLatin1("webmapview_%1").arg(QLocale().name());
    if (translator.load(filename, "app/native/qm"))
        app.installTranslator(&translator);

    //! [1]
    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(&app);
    qml->setContextProperty("_webMaps", new WebMaps(&app));
    //! [1]

    AbstractPane *root = qml->createRootObject<AbstractPane>();
    app.setScene(root);

    return app.exec();
}
