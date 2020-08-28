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
    virtual float showValue(const float val)=0;
};

class AlertSms:public Alert
{
  public:
    void sendAlert(const char* vitalName,const char* value) override{
      cout<<"SMS:"<<vitalName<<"--------"<<value<<endl;}
    float showValue(const float val) override{
      cout<<"Value;---:"<<val<<endl;
    }
};

class AlertSound:public Alert
{
  public:
    void sendAlert(const char* vitalName,const char* value) override{
      cout<<"SOUND:"<<vitalName<<"--------"<<value<<endl;}
     float showValue(const float val) override{
      cout<<"Value;---:"<<val<<endl;
    } 
};

class vitals
{
 public:
    const char* vitalIsOk(float value,const float *limits)
    {
      if(value< limits[0]){return "below";}
      else if(value> limits[1]){return "above";}
      else {return "all okay";}
    }
    
    void vitalsAreOk(float bpm, float spo2, float respRate) 
    {
       // int bool_array[]={int(vitalIsOk(bpm,bpmLimit)),int(vitalIsOk(spo2,spo2Limit)),int(vitalIsOk(respRate,respRateLimit))};
        //if(int(vitalIsOk(bpm,bpmLimit)) +int( vitalIsOk(spo2,spo2Limit)) +int(vitalIsOk(respRate,respRateLimit))!=3){return false;}
        //else return true;
        const char* bpmlevel=vitalIsOk(bpm,bpmLimit);
        const char* spo2level=vitalIsOk(spo2,spo2Limit);
        const char* respRatelevel=vitalIsOk(respRate,respRateLimit);
        //alerting
        Alert *alert;
        AlertSms alertSms;
        AlertSound alertSound;
        //derv class addr pass to bas class pointer
        alert=&alertSms;
        alert->sendAlert("BPM",bpmlevel);
        alert->showValue(bpm);
        alert->sendAlert("SPO2",spo2level);
        alert->showValue(spo2);
        alert->sendAlert("RESPRATE",respRatelevel);
        alert->showValue(respRate);
        
        alert=&alertSound;
        alert->sendAlert("BPM", bpmlevel);alert->showValue(bpm);
        alert->sendAlert("SPO2", spo2level);alert->showValue(spo2);
        alert->sendAlert("RESPRATE", respRatelevel);alert->showValue(respRate);
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
