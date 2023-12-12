import QtQuick 2.15
import QtQuick.Controls 2.15
import QtLocation 5.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "Map Application"

    StackView {
        id: stackView
        initialItem: signInPage // Display the SignInPage.qml initially

        Component {
            id: signInPage
            Rectangle {
                width: 200
                height: 100
                color: "lightblue"
                Text {
                    text: "Sign In Page"
                    anchors.centerIn: parent
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: stackView.push(mapPage)
                }
            }
        }

        Component {
            id: mapPage
            Map {
                anchors.fill: parent
                plugin: Plugin {
                    name: "osm" // This is an example using OpenStreetMap
                }
                center: QtPositioning.coordinate(37.7749, -122.4194) // Set the initial center of the map
                zoomLevel: 10 // Set the initial zoom level
            }
        }
    }
}
