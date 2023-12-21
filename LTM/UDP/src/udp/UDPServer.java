package udp;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

/**
 *
 * @author PhucQuach
 */
public class UDPServer {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws SocketException, IOException {
        DatagramSocket server = new DatagramSocket(2000);
        System.out.println("Server is running...");
        while (true) {
            byte[] buf = new byte[1024];
            DatagramPacket dpReq = new DatagramPacket(buf, buf.length);
            server.receive(dpReq);
            String s = new String(dpReq.getData()).trim();
            System.out.println(s);
            
            String strRes = new StringBuilder(s).reverse().toString();
            System.out.println(strRes);
            DatagramPacket dpRes = new DatagramPacket(strRes.getBytes(), strRes.length(), dpReq.getAddress(), dpReq.getPort());
            server.send(dpRes);
        }
    }
    
}
