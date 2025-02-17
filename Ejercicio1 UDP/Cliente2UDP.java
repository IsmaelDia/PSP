import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Cliente2UDP {
    public static void main(String[] args) throws Exception {
  
        byte [] bufer = new byte[1024];

        DatagramSocket socket = new DatagramSocket(54321);
        System.out.println("Cliente 2 esperando al servidor");

        DatagramPacket recibo = new DatagramPacket(bufer, bufer.length);

        socket.receive(recibo);
        System.out.println("recibido");
        String paquete= new String(recibo.getData(), 0, recibo.getLength());
        int numero = Integer.parseInt(paquete);

        int factorial = 1;
        for (int i = 1; i <= numero; i++) 
        {
            factorial *= i;
        }

        //-------------------------------------------------------------------

        int puertoServidor = recibo.getPort(); 
        InetAddress destino = recibo.getAddress();
        byte[] datosAEnviar = String.valueOf(factorial).getBytes();
        System.out.println("Enviando factorial calculado");
        DatagramPacket envio = new DatagramPacket(datosAEnviar, datosAEnviar.length, destino, puertoServidor);

        socket.send(envio);

        socket.close();
    }
}