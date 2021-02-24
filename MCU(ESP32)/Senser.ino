void Senser()
{
static int index;
  if(Serial2.available()>0){   
    char dataIn = Serial2.read();
    if(dataIn == '\n'){    
    }
    else if(dataIn == '\r') {      
      state = true;
      //Serial2.flush() ;      
    }
    else{
      buf[index] = dataIn;
      index++;      
    }
  }
  
  if(state == true){
   if(index == 19 && buf[0] == 'T')  // เก็บค่า T Object  
   {
    trig = true;
    s = true;
    for (int i=11;i<sizeof(buf);i++)
    {
     sText += buf[i];
    }
      T_Object = sText.toFloat();
      sText = "\0";
      
    }   
     else if((index == 26 || index == 27) && buf[0] == 'T')  //กรณี 1 , 2
     {
       for (int i=9;i<sizeof(buf);i++)
       {
        sText += buf[i];
       }
        T_Body = sText.toFloat();
       
        sText = "\0";
         
    if((T_Body>37.5 && T_Body<40.0) && (T_Body <= T_Object)){
        Temp = &T_Object;
        //Serial.println(*Temp,1);
        
      }
    else if((T_Body>37.5 && T_Body<40.0) && (T_Body >= T_Object)){
        Temp = &T_Body;
      //Serial.println(*Temp,1);
      
      }
    else if(T_Body>=40.0){
       Temp = &T_Body;
      //Serial.println("HIGH");
     
    }
    else if(T_Body == 0.0){
      //Serial.println("LOW");           
    }
    else{
      Temp = &T_Body;               
      //Serial.println(*Temp,1);
       
    }
  }
  else
  {
    //---
  }
       
    index = 0;
    state = false;

  }
     if((millis()- t > p) && trig == true)
     {
       t = millis();
       if(s == true){
        s = false;
       
       }
       else{
        T_Object = 0;
        T_Body   = 0;
        Temp = &T_Object;
        *Temp = 0;
        Temp = &T_Body;
        *Temp = 0;
        s = true;
        trig = false;
        //Serial.println("......Reset......");
       }       
     }   
}
