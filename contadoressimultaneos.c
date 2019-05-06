#include <18F4620.h>
#FUSES NOWDT, NOMCLR                    //No Watch Dog Timer
#use delay(clock=16M)
//variables
int contador=0;
//Declarando interrupcion de timer1
//contador de 100ms frecuencia de 10HZ
#int_timer0
void timer_0()
{
   contador++;
   set_timer0(59286);
}

void main()
{
   //estados de puertos
   set_tris_a(0x00);
   set_tris_b(0x00);
   set_tris_c(0x00);
   set_tris_d(0x00);
   //variables
   int conteo;
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_64);//sino se agrega la linea RTCC_8_BIT TRABAJA A 16BITS
   set_timer0(59286);
   enable_interrupts(int_timer0);
   enable_interrupts(global);
   
   while(TRUE)
   {
     if(contador>=20)
     {
         for(conteo=32;conteo>=1;conteo/=2)
         {
            output_c(conteo);
         }
     }
     if(contador>=40)
     {
         for(conteo=32;conteo>=1;conteo/=2)
         {
            output_a(conteo);
         }
     }
     if(contador>=70)
     {
         for(conteo=32;conteo>=1;conteo/=2)
         {
            output_b(conteo);
         }
     }
     if(contador>=100)
     {
         for(conteo=32;conteo>=1;conteo/=2)
         {
            output_d(conteo);
         }
     } 
   }
}
