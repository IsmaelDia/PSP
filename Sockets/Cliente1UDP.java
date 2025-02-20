import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class Cliente1UDP {
    public static void main(String[] args) throws Exception {
        //------------------------------------------------------------------------
        InetAddress destino = InetAddress.getLocalHost();
        int port = 12345;
        
        Scanner teclado = new Scanner(System.in);
        //pido numero por pantalla
        System.out.println("Escriba un número ");
        String numero = teclado.next();
        byte [] mensaje = numero.getBytes();
       
        
        //Datagrama
        DatagramPacket envio = new DatagramPacket(mensaje, mensaje.length, destino, port);
        DatagramSocket socket = new DatagramSocket();

        socket.send(envio);
        //-------------------------------------------------------------------------------------

        byte[] bufer = new byte[1024];
        DatagramPacket respuesta = new DatagramPacket(bufer, bufer.length);
        socket.receive(respuesta);

        String factorial = new String(respuesta.getData());

        System.out.println("Factorial recibido de cliente 2 " + factorial);

        socket.close();

    }
}