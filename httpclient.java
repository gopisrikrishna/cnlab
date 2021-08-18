import java.io.*;
import java.net.*;
public class httpclient {
public static void main(String[] args) {
try 
{
	URL url = new URL("http://localhost:8091");
	HttpURLConnection con = (HttpURLConnection) url.openConnection();
	BufferedReader in = new BufferedReader(new InputStreamReader(con.getInputStream()));
	String temp;
	while((temp = in.readLine()) != null)
	System.out.println(temp);
	in.close();
	con.disconnect();
} 
catch(Exception e) 
{
	e.printStackTrace();
	System.exit(1);
}}}