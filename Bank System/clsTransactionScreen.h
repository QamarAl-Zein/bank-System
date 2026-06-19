#pragma once
#include<iostream>
#include"clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrowScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
using namespace std;
class clsMainScreen;

class clsTransactionScreen :protected clsScreen
{
private:
	enum enTransactionsMenueOptions {
		eDeposit = 1, eWithdraw = 2,
		eShowTotalBalance = 3,eTransfer=4,eTransferLog=5, eShowMainMenue = 6
	};
	static short _ReadTranscationMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate<short>::ReadNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}
	static void _GoBackToTransactionsMenue()
	{
		cout << setw(37) << left << "" << "\n\nPress any key to go back to TransactionsMenue...";
		system("pause>0");
		ShowTransactionMenue();
	}

	static void _ShowDepositScreen() 
	{
		clsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithDrawScreen()
	{
		clsWithdrowScreen::ShowWithdrawScreen();
	}
	static void _ShowTotalBalanceScreen()
	{ 
		clsTotalBalancesScreen::ShowTotalBalances();
	}
	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}
	static void _ShowTranferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();
	}
	static void _PerfromTranactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption)
	{
		switch (TransactionMenueOption)
		{
		case enTransactionsMenueOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eWithdraw:
		{
			system("cls");
			_ShowWithDrawScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eTransferLog:
		{
			system("cls");
			_ShowTranferLogScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eShowMainMenue:
		{
			
		}
		}
	}

public:
	static void ShowTransactionMenue()
	{
		system("cls");
		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;
		}
		_DrawScreenHeader("\t Transaction Menue");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tTransactions Menue Screen\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" <<"\t[1] Deposit.\n";
		cout << setw(37) << left << "" <<"\t[2] Withdraw.\n";
		cout << setw(37) << left << "" <<"\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerfromTranactionsMenueOption((enTransactionsMenueOptions)_ReadTranscationMenueOption());
	}
};

