import java.io.*;
import java.util.Formatter;
import java.util.Scanner;
import java.sql.*;

public class Report {
	    
    
    public void userInput(){
		System.out.println("\nYou can view Companion information, add employees'" + "', and run the grading using this system.");
		System.out.println("Please select one of the following options (1-5):");
		System.out.println("1. Print Grade Report for All Companions\n2. Run Grade Roster for the Course\n3. Print Statistics for an Exam\n4. Print Statistics for Final Course Grade\n5. Quit\n");
		
		Scanner choice = null;
		choice = new Scanner(System.in);
		
		//Choosing event case
		String quitVariable = "QUIT";
		String userOption = choice.next().toUpperCase();
		if(userOption.equals(quitVariable)){
						System.out.println("Thank you for using the Grading System");
		 				System.exit(0);		
		}
			int myChoice = Integer.parseInt(userOption);
		try{
			switch(myChoice){
			case 1:
				System.out.println("option 1");
				optionOne();
				userInput();
				break;
			}
		}catch (Exception e){
	          e.printStackTrace();
        }
    }
    
    
    
    public void optionOne() throws SQLException, ClassNotFoundException{

        ResultSet noOfStudents = statement.executeQuery("SELECT COUNT(`testID`) FROM exams");
        noOfStudents.next();
        String totalStudents = noOfStudents.getString(1);
        System.out.println("Total number of students: " + totalStudents);
        
        //ResultSet averageScore = statement.executeQuery("");
        System.out.println("Average score: ");
		System.out.print("   ");
		System.out.format("%6s   %6s","LastName","FirstName");
		System.out.print("   ");
		System.out.format("  %6s   %6s"," Final Grade","Overall %\n");

    }//End optionOne
    

    

    
    
	public static void main(String[] args) throws IOException {
		Report grades = new Report();
		grades.userInput();
		grades.optionOne();
	}
	
}
