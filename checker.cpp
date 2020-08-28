#include <assert.h>
#include<iostream>
using namespace std;
const float bpmLimit[]={70,150};
const float spo2Limit[]={90,100};//make INT_MAX
const float respRateLimit[]={30,95};
class Alert
{
  public:
    virtual void sendAlert(const char* vitalName,const char* value)=0;//pure virtual fun
};
class AlertSms:public Alert
{
  public:
    void sendAlert(const char* vitalName,const char* value) override{
      cout<<"SMS:"<<vitalName<<"--------"<<value<<endl;
}
class AlertSound:public Alert
{
  public:
    void sendAlert(const char* vitalName,const char* value) override{
      cout<<"SOUND:"<<vitalName<<"--------"<<value<<endl;
}

class vitals{
 public:
    const char* vitalIsOk(float value,float lower,float upper ){
      if(value<lower){cout<<"below"<<endl;}
      else if(value>upper){cout<<"above"<<endl;}
      else {cout<<"all okay"<<endl;}
    }
    void vitalsAreOk(float bpm, float spo2, float respRate) {
       // int bool_array[]={int(vitalIsOk(bpm,bpmLimit)),int(vitalIsOk(spo2,spo2Limit)),int(vitalIsOk(respRate,respRateLimit))};
        //if(int(vitalIsOk(bpm,bpmLimit)) +int( vitalIsOk(spo2,spo2Limit)) +int(vitalIsOk(respRate,respRateLimit))!=3){return false;}
        //else return true;
        const char* bpmlevel=vitalIsOk(bpm,70,150);
        const char* spo2level=vitalIsOk(spo2,90,100);
        const char* respRatelevel=vitalIsOk(respRate,30,95);
        //alerting
        Alert *alert;
        AlertSms alertSms;
        AlertSound alertSound;
        //derv class addr pass to bas class pointer
        alert=&alertSms;
        alert->sendAlert("BPM",bpmlevel);
        alert->sendAlert("SPO2",spo2level);
        alert->sendAlert("RESPRATE",respRatelevel);
        
        alert=&alertSound;
        alert->sendAlert("BPM", bpmlevel);
        alert->sendAlert("SPO2", spo2level);
        alert->sendAlert("RESPRATE", respRatelevel);
        
    }//CCN-2
};
int main() 
{
  /*assert(vitalsAreOk(80, 95, 60) == true);  // 1 1  1
  assert(vitalsAreOk(60, 90, 40) == false); // 0 1  1
  assert(vitalsAreOk(90,85,70)==false);// 1 0 1
  assert(vitalsAreOk(100,95,100)==false);// 1 1 0
  assert(vitalsAreOk(50,85,99)==false);//0  0 0 */
  vitals vital;
  vital.vitalsAreOk(80,95,60);
  vital.vitalsAreOk(60, 90, 40);
}
