#include "llcl/Standard/MultiThread/Mutex.h"

#include <gtest/gtest.h>

namespace llcl {
namespace {

class my_Account {
  double d_money;

 public:
  my_Account();

  my_Account(const my_Account& original);

  ~my_Account();

  my_Account& operator=(const my_Account& rhs);

  void deposit(double amount);

  void withdraw(double amount);

  double balance() const;
};

my_Account::my_Account() : d_money(0.0) {}

my_Account::my_Account(const my_Account& original)
    : d_money(original.d_money) {}

my_Account::~my_Account() {}

my_Account& my_Account::operator=(const my_Account& rhs) {
  d_money = rhs.d_money;
  return *this;
}

void my_Account::deposit(double amount) { d_money += amount; }

void my_Account::withdraw(double amount) { d_money -= amount; }

double my_Account::balance() const { return d_money; }

class my_SafeAccountHandle {
  my_Account* d_account_p;
  mutable llcl::standard::mt::Mutex d_lock;

  my_SafeAccountHandle(const my_SafeAccountHandle&);
  my_SafeAccountHandle& operator=(const my_SafeAccountHandle&);

 public:
  my_SafeAccountHandle(my_Account* account);

  ~my_SafeAccountHandle();

  void deposit(double amount);

  void lock();

  void unlock();

  void withdraw(double amount);

  my_Account* account() const;

  double balance() const;
};

my_SafeAccountHandle::my_SafeAccountHandle(my_Account* account)
    : d_account_p(account) {}

my_SafeAccountHandle::~my_SafeAccountHandle() {}

void my_SafeAccountHandle::deposit(double amount) {
  d_lock.lock();
  d_account_p->deposit(amount);
  d_lock.unlock();
}

void my_SafeAccountHandle::lock() { d_lock.lock(); }

void my_SafeAccountHandle::unlock() { d_lock.unlock(); }

void my_SafeAccountHandle::withdraw(double amount) {
  d_lock.lock();
  d_account_p->withdraw(amount);
  d_lock.unlock();
}

my_Account* my_SafeAccountHandle::account() const { return d_account_p; }

double my_SafeAccountHandle::balance() const {
  d_lock.lock();
  const double res = d_account_p->balance();
  d_lock.unlock();
  return res;
}

TEST(MutexTest, Basic) {
  my_Account account;
  account.deposit(100.50);
  double paycheck = 50.25;
  my_SafeAccountHandle handle(&account);

  EXPECT_EQ(100.50, handle.balance());
  handle.deposit(paycheck);
  EXPECT_EQ(150.75, handle.balance());

  double check[5] = {25.0, 100.0, 99.95, 75.0, 50.0};

  handle.lock();  // consider using 'bslmt::LockGuard'

  double originalBalance = handle.account()->balance();
  for (int i = 0; i < 5; ++i) {
    handle.account()->deposit(check[i]);
  }
  EXPECT_EQ(originalBalance + 349.95, handle.account()->balance());
  handle.unlock();
}

}  // namespace
}  // namespace llcl