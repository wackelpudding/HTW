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
import javafx.util.StringConverter;
import javafx.util.converter.NumberStringConverter;

import java.util.Random;


public class ListenerTest extends Application {

    Thread thread;

    public static void main(String[] args){
        Application.launch(ListenerTest.class);
    }


    @Override
    public void start(Stage primaryStage) throws Exception{
        //VBox root = FXMLLoader.load(getClass().getResource("layout.fxml"));

        VBox root = new VBox();

        root.setSpacing(10.0);

        Label label = new Label("Hier steht ein Text");
        Button b1 = new Button("Knopf");

        b1.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                boolean visible = label.visibleProperty().get();
                label.visibleProperty().set(!visible);

            }
        });

        Slider s1 = new Slider();
        Circle c1 = new Circle();
        c1.setFill(Color.RED);
        c1.setRadius(50);


        s1.valueProperty().addListener(new ChangeListener<Number>() {
            @Override
            public void changed(ObservableValue<? extends Number> observable, Number oldValue, Number newValue) {
                double d1 = new Random().nextDouble();
                double d2 = new Random().nextDouble();
                double d3 = new Random().nextDouble();
                c1.setFill(new Color(d1,d2,d3,1));

            }
        });

        root.getChildren().addAll(b1,label,s1,c1);
        Scene scene = new Scene(root, 250, 250);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Meine Anwendung");
        primaryStage.show();
    }

}


