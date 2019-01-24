package oop.uebung13;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.io.File;

public class WebsiteAnalyzer extends Application {
    public static void main(String[] args){
        Application.launch(WebsiteAnalyzer.class);
    }


    @Override
    public void start(Stage primaryStage) throws Exception{
        VBox root = FXMLLoader.load(getClass().getResource("layout.fxml"));


        Scene scene = new Scene(root);
        scene.getStylesheets().add(new File("/Users/jimeneztuero/Intellij/src/oop/uebung13/style.css").toURI().toURL().toExternalForm());
        primaryStage.setScene(scene);
        primaryStage.setTitle("Website Analyzer");
        primaryStage.show();
    }
}
