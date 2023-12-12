import QtQuick
import QtQuick.Controls
import QtLocation
import QtPositioning


Rectangle {

    Plugin {
        id: mapPlugin
        name: "osm"
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(27.6989, 84.4304)
        zoomLevel: 10

        property var markerCoordinates: [
            { lat: 27.6989, lon: 84.4304 },
            // Add more coordinate objects as needed
        ]

        property real markerSize: 15 // Initial scale factor for the marker




        // MouseArea for zooming with the mouse wheel
               MouseArea {
                   anchors.fill: parent
                   onWheel: {
                       // Adjust the zoom level based on the wheel delta
                       map.zoomLevel += wheel.angleDelta.y / 120
                   }
                  }
        MapItemView {
            model: ListModel {
                id: markerListModel
                Component.onCompleted: {
                    // Populate the ListModel from markerCoordinates
                    for (var i = 0; i < map.markerCoordinates.length; i++) {
                        markerListModel.append({ coordinate: QtPositioning.coordinate(map.markerCoordinates[i].lat, map.markerCoordinates[i].lon) });
                    }
                }
            }

            delegate: MapQuickItem {
                anchorPoint.x: image.width / 2
                anchorPoint.y: image.height
                coordinate: model.coordinate

                // Use a Behavior to smoothly animate the changes in markerScale

                Behavior on width {
                                    SpringAnimation {
                                        spring: 2
                                        damping: 0.4
                                    }
                                }

                Behavior on height {
                        SpringAnimation {
                            spring: 2
                            damping: 0.4
                        }
                    }

                sourceItem: Image {
                    id: image
                    source: "marker.png"
                    width: map.markerSize
                    height: map.markerSize
                }
            }
        }
    }

}
