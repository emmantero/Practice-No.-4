#ifndef PERSON_H
#define PERSON_H

#define MAX_LIST 20
#define MAX_VSPACE 30

typedef char String[30];

typedef struct {
    String name;
    char sex;
    String city;
} Person;

typedef struct {
    Person data[MAX_LIST];
    int count;
} PersonStaticArrayList;

typedef struct {
    Person *data;
    int count;
    int max;
} PersonDynamicArrayList, *PersonDynamicArrayListPointer;

typedef struct node{
    Person elem;
    struct node *next;
} PersonNode, *PersonLinkedList;

typedef int Position;
typedef int PersonCusorBasedList;

typedef struct {
    Person elem;
    Position next;
} CNode;

typedef struct {
    CNode data[MAX_VSPACE];
    Position avail;
} VSpace;


Person createPerson(String name, char sex, String city);
void displayPersonInfo(Person p);

/* Static Array List*/
void init_SAL(PersonStaticArrayList *list){
	list->count = 0;
}

void insert_first_SAL(PersonStaticArrayList *list, Person p){
	int a;
	if(list->count < MAX_LIST){
		for(a=list->count; a>=0; a--){
			list->data[list->count]=list->data[list->count-1];
		}
		list->data[a] = p;
	}
}

void insert_last_SAL(PersonStaticArrayList *list, Person p){
	if(list->count < MAX_LIST){
		list->data[list->count++] = p;
	}
}

void insert_at_SAL(PersonStaticArrayList *list, Person p, int index){
	int a;
	int(list->count < MAX_LIST && (index < list->count && index >= 0)){
		for(a = list->count; a > index; a--){
			list->data[a] = list->data[a - 1];
		}
		list->data[a] = p;
	}
}

void delete_first_SAL(PersonStaticArrayList *list){
	int a; 
	if(list->count > 0){
		for(a=0; a<list->count; a++){
			list->data[a] = list->data[a+1];
		}
		list->count--;
	}
}

void delete_last_SAL(PersonStaticArrayList *list){
	if(list->count > 0){
		list->count--;
	}
}

// all ocurrences
void delete_by_sex_SAL(PersonStaticArrayList *list, char sex){ 
	int a, b;
	
	if(list->count > 0){
		for(a=0; a<list->count; a++){
			if(list->data[a].sex = 'f' || list->data[a].sex = 'F'){
				for(b=a; b < list->count; b++){
					list->data[b] = list->data[b+1]; 
				}
			}
		}
	}
}

void display_SAL(PersonStaticArrayList list){
	int a;
	for(a=0; a<list.count; a++){
		printf("%d ", list.data[a]);
	}
}

/* Dynamic Array List - v1 
 * Doubles the maximum size of the array when full.
 */
void init_DAL(PersonDynamicArrayList *list){
	list->data = (Person*)malloc(sizeof(Person)*MAX_LIST);
	list->count = 0;
	list->max = MAX_LIST;
}

void insert_first_DAL(PersonDynamicArrayList *list, Person p){
	int a;
	if(list->count == list->max){
		list->max*=2;
	}
}

void insert_last_DAL(PersonDynamicArrayList *list, Person p){
	if(list->count == list->max){
		list->max*=2;
	}
	list->data[list->count] = p;
	list->count++;
}

void insert_at_DAL(PersonDynamicArrayList *list, Person p, int index){
	int a;
	if(list->count == list->max){
		list->max*=2;
	}
	for(a=list->count; a > index; a--){
		list->data[x] = list->data[x-1];
	}
}

void delete_first_DAL(PersonDynamicArrayList *list){
	int a;
	if(list->count > 0){
		for(a=0; a < list->count; a++){
			list->data[a] = list->data[a+1];
		}
		list->count--;
	}
}

void delete_last_DAL(PersonDynamicArrayList *list){
//	int a;
//	if(list->count > 0){
//		for(a=list->count; a < list->count; a--){
//			list->data[a] = list->data[a-1];
//		}
//		list->count--;
//	}
//	if(list->count > 0){
//		list->data[list->count] = list->data[list->count-1];  //TRY TO ASK IF PWEDE BA NI
//	}
	if(list->count > 0){
		list->count--;
	}
}

// first ocurrence
void delete_by_city_DAL(PersonDynamicArrayList *list, String city){
	int a,b;
	
	if(list->count > 0){
		for(a=0; a < list->count && strcmp(list->data[a].city, city)!=0; a++){}
		
		if(a < list->count){
			for(b=a; b < list->count; b++){
				list->data[b] = list->data[b+1];
			}
			list->count--;
		}
	}
}

void display_DAL(PersonDynamicArrayList list){
	int a;
	
	for(a=0; a < list->count; a++){
		printf("%s ", list->data[a].name);
	}
}

