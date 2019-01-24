package oop.uebung13;

import javafx.application.Application;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.text.Text;
import javafx.stage.Stage;



public class ControllerTest extends Application {

    Thread thread;

    public static void main(String[] args){
        Application.launch(ControllerTest.class);
    }


    @Override
    public void start(Stage primaryStage) throws Exception{
        VBox root = FXMLLoader.load(getClass().getResource("controllerlayout.fxml"));


        Scene scene = new Scene(root, 500, 500);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Meine Anwendung");
        primaryStage.show();
    }

}


