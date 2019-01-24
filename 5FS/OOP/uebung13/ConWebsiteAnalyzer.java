package oop.uebung13;


import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.text.Text;
import oop.uebung10.*;

import java.io.IOException;


public class ConWebsiteAnalyzer {

    @FXML
    Button closeButton;
    @FXML
    TextField inputUrl;
    @FXML
    TextField inputSearch;
    @FXML
    Button searchButton;
    @FXML
    Text resultField;


    @FXML
    void search(ActionEvent event){
        try {
            String test = new Downloader().download(inputUrl.textProperty().getValue());
            StringAnalyzer salyzer = new StringAnalyzer(test);
            salyzer.countWords();

            salyzer.getCountOf(inputSearch.getText());
            resultField.getStyleClass().clear();
            resultField.getStyleClass().add("blue");

            resultField.textProperty().setValue("Das Wort '" + inputSearch.getText() + "' wurde so oft gefunden: " + salyzer.getCountOf(inputSearch.getText()));
        }
        catch (IOException ioe) {
            resultField.textProperty().setValue("Bitte geben sie eine gültige URL ein!");
            resultField.getStyleClass().clear();
            resultField.getStyleClass().add("red");
        }

    }

    @FXML
    void exit(ActionEvent event){
        Platform.exit();
    }
}
