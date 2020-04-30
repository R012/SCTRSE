

#include <public/ccsensormanager_iface_v1.h>



	// ******************* HANDLING IRQ 5********************

Pr_IRQEvent	CCSensorManager::EDROOMEventIRQ5(5);
Pr_SemaphoreBin	CCSensorManager::EDROOMSemEndIRQ5(0);


		// ******************* DATA ***************

CDSensorTMBufferStatus	CCSensorManager::	EDROOMVarIRQ5;


		// ******************* DATA POOL *******

CCSensorManager::CEDROOMPOOLIRQ5CDSensorTMBufferStatus	CCSensorManager::EDROOMPoolIRQ5;


		// ******************* Aux IRQ Handler **************

void 	CCSensorManager::EDROOMIRQ5HandlerTopHalfFunction(void){

	TEDROOMBool EDROOMIRQ5BottomHalfSignal=true;
	EDROOMVarIRQ5.GetCurrentStatus();

	if (EDROOMIRQ5BottomHalfSignal)
		EDROOMEventIRQ5.Signal();

}



		// ******************* IRQ Handler **************

Pr_IRQHandler_RetType	CCSensorManager::EDROOMIRQ5Handler(void){

	EDROOMIRQ5HandlerTopHalfFunction();

}



		// ******************* IRQ Idle Handler **************

Pr_IRQHandler_RetType	CCSensorManager::EDROOMIRQ5IdleHandler(void){

}



		// ******************* Bottom Half Task **************

Pr_TaskRV_t 	CCSensorManager::EDROOMIRQ5BottomHalfTask(Pr_TaskP_t){

	TEDROOMBool endTask=false;

	do{

		EDROOMEventIRQ5.Wait();

		TEDROOMBool EDROOMIRQ5SendMsgToCmp=true;

		if(!EDROOMSemEndIRQ5.WaitCond()){

			if(EDROOMIRQ5SendMsgToCmp){
				CDSensorTMBufferStatus	*pEDROOMVarIRQ;

				pEDROOMVarIRQ=EDROOMPoolIRQ5.AllocData();

				*pEDROOMVarIRQ=EDROOMVarIRQ5;

				RxTimeCode.NewIRQMsg(EDROOMIRQsignal, pEDROOMVarIRQ, &EDROOMPoolIRQ5);

			}
			Pr_IRQManager::EnableIRQ(5);

		}else endTask=1;

	}while(!endTask);

}



		// ******************* IRQPort **************

CEDROOMIRQInterface CCSensorManager::RxTimeCode( 
		CCSensorManager::EDROOMIRQ5Handler 
		,CCSensorManager::EDROOMIRQ5IdleHandler 
		,CCSensorManager::EDROOMEventIRQ5
		,CCSensorManager::EDROOMSemEndIRQ5
		,5 );




	// ******************* CONSTRUCTOR ************************************



CCSensorManager::CCSensorManager(TEDROOMComponentID id,TEDROOMUInt32 roomNumMaxMens, TEDROOMPriority roomtaskPrio, TEDROOMStackSizeType roomStack, CEDROOMMemory *pActorMemory ) : 

		CEDROOMComponent(id,EDROOMprioMINIMUM+1,roomNumMaxMens,roomtaskPrio,roomStack, pActorMemory )

		// ***************   BOTTOM HALF IRQ TASKS  ********************

		,EDROOMIRQ5BottomHalfT( EDROOMIRQ5BottomHalfTask,EDROOMprioURGENT,256)


		// ***************	Top State  *****************

		,edroomTopState(*this,pActorMemory)


{


}


	//***************	PUBLIC METHODS  ********************************



		//**********           Configuration               ************


int CCSensorManager::EDROOMConfig() {




 return 0; }



		//**********           START               ************


int CCSensorManager::EDROOMStart() {



		//****************** Component Start **********************

	CEDROOMComponent::EDROOMStart(); 	// Call to EDROOMStart method of CEDROOMComponent

return 0;}


	// ***************	PROTECTED METHODS *******************************



		//***************** Behaviour ******************



void CCSensorManager::EDROOMBehaviour() {

	edroomTopState.EDROOMInit();
	edroomTopState.EDROOMBehaviour();


		// *************** PUERTOS IRQ ********************

	RxTimeCode.EndIRQHandlerTask();
}




		//**********        ComponentIsFinished           ************


	#ifdef _EDROOM_SYSTEM_CLOSE

TEDROOMBool CCSensorManager::EDROOMIsComponentFinished() {


	return ( CEDROOMComponent::EDROOMIsComponentFinished());

}


	#endif

	// ***************	EDROOM Memory ******************************

void CCSensorManager::CEDROOMMemory::SetMemory(TEDROOMUInt32 numMessages_ 
		, CEDROOMMessage * MessagesMem_
		, TEDROOMBool * MessagesMemMarks_
		, TEDROOMUInt32 numberOfNodes_
		, CEDROOMQueue::CQueueNode * QueueNodesMem_
		, TEDROOMBool * QueueNodesMemMarks_){

		CEDROOMComponentMemory::SetMemory( numMessages_,MessagesMem_, MessagesMemMarks_
			,numberOfNodes_,QueueNodesMem_, QueueNodesMemMarks_, QueueHeads);


}

