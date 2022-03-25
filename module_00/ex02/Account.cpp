#include "Account.hpp"

#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int   Account::getNbAccounts(void) {
  return (_nbAccounts);
}

int   Account::getTotalAmount(void) {
  return (_totalAmount);
}

int   Account::getNbDeposits(void) {
  return (_totalNbDeposits);
}

int   Account::getNbWithdrawals(void) {
  return (_totalNbWithdrawals);
}

Account::Account(int initial_deposit)
  : _nbDeposits(0),
  _nbWithdrawals(0) {
  _amount = initial_deposit;
  _totalAmount += _amount;
  _accountIndex = getNbAccounts();
  _nbAccounts += 1;
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";amount:" << _amount <<
               ";created\n";
}

Account::~Account(void) {
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";amount:" << _amount <<
               ";closed\n";
}

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << " accounts:" << _nbAccounts <<
               ";total:" << _totalAmount <<
               ";deposits:" << _totalNbDeposits <<
               ";withdrawals:" << _totalNbWithdrawals << '\n';
}

void Account::makeDeposit(int deposit) {
  const int previousAmount = _amount;
  _amount += deposit;
  _nbDeposits += 1;
  _displayTimestamp();
  std::cout << " index:" << _accountIndex <<
               ";p_amount:" << previousAmount <<
               ";deposit:" << deposit <<
               ";amount:" << _amount <<
               ";nb_deposits:" << _nbDeposits << '\n';
  _totalAmount += deposit;
  _totalNbDeposits += 1;
}

bool Account::makeWithdrawal(int withdrawal) {
  const int previousAmount = _amount;
  _amount -= withdrawal;
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";p_amount:" << previousAmount <<
               ";withdrawal:";
  if (checkAmount() == -1) {
    std::cout << "refused\n";
    _amount = previousAmount;
    return (false);
  }
  _nbWithdrawals += 1;
  std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" <<
               _nbWithdrawals << std::endl;
  _totalAmount -= withdrawal;
  _totalNbWithdrawals += 1;
  return (true);
}

int Account::checkAmount(void) const {
  if (_amount < 0)
    return (-1);
  return (0);
}

void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << " index:" << _accountIndex
            << ";amount:" << _amount
            << ";deposits:" << _nbDeposits
            << ";withdrawals:" << _nbWithdrawals << '\n';
}

void Account::_displayTimestamp(void) {
  time_t raw_time = time(NULL);
  const struct tm* t = localtime(&raw_time);
  std::cout << "[";
  std::cout << t->tm_year + 1900;
  std::cout << std::setfill('0') << std::setw(2) << t->tm_mon + 1 <<
               std::setfill('0') << std::setw(2) << t->tm_mday << "_" <<
               std::setfill('0') << std::setw(2) << t->tm_hour <<
               std::setfill('0') << std::setw(2) << t->tm_min <<
               std::setfill('0') << std::setw(2) << t->tm_sec << "]";
}
