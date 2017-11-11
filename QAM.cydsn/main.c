/* ========================================
    Author: Julian Santos 
*/
#include "project.h"
// ********************************************************* Functions firm 
void initialize();

// ******************************************************** Var declaration
uint16 data_QAM; // This would be the data out 
uint16 tmp;   // Temporal for QAM data
uint16 N; // It is the N-QAM 4,8,16,32,64,128,256,512,1024
uint8 nbit; // Number of the bit to be send
uint8 log2N; // Number of bits used in the N-QAM 2 3 4 5 6 7 8 9 10
uint8 s; // step size
uint8 xcoor; // this will be the x coordinate for the cons**
uint8 ycoor; // this will be the y coordinate for the cons**
uint8 xlim; // Represent how far the data will be in the x  axis
uint8 uno;

// ******************************************************************* ISR clock 
CY_ISR(isr1_clk){
   //Send n bit in a serial way
    data_out_Write((data_QAM&(uno<<nbit))>0); 
    nbit ++ ;
    if(nbit>(log2N-1)){ // restrict the number of bits to be sent
        nbit = 0;
        data_QAM++; // this line could be replaced with lecture of sensors
        if(data_QAM > (N-1)){ // restrict the top of the data 
            data_QAM = 0;
        }
        // here will be the function to calculate xcoor and ycoor
        xcoor = data_QAM ;
        ycoor = 1 ;
        
        while(xcoor > (xlim-1)){
            ycoor++;
            xcoor = xcoor-xlim;
        }
    }
    Pin_in_clk_ClearInterrupt();
}

// *************************************************************** ISR RX Bluetooth
CY_ISR(isr2_bl){
    uint8 temp;
    temp = UART_GetChar();
        if(temp>1 && temp<11){ // for make sure that the data is in the ok range
            log2N = temp; 
            N = 2^log2N ;
            if(temp == 2 ){ // for QAM 4
            }
            else if(temp == 3 ){ // for QAM 8
            }
            else if(temp == 4 ){ //for QAM 16
            }
            else if(temp == 5 ){ //for QAM 32
            }
            else if(temp == 6 ){ //for QAM 64
            }
            else if(temp == 7 ){ //for QAM 128
            }
            else if(temp == 8 ){ //for QAM 256
            }
            else if(temp == 9 ){ //for QAM 512
            }
            else if(temp == 10 ){ //for QAM 1024
            }
            else{}
        }      
        else{}
}

