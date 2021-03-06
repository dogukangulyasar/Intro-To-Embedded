import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
        width: 640
        height: 480
        visible: true
        title: qsTr("Led Controller")
        Image {
                id: imgOn
                source: "on.png"
                visible: app.ledStatus === "1" ? true:false
                x: (parent.width - width) / 2
                y: (parent.height - height) / 2
                MouseArea {
                           anchors.fill: parent
                           onClicked: function(){
                                   app.setOff(txtLed.text, "off");
                                   imgOff.visible = true
                                   imgOn.visible = false
                           }
                }
        }
        Image {
                id: imgOff
                source: "off.png"
                visible: true
                x: (parent.width - width) / 2
                y: (parent.height - height) / 2
                MouseArea {
                           anchors.fill: parent
                           onClicked: function(){
                                   app.setOn(txtLed.text, "on");
                                   imgOff.visible = false
                                   imgOn.visible = true
                           }

                }
        }
        Item {
                TextArea {
                        id: txtLed
                        placeholderText: "Enter Led Pin No"
                }
                TextArea {
                        id: txtLedGrd
                        placeholderText: "Enter Led Grd No"
                        anchors.left: txtLed.right
                }
                TextArea {
                        id: txtButton
                        placeholderText: "Enter Button Pin No"
                        anchors.left: txtLedGrd.right
                }
                TextArea {
                        id: txtButtonGrd
                        placeholderText: "Enter Button Grd No"
                        anchors.left: txtButton.right
                }
                Button {
                        id: btnSubmit
                        text: "Set pin numbers"
                        anchors.top: txtLed.bottom
                        onClicked: function(){
                                app.pinSetted(txtLed.text, txtLedGrd.text, txtButton.text, txtButtonGrd.text);
                        }
                }
                Text{
                        id: txtLedInfo
                        text: "Led: "
                        anchors.top: btnSubmit.bottom
                }
                Text{
                        id: txtLedValue
                        text: app.ledPin
                        anchors.top: btnSubmit.bottom
                        anchors.left: txtLedInfo.right
                }
                Text{
                        id: txtButtonInfo
                        text: "Button: "
                        anchors.top: txtLedInfo.bottom
                }
                Text{
                        id: txtButtonValue
                        text: app.buttonPin
                        anchors.top: txtLedValue.bottom
                        anchors.left: txtButtonInfo.right
                }

        }
}
