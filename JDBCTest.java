import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.SQLException;

class JDBCTest {

private static final String url = "jdbc:mysql://localhost";

private static final String user = "root";

private static final String password = "alto@5755";

public static void main(String args[]) {
try {
Class.forName("com.mysql.jdbc.Driver");
Connection con = DriverManager.getConnection(url, user, password);
System.out.println("Success");

} catch (Exception e) {
e.printStackTrace();
}
}
}
