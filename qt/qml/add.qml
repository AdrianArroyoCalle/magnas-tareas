import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Window 2.0
import QtQuick.Dialogs 1.0
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.1

Window{
	id: add_dialog
	flags: Qt.Dialog
	title: qsTr("Nueva tarea")
	modality: Qt.WindowModal
	width: 300
	height: 400
	color: "#003D21"
	
	property string task_title: ""
	property string task_description: ""
	property string task_category: ""
	
	ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10

        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 10
            
			ColumnLayout{
				Layout.fillWidth: true
				Layout.fillHeight: true
				spacing: 5
				Text{
					height: 25
					Layout.fillWidth: true
					text: qsTr("Title")
					color: "white"
					font.pointSize: 20
				}
				Rectangle{
					height: 25
					Layout.fillWidth: true
					color: "#6E9985"
					TextEdit{
						id: title
						focus: true
						text: "Hola"
						selectByMouse: true
						selectedTextColor: Qt.rgba(0,122,65,0.4)
						selectionColor: "#007A41"
						font.pointSize: 16
					}
				}
			}
			ColumnLayout{
				Layout.fillWidth: true
				Layout.fillHeight: true
				spacing: 5
				Text{
					height: 25
					Layout.fillWidth: true
					text: qsTr("Description")
					color: "white"
					font.pointSize: 20
				}
				Rectangle{
					height: 100
					Layout.fillWidth: true
					color: "#6E9985"
					TextEdit{
						anchors.fill: parent
						id: description
						text: "Hola"
						selectByMouse: true
						selectedTextColor: Qt.rgba(0,122,65,0.4)
						selectionColor: "#007A41"
						wrapMode: TextEdit.Wrap
						//font.family: "Helvetica"
						//textFormat: TextEdit.RichText
					}
				}
			}
            
            ColumnLayout{
				Layout.fillWidth: true
				Layout.fillHeight: true
				spacing: 5
				
				Text{
					height: 25
					Layout.fillWidth: true
					text: qsTr("Category")
					color: "white"
					font.pointSize: 20
				}
				
				
				ComboBox{
					id: category
					anchors.fill: parent
					model: {
						// OBTENER LISTA DE CATEGORIAS
						// PASAR VALOR DE CATEGORIAS VIA CONNECTIONS
						return ["New category"];
					}
				}
            }
            
            Rectangle{
				height: 30
				Layout.fillWidth: true
				color: "#003D21"
				Button{
					text: qsTr("Save")
					style: ButtonStyle{
						/*background: Rectangle{
						
						}*/
						label: Text{
							renderType: Text.NativeRendering
							verticalAlignment: Text.AlignVCenter
							horizontalAlignment: Text.AlignHCenter
							font.family: "Helvetica"
							font.pointSize: 15
							color: "black"
							text: control.text
						}
					}
					anchors.centerIn: parent
					onClicked: {
						task_title= title.text;
						task_description=description.text;
						task_category= "sqlite-3";
						add_dialog.close();
					}
				}
			}
        }
     }
}
