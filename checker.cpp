#include <assert.h>
#include<iostream>
#include<fstream>
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

struct vitalArray
{
  float bpm_val;
  float spo2_val;
  float respRate_val;
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
        const char* bpmlevel=vitalIsOk(bpm,bpmLimit);
        const char* spo2level=vitalIsOk(spo2,spo2Limit);
        const char* respRatelevel=vitalIsOk(respRate,respRateLimit);
        //alerting
        Alert *alert;
        AlertSms alertSms;
        AlertSound alertSound;
        //dervied class address pass to base class pointer
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
    }
    void vitalsList(vitalArray vitalarr[],int size)
    {
      for(int i=0;i<size;i++)
      {
        vitalsAreOk(vitalarr[i].bpm_val,vitalarr[i].spo2_val,vitalarr[i].respRate_val);
      }
    }
};

int main() 
{
  /*assert(vitalsAreOk(80, 95, 60) == true);  // 1 1  1
  assert(vitalsAreOk(60, 90, 40) == false); // 0 1  1
  assert(vitalsAreOk(90,85,70)==false);// 1 0 1
  assert(vitalsAreOk(100,95,100)==false);// 1 1 0
  assert(vitalsAreOk(50,85,99)==false);//0  0 0 */
  vitalArray vitalarr[5];//can be dynamic malloc
  /*vitalarr[0].bpm_val=80;
  vitalarr[0].spo2_val=95;
  vitalarr[0].respRate_val=60;
  vitalarr[1].bpm_val=60;
  vitalarr[1].spo2_val=90;
  vitalarr[1].respRate_val=40;
  vitals vital;
  //vital.vitalsAreOk(80,95,60);
  //vital.vitalsAreOk(60, 90, 40);
  vital.vitalsList(vitalarr,2);*/
  ifstream ip("test_case.csv");
  if(!ip.is_open()) cout<<"FILE OPEN ERROR"<<endl;
  int size=0;//init
  while(ip.good())
  {
    getline(ip,vitalarr[size].bpm_val,',');
    getline(ip,vitalarr[size].spo2_val,',');
    getline(ip,vitalarr[size].respRate_val,'\n');
    size++;
  }
  vital.vitalsList(vitalarr,5);
  ip.close();
}
