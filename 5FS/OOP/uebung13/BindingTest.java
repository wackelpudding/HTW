package oop.uebung13;

import javafx.application.Application;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.util.StringConverter;
import javafx.util.converter.NumberStringConverter;

import java.util.Random;


public class BindingTest extends Application {

    Thread thread;

    public static void main(String[] args){
        Application.launch(BindingTest.class);
    }


    @Override
    public void start(Stage primaryStage) throws Exception{
        //VBox root = FXMLLoader.load(getClass().getResource("layout.fxml"));

        VBox root = new VBox();

        root.setSpacing(10.0);
        Slider slider = new Slider();
        Text text = new Text("Hallo");
        text.textProperty().bind(slider.valueProperty().asString());

        TextField tf1 = new TextField();
        TextField tf2 = new TextField();
        tf1.textProperty().bindBidirectional(tf2.textProperty());

        Slider slider2 = new Slider();
        TextField tf3 = new TextField();

        StringConverter<Number> converter = new NumberStringConverter();
        tf3.textProperty().bindBidirectional(slider2.valueProperty(), converter);

        Slider slider3 = new Slider();
        IntegerProperty myInt = new SimpleIntegerProperty();
        slider3.valueProperty().bind(myInt);

        thread = new Thread(new Runnable() {
            @Override
            public void run() {
                while(true) {
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    myInt.setValue(new Random().nextInt(100));
                }
            }
        });

        thread.start();


        root.getChildren().addAll(slider,text, tf1, tf2, slider2, tf3, slider3);
        Scene scene = new Scene(root, 250, 250);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Meine Anwendung");
        primaryStage.show();
    }
    @Override
    public void stop() throws Exception{
        super.stop();
        thread.join();
    }
}


