#include <assert.h>

const int bpmLimit={70,150};
const int resRateLimit={30,95};

bool bpmCheck(float bpm){
  return  (bpm>bpmLimit[0] && bpm<bpmLimit[1]);
}
bool resRateCheck(float resRate){
  return  (bpm>resRateLimit[0] && bpm<resRateLimit[1]);
}   
bool vitalsAreOk(float bpm, float spo2, float respRate) {
  if(!bpmCheck) {
    return false;
  } else if(spo2 < 90) {
    return false;
  } else if(!respRateCheck) {
    return false;
  }
  return true;
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);  // 1 1  1
  assert(vitalsAreOk(60, 90, 40) == false); // 0 1  1
  assert(vitalsAreOk(90,85,70)==false);// 1 0 1
  assert(vitalsAreOk(100,95,100)==false);// 1 1 0
}
