import QtQuick 2.15
import QtQuick.Controls 2.15
import QtLocation 5.15
import QtPositioning 5.15

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Map Example"

    Plugin {
        id: mapPlugin
        name: "osm"
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(37.7749, -122.4194)
        zoomLevel: 10

        // MouseArea for zooming with the mouse wheel
        MouseArea {
            anchors.fill: parent
            onWheel: {
                // Adjust the zoom level based on the wheel delta
                map.zoomLevel += wheel.angleDelta.y / 120
            }
        }
    }
}
