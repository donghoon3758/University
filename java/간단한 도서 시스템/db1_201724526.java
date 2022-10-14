import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class db1_201724526 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Connection conn;
		Statement stmt=null;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn=DriverManager.getConnection("jdbc:mysql://localhost:3306/bookdb","root","3751");
			System.out.println("DB ���� ����");
			
			stmt=conn.createStatement();
		  	stmt.executeUpdate("insert into book(id,title,publisher,author) values('0','Harry Potter','Bloomsbury','J. K. Rowling')");
		  	stmt.executeUpdate("insert into book(id,title,publisher,author) values('1','The Lord of the Rings','Allen & Unwin','J. R. R. Tolkein')");
		  	stmt.executeUpdate("insert into book(id,title,publisher,author) values('2','Pride and Prejudice','T. Egerton Kingdom','Jane Austen')");
		  	printTable(stmt);
		  	stmt.executeUpdate("update book set title='Pride& Prejudice',author='���� ����ƾ' where title='Pride and Prejudice'");
		  	printTable(stmt);
			stmt.executeUpdate("delete from book where title='Pride& Prejudice'");
			printTable(stmt);
		}catch(ClassNotFoundException e)
		{
			System.out.println("JDBC����̹� �ε� ����");
		}
		catch(SQLException e)
		{
			System.out.println("SQL ���� ����");
		}
	}
	private static void printTable(Statement stmt) throws SQLException
	{
		ResultSet rs = stmt.executeQuery("select * from book");
		while(rs.next()) {
			System.out.print(rs.getString("id"));
			System.out.print("\t|\t"+rs.getString("title"));
			System.out.print("\t|\t"+rs.getString("publisher"));
			System.out.println("\t|\t"+rs.getString("author"));
		}
		System.out.println("----------------------------------------------------------------------------------------");
	}

}