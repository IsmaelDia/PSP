public class SupermercadoHilos {
    public static void main(String[] args) {
        Supermercado supermercado = new Supermercado();

        // Crear y ejecutar 15 clientes
        for (int i = 1; i <= 15; i++) {
            Cliente cliente = new Cliente(supermercado, "Cliente " + i);
            cliente.start();
        }
    }
}