// ********************************************************* Main function
int main(void)
{
    initialize();                   // calling the function to initialize the variables.
    CLOCK_Start();                  // on clock
    X_Start();                      // on DAC X axis.
    Y_Start();                      // on DAC Y axis.
    UART_Start();                   // on UART 
    isr_clk_StartEx(isr1_clk);      // on interrupt clk.
    //isr_bluetooth_StartEx(isr2_bl); // on rx interrupt.
    CyGlobalIntEnable;              // Enable global interrupts.

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    for(;;)
    {
        //****************************************4 QAM (1 per cuadrant) [2 bits] ok
        if(log2N == 2){
            if(data_QAM == 0){X_SetValue(10*s); Y_SetValue(10*s); signX_Write(0); signY_Write(0);}
            else if(data_QAM == 1){X_SetValue(10*s); Y_SetValue(10*s); signX_Write(1); signY_Write(0);}
            else if(data_QAM == 2){X_SetValue(10*s); Y_SetValue(10*s); signX_Write(0); signY_Write(0);}
            else if(data_QAM == 3){X_SetValue(10*s); Y_SetValue(10*s); signX_Write(0); signY_Write(1);}
            else{}; //error case
        }
        //****************************************8 QAM [3 bits] ok
        else if(log2N == 3){
            if(data_QAM == 0){X_SetValue(8*s); Y_SetValue(0); signX_Write(0); signY_Write(0);}
            else if(data_QAM == 1){X_SetValue(0); Y_SetValue(8*s); signX_Write(0); signY_Write(0);}
            else if(data_QAM == 2){X_SetValue(8*s); Y_SetValue(0); signX_Write(1); signY_Write(0);}
            else if(data_QAM == 3){X_SetValue(0); Y_SetValue(8*s); signX_Write(0); signY_Write(1);} 
            else if(data_QAM == 4){X_SetValue(16*s); Y_SetValue(16*s); signX_Write(0); signY_Write(0);}
            else if(data_QAM == 5){X_SetValue(16*s); Y_SetValue(16*s); signX_Write(1); signY_Write(0);}
            else if(data_QAM == 6){X_SetValue(16*s); Y_SetValue(16*s); signX_Write(1); signY_Write(1);} 
            else if(data_QAM == 7){X_SetValue(16*s); Y_SetValue(16*s); signX_Write(0); signY_Write(1);}
            else {} // error case 
        }
        //****************************************16 QAM (4 per cuadrant) [4 bits] ok
        else if(log2N == 4){
            //bias
            if(data_QAM > 11){signX_Write(0); signY_Write(1); tmp = data_QAM - 12;}
            else if(data_QAM > 7){signX_Write(1); signY_Write(1); tmp= data_QAM - 8;}
            else if(data_QAM >3){signX_Write(1); signY_Write(1); tmp = data_QAM - 4;}
            else{signX_Write(0); signY_Write(0);};
            //analog data
            if(tmp == 0){X_SetValue(8*s); Y_SetValue(8*s);}
            else if(tmp == 1){X_SetValue(16*s); Y_SetValue(8*s);}
            else if(tmp == 2){X_SetValue(8*s); Y_SetValue(16*s);}
            else if(tmp == 3){X_SetValue(16*s); Y_SetValue(16*s);}
            else{}; //error case
        }        
        //****************************************32 QAM (8 per cuadrant) [5 bits]
        else if(log2N == 5){
            //bias
            if(data_QAM > 23){signX_Write(0); signY_Write(0); tmp = data_QAM - 24;}
            else if(data_QAM > 15){signX_Write(0); signY_Write(0); tmp= data_QAM - 16;}
            else if(data_QAM >7){signX_Write(0); signY_Write(0); tmp = data_QAM - 8;}
            else{signX_Write(0); signY_Write(0);};
            //analog data
            X_SetValue(s*xcoor);
            Y_SetValue(s*ycoor);
        }
        //****************************************64 QAM (16 per cuadrant) [6 bits]
        else if(log2N == 6){
            //bias
            if(data_QAM > 47){signX_Write(0); signY_Write(0); tmp = data_QAM - 48;}
            else if(data_QAM > 31){signX_Write(1); signY_Write(0); tmp= data_QAM - 32;}
            else if(data_QAM >15){signX_Write(1); signY_Write(1); tmp = data_QAM - 16;}
            else{signX_Write(0); signY_Write(0);};
            //analog data
            //analog data
            X_SetValue(s*xcoor);
            Y_SetValue(s*ycoor);
        }
        //****************************************128 QAM (32 per cuadrant) [7 bits]
        else if(log2N == 7){
            //bias
            if(data_QAM > 95){signX_Write(0); signY_Write(0); tmp = data_QAM - 96;}
            else if(data_QAM > 63){signX_Write(1); signY_Write(0); tmp= data_QAM - 64;}
            else if(data_QAM >31){signX_Write(1); signY_Write(1); tmp = data_QAM - 32;}
            else{signX_Write(0); signY_Write(0);};
             //analog data
            X_SetValue(s*xcoor);
            Y_SetValue(s*ycoor);
        }
        //****************************************256 QAM (64 per cuadrant) [8 bits]
        else if(log2N == 8){
            //bias
            if(data_QAM > 191){signX_Write(0); signY_Write(0); tmp = data_QAM - 192;}
            else if(data_QAM > 127){signX_Write(1); signY_Write(0); tmp= data_QAM - 128;}
            else if(data_QAM >63){signX_Write(1); signY_Write(1); tmp = data_QAM - 64;}
            else{signX_Write(0); signY_Write(0);};
             //analog data
            X_SetValue(s*xcoor);
            Y_SetValue(s*ycoor);
        }
        //****************************************512 QAM (128 per cuadrant) [9 bits]
        else if(log2N == 9){
        //bias
            if(data_QAM > 383){signX_Write(0); signY_Write(0); tmp = data_QAM - 384;}
            else if(data_QAM > 255){signX_Write(1); signY_Write(0); tmp= data_QAM - 256;}
            else if(data_QAM >127){signX_Write(1); signY_Write(1); tmp = data_QAM - 128;}
            else{signX_Write(0); signY_Write(0);};
            //analog data
            X_SetValue(s*xcoor);
            Y_SetValue(s*ycoor);    
        }
        //****************************************1024 QAM (256 per cuadrant) [10 bits]
        else if(log2N == 10){
            //bias
            if(data_QAM > 767){signX_Write(0); signY_Write(1); tmp = data_QAM - 768;}
            else if(data_QAM > 511){signX_Write(1); signY_Write(0); tmp= data_QAM - 512;}
            else if(data_QAM > 255){signX_Write(1); signY_Write(1); tmp = data_QAM - 256;}
            else{signX_Write(0); signY_Write(0);};
             //analog data
            X_SetValue(s*xcoor);
            Y_SetValue(s*ycoor);
            
        }
        
        //****************************************** error case 
        else{
        }
    }
}

// ***************************** This function is for initialize variables
void initialize(){
    nbit = 0; // for start sending the  first bit
    data_QAM = 0; // initial value
    N =4; // initial value 
    log2N = 2;
    s = 15; // step (less distance between stars)
    xlim = 2; // in fact it is 16 but the flux of data starts at 0
    uno=1; // 
}


