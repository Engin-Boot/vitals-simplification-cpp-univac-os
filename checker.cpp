#include <assert.h>

const int bpmLimit[]={70,150};
const int spo2Limit=90;
const int respRateLimit[]={30,95};

bool bpmCheck(float bpm){
  return  (bpm>bpmLimit[0] && bpm<bpmLimit[1]);
}
bool spo2Check(float spo2){
  return  (spo2>spo2Limit);
}

bool resRateCheck(float respRate){
  return  (respRate>respRateLimit[0] && respRate<respRateLimit[1]);
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
//  int b=bpmCheck;
  //int s=spo2Check;
  //int r=resRateCheck;
  //if( b+s+r!=3){
    return (bpmCheck(bpm) && spo2Check(spo2) && respRateCheck(respRate);
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);  // 1 1  1
  assert(vitalsAreOk(60, 90, 40) == false); // 0 1  1
  assert(vitalsAreOk(90,85,70)==false);// 1 0 1
  assert(vitalsAreOk(100,95,100)==false);// 1 1 0
}
