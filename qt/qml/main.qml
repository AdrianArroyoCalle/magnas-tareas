import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Window 2.0
import QtQuick.Dialogs 1.0
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.1

ApplicationWindow {
    title: qsTr("Magnas Tareas")
    width: 800
    height: 600
    visible: true
    id: app
    
    Component{
		id: ui_button 
		ButtonStyle {
			label: Text {
				renderType: Text.NativeRendering
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				font.family: "Helvetica"
				font.pointSize: 18
				color: "black"
				text: control.text
			}
		}
	}

	ListModel{
		id: categoryModel
	}
    
    ColumnLayout{
		spacing: 6
    
		Layout.fillWidth: true
		Layout.fillHeight: true
		
		RowLayout{
			id: toolbar
			anchors.top: parent.top
			Layout.preferredHeight: 50
			Layout.fillWidth: true
			Layout.preferredWidth: app.width
			
			Button {
				text: qsTr("New task") //TODO - Put 64x64 icons
				height: parent.height
				style: ui_button
			}
			Button {
				text: qsTr("New category")
				height: parent.height
				style: ui_button
			}
			Button {
				text: qsTr("Sync")
				height: parent.height
				style: ui_button
			}
			Button {
				text: qsTr("Setup online accounts")
				height: parent.height
				style: ui_button
			}
		}
    
		RowLayout{
			id: content
			Layout.fillWidth: true
			Layout.preferredHeight: app.height - 50
			
			ListView{
				id: categories
				Layout.preferredWidth: app.width / 4
				Layout.fillHeight: true
				header: Text{
					text: "Categories"
					font.bold: true
					font.pixelSize: 20
				}
				footer: Text{
					text: "Categories: <b>" + categories.count + "</b>" 
				}
				model: categoryModel
				delegate: Text {
					text: name

					MouseArea {
						anchors.fill: parent
						onClicked: categories.currentIndex = index
					}
				}
				highlight: Rectangle {
					color: "mediumseagreen";
					radius: 5
				}
				focus: true
			}

			//Tasks
			ListView{
				id: tasks
				objectName: "tasks"
				signal selectTask(int index)
				Layout.preferredWidth: app.width / 4
				Layout.fillHeight: true
				header: Text{
					text: "Tasks"
					font.bold: true
					font.pixelSize: 20
				}
				footer: Text{
					text: "Tasks: <b>" + tasks.count + "</b>" 
				}
				model: ListModel{
					id: taskModel
					ListElement{
						name: "Tareas Smith"
						uuid: "local-1"
					}
					ListElement{
						name: "Soporte básico de lectura"
						uuid: "local-2"
					}
				}
				delegate: Text {
					property variant myData: model
					text: name

					MouseArea {
						anchors.fill: parent
						onClicked: {
							tasks.currentIndex = index
							//tasks.selectTask(index)
							taskTitle.text=tasks.currentItem.myData.name
							taskContent.text=MagnasTareas.readTask(tasks.currentItem.myData.uuid)
						}
					}
				}
				highlight: Rectangle {
					color: "lightsteelblue";
					radius: 5
				}
				focus: true
			}
			
			Rectangle{
				anchors.top: parent.top
				id: task
				Layout.preferredWidth: app.width / 2
				width: app.width / 2
				ColumnLayout{
					Text{
						id: taskTitle
						objectName: "taskTitle"
						text: "No task selected"
						font.bold: true
						font.pixelSize: 30
					}
					Item{
						width: app.width / 2
						height: parent.height
						TextEdit{
							id: taskContent
							objectName: "taskContent"
							readOnly: true
							width: app.width / 2
							wrapMode: TextEdit.Wrap
							text: "No task selected"
							font.family: "Helvetica"
							font.pixelSize: 15 
							selectByMouse: true
							textFormat: TextEdit.RichText
							clip: true
					}	}
				}
			}

		}
	}
	function addVisualCategory(name,uuid){
		console.log("Adding "+name)
		categoryModel.append({"name": name, "uuid": uuid})
	}
	function refresh(){
		MagnasTareas.getCategories()
	}
}
