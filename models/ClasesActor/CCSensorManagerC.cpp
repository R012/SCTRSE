#include <public/ccsensormanager_iface_v1.h>

// ***********************************************************************

// class EDROOMTopContext

// ***********************************************************************



	// CONSTRUCTORS***********************************************

CCSensorManager::EDROOMTopContext::EDROOMTopContext (CCSensorManager &act
	, CDEventList & EDROOMpVarVCurrentEvList
	, CDTMList & EDROOMpVarVCurrentTMList
	, CEDROOMPOOLCDTMList & EDROOMpPoolCDTMList
	, CEDROOMPOOLCDEventList & EDROOMpPoolCDEventList ):

	EDROOMcomponent(act)
	,Msg(EDROOMcomponent.Msg)
	,MsgBack(EDROOMcomponent.MsgBack)
	,TMChannelCtrl(EDROOMcomponent.TMChannelCtrl)
	,CmpHK(EDROOMcomponent.CmpHK)
	,SensorMngCtrl(EDROOMcomponent.SensorMngCtrl)
	,RxTimeCode(EDROOMcomponent.RxTimeCode)
	, VCurrentEvList ( EDROOMpVarVCurrentEvList )
	, VCurrentTMList ( EDROOMpVarVCurrentTMList )
	, EDROOMPoolCDTMList ( EDROOMpPoolCDTMList )
	, EDROOMPoolCDEventList ( EDROOMpPoolCDEventList )
 {

}

CCSensorManager::EDROOMTopContext::EDROOMTopContext ( EDROOMTopContext &contex ):

	EDROOMcomponent(contex.EDROOMcomponent),
	Msg(contex.Msg),
	MsgBack(contex.MsgBack)
	,TMChannelCtrl(contex.TMChannelCtrl)
	,CmpHK(contex.CmpHK)
	,SensorMngCtrl(contex.SensorMngCtrl)
	,RxTimeCode(contex.RxTimeCode)
	, VCurrentEvList ( contex.VCurrentEvList )
	, VCurrentTMList ( contex.VCurrentTMList )
	, EDROOMPoolCDTMList ( contex.EDROOMPoolCDTMList )
	, EDROOMPoolCDEventList ( contex.EDROOMPoolCDEventList )
 {

}

	// EDROOMSearchContextTrans********************************************

TEDROOMBool CCSensorManager::EDROOMTopContext::EDROOMSearchContextTrans(TEDROOMTransId &edroomCurrentTrans){

	TEDROOMBool edroomValidMsg=false; 

	 switch(Msg->signal){

		 case ( EDROOMSignalDestroy ): 

			 edroomValidMsg=true;
			 edroomCurrentTrans.distanceToContext = 0 ;
			 edroomCurrentTrans.localId = -1 ;
			 break;

	}

	return(edroomValidMsg);

}

	// User Defined Functions   ****************************

void	CCSensorManager::EDROOMTopContext::FExecSensorTC()

{
   //Handle Msg->data
  CDTCDescriptor & varSSensorTC = 
                                                   *(CDTCDescriptor *)Msg->data;
	
		// Data access
	
  PUS_SensorsTC::ExecTC(varSSensorTC,VCurrentTMList,VCurrentEvList);

}



void	CCSensorManager::EDROOMTopContext::FIamAlive()

{
   //Allocate data from pool
  CDEventList * pSIAmAlive_Data = 
                                              EDROOMPoolCDEventList.AllocData();
	
		// Complete Data 
	
 *pSIAmAlive_Data=VCurrentEvList;
   //Send message 
   CmpHK.send(SIAmAlive, pSIAmAlive_Data, &EDROOMPoolCDEventList); 
}



void	CCSensorManager::EDROOMTopContext::FProcessSensorsTM()

{
   //Handle Msg->data
  CDSensorTMBufferStatus & varEDROOMIRQsignal = 
                                           *(CDSensorTMBufferStatus *)Msg->data;
	
		// Data access
 
PUSService21::ProcessSensorTM( varEDROOMIRQsignal,
                               VCurrentTMList,VCurrentEvList);

}



void	CCSensorManager::EDROOMTopContext::FSendTMList()

{
   //Allocate data from pool
  CDTMList * pSTxTMList_Data = 
                                                 EDROOMPoolCDTMList.AllocData();
	
		// Complete Data 
	
	*pSTxTMList_Data=VCurrentTMList;
	VCurrentTMList.Clear();
 
   //Invoke synchronous communication 
   MsgBack=TMChannelCtrl.invoke(STxTMList, pSTxTMList_Data
                                                        , &EDROOMPoolCDTMList); 
}



	//********************************** Pools *************************************

	//CEDROOMPOOLCDTMList

CCSensorManager::EDROOMTopContext::CEDROOMPOOLCDTMList::CEDROOMPOOLCDTMList(TEDROOMUInt32 elemCount, CDTMList* pMem, TEDROOMBool * pMemMarks):CEDROOMProtectedMemoryPool(elemCount, pMem, pMemMarks, sizeof (CDTMList)){;}

