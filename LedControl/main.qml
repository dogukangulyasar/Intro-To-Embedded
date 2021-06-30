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
                        onClicked: led.setStatusOn()
                }

                Button {
                        id: btnOff
                        anchors.left: btnOn.right
                        text: "Off"
                        onClicked: led.setStatusOff()
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
        }


}
