#include <18F4620.h>
#FUSES NOWDT, NOMCLR                    //No Watch Dog Timer
#use delay(clock=4M)
//variables
int contador=0;
//Declarando interrupcion de timer1
//contador de 100ms frecuencia de 10HZ
#int_timer1
void timer_1()
{
   contador++;
   set_timer1(15536);
}

void main()
{
   //estados de puertos
   set_tris_c(0x00);
   //variables
   int conteo;
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);
   set_timer1(15536);
   enable_interrupts(int_timer1);
   enable_interrupts(global);
   
   while(TRUE)
   {
     if(contador>=2)
     {
         for(conteo=32;conteo>=1;conteo/=2)
         {
            output_c(conteo);
         }
     }
   }
}
