import java.io.*;
import java.net.*;
//import java.net.Socket;
import java.util.Date;
//import java.net.ServerSocket;
public class httpserver {
public static void main(String[] args) { 
	try {
ServerSocket serverSocket = new ServerSocket(8091);
System.out.println("HTTP Server on 'http://localhost:8090' is ready \n");
while(true) {
try (Socket clientSocket = serverSocket.accept()){
System.out.println(clientSocket.getInetAddress() + " " + clientSocket.getPort());
System.out.println(Inet4Address.getLocalHost().getHostAddress());
Date today = new Date();
String response = "HTTP/1.1 200 OK\r\n\r\n" + today;
response =response +  "\nServer: Gopi's Server\n\r";
response = response + "Connection: close\n\r";
response = response + "1";
clientSocket.getOutputStream().write(response.getBytes("UTF-8"));
}}} 
catch(Exception e) 
{ 
	System.out.println("ERROR: " + e.getMessage()); 
	//System.exit(1);
}}}