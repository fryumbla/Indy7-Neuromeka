extern "C" {
    #include "/home/francisco/cobots_ws/src/Indy7-Neuromeka/indy7_vrep/remoteApi/extApi.h"
}
#include <iostream>
#include <string>
#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <sensor_msgs/JointState.h>


using namespace std;

int clientID;

sensor_msgs::JointState pub_msg;

int found(int a,char* b,int c,int d)
{
  if(simxGetObjectHandle(a,(const simxChar*) b,(simxInt *) &c,(simxInt) simx_opmode_oneshot_wait)){
    cout << "no joint " << d << " found" << std::endl;
  }
  else{
    return c;
    cout << "joint " << d << " found"  << std::endl;
  }

}

void joint_callback(const sensor_msgs::JointState& data)
{
  pub_msg.name=data.name;
  pub_msg.position = data.position;

  char* joints[12]={"joint0","joint1","joint2","joint3","joint4","joint5","finger_joint", "left_inner_knuckle_joint","left_inner_finger_joint", "right_outer_knuckle_joint", "right_inner_knuckle_joint", "right_inner_finger_joint"};
  // char* joints[12];

  // for (int i = 0; i < pub_msg.name.size(); i++)
  // {
  //   string name=pub_msg.name.at(i);
  //   std::cout << name << '\n';
  //   char* cstr= new char[pub_msg.name.size()];
  //   name.copy(cstr, name.size());
  //   // cstr[name.size()] = '\0';
  // 	// strcpy(cstr,name.c_str());
  //   joints[i]=cstr;
  //   std::cout << cstr << '\n';
  // }

  // std::cout << joints[0] << '\n';
  // std::cout << joints[1] << '\n';
  // std::cout << joints[2] << '\n';
  

  int joint_handle[12]={0,0,0,0,0,0,0,0,0,0,0,0};

  for (int i=0;i<=11; ++i){
    joint_handle[i]=found(clientID,joints[i],joint_handle[i],i+1);
  }
  for (int i=0;i<=11; ++i){
    simxSetJointTargetPosition(clientID, (simxInt) joint_handle[i], data.position.at(i), simx_opmode_oneshot);
  }

}

int main(int argc, char **argv) 
{
  string serverIP = "127.0.0.1";
  int serverPort = 19999;

  clientID=simxStart((simxChar*)serverIP.c_str(),serverPort,true,true,2000,5);
  
  if (clientID!=-1)
  {
    cout << "Servidor conectado!" << std::endl;
    
    ros::init(argc, argv, "vrep_communication");
    ros::NodeHandle nh = ros::NodeHandle();
    
    ros::Subscriber sub = nh.subscribe("/joint_states", 2000, joint_callback);

    // Waits for simulation time update.
    ros::Time last_ros_time_;
    bool wait = true;

    ros::spin();
    simxFinish(clientID); // fechando conexao com o servidor
    cout << "Conexao fechada!" << std::endl;
  }
  else
    cout << "Problemas para conectar con servidor!" << std::endl;
  return 0;
}


