#ifndef BANDIT_HPP
#define BANDIT_HPP

using namespace std;

class Bandit {
    private:
        double banditAttack;
    public:
        double banditHealth;
        Bandit(double bh, double ba) : banditHealth(bh), banditAttack(ba) {}
        double getDamageDone();
        void dealDamage(double d);
        double getBanditHealth();

};

#endif //BANDIT_HPP