CDTMList *	CCSensorManager::EDROOMTopContext::CEDROOMPOOLCDTMList::AllocData(){
	return(CDTMList*)CEDROOMProtectedMemoryPool::AllocData();
}

	//CEDROOMPOOLCDEventList

CCSensorManager::EDROOMTopContext::CEDROOMPOOLCDEventList::CEDROOMPOOLCDEventList(TEDROOMUInt32 elemCount, CDEventList* pMem, TEDROOMBool * pMemMarks):CEDROOMProtectedMemoryPool(elemCount, pMem, pMemMarks, sizeof (CDEventList)){;}

CDEventList *	CCSensorManager::EDROOMTopContext::CEDROOMPOOLCDEventList::AllocData(){
	return(CDEventList*)CEDROOMProtectedMemoryPool::AllocData();
}



// ***********************************************************************

// class EDROOMTopState

// ***********************************************************************



	// CONSTRUCTOR*************************************************

CCSensorManager::EDROOMTopState::EDROOMTopState (CCSensorManager &act, CEDROOMMemory *pEDROOMMemory  ):
	  EDROOMTopContext( act 
		, VCurrentEvList
		, VCurrentTMList
		, EDROOMPoolCDTMList
		, EDROOMPoolCDEventList )
	, EDROOMPoolCDTMList ( 10, pEDROOMMemory->poolCDTMList, pEDROOMMemory->poolMarkCDTMList)
	, EDROOMPoolCDEventList ( 10, pEDROOMMemory->poolCDEventList, pEDROOMMemory->poolMarkCDEventList)
{

}

	//***************************** EDROOMBehaviour ********************************

void CCSensorManager::EDROOMTopState::EDROOMBehaviour(){

	TEDROOMTransId edroomCurrentTrans;

	//Behaviour starts from Init State

	edroomCurrentTrans = EDROOMIllegada();

	do{

		//Take next transition

		switch(edroomCurrentTrans.localId){

			//Next Transition is Init
			case(Init):
				//Next State is Ready
				edroomNextState = Ready;
				break;
			//Next Transition is ExecTC
			case(ExecTC):
				//Msg->Data Handling 
				FExecSensorTC();
				//Invoke Synchronous Message 
				FSendTMList();
				//Next State is Ready
				edroomNextState = Ready;
				break;
			//Next Transition is ProcessSensorTM
			case(ProcessSensorTM):
				//Msg->Data Handling 
				FProcessSensorsTM();
				//Send Asynchronous Message 
				FIamAlive();
				//Invoke Synchronous Message 
				FSendTMList();
				//Next State is Ready
				edroomNextState = Ready;
				break;
		}

		//Entry into the Next State 
		switch(edroomNextState){

				//Go to the state I
			case(I):
				//Entry into the State I
				edroomCurrentTrans=EDROOMIllegada();
				break;

				//Go to the state Ready
			case(Ready):
				//Entry into the State Ready
				edroomCurrentTrans=EDROOMReadyllegada();
				break;

		}

		edroomCurrentState=edroomNextState;

	}while(Msg->signal != EDROOMSignalDestroy);

}



	// Inicio**********************************************

void CCSensorManager::EDROOMTopState::EDROOMInit(){

edroomCurrentState=I;

}



//	 ***********************************************************************

//	 SubState I

//	 ***********************************************************************



TEDROOMTransId CCSensorManager::EDROOMTopState::EDROOMIllegada(){

	TEDROOMTransId edroomCurrentTrans;

	//Next transition is  Init
	edroomCurrentTrans.localId = Init;
	edroomCurrentTrans.distanceToContext = 0;
	return(edroomCurrentTrans);

}



	// ***********************************************************************

	// Leaf SubState  Ready

	// ***********************************************************************



TEDROOMTransId CCSensorManager::EDROOMTopState::EDROOMReadyllegada(){

	TEDROOMTransId edroomCurrentTrans;

	int edroomValidMsg=false;

	do{

		EDROOMNewMessage ();

		switch(Msg->signal){

			case (SSensorTC): 

				 if ( *Msg->GetPInterface() == SensorMngCtrl) {

					edroomCurrentTrans.localId= ExecTC;
					edroomCurrentTrans.distanceToContext = 0;
					edroomValidMsg=true;
				 }

				break;

			case (EDROOMIRQsignal): 

				 if ( *Msg->GetPInterface() == RxTimeCode) {

					edroomCurrentTrans.localId= ProcessSensorTM;
					edroomCurrentTrans.distanceToContext = 0;
					edroomValidMsg=true;
				 }

				break;

		};

		if (!edroomValidMsg) edroomValidMsg = EDROOMSearchContextTrans(edroomCurrentTrans);

	} while (!edroomValidMsg);

	return(edroomCurrentTrans);

}



