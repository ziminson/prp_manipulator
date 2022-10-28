#include <DynamixelWorkbench.h>

uint8_t dxl_id[6] = {1, 2, 3, 4, 5, 6}; //айдишники движков
DynamixelWorkbench dxl_wb;  //объектик

void setup() 
{
  Serial.begin(57600); //запуск монитора
  //while(!Serial); // пока не включится монитор - ждем

  dxl_wb.begin("3", 1000000); //говорим через какой порт и с какой скоростью работаем с устр-ми

  //тут "пингуем", инициализация движков. Если не сделать - работать не будут
  dxl_wb.ping(dxl_id[0]);
  dxl_wb.ping(dxl_id[1]);
  dxl_wb.ping(dxl_id[2]);
  dxl_wb.ping(dxl_id[3]);
  dxl_wb.ping(dxl_id[4]);
  dxl_wb.ping(dxl_id[5]);


  //включаю режим шарнира
  //0 ~ 1,023(0x3FF) can be used, and the unit is about 0.111rpm.
  //0 - максимальные обороты без контроля
  //1023 - 
  //For example, if it is set to 300, it is about 33.3 rpm.
  dxl_wb.jointMode(dxl_id[0],50,50);
  dxl_wb.jointMode(dxl_id[1],50,50);
  dxl_wb.jointMode(dxl_id[2],50,50);
  dxl_wb.jointMode(dxl_id[3],50,50);
  dxl_wb.jointMode(dxl_id[4],50,50);
  dxl_wb.jointMode(dxl_id[5],50,50);

  dxl_wb.goalPosition(dxl_id[0], 2048);
  dxl_wb.goalPosition(dxl_id[1], 2048);
 
  dxl_wb.goalPosition(dxl_id[2], 2048);
  dxl_wb.goalPosition(dxl_id[3], 2048);
  dxl_wb.goalPosition(dxl_id[4], 512);
  dxl_wb.goalPosition(dxl_id[5], 512);
 

  //включаю режим свободного вращения
  //dxl_wb.wheelMode(dxl_id[0], 10000);
  //dxl_wb.wheelMode(dxl_id[1], 10000);

}

void setPos()
{
  dxl_wb.goalPosition(dxl_id[0], random (1500, 2500));
  dxl_wb.goalPosition(dxl_id[1], random (1500, 2500));
  dxl_wb.goalPosition(dxl_id[2], random (1500, 2500)); 
  dxl_wb.goalPosition(dxl_id[3], random (1500, 2500)); 
  dxl_wb.goalPosition(dxl_id[4], random (400, 600)); 
  dxl_wb.goalPosition(dxl_id[5], random (520, 600));  

  delay (random (3000, 5000));
}

void loop() 
{
  setPos();
  /*
  dxl_wb.goalPosition(dxl_id[0], 512);
  dxl_wb.goalPosition(dxl_id[1], 512);
  delay (3000);

  dxl_wb.goalPosition(dxl_id[0], 300);
  dxl_wb.goalPosition(dxl_id[1], 0);
  delay (3000);

  dxl_wb.goalPosition(dxl_id[0], 700);
  dxl_wb.goalPosition(dxl_id[1], 1023);
  delay (3000);
  

  /*
  0 ~ 2,047(0x7FF) can be used, the unit is about 0.1%.
  If a value in the range of 0 ~ 1,023 is used, it is stopped by setting to 0 while rotating to CCW direction.
  If a value in the range of 1,024 ~ 2,047 is used, it is stopped by setting to 1,024 while rotating to CW direction.
  That is, the 10th bit becomes the direction bit to control the direction
  */
  
  /*
  dxl_wb.goalVelocity(dxl_id[0], 1023);
  dxl_wb.goalVelocity(dxl_id[1], 1023);
  delay(500);

  dxl_wb.goalVelocity(dxl_id[0], 2000);
  dxl_wb.goalVelocity(dxl_id[1], 2000);
  delay(3000);

  dxl_wb.goalVelocity(dxl_id[0], 0);
  dxl_wb.goalVelocity(dxl_id[1], 0);
  delay(5000);
  */
}