/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */
package udp;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.util.Scanner;

/**
 *
 * @author PhucQuach
 */
public class UDPClient {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) throws SocketException, UnknownHostException, IOException {
        DatagramSocket client = new DatagramSocket();
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap mot string bat ky: ");
        String s = sc.next();
        DatagramPacket dpReq = new DatagramPacket(s.getBytes(), s.length(), InetAddress.getByName("localhost"), 2000);
        client.send(dpReq);
        
        byte[] buf = new byte[1024];
        DatagramPacket dpRes = new DatagramPacket(buf, buf.length);
        client.receive(dpRes);
        System.out.println(new String(dpRes.getData()).trim());
    }
}
