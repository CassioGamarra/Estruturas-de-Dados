public class Tarefa1 extends Thread {
    
    @Override
    public void run(){
        for(int i = 0; i < 10; i++){
            System.out.println("Thread c/ herança: "+i);
        }
        try{
            Thread.sleep(1000);
        }
        catch(Exception e){
        }
    }
    
}
