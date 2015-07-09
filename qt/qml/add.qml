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
	property string task_category_name: ""
	
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
					textRole: "name"
					model: {
						// OBTENER LISTA DE CATEGORIAS
						// PASAR VALOR DE CATEGORIAS VIA CONNECTIONS
						var array=MagnasTareas.getCategoriesOnly();
						array.push({name: "New category", uuid: "new"});
						return array;
					}
					onCurrentIndexChanged: {
						if(currentIndex==count-1){
							new_category.visible=true;
						}else{
							new_category.visible=false;
						}
					}
				}
            }
            
            Item{
				id: new_category
				Layout.fillWidth: true
				Layout.fillHeight: true
				visible: false
				Rectangle{
					height: 25
					Layout.fillWidth: true
					color: "#6E9985"
					TextEdit{
						id: category_name
						focus: true
						text: "New category"
						selectByMouse: true
						selectedTextColor: Qt.rgba(0,122,65,0.4)
						selectionColor: "#007A41"
						font.pointSize: 16
					}
				}
            }
            
            // AÑADIR TIPOS DE DRIVERS
            
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
						if(new_category.visible){
							task_category= generateUUID();
							task_category_name = category_name.text;
						}else{
							task_category=MagnasTareas.getCategoriesOnly()[category.currentIndex].uuid;
							task_category_name =MagnasTareas.getCategoriesOnly()[category.currentIndex].name;
						}
						add_dialog.close();
					}
				}
			}
        }
     }
    function generateUUID(){
		var d = new Date().getTime();
		var uuid = 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function(c) {
			var r = (d + Math.random()*16)%16 | 0;
			d = Math.floor(d/16);
			return (c=='x' ? r : (r&0x3|0x8)).toString(16);
		});
		return uuid;
	}
}
