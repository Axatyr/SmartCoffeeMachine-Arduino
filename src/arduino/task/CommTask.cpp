#include "CommTask.h"

#define MSG_COFFEE_REFILLED "5"

CommTask::CommTask(){
}

void CommTask::init(int period){
  Task::init(period);
}

void CommTask::tick(){
  if (MsgService.isMsgAvailable()){
    Msg* msg = MsgService.receiveMsg();
    if (msg->getContent() == "MSG_REFILLED"){
      refill = false;
    } else if (msg->getContent() == "MSG_RECOVER") {
      recover = false;
    } else {
      MsgService.sendMsg("CommTask: unknown req: "+content);
    }
 
  delete msg;
  }
}