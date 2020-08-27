#include <assert.h>

const float bpmLimit[]={70,150};
const float spo2Limit=90;
const float respRateLimit[]={30,95};

/*bool bpmCheck(float bpm){
  return  (bpm>bpmLimit[0] && bpm<bpmLimit[1]);
}
bool spo2Check(float spo2){
  return  (spo2>spo2Limit);
}

bool respRateCheck(float respRate){
  return  (respRate>respRateLimit[0] && respRate<respRateLimit[1]);
}
*/
bool vitalIsOk(float value, const float *limits[2]){
  return (value >= limits[0] && value <= limits[1]);
 }
bool vitalOk (float value,const float limit)
{
  return (value >= limit);
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {

  //if( int(bpmCheck(bpm))+ int(spo2Check(spo2)) + int(respRateCheck(respRate))!=3){
   // return false;
  //}
  //else
    //return true;
  vitalIsOk(bpm,bpmLimit) && vitalOk(spo2,spo2Limit) && vitalIsOk(respRate,respRateLimit));
   // return (bpmCheck(bpm) && spo2Check(spo2) && respRateCheck(respRate);
}//CCN-2

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);  // 1 1  1
  assert(vitalsAreOk(60, 90, 40) == false); // 0 1  1
  assert(vitalsAreOk(90,85,70)==false);// 1 0 1
 assert(vitalsAreOk(100,95,100)==false);// 1 1 0
  assert(vitalsAreOk(50,85,99)==false);//0  0 0
  
  //assert(vitalsIsOk(3,1,5)==true);//1<3<5
  //assert(vitalsIsOk(40,10,30)==false); //10<40>30
}
