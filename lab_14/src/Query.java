 import java.sql.*;
public class Query {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Listing all table name in Database!");
	    Connection con = null;
	    ResultSet rs=null;
	    Statement statement = null;
	 
	    String url = "jdbc:mysql://cse.unl.edu/";
	    String db = "dsimpson";
	    String driver = "com.mysql.jdbc.Driver";
	    String user = "dsimpson";
	    String pass = "t64__W";
	    
	 
	    try{
	        Class.forName(driver);
	        con = DriverManager.getConnection(url+db, user, pass);
	        try{
	            DatabaseMetaData dbm = con.getMetaData();
	            String[] types = {"TABLE"};
	        
	            rs = dbm.getTables(null,null,"%",types);
	            System.out.println("Table name:");
	            while (rs.next()){
	              String table = rs.getString("TABLE_NAME");
	              System.out.println(table);
	            }
	            System.out.println("\nAll songs by Linkin Park:");
	            statement = con.createStatement();
	            ResultSet results = statement.executeQuery("SELECT SongTitle FROM Songs natural join AlbumSongs natural join Albums natural join Bands WHERE BandName='Linkin Park'");
	            while(results.next()){
	            	String table2 = results.getString("SongTitle");
	            	System.out.println(table2);
	            }
	 
	            System.out.println("\nUpdating...");
	            int update = statement.executeUpdate("UPDATE Albums SET AlbumTitle='Kids' WHERE AlbumTitle='Kid'");
	            int bands = statement.executeUpdate("INSERT INTO Bands (BandName) VALUES " +"('Random Band')",Statement.RETURN_GENERATED_KEYS);
	            ResultSet BandID = statement.getGeneratedKeys();
	            BandID.next();
	            // key = BandID
	            String key = BandID.getString(0);
	            // insert bands with BandID
	            int bandMusicians = statement.executeUpdate("INSERT INTO BandMusicians (BandId) VALUES ('" +key+"')",Statement.RETURN_GENERATED_KEYS);
	            // insert album with BandID
	            ResultSet MusicianID = statement.getGeneratedKeys();
	            MusicianID.next();
	            int album = statement.executeUpdate("INSERT INTO Albums (AlbumTitle ,BandID) VALUES ('" +key+",'Album1')",Statement.RETURN_GENERATED_KEYS);
	            ResultSet AlbumID = statement.getGeneratedKeys();
	            AlbumID.next();
	            key = MusicianID.getString(0);
	            int musicians = statement.executeUpdate("INSERT INTO Musicians (MusicianID,MusicianFirstName,MusicianLastName) VALUES ('" +key+",'Alex','Rock')",Statement.RETURN_GENERATED_KEYS);
	            int Song1 = statement.executeUpdate("INSERT INTO Songs (SongTitle) VALUES ('Song1')",Statement.RETURN_GENERATED_KEYS);
	            ResultSet Song1ID = statement.getGeneratedKeys();
	            Song1ID.next();
	            int Song2 = statement.executeUpdate("INSERT INTO Songs (SongTitle) VALUES ('Song2')",Statement.RETURN_GENERATED_KEYS);
	            ResultSet Song2ID = statement.getGeneratedKeys();
	            Song2ID.next();

	            String albumKey =AlbumID.getString(0);
	            String Song11 = Song1ID.getString(0);
	            String Song22 = Song2ID.getString(0);

	            int AlbumSong1 = statement.executeUpdate("INSERT INTO Songs (SongID,AlbumID,TrackNumber,TrackLength) VALUES ('"+Song11+"','"+albumKey+"1,100)");
	            int AlbumSong2 = statement.executeUpdate("INSERT INTO Songs (SongID,AlbumID,TrackNumber,TrackLength) VALUES ('"+Song22+"','"+albumKey+"2,200)");
	          }
	          catch (SQLException s){
	            System.out.println("Not any table in the database");
	          }
		      finally{
		        con.close();
		      }
	        }
	        catch (Exception e){
	          e.printStackTrace();
	        }

	      }
	    }