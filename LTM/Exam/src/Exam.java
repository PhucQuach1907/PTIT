import java.io.*;
import java.net.Socket;

public class Exam {

    public static void main(String[] args) {
        String serverAddress = "10.21.96.15";
        int serverPort = 806;
        
        try  {
            Socket socket = new Socket(serverAddress, serverPort);
            InputStream inputStream = socket.getInputStream();
            OutputStream outputStream = socket.getOutputStream();

            String studentCode = "B20DCCN513";
            int qCode = 700;
            String request = studentCode + ";" + qCode;
            outputStream.write(request.getBytes());

            byte[] buffer = new byte[1024];
            int bytesRead = inputStream.read(buffer);
            String response = new String(buffer, 0, bytesRead);
            
            String[] numbers = response.split("\\|");
            int sum = 0;
            for (String number : numbers) {
                sum += Integer.parseInt(number);
            }

            System.out.println("Sum: " + sum);
            outputStream.write(String.valueOf(sum).getBytes());
            outputStream.flush();
            
            socket.close();
        } catch (IOException e) {
        }
    }
}
