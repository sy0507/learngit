#include<stdio.h> 
public class ElevatorThread extends  
    Thread{
    int curPos = 1;
    boolean direction = true; //方向， 上--true;   下----false
    boolean status = false; //电梯的状态, true -----正在运行， false----等待prey.
    private TubePanel tubePanel;
    int threadID;
    TreeSet destSet = new TreeSet();    
    public ElevatorThread( TubePanel p){
        tubePanel = p;
        start();
    }
    public void setThreadID( int i ){
        threadID  = i;
    }
    public synchronized void addDest( int dest ){
        destSet.add(new Integer(dest));
    }
    public synchronized void addDestNotify( int dest ){
        destSet.add(new Integer( dest ));
        this.notify();
        
    }
    public  void run(){
        while( true){
            status = false;
            try{
                synchronized ( this ){
                    wait();
                }
                status = true;    
                System.out.println("Thread " + threadID + " begin to run");
                while( !destSet.isEmpty() ){
                    Integer integer = (Integer)destSet.first();
                    int dest = (integer).intValue();
                    System.out.println("dest is " + dest);
                    tubePanel.closeDoor();
                    //电梯关门 ， 开始向一个目的楼层行进
                    while( curPos != dest ){
                        if( curPos < dest ){
                              curPos ++;
                              direction = true; 
                              tubePanel.setCurFloor(curPos);
                        }else  {
                                curPos --;
                                direction = false;
                                tubePanel.setCurFloor(curPos);
                                
                        } 
                        System.out.println("Thread " + threadID + " now at " + curPos );
                        sleep(500);
                        integer = (Integer)destSet.first();
                        dest = (integer).intValue();
                    }
                    //电梯开门， 一个目标楼层已到达
                    System.out.println("Thread " + threadID + " arrive at " + curPos + " Floor" );
                    destSet.remove(integer);
                    tubePanel.openDoor();
                    sleep(2000);
                }
                tubePanel.allUnload();
                //如果所有的目的楼层都经过了， 则电梯的状态为全部卸载
                status = false;
            }catch( InterruptedException e){
                    e.printStackTrace();
            }
            
        }
    }
    
}

