public class Principal {

    public static void main(String[] args) {
        Thread tarefa1 = new Tarefa1(); //Herança
        Thread tarefa2 = new Thread(new Tarefa2()); //Implementação
        
        tarefa1.start();
        tarefa2.start();
    }
}
