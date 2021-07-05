import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
Window {
        property string btnPin: app.buttonPinValue
        property string ledPin: app.ledPinValue
        width: 640
        height: 480
        id: wndMain
        visible: true
        title: qsTr("Led Control")
                TextArea{
                        id: txtLedNum
                        placeholderText: "Enter Led Pin number"
                }
                TextArea{
                        id: txtButtonNum
                        anchors.left: txtLedNum.right
                        anchors.leftMargin: 5
                        placeholderText: "Enter Button Pin number"
                        width: 300
                }

                Button {
                        id: btnGetPins
                        anchors.leftMargin: 5
                        anchors.top: txtLedNum.bottom
                        text: "Get Pin Numbers"
                        onClicked: function() {
                                app.setPins(txtLedNum.text, txtButtonNum.text)
                        }
                }
                        Text {
                                id: ledPinInfo
                                anchors.top: btnGetPins.bottom
                                text: "Led Pin: "
                        }

                        Text {
                                id: ledPin
                                anchors.top: btnGetPins.bottom
                                anchors.left: ledPinInfo.right
                                text: app.ledPin ? app.ledPin : "Not defined"
                        }

                        Text {
                                id: buttonPinInfo
                                anchors.top: btnGetPins.bottom
                                anchors.left: ledPin.right
                                anchors.leftMargin: 5
                                text: "Button Pin: "
                        }
                        Text {
                                id: buttonPin
                                anchors.left: buttonPinInfo.right
                                anchors.leftMargin: 5
                                anchors.top: btnGetPins.bottom
                                text: app.buttonPin ? app.buttonPin : "Not defined"
                        }

        }

