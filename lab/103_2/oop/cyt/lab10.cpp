#include <iostream>
#include <iomanip>
using namespace std;

class people{
    private:
        int hp, shield_hp, max_hp;
    public:
        people(){}
        people(int _hp, int _shield_hp) : hp(_hp), shield_hp(_shield_hp), max_hp(_hp) {}
        virtual void be_damage(int x){
            if(shield_hp){
                shield_hp -= x;
                shield_hp = max(0, shield_hp);
            } else {
                hp -= x;
                hp = max(0, hp);
            }
        }
        int get_hp(){
            return hp;
        }
        int get_max_hp(){
            return max_hp;
        }
        int get_shield_hp(){
            return shield_hp;
        }
        void set_shield(int x){
            shield_hp = x;
        }
};

class swordsman : virtual public people{
    private:
        int weapon_level;
    public:
        swordsman(int _weapon_level) : weapon_level(_weapon_level){}
        swordsman(int _hp, int _shield_hp, int _weapon_level) : people(_hp, _shield_hp), weapon_level(_weapon_level) {}
        int make_damage(){
            return 10 * weapon_level;
        }
};

class wizard : virtual public people{
    private:
        int wand_level;
    public:
        wizard(int _wand_level) : wand_level(_wand_level){}
        wizard(int _hp, int _shield_hp, int _wand_level) : people(_hp, _shield_hp), wand_level(_wand_level) {}
        int make_damage(int skill){
            if(!skill){
                people::set_shield(100);
                return 0;
            }
            int damage = skill == 13112 ? 100 : 50;
            return float(damage) * float(float(wand_level) * 0.5 + 0.5);
        }
};

class magicka : public swordsman, public wizard{
    public:
        magicka(int a, int b, int c, int d) : people(a, b), swordsman(c), wizard(d) {}
        int make_damage(int c, int skill = 0){
            if(c == 0){
                return swordsman::make_damage();
            } else {
                return wizard::make_damage(skill);
            }
        }
};

class boss : public people{
    public:
        boss(int a, int b) : people(a, b) {}
        int make_damage(){
            return 50;
        }
};
void print(string str, people a){
    cout << setfill(' ') << setw(5) << str << " HP (" << a.get_hp() << "/" << a.get_max_hp() << "):";
    for(int i = 0 ; i < a.get_hp() / 10 ; i++) cout << "|";
    cout << endl;
    if(a.get_shield_hp()){
        cout << setfill(' ') << setw(5) << str << " HP (" << a.get_shield_hp() << "/100):";
        for(int i = 0 ; i < a.get_shield_hp() / 10 ; i++) cout << "|";
        cout << endl;
    }
}
int main(){
    int c, d;
    cout << "Please choose weapon for hero. [0]:Sword [1]:M60 [2]:Excalibur >>" << endl;
    cin >> c;
    c = c == 2 ? 10 : c+1;
    cout << "Please choose wand for hero. [0]:Wood Wand [1]:Silver Wand [2]:Gold wand" << endl;
    cin >> d;
    magicka user(100, 0, c, d+1);
    boss com(500, 0);
    int round = 0;
    while(1){
        cout << "Round " << ++round << endl;
        print("Boss", com);
        print("Hero", user);
        cout << "Boss Attack!!" << endl;
        int a, b = 0;
        cout << "Select attack or magic for Hero. [0]:attack [1]:magic >> ";
        cin >> a;
        if(a){
            cout << "Select skill for Hero >>";
            cin >> b;
        }
        int user_damage = user.make_damage(a, b);
        int com_damage = com.make_damage();

        if(user.get_shield_hp())
            com_damage = 40;
        user.be_damage(com_damage);
        com.be_damage(user_damage);
        
        cout << "Hero got " << com_damage << " Damage" << endl;
        cout << "Boss got " << user_damage << " Damage" << endl;


        if(user.get_hp() == 0){
            cout << "user died." << endl;
            return 0;
        } else if (com.get_hp() == 0){
            cout << "boss died." << endl;
            return 0;
        }
    }
    return 0;
}
