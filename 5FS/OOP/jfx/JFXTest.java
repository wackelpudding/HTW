package oop.jfx;

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.io.File;

public class JFXTest extends Application {

    public static void main(String[] args){
        Application.launch();
    }

    @Override
    public void start(Stage primaryStage) throws Exception{
/*
        VBox root = new VBox();
        HBox hbox = new HBox();
        Text myText = new Text("Hello World!");

        root.getChildren().add(myText);
        Button myButton = new Button("Klick mich!");
        root.getChildren().add(myButton);
        root.getChildren().add(hbox);

        TextField myTextField = new TextField();
        hbox.getChildren().add(myTextField);

        Slider mySlider = new Slider(0,100,50);
        hbox.getChildren().add(mySlider);

        ChoiceBox<String> myChoiceBox = new ChoiceBox<>();

        ObservableList<String> list = FXCollections.<String>observableArrayList("a", "b", "c");
        myChoiceBox.setItems(list);
        root.getChildren().add(myChoiceBox);

        RadioButton myRadio1 = new RadioButton("Möglichkeit 1");
        RadioButton myRadio2 = new RadioButton();
        myRadio2.setText("Möglichkeit 2");

        ToggleGroup group = new ToggleGroup();
        group.getToggles().addAll(myRadio1,myRadio2);

        root.getChildren().addAll(myRadio1,myRadio2);

*/

/*
        TilePane root = new TilePane();

        for (int i = 1; i <= 30; i++) {
            if (i == 6){
                Button button = new Button("Button" + i);
                button.setPrefWidth(200);
                button.setPrefHeight(100);
                root.getChildren().add(button);
            } else {
                root.getChildren().add(new Button("Button" + i));
            }
        }
*/

        VBox root = FXMLLoader.load(getClass().getResource("layout.fxml"));

        Scene scene = new Scene(root);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Meine Anwendung");
        primaryStage.show();
    }
}
