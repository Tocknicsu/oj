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

//ctor
Person::Person(){
	parent = child = sibling = NULL;
	id = 0;
	energy = 0;
	degree = 0;
}

//ctor
Person::Person(int i, int e){// define a new Person with id = i and energy = e
	parent = child = sibling = NULL;
	id = i;
	energy = e;
	degree = 0;
}

//dtor
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
    void go(Person*);
    void Go();
    int  calc_people_below(Person*,int);
private:
	Person *head;
	int num;//caculate how many people in the promenade
};

Person* pointer_id[131072];

//ctor
Promenade::Promenade(){
	head = new Person();
	num = 0;
}

//dtor
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
    if(now_a != NULL)
        now->sibling = now_a;
    if(now_b != NULL)
        now->sibling = now_b;
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
    Go();
    printf("====\n");
}

void Promenade::absorb_energy(int id, int energy){
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
            one_group_joined(tmp);
        }
        delete pointer_id[id];
        pointer_id[id] = NULL;
    }
    Go();
}

int Promenade::calculate_people_below(int energy){
	//TODO: You should calculate how many people's energy are below the number (include the number) and return it
    //O(n)
	return calc_people_below(head->sibling, energy);
}
int Promenade::calc_people_below(Person* now, int energy){
    if(now == NULL)
        return 0;
    return (now->energy <= energy) + calc_people_below(now->sibling, energy) + calc_people_below(now->child, energy);
}

int Promenade::get_weakest_person(){
    int ans = 2147483647, ans_id;
    Person *now = head->sibling;
    while(now){
        if(ans > now->energy){
            ans = now->energy;
            ans_id = now->id;
        }
        now = now->sibling;
    }
    Go();
	return ans_id;
}

int Promenade::size(){
	return num;
}
void Promenade::Go(){
    go(head->sibling);

}
void Promenade::go(Person *now){
    if(now == NULL) return;
    printf("Now: %d %d\n", now->id, now->energy);
    if(now->child != NULL){
        printf("Child: %d\n", now->child->id);
    }
    if(now->sibling != NULL){
        printf("Sibling: %d\n", now->sibling->id);
    }
    go(now->child);
    go(now->sibling);
}
