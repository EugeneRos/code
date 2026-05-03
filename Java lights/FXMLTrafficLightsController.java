
import java.util.Scanner;
import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Rectangle;


/**
 *
 * This is the controller class for the TrafficLights application.
 * @author Yevgeni Roskin
 */
public class FXMLTrafficLightsController extends Thread {

     @FXML
    private Circle circLight1;

    @FXML
    private Circle circLight2;

    @FXML
    private Circle circLight3;

    @FXML
    private Circle circLight4;

    @FXML
    private Circle circLight5;

    @FXML
    private Circle circLight6;

    @FXML
    private Circle circLight7;

    @FXML
    private Circle circLight8;

    @FXML
    private Rectangle rectLight1;

    @FXML
    private Rectangle rectLight2;

    @FXML
    private Rectangle rectLight3;

    @FXML
    private Rectangle rectLight4;

    @FXML
    private Rectangle rectLight5;

    @FXML
    private Rectangle rectLight6;

    @FXML
    private Rectangle rectLight7;

    @FXML
    private Rectangle rectLight8;
    
    

    int timeGreen, timeRed;
    boolean lightsCondition = false;
    private boolean isVisible = false;
    
    
    private CircleLights circLights;
    private RectangleLights rectLights;
    
    private boolean isWindowClosed;

    private Runnable windowClosedCallback;

    public void setIsWindowClosed(boolean isWindowClosed) {     //for ending the loop when exiting the window
        this.isWindowClosed = isWindowClosed;
        if (isWindowClosed && windowClosedCallback != null) {
            windowClosedCallback.run();
        }
    }

    public void setWindowClosedCallback(Runnable callback) {
        this.windowClosedCallback = callback;
    }
    
    /**
     * Initializes the controller class.
     */
    @FXML
    public void initialize() {
        
        Circle[] circ = new Circle[]{circLight1, circLight2, circLight3, circLight4, circLight5, circLight6, circLight7, circLight8};
        Rectangle[] rect = new Rectangle[]{rectLight1, rectLight2, rectLight3, rectLight4, rectLight5, rectLight6, rectLight7, rectLight8};
        circLights = new CircleLights(circ);    //initializes the CircleLights object
        rectLights = new RectangleLights(rect); //initializes the RectangleLights object
        System.out.println("Please insert the time in seconds for green light and the time for red light");
        Scanner scanner = new Scanner(System.in);
        timeGreen = scanner.nextInt();  //time for the first state
        timeRed = scanner.nextInt();    //time for the second state
        scanner.close();
        
        
        
        start();
        
        
    }
    
    
    
    @Override
    public void run() {
        super.run();
        
            
        while(!isWindowClosed)  //isWindowClosed changes when the user exits the window
        {
            while (!lightsCondition) 
            {
                lightsCondition = !lightsCondition;     //changes lightsCondition for the next iteration
                rectLights.setState(false);   //changes the rectLights to the first state
                circLights.setState(false);   //changes the circLights to the first state

                try {
                    Thread.sleep(timeGreen * 1000);     //sleeps for the amount of seconds the user entered for the first state
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            while (lightsCondition)
            {
                lightsCondition = !lightsCondition;
                rectLights.setState(true);      //changes the rectLights to the second state
                circLights.setState(true);      //changes the circLights to the second state

                try {
                    Thread.sleep(timeRed * 1000);       //sleeps for the amount of seconds the user entered for the second state
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
        rectLights.setIsWindowClosed(isWindowClosed);   //sets the isWindowClosed variable in rectLights to true when the window is closed, to exit the loop in that object
}
    
}
