
/*

ssi������


*/




//ssiͨ�ű���ļ��㣬 

/*------------------------------------------------    
    ��ssi������
    ʱ��Ƶ�ʿɵ�
    ��������ֵΪ����ı��������ݣ�bit����sumΪ�������ݵ�λ��
    CLKΪssiʱ����
    DATAΪ��������������
    SET_CLK�ñ�����Ϊ��
    CLR_CLK�ñ�����Ϊ��
      
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
    delay(baud>>1);                       //������ֵ����
       
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
���ʱ���ߣ�ƽʱΪ�ߣ���һ���½��أ��������ݲ������뷢�ͼĴ���S_buf

����ʱ���ź��ߣ��������
  
-----------------------------------------------------------*/   
   
   
void SSI_Writ(unsigned char mod,unsigned char bit_sum,unsigned long data){   
    unsigned char i;   
    if(mod){   
        data=b_to_g(data);   
    }   
   
    for(i=bit_sum;i=0;i--){   
        while(!CLK){                                    //�ȸ�  
        }   
        if((bit)(data & (1<<(bit_sum-1)))){   
            SET_DATA;   
        }else{   
            CLR_DATA;   
        }   
        data<<=1;   
        while(CLK){                                     //�ȵ� 
        }   
    }   
    CLR_DATA;   
}   
   
   
void main_handle(){   
    unsigned long num_data;   
    unsigned char over=0;   
    while(!CLK);                                                            //�ȸ� 
    while(CLK);                                                             //���½���  
    num_data=step_num;   
       
    do{                                                                
        SSI_Write(bm_mode,bit_num,num_data);            //������
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
                    �����ж�
                    contrl ΪI/O�ڣ�
                   ת��ģʽ
                                        0:0Ϊ��ת,1Ϊ��ת
                                        1:1Ϊ����,0Ϊ��ת
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


