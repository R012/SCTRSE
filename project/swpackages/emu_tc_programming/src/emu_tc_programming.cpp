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

//#define FT_SOLO_EPD_ICU_SERV_3_0080
//#define FT_SOLO_EPD_ICU_SERV_3_0090
//#define FT_SOLO_EPD_ICU_SERV_20_0100
//#define FT_SOLO_EPD_ICU_SERV_20_0110
//#define FT_SOLO_EPD_ICU_SERV_3_0020

//TODO
//#define FT_SOLO_EPD_ICU_SERV_20_0030
//#define FT_SOLO_EPD_ICU_SERV_3_0040
//#define FT_SOLO_EPD_ICU_SERV_3_0050

//#define FT_SOLO_EPD_ICU_SERV_12_0120
//#define FT_SOLO_EPD_ICU_SERV_12_0130
//#define FT_SOLO_EPD_ICU_SERV_12_0140

#define PRUEBA_FUNCIONAL
//...


//Uni Time
Program9_129TC prog_tc1(0,"Set Power-On Universal Time",UNITIME_AFTER_POWER_ON);


#ifdef FT_SOLO_EPD_ICU_SERV_17_0010
Program17_1TC prog_FT_0010_step_0(UNITIME_AFTER_POWER_ON + 6,"FT_SOLO_EPD_ICU_SERV_17_0010 step 0, Connection Test");
#endif

#ifdef FT_SOLO_EPD_ICU_SERV_9_0020
#define FT_SOLO_EPD_ICU_SERV_9_0020_TIME 200001
Program9_129TC prog_FT_0020_step_0(UNITIME_AFTER_POWER_ON + 10 ,"FT_SOLO_EPD_ICU_SERV_9_0020 step 0, Update UniTime Test",FT_SOLO_EPD_ICU_SERV_9_0020_TIME);
#endif

#ifdef FT_SOLO_EPD_ICU_SERV_3_0080
Program3_6TC prog_tc_disable_SID_10(UNITIME_AFTER_POWER_ON + 13, // deshabilito el 10
				"test FT_SOLO_EPD_ICU_SERV_3_0080 step 1, DISABLE SID 10", 10);
Program3_6TC prog_tc_disable_SID_11(UNITIME_AFTER_POWER_ON + 13, // deshabilito el 11
				"test FT_SOLO_EPD_ICU_SERV_3_0080 step 1, DISABLE SID 11", 11);
Program3_5TC prog_tc_enable_SID_10(UNITIME_AFTER_POWER_ON + 21, // habilito el 10
				"test FT_SOLO_EPD_ICU_SERV_3_0080 step 2, ENABLE SID 10", 10);
#endif

#ifdef FT_SOLO_EPD_ICU_SERV_3_0090
Program3_31TC prog_tcx(UNITIME_AFTER_POWER_ON + 11, "test FT_SOLO_EPD_ICU_SERV_3_0090 step 0, change period of SID 11 to 3 seconds", 11,3);

#endif

#ifdef FT_SOLO_EPD_ICU_SERV_20_0100
Program20_3TC prog_tc10 (UNITIME_AFTER_POWER_ON + 12,
                         "test FT_SOLO_EPD_ICU_SERV_20_0110 step 0, set Param 11 to value 1994",11,1994);
#endif

#ifdef FT_SOLO_EPD_ICU_SERV_20_0110
Program20_1TC prog_tc11(UNITIME_AFTER_POWER_ON + 14,
                        "test FT_SOLO_EPD_ICU_SERV_20_0110 step 1, Get Param 11 value",11);
#endif

#ifdef FT_SOLO_EPD_ICU_SERV_3_0020
Program3_31TC prog_tcx(UNITIME_AFTER_POWER_ON + 11, "test FT_SOLO_EPD_ICU_SERV_3_0020 step 0, try to change period of SID 11 to 0,5 seconds", 11,0.5);
#endif

#ifdef FT_SOLO_EPD_ICU_SERV_12_0120
Program12_1TC prog_FT_0120_step_0(UNITIME_AFTER_POWER_ON + 10, "Enable Monitoring Param 0",0);
Program12_2TC prog_FT_0120_step_1(UNITIME_AFTER_POWER_ON + 15, "Disable Monitoring Param 0",0);
#endif

#ifdef FT_SOLO_EPD_ICU_SERV_12_0130
Program5_5TC prog_FT_0130_step_0(UNITIME_AFTER_POWER_ON + 6, "Enable EvRID 0x4002", 0x4002);
Program12_5TC prog_FT_0130_step_1(UNITIME_AFTER_POWER_ON + 10, "Define Monitoring Param 0", 0, 10, 0x4001, 3, 0x4002, 7);
Program12_1TC prog_FT_0130_step_2(UNITIME_AFTER_POWER_ON + 13, "Enable Monitoring Param 0",0);
Program20_3TC prog_FT_0130_step_3(UNITIME_AFTER_POWER_ON + 15, "Set Param 0 to value 8",0,8);
Program5_6TC prog_FT_0130_step_4(UNITIME_AFTER_POWER_ON + 30, "Disable EvRID 0x4002", 0x4002);
#endif

