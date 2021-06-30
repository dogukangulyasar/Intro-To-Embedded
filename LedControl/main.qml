import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
Window {
        width: 640
        height: 480
        visible: true
        title: qsTr("Hello World")
        Item {
                Button {
                        id: btnOn
                        text: "On"
                        onClicked: function () {
                                led.setStatusOn()
                                bulbOn.visible = true
                                bulbOff.visible = false
                        }
                }
                Button {
                        id: btnOff
                        anchors.left: btnOn.right
                        text: "Off"
                        onClicked: function() {
                                led.setStatusOff()
                                bulbOn.visible = false
                                bulbOff.visible = true
                        }
                }

                Text{
                        anchors.left: btnOff.right
                        id: txtInfo
                        text: "Status: "
                        visible: true
                }

                Text{
                        anchors.left: txtInfo.right
                        id: txtStatus
                        text: led.status
                        visible: true
                }
                Image {
                        id: bulbOn
                        visible: led.status==="on" ? true : false
                        source: "images/aspi13190700012.jpg"
                        anchors.left: txtStatus.right
                }
                Image {
                        id: bulbOff
                        visible: led.status==="off" ? true : false
                        source: "images/freestock_563599207.jpg"
                        anchors.left: txtStatus.right
                }
        }


}