/* Dynamic Array List - v2 
 * Doubles the maximum size of the array when full.
 * The Dynamic Array List must also be created in the heap.
 */
void init_DAL_2(PersonDynamicArrayList **list);
void insert_first_DAL_2(PersonDynamicArrayList *list, Person p);
void insert_last_DAL_2(PersonDynamicArrayList *list, Person p);
void insert_at_DAL_2(PersonDynamicArrayList *list, Person p, int index);
void delete_first_DAL_2(PersonDynamicArrayList *list);
void delete_last_DAL_2(PersonDynamicArrayList *list);
void delete_by_name_DAL_2(PersonDynamicArrayList *list, String name); // last ocurrence
void display_DAL_2(PersonDynamicArrayList list);

/* Singly Linked List */
void insert_first_LL(PersonLinkedList *list, Person p){
	PersonLinkedList tmp = (PersonLinkedList)malloc(sizeof(PersonNode));
	
	if(tmp!=NULL){
		tmp->elem = p;
		tmp->next = *list;
		*list = tmp;
	}
}

void insert_last_LL(PersonLinkedList *list, Person p){
	PersonLinkedList *trav;
	PersonLinkedList tmp = (PersonLinkedList)malloc(sizeof(PersonNode));
	
	if(tmp != NULL){
		for(trav=list; *trav != NULL; trav=&(*trav)->next){}

	}
}

void insert_after_LL(PersonLinkedList *list, Person p, String name){
	PersonLinkedList *trav;
	PersonLinkedList tmp = (PersonLinkedList)malloc(sizeof(PersonNode));
	
	if(tmp != NULL){
		for(trav = list; *trav != NULL && strcmp((*trav)->elem.name, name)!= NULL; trav=&(*trav)->next){}
		
		if(*trav != NULL){
			tmp->elem = p;
			tmp->next = (*trav)->next;
			(*trav)->next = tmp;
		}
	}
}

void delete_first_LL(PersonLinkedList *list){
	PersonLinkedList tmp = (PersonLinkedList)malloc(sizeof(PersonNode));
	
	if(*list != NULL){
		tmp = *list;
		list = tmp->next;
		free(tmp);
	}	
}

void delete_last_LL(PersonLinkedList *list){
	PersonLinkedList *trav;
	PersonLinkedList tmp = (PersonLinkedList)malloc(sizeof(PersonNode));
	
	if(*list != NULL){
		for(trav = list; *trav != NULL; trav = &(*trav)->next){}
		
		if(*trav != NULL){
			tmp = *trav;
			*trav = tmp->next;
			free(tmp);
		}
	}
}

// all ocurrences
void delete_by_city_LL(PersonLinkedList *list, String city){
	PersonLinkedList *trav, tmp;
	
 	if(*list !=NULL){
 		for(trav = list; *trav != NULL; trav = &(*trav)->next){
 			if(strcmp((*trav)->elem.city, city)==0){
 				tmp = *trav;
 				*trav = tmp->next;
 				free(tmp);
			 }
		 }
	 }
}

void display_LL(PersonLinkedList list){
	//to be placed
}

/* Implement all VSpace conncept and Cusor Based List*/
void init_vspace(VSpace *vs){
	int a;
	
	for(a=0; a < MAX_VSPACE; a++){
		vs->data[a].next = a + 1;
	}
	
	vs->avail = MAX_VSPACE - 1;
}

Position alloc_space(VSpace *vs){
	Position avail = vs->avail;
	
	if(avail != -1){
		vs->avail = vs->data[vs->avail].next;
	}
	return avail;
}

void free_space(VSpace *vs, Position index){
	if(index > -1 && index < MAX_SPACE){
		vs->data[index].next = vs->avail;
		vs->avail = index;
	}
}

void insert_first_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){
	int tmp = alloc_space(vs);
	
	if(tmp!=-1){
		vs->data[tmp].elem=p;
		vs->data[tmp].next=*list;
		*list=tmp;
	}
}

void insert_last_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){
	int a,tmp=alloc_space(vs);
	
	if(tmp!=-1){
		for(a=*list; a!=-1 && vs->data[a].next!=-1; a=vs->data[a].next){}
		
		if(vs->data[a].next==-1){
			vs->data[tmp].elem=p;
			vs->data[a].next=tmp;
			vs->data[tmp].next=-1;
		}
	}		
}

void insert_at_CBL(VSpace *vs, PersonCusorBasedList *list, Person p, int index);

void delete_first_CBL(VSpace *vs, PersonCusorBasedList *list);

void delete_last_CBL(VSpace *vs, PersonCusorBasedList *list);
void delete_by_sex_CBL(VSpace *vs, PersonCusorBasedList *list, char sex); // all ocurrences
void display_CBL(VSpace vs, PersonCusorBasedList list);
#endif