#ifdef FT_SOLO_EPD_ICU_SERV_12_0140
Program5_6TC prog_FT_0140_step_0(UNITIME_AFTER_POWER_ON + 4, "Disable EvRID 0x4001", 0x4001);
Program5_5TC prog_FT_0140_step_1(UNITIME_AFTER_POWER_ON + 6, "Enable EvRID 0x4001", 0x4001);
Program12_5TC prog_FT_0140_step_2(UNITIME_AFTER_POWER_ON + 10, "Define Monitoring Param 0", 0, 10, 0x4001, 3, 0x4002, 7);
Program12_1TC prog_FT_0140_step_3(UNITIME_AFTER_POWER_ON + 13, "Enable Monitoring Param 0",0);
Program20_3TC prog_FT_0140_step_4(UNITIME_AFTER_POWER_ON + 15, "Set Param 0 to value 2",0,2);
Program20_3TC prog_FT_0140_step_5(UNITIME_AFTER_POWER_ON + 27, "Set Param 0 to value 5",0,5);
#endif



/* PRUEBA FUNCIONAL (Borrar al incluir los tests) */
#ifdef PRUEBA_FUNCIONAL
Program12_5TC prog_tc_prueba1 (UNITIME_AFTER_POWER_ON + 3,
                "Define Monitoring Param 0: Period 10, range 3-6",
                0,
                10,
                0x4001,
                3,
                0x4002,
                6);

Program19_1TC prog_tc_prueba2(UNITIME_AFTER_POWER_ON + 6,
                       "Assign TC(128,2) as action of Event 0x4002",
                       0x4002,
                       128,2);

Program12_1TC prog_tc_prueba3(UNITIME_AFTER_POWER_ON + 8,
                       "Enable Monitoring Param 0",0);

Program19_4TC prog_tc_prueba5(UNITIME_AFTER_POWER_ON + 11,
                       "Enable Action of Event 0x4002",
                       0x4002);

Program20_3TC prog_tc_prueba6(UNITIME_AFTER_POWER_ON + 15,
                         "Set Param 0 to value 8",0,8);

Program19_5TC prog_tc_prueba7(UNITIME_AFTER_POWER_ON + 22,
                       "Disable Action of Event 0x4002",
                       0x4002);

Program19_2TC prog_tc_prueba8(UNITIME_AFTER_POWER_ON + 25,
                       "Delete TC(128,2) as action of Event 0x4002",
                       0x4002);
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
Program19_1TC prog_tc3(UNITIME_AFTER_POWER_ON + 3,
                       "Assign TC(128,2) as action of Event 0x4002",
                       0x4002,
                       128,2);

Program19_2TC prog_tc4(UNITIME_AFTER_POWER_ON + 3,
                       "Delete TC(128,2) as action of Event 0x4002",
                       0x4002);

//Enable Event 0x4002- Action

Program19_4TC prog_tc5(UNITIME_AFTER_POWER_ON + 3,
                       "Enable Action of Event 0x4002",
                       0x4002);


//Enable Event 0x4002- Action

Program19_5TC prog_tc6(UNITIME_AFTER_POWER_ON + 3,
                       "Disable Action of Event 0x4002",
                       0x4002);
*/

//**********************************
//Enable Monitoring
//**********************************

//Enable Param 0 Monitoring

/*
Program12_1TC prog_tc7(UNITIME_AFTER_POWER_ON + 4,
                       "Enable Monitoring Param 0",0);

Program12_2TC prog_tc8(UNITIME_AFTER_POWER_ON + 5,
                       "Disable Monitoring Param 0",0);
*/

//**********************************
//Event Reporting
//**********************************

//Enable Param 0 Monitoring

/*
Program5_6TC prog_tc9(UNITIME_AFTER_POWER_ON + 4,
                       "Disable EvRID 0x4002",
                       0x4002);

Program5_5TC prog_tc10(UNITIME_AFTER_POWER_ON + 6,
                       "Enable EvRID 0x4002",
                       0x4002);
*/

//**********************************
//Memory Management
//**********************************


/*
Program6_2TC prog_tc11(UNITIME_AFTER_POWER_ON + 5,
                         "Memory Patch",0x10000,32,NULL);

Program6_5TC prog_tc12(UNITIME_AFTER_POWER_ON + 6,
                         "Memory Dump",0x10000,32);
*/

//**********************************
//Housekeeping
//**********************************

/*
Program3_31TC prog_tc13(UNITIME_AFTER_POWER_ON + 12,
                        "FT_ Change period of SID 0 to 5 seconds",
             0,5);

Program3_6TC prog_tc14(UNITIME_AFTER_POWER_ON + 25,
				"FT_ DISABLE SID 0", 0);

Program3_5TC prog_tc15(UNITIME_AFTER_POWER_ON + 50,
				"FT_ ENABLE SID 0", 0);
*/

//**********************************
//Private Service System Data Pool Mng
//**********************************

/*
//Read Param 0 value
Program20_1TC prog_tc16(UNITIME_AFTER_POWER_ON + 13,
                        "Get Param 0 value",0);

//Set Param 0 to 6
Program20_3TC prog_tc17(UNITIME_AFTER_POWER_ON + 12,
                         "Set Param 0 to value 6",0,6);

//Read Param 0 value
Program20_5C prog_tc18(UNITIME_AFTER_POWER_ON + 13,
                        "Get Param 0 value",0);


//Set Param 0 to 6
Program128_4TC prog_tc19(UNITIME_AFTER_POWER_ON + 35,
                         "Set Param 0 to value 3",0,3);


//Set Param 0 to 6
Program128_4TC prog_tc20(UNITIME_AFTER_POWER_ON + 55,
                         "Set Param 0 to value 7",0,7);
*/
