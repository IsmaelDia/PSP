import java.util.logging.Level;
import java.util.logging.Logger;

class Cliente extends Thread {
    private final Supermercado supermercado;
    private final String nombre;

    public Cliente(Supermercado supermercado, String nombre) {
        this.supermercado = supermercado;
        this.nombre = nombre;
    }

    @Override
    public void run() {
        int cajaAsignada = supermercado.entrarCaja(nombre); // Obtiene una caja libre
        try {
            Thread.sleep(5000); // Simula el pago durante 5 segundos
        } catch (InterruptedException ex) {
            Logger.getLogger(Cliente.class.getName()).log(Level.SEVERE, null, ex);
        }
        supermercado.salirCaja(nombre, cajaAsignada); // Libera la caja
    }
}

