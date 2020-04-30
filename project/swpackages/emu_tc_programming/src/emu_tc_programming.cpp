/*
 * emu_tc_programming.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: user
 */

#include <public/emu_sc_channel_drv_slib_v1.h>

#define UNITIME_AFTER_POWER_ON 100001



// FUNCTIONAL TESTS EXECUTION CONTROL
//#define FT_SOLO_EPD_ICU_SERV_17_0010
//#define FT_SOLO_EPD_ICU_SERV_9_0020

//TODO
//#define FT_SOLO_EPD_ICU_SERV_20_0030
//#define FT_SOLO_EPD_ICU_SERV_3_0070
//#define FT_SOLO_EPD_ICU_SERV_3_0080
//#define FT_SOLO_EPD_ICU_SERV_3_0090
//#define FT_SOLO_EPD_ICU_SERV_20_0100
//#define FT_SOLO_EPD_ICU_SERV_20_0110
//#define FT_SOLO_EPD_ICU_SERV_3_0010
//#define FT_SOLO_EPD_ICU_SERV_3_0020
//...


//printf("step 0, system init");

//Uni Time
Program9_129TC prog_tc1(0,"Set Power-On Universal Time",UNITIME_AFTER_POWER_ON);



#ifdef FT_SOLO_EPD_ICU_SERV_17_0010

Program17_1TC prog_FT_0010_step_0(UNITIME_AFTER_POWER_ON + 6,"FT_SOLO_EPD_ICU_SERV_17_0010 step 0, Connection Test");

#endif

#ifdef FT_SOLO_EPD_ICU_SERV_9_0020

#define FT_SOLO_EPD_ICU_SERV_9_0020_TIME 200001

Program9_129TC prog_FT_0020_step_0(UNITIME_AFTER_POWER_ON + 10 ,"FT_SOLO_EPD_ICU_SERV_9_0020 step 0, Update UniTime Test",FT_SOLO_EPD_ICU_SERV_9_0020_TIME);

#endif


//**********************************
//Housekeeping
//**********************************

// habilitar y deshabilitar
#ifdef FT_SOLO_EPD_ICU_SERV_3_0080

Program3_6TC prog_tc_disable_SID_10(UNITIME_AFTER_POWER_ON + 13, // deshabilito el 10
				"test FT_SOLO_EPD_ICU_SERV_3_0080 step 1, DISABLE SID 10", 10);

Program3_6TC prog_tc_disable_SID_11(UNITIME_AFTER_POWER_ON + 13, // deshabilito el 11
				"test FT_SOLO_EPD_ICU_SERV_3_0080 step 1, DISABLE SID 11", 11);

Program3_5TC prog_tc_enable_SID_10(UNITIME_AFTER_POWER_ON + 21, // habilito el 10
				"test FT_SOLO_EPD_ICU_SERV_3_0080 step 2, ENABLE SID 10", 10);

#endif

// cambiar el periodo del reporte
#ifdef FT_SOLO_EPD_ICU_SERV_3_0090

Program3_31TC prog_tcx(UNITIME_AFTER_POWER_ON + 11,
                        "test FT_SOLO_EPD_ICU_SERV_3_0090 step 0, change period of SID 11 to 3 seconds", // T del 11 a 3 segundos manteniendo los otros
             11,3);

#endif

#ifdef FT_SOLO_EPD_ICU_SERV_3_0020

Program3_31TC prog_tcx(UNITIME_AFTER_POWER_ON + 11,
                        "test FT_SOLO_EPD_ICU_SERV_3_0020 step 0, try to change period of SID 11 to 0,5 seconds", // T del 11 a 3 segundos manteniendo los otros
             11,0.5);

#endif

#ifdef FT_SOLO_EPD_ICU_SERV_3_0010

Program3_5TC prog_tc_enable_SID_100(UNITIME_AFTER_POWER_ON + 10,
				"test FT_SOLO_EPD_ICU_SERV_3_0010 step 0, ENABLE SID 100", 100);
Program3_5TC prog_tc_enable_SID_110(UNITIME_AFTER_POWER_ON + 10,
				"test FT_SOLO_EPD_ICU_SERV_3_0010 step 0, ENABLE SID 110", 110);
Program3_5TC prog_tc_enable_SID_120(UNITIME_AFTER_POWER_ON + 10,
				"test FT_SOLO_EPD_ICU_SERV_3_0010 step 0, ENABLE SID 120", 120);
Program3_5TC prog_tc_enable_SID_200(UNITIME_AFTER_POWER_ON + 10,
				"test FT_SOLO_EPD_ICU_SERV_3_0010 step 0, ENABLE SID 200", 200);
Program3_5TC prog_tc_enable_SID_220(UNITIME_AFTER_POWER_ON + 10,
				"test FT_SOLO_EPD_ICU_SERV_3_0010 step 0, ENABLE SID 220", 210);

#endif


//**********************************
//Private Service System Data Pool Mng
//**********************************

#ifdef FT_SOLO_EPD_ICU_SERV_20_0100

Program20_3TC prog_tc10 (UNITIME_AFTER_POWER_ON + 12,
                         "test FT_SOLO_EPD_ICU_SERV_20_0110 step 0, set Param 11 to value 1994",11,1994);

#endif



#ifdef FT_SOLO_EPD_ICU_SERV_20_0110

Program20_1TC prog_tc11(UNITIME_AFTER_POWER_ON + 14,
                        "test FT_SOLO_EPD_ICU_SERV_20_0110 step 1, Get Param 11 value",11);

#endif






//**********************************
//Define Monitoring
//**********************************

//Add Param 0 monitoring definition

/*
Program12_5TC prog_tc2 (UNITIME_AFTER_POWER_ON + 2 ,
                "Define Monitoring Param 0",
                0,
                10,
                0x4001,
                0,
                0x4002,
                5);
*/

//**********************************
//Event-Action
//**********************************

//Event 0x4002- Action

/*
Program19_1TC prog_tc5(UNITIME_AFTER_POWER_ON + 3,
                       "Assign TC(128,2) as action of Event 0x4002",
                       0x4002,
                       128,2);


//Enable Event 0x4002- Action

Program19_4TC prog_tc6(UNITIME_AFTER_POWER_ON + 3,
                       "Enable Action of Event 0x4002",
                       0x4002);

*/

//**********************************
//Enable Monitoring
//**********************************

//Enable Param 0 Monitoring

/*
Program12_1TC prog_tc7(UNITIME_AFTER_POWER_ON + 4,
                       "Enable Monitoring Param 0",0);
*/

//**********************************
//Memory Management
//**********************************


/*
Program6_2TC prog_tc8 (UNITIME_AFTER_POWER_ON + 5,
                         "Memory Patch",0x10000,32,NULL);

Program6_5TC prog_tc9 (UNITIME_AFTER_POWER_ON + 6,
                         "Memory Dump",0x10000,32);
*/


