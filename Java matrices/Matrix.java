/**
 * This is a class that implements a matrix multiplication.
 * @author Yevgeni Roskin
 */
public class Matrix extends Thread{
    private int[][] m1;
    private int[][] m2;
    private int row;
    private int col;
    private Monitor m;
    private int id;

    
    public Matrix(int[][] m1, int[][] m2, int row, int col, Monitor m, int id)
    {
        this.m1 = m1;
        this.m2 = m2;
        this.row = row;
        this.col = col;
        this.m = m;
        this.id = id;
    }
    
    public void run()
    {
        super.run();
        int product = 0;
        
        for(int i = 0,j = 0; j < m1[0].length; i++,j++)     //goes through the row of the first matrix and the column of the second matrix multiplies the values and sums them
        {                                                   //it does the multiplication for the specific cell in the resulting matrix
                product += m1[row][j] * m2[i][col];
        }
        m.waitForPrint(id);     //method that gets this thread to wait to its turn before it prints
        if(col == 0)    //starts a new line when reaches a new row in the first matrix
        {
            System.out.println("");
        }
        System.out.print(product + " ");      //prints the product of multiplication
        m.donePrint();     //advances the next id that is allowed to print
        
            
    }
    
    
}
