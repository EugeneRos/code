import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

/**
 * This is the main class of the TrafficLights application.
 * The application receives two inputs, the time of the first state in seconds and the time of the second state in seconds, then it activates a thread that alternates between these
 * two states staying in each state the numbers of seconds that were inputted by the user.
 * @author Yevgeni Roskin
 */
public class TrafficLightsMain extends Application {
    
    private boolean isWindowClosed = false;
    
    @Override
    public void start(Stage primaryStage) throws Exception {
        
        
        FXMLLoader loader = new FXMLLoader(getClass().getResource("FXMLTrafficLights.fxml"));
        Parent root = loader.load();
        FXMLTrafficLightsController controller = loader.getController();
        controller.setWindowClosedCallback(() -> isWindowClosed = true);        //changes the value of the variable isWindowClosed for ending the loops
        
        primaryStage.setOnCloseRequest(event -> {
            
            isWindowClosed = true;
            controller.setIsWindowClosed(isWindowClosed);
        });
        
        
        Scene scene = new Scene(root);
        
        primaryStage.setTitle("Traffic Lights");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
    
}
