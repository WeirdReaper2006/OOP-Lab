#include <iostream>
using namespace std;

class PocketMoney
{
private:
    string source;
    float amount_received;

public:
    static float total_amount;
    PocketMoney(string s, float a) : source(s), amount_received(a)
    {
        total_amount += a;
    };
    void setSource(string s) { source = s; };
    void setAmountReceived(float a) { amount_received = a; };
    string getSource() { return source; };
    float getAmountReceived() { return amount_received; };
    void displayPocketMoney()
    {
        cout << "Amount Received: " << amount_received << "       Total: " << total_amount << endl;
    };
};

float PocketMoney::total_amount = 0;

int main()
{
    PocketMoney amount1 = PocketMoney("Grandma", 20);
    PocketMoney amount2 = PocketMoney("Grandma", 30);
    amount1.displayPocketMoney();
    return 0;
}