#include <iostream>
#include <sys/time.h>
#include <time.h>
#include "Account.hpp"


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(){}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = _nbAccounts;
	Account:: _displayTimestamp();
	std::cout << " " << "index:" << _accountIndex;
	std::cout << ";" << "amount:" << _amount;
	std::cout << ";" << "created" << std::endl;
	_nbAccounts ++;
	_totalAmount += _amount;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
	struct timeval	tv;
	struct tm		*ptm;

	gettimeofday(&tv, NULL);
	ptm = localtime(&tv.tv_sec);
	std::cout << "[" << ptm->tm_year + 1900 << ptm->tm_mon + 1 <<  ptm->tm_mday << "_" \
	<< ptm->tm_hour << ptm->tm_min << ptm->tm_sec << "]";
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " " << "accounts:" << _nbAccounts;
	std::cout << ";" << "total:" << _totalAmount;
	std::cout << ";" << "deposits:" << _totalNbDeposits;
	std::cout << ";" << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_nbDeposits ++;
	std::cout << " " << "index:" << _accountIndex;
	std::cout << ";" << "p_amount:" << _amount;
	std::cout << ";" << "deposit:" << deposit;
	std::cout << ";" << "amount:" << _amount + deposit;
	std::cout << ";" << "nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits ++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " " << "index:" << _accountIndex;
	if (withdrawal > _amount)
	{
		std::cout << ";" << "p_amount:" << _amount;
		std::cout << ";" << "withdrawal:refused" << std::endl;
		return (false);
	}
	_nbWithdrawals ++;
	std::cout << ";" << "p_amount:" << _amount;
	std::cout << ";" << "withdrawal:" << withdrawal;
	std::cout << ";" << "amount:" << _amount - withdrawal;
	std::cout << ";" << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals ++;
	return (true);
}

void	Account::displayStatus( void ) const
{
	//[19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
	_displayTimestamp();
	std::cout << " " << "index:" << _accountIndex;
	std::cout << ";" << "amount:" << _amount;
	std::cout << ";" << "deposits:" << _nbDeposits;
	std::cout << ";" << "withdrawals:" << _nbWithdrawals << std::endl;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << " " << "index:" << _accountIndex;
	std::cout << ";" << "amount:" << _amount;
	std::cout << ";" << "closed" << std::endl;
}


