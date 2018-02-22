#include<stdio.h> 
public class ElevatorThread extends  
    Thread{
    int curPos = 1;
    boolean direction = true; //���� ��--true;   ��----false
    boolean status = false; //���ݵ�״̬, true -----�������У� false----�ȴ�prey.
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
                    //���ݹ��� �� ��ʼ��һ��Ŀ��¥���н�
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
                    //���ݿ��ţ� һ��Ŀ��¥���ѵ���
                    System.out.println("Thread " + threadID + " arrive at " + curPos + " Floor" );
                    destSet.remove(integer);
                    tubePanel.openDoor();
                    sleep(2000);
                }
                tubePanel.allUnload();
                //������е�Ŀ��¥�㶼�����ˣ� ����ݵ�״̬Ϊȫ��ж��
                status = false;
            }catch( InterruptedException e){
                    e.printStackTrace();
            }
            
        }
    }
    
}

