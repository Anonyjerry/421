
/*

ssi测试用


*/




//ssi通信编码的计算， 

/*------------------------------------------------    
    对ssi器件都
    时钟频率可调
    函数返回值为读入的编码器数据，bit——sum为读入数据的位数
    CLK为ssi时钟线
    DATA为编码器的数据线
    SET_CLK置编码器为高
    CLR_CLK置编码器为低
      
---------------------------------------------------*/   
void delay(unsigned char i){   
    while(i){   
        i--;   
        }   
    }   
   
   
   
unsigned long SSI_Read(unsigned char bit_sum,unsigned int baud){   
    char i;   
    unsigned long count;   
    SET_CLK;   
    delay(2);   
    CLR_CLK;   
    delay(baud>>1);                       //编码器值储存
       
    for(i=bit_sum;i=0;i--){   
        SET_CLK;   
        count=count<<1;   
        if(DATA){   
            count++;   
        }   
        delay(baud>>1);   
        CLR_CLK;   
        delay(baud>>1);   
    }   
    SET_CLK;   
}   
   
/*---------------------------------------------------------  
检测时钟线，平时为高，第一个下降沿，计数数据并保存入发送寄存器S_buf

根据时钟信号线，输出数据
  
-----------------------------------------------------------*/   
   
   
void SSI_Writ(unsigned char mod,unsigned char bit_sum,unsigned long data){   
    unsigned char i;   
    if(mod){   
        data=b_to_g(data);   
    }   
   
    for(i=bit_sum;i=0;i--){   
        while(!CLK){                                    //等高  
        }   
        if((bit)(data & (1<<(bit_sum-1)))){   
            SET_DATA;   
        }else{   
            CLR_DATA;   
        }   
        data<<=1;   
        while(CLK){                                     //等低 
        }   
    }   
    CLR_DATA;   
}   
   
   
void main_handle(){   
    unsigned long num_data;   
    unsigned char over=0;   
    while(!CLK);                                                            //等高 
    while(CLK);                                                             //等下降沿  
    num_data=step_num;   
       
    do{                                                                
        SSI_Write(bm_mode,bit_num,num_data);            //传数据
        unsigned char k=3;   
        while(!CLK);   
        while(k--){   
            if(CLK){   
                over=3;   
            }else{   
                over=0;   
            }   
        }   
        SET_DATA;   
    }while(!over)      
}   
   
   
/*---------------------------------------------  
                    计数中断
                    contrl 为I/O口，
                   转向模式
                                        0:0为正转,1为反转
                                        1:1为正传,0为反转
-----------------------------------------------*/   
unsigned long step_num;   
   
   
void count_num(){   
    if(turn_mode)   
    {   
        if(contrl){   
            step_num--;   
        }else{   
            step_num++;   
        }   
    }else{   
        if(contrl){   
            step_num++;   
        }else{   
            step_num--;   
        }   
    }   
}   


