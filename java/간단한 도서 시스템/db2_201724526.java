import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;
enum OperationKind {ADD,REMOVE,MODIFIED , QUIT,INVALID} ;
public class db2_201724526 {
	private static OperationKind getOperation(String operation) {
		OperationKind kind = OperationKind.INVALID ;
		if ( operation.equalsIgnoreCase("ADD"))
			kind = OperationKind.ADD ;
		else if ( operation.equalsIgnoreCase("REMOVE"))
			kind = OperationKind.REMOVE ;
		else if ( operation.equalsIgnoreCase("MODIFIED"))
			kind = OperationKind.MODIFIED ;
		else if ( operation.equalsIgnoreCase("QUIT"))
			kind = OperationKind.QUIT ;
		return kind ;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Connection conn;
		Statement stmt=null;
		String op;
		String title,publisher,author,information,newTitle,newPublisher,newAuthor,currentTitle,currentPublisher,currentAuthor;
		int id,newId,currentId;
		
		Scanner scan=new Scanner(System.in);
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn=DriverManager.getConnection("jdbc:mysql://localhost:3306/bookdb","root","3751");
			System.out.println("DB 연결 성공");
			stmt=conn.createStatement();

		while(true) {
			printTable(stmt);
			System.out.print("Enter Operation String!(ADD, REMOVE, MODIFIED, QUIT)");
			op=scan.next();
			OperationKind kind=getOperation(op);
			if(kind==OperationKind.QUIT) break;
			switch(kind) {
			case ADD:
				System.out.print("Enter the ID to register");
				id=scan.nextInt();
				System.out.print("Enter the title to register");
				title=scan.next();
				System.out.print("Enter the publisher to register");
				publisher=scan.next();
				System.out.print("Enter the author to register");
				author=scan.next();
				stmt.executeUpdate("insert into book(id,title,publisher,author) values('"+id+"','"+title+"','"+publisher+"','"+author+"')");
				break;
			case REMOVE:
				System.out.print("Enter the ID to remove");
				int removeId=scan.nextInt();
				stmt.executeUpdate("delete from book where id="+removeId+"");
				break;
			case MODIFIED:
				System.out.print("Enter the information to be modified");
				information=scan.next();
				if(information.equals("id")) {
					System.out.print("Enter current ID");
					currentId = scan.nextInt();
					System.out.print("Enter the ID to be modified");
					newId = scan.nextInt();
					stmt.executeUpdate("update book set id='"+newId+"' where id='"+currentId+"'");
				}else if(information.equals("title")) {
					System.out.print("Enter current title");
					currentTitle = scan.next();
					System.out.print("Enter the title to be modified");
					newTitle = scan.next();
					stmt.executeUpdate("update book set title='"+newTitle+"' where title='"+currentTitle+"'");
				}else if(information.equals("publisher")) {
					System.out.print("Enter current publisher");
					currentPublisher = scan.next();
					System.out.print("Enter the publisher to be modified");
					newPublisher = scan.next();
					stmt.executeUpdate("update book set publisher='"+newPublisher+"' where publisher='"+currentPublisher+"'");
				}else if (information.equals("author")) {
					System.out.print("Enter current author");
					currentAuthor = scan.next();
					System.out.print("Enter the author to be modified");
					newAuthor = scan.next();
					stmt.executeUpdate("update book set author='"+newAuthor+"' where author='"+currentAuthor+"'");
				}
				break;
			default:
				break;	
			}
		}
		System.out.println("종료합니다.");
		}catch(ClassNotFoundException e)
		{
			System.out.println("JDBC드라이버 로드 실패");
		}
		catch(SQLException e)
		{
			System.out.println("SQL 실행 에러");
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
