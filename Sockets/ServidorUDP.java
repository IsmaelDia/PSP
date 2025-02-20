import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class ServidorUDP {
    public static void main(String[] args) throws Exception {
        byte[] bufer = new byte[1024];

        DatagramSocket socket = new DatagramSocket(12345);

        System.out.println("Esperando a cliente 1");
        DatagramPacket recibo = new DatagramPacket(bufer, bufer.length);

        socket.receive(recibo);
        String paquete= new String(recibo.getData(), 0, recibo.getLength());
        int numero = Integer.parseInt(paquete);

        //---------------------------------------------------------------------

        InetAddress direccionCliente2 = InetAddress.getLocalHost(); 
        int puertoCliente2 = 54321; 
        byte[] datosAEnviar = String.valueOf(numero).getBytes();
        System.out.println("Enviando numero "  + numero + " al cliente2");
        DatagramPacket envio = new DatagramPacket(datosAEnviar, datosAEnviar.length, direccionCliente2, puertoCliente2);

        socket.send(envio);
        System.out.println("Esperando factorial de cliente2");
        //--------------------------------------------------------------------------------------

        DatagramPacket respuesta = new DatagramPacket(bufer, bufer.length);
        socket.receive(respuesta);

        String factorial = new String(recibo.getData(), 0, respuesta.getLength());

        //--------------------------------------------------------------------

        System.out.println("Enviando factorial al cliente1");
        DatagramPacket enviofinal = new DatagramPacket(factorial.getBytes(), factorial.getBytes().length, recibo.getAddress(), recibo.getPort());

        socket.send(enviofinal);

        socket.close();
    }
}