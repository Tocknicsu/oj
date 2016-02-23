#include<iostream>
using namespace std;

class Person{
public:
	Person();
	Person(int i, int e);
	~Person();
private:
	Person *parent, *child, *sibling; // the pointers to his parent, child, sibling
	int id; // record Person's id
	int energy; // record Person's energy
	int degree;// record how many levels of this Person's children
	friend class Promenade;//you could access all valuables in class Promenade
};

Person::Person(){
	parent = child = sibling = NULL;
	id = 0;
	energy = 0;
	degree = 0;
}

Person::Person(int i, int e){// define a new Person with id = i and energy = e
	parent = child = sibling = NULL;
	id = i;
	energy = e;
	degree = 0;
}

Person::~Person(){

}

class Promenade{
public:
	Promenade();
	~Promenade();
	void one_person_joined(int id, int energy);
	void one_group_joined(Promenade *g);
	void absorb_energy(int id, int energy);
	int  calculate_people_below(int energy);
	int  get_weakest_person();
	int  size();
    int  calc_people_below(Person*,int);
private:
	Person *head;
	int num;//caculate how many people in the promenade
};

Person* pointer_id[1310720];
Promenade::Promenade(){
	head = new Person();
	num = 0;
}

Promenade::~Promenade(){
}

void Promenade::one_person_joined(int id, int energy){
    Promenade *g = new Promenade();
    g->head->sibling = new Person(id, energy);
    g->num = 1;
    pointer_id[id] = g->head->sibling;
    (*this).one_group_joined(g);
}

void Promenade::one_group_joined(Promenade *g){
    num += g->num;
    Person *now_a = head->sibling;
    Person *now_b = g->head->sibling;
    Person *new_head = new Person();
    Person *now = new_head;
    while(now_a != NULL && now_b != NULL){
        if(now_a->degree < now_b->degree){
            now->sibling = now_a;
            now_a = now_a->sibling;
            now = now->sibling;
        } else {
            now->sibling = now_b;
            now_b = now_b->sibling;
            now = now->sibling;
        }
    }
    if(now_a != NULL) now->sibling = now_a;
    if(now_b != NULL) now->sibling = now_b;
    delete head;
    head = new_head;
    g->head = NULL;
    now = new_head;
    while(now->sibling != NULL && now->sibling->sibling != NULL){
        if(now->sibling->sibling->sibling != NULL && now->sibling->sibling->sibling->degree == now->sibling->degree){
            now = now->sibling;
        } else if(now->sibling->degree == now->sibling->sibling->degree){
            Person *tmp_a = now->sibling;
            Person *tmp_b = now->sibling->sibling;
            Person *next = now->sibling->sibling->sibling;
            if(tmp_a->energy > tmp_b->energy) 
                swap(tmp_a, tmp_b);
            now->sibling = tmp_a;
            tmp_a->degree++;
            tmp_a->sibling = next;
            tmp_b->parent = tmp_a;
            tmp_b->sibling = tmp_a->child;
            tmp_a->child = tmp_b;
            continue;
        } else {
            now = now->sibling;
        }
    }
}

void Promenade::absorb_energy(int id, int energy){
    if(pointer_id[id] == NULL) return;
    pointer_id[id]->energy -= energy;
    while(pointer_id[id]->parent != NULL && pointer_id[id]->energy < pointer_id[id]->parent->energy){
        swap(pointer_id[id]->energy, pointer_id[id]->parent->energy);
        swap(pointer_id[id]->id, pointer_id[id]->parent->id);
        swap(pointer_id[id], pointer_id[pointer_id[id]->id]);
    }
    if(pointer_id[id]->energy <= 0){
        num-=(1<<pointer_id[id]->degree);
        Person *now = head;
        while(now->sibling->id != id){
            now = now->sibling;
        }
        now->sibling = now->sibling->sibling;
        now = pointer_id[id]->child;
        while(now!=NULL){
            Promenade *tmp = new Promenade();
            tmp->head = new Person();
            tmp->head->sibling = now;
            now = now->sibling;
            tmp->head->sibling->sibling = NULL;
            tmp->num = (1 << tmp->head->sibling->degree);
            tmp->head->sibling->parent = NULL;
            one_group_joined(tmp);
        }
        delete pointer_id[id];
        pointer_id[id] = NULL;
    }
}

int Promenade::calculate_people_below(int energy){
	return calc_people_below(head->sibling, energy);
}
int Promenade::calc_people_below(Person* now, int energy){
    return now == NULL ? 0 : calc_people_below(now->sibling, energy) + ((now->energy <= energy) ? 1 + calc_people_below(now->child, energy):0);
}

int Promenade::get_weakest_person(){
    if(head->sibling == NULL) return -1;
    int ans = 2147483647, ans_id;
    for(Person *now = head->sibling ; now ; now = now->sibling)
        if(ans > now->energy){
            ans = now->energy;
            ans_id = now->id;
        }
	return ans_id;
}

int Promenade::size(){
	return num;
}
