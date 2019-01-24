package oop.uebung13;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;

public class MyController {

    @FXML
    Button myButton;

    @FXML
    void handleMyButtonClicked(ActionEvent event){
        double oldWidth = myButton.getWidth();
        myButton.setPrefWidth(oldWidth * 1.5);
    }
}
