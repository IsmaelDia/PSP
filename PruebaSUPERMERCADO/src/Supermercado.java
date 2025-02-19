class Supermercado {
    private static final boolean[] cajas = {true, true, true}; // true = libre, false = ocupada

    // Método sincronizado para entrar en una caja libre
    public synchronized int entrarCaja(String nombre) {
        int cajaAsignada = -1;

        while (cajaAsignada == -1) {
            for (int i = 0; i < cajas.length; i++) {
                if (cajas[i]) { // Si la caja está libre
                    cajas[i] = false; // Marcar la caja como ocupada
                    cajaAsignada = i + 1; // Guardar el número de la caja (1, 2 o 3)
                    System.out.println(nombre + " entra en la Caja " + cajaAsignada);
                    break;
                }
            }
            if (cajaAsignada == -1) {
                try {
                    wait(); // Espera hasta que una caja se libere
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    throw new RuntimeException(e);
                }
            }
        }
        return cajaAsignada; // Devuelve el número de la caja asignada
    }

    // Método sincronizado para salir de la caja
    public synchronized void salirCaja(String nombre, int cajaAsignada) {
        cajas[cajaAsignada - 1] = true; // Liberar la caja (1 -> índice 0, 2 -> índice 1, etc.)
        System.out.println(nombre + " termina su compra y sale de la Caja " + cajaAsignada);
        notifyAll(); // Despertar a los clientes en espera
    }
}
