/**
 * This is the main class for the MatrixMultiplication application. It receives the sizes of two matrices, generates matrices using random, prints the matrices and prints the product.
 * matrix of the multiplication.
 * @author Yevgeni Roskin
 */
import java.util.Random;
import java.util.Scanner;

public class MatrixMain {
    private static final int UPPER_BOUND = 11;
    
    public static void main(String[] args)
    {
        Monitor m = new Monitor();
        Random rand = new Random();
        Scanner scanner = new Scanner(System.in);
        int rowsFirst, columnsFirst, rowsSecond, columnsSecond, i, j;
        
        System.out.println("Please insert the sizes of the matrices, 4 numbers: (rowsFirst) (columsFirst) (rowsSecond) (columnsSecond), columsFirst has to be equal to rowsSecond ");
        
        rowsFirst = scanner.nextInt();      //receives the sizes of the matrices
        columnsFirst = scanner.nextInt();
        rowsSecond = scanner.nextInt();
        columnsSecond = scanner.nextInt();
        
        scanner.close();
        
        if(columnsFirst != rowsSecond)
        {
            System.out.println("Invalid matrix multiplication, columsFirst has to be equal to rowsSecond");
            return;
        }
        
        System.out.println("");
        
        int[][] m1 = new int[rowsFirst][columnsFirst];
        int[][] m2 = new int[rowsSecond][columnsSecond];
        int[][] m3 = new int[rowsFirst][columnsSecond];
        
        for(i=0;i<rowsFirst;i++)        //fills the first matrix with values
        {
            for(j=0;j<columnsFirst;j++)
            {
                m1[i][j] = rand.nextInt(UPPER_BOUND);
                System.out.print(m1[i][j] + " ");
            }
            System.out.println("");
        }
        
        System.out.println("");
        
        for(i=0;i<rowsSecond;i++)       //fills the second matrix with values
        {
            for(j=0;j<columnsSecond;j++)
            {
                m2[i][j] = rand.nextInt(UPPER_BOUND);
                System.out.print(m2[i][j] + " ");
            }
            System.out.println("");
        }
        
        Matrix[][] matrix = new Matrix[rowsFirst][columnsSecond];
        
        System.out.println("\nThe result of the multiplication: ");
        
        int id = 0;
        for(i=0;i<rowsFirst;i++)
        {
            for(j=0;j<columnsSecond;j++)
            {
                matrix[i][j] = new Matrix(m1, m2, i, j, m, id);    //initializes a matrix object in the [i][j] cell
                matrix[i][j].start();       //starts the thread
                id++;   //increases id to assign a new id for the new object in the next cell
            }
            
        }
        
        
    }
    
    
}
