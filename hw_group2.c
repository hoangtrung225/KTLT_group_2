#include <stdio.h>
#include <string.h>

#define NAME_LEN 32
#define ADDR_LEN 128
#define EMAIL_LEN 32
#define PHONE_LEN 10

#define clear() printf("\033[H\033[J")

struct contact_struct{
  char name[NAME_LEN + 1];
  char address[ADDR_LEN + 1];
  char email[EMAIL_LEN + 1];
  char office_phone[PHONE_LEN + 1];
  char home_phone[PHONE_LEN + 1];
  char mobile_phone[PHONE_LEN + 1];
  struct contact_struct* next_contact;
}

struct contact_list{
  struct contact_struct* head_ptr;
  struct contact_struct* tail_ptr;
}

enum {
  NAME_S, ADDRESS_S, EMAIL_S, OFFICE_P, HOME_P, MOBILE_P
};


int main(void){
  int input_code;
  struct contact_struct tmp_contact;
  struct contact_list list;
  list.head_ptr = NULL;
  list.tail_ptr = NULL;
  while(true){
    printf("-----------------------Chon mot trong cac tuy chon-----------------------\n");
    printf("0: them thong tin lien lac\n");
    printf("1: tim kiem lien lac theo truong\n");
    printf("2: kiem tra lien lac co ton tai danh sach\n");
    printf("3: liet ke toan bo danh sach\n");
    printf("4: thoat!\n");
    printf("chon: ");
    scanf("%d", &input_code);
    clear();
    switch (input_code) {
      case 0
      //over flow...
        printf("Ten lien lac: ");
        scanf("%s", tmp_contact.name);
        printf("Dia chi: ");
        scanf("%s", tmp_contact.address);
        printf("Email: ");
        scanf("%s", tmp_contact.email);
        printf("So dien thoai gia dinh: ");
        scanf("%s", tmp_contact.home_phone);
        printf("So dien thoai co quan: ");
        scanf("%s", tmp_contact.office_phone);
        printf("So dien thoai di dong: ", );
        scanf("%s", tmp_contact.mobile_phone);


    }
  }
}
struct contact_struct* make_new_contact(char* name, char* address, char* email, char* office_p, char* home_p, char* mobile_p){
  struct contact_struct* new = (struct contact_struct* ) malloc(sizeof struct contact_struct);

  //mot trong cac truong vuot qua gia tri gioi han
  if(strlen(name) > NAME_LEN || strlen(address) > ADDR_LEN || strlen(email) > EMAIL_LEN || \
    strlen(office_p) > PHONE_LEN || strlen(home_p) > PHONE_LEN || strlen(mobile_p) > PHONE_LEN)
    return NULL;
  strncpy(new.name, name, NAME_LEN);
  strncpy(new.address, address, ADDR_LEN);
  strncpy(new.email, email, EMAIL_LEN);
  strncpy(new.office_phone, office_p, PHONE_LEN);
  strncpy(new.home_phone, home_p, PHONE_LEN);
  strncpy(new.mobile_phone, mobile_p, PHONE_LEN);
  new.next_contact = NULL;

  //tra ve node moi tao
  return new;
}

//them elem vao cuoi list
int list_add (struct contact_list* L, struct contact_struct* elem){
  if(L == NULL) return -1;

  //list chua co phan tu them phan tu dau tien
  if(L->head_ptr == NULL){
    L->head_ptr = elem;
    L->tail_ptr = elem;
    return 0;
  }

  //cho phan tu cuoi tro vao elem
  L->tail_ptr->next_contact = elem;
  return 0;
}

int edit_contact_field(struct contact_struct* elem, int field, char* value){
  switch (field) {
    case NAME_S:
      if(strlen(value) > NAME_LEN)
        return -1;
      strncpy(elem->name, value, NAME_LEN);
      break;
    case ADDRESS_S:
      if(strlen(value) > ADDR_LEN)
        return -1;
      strncpy(elem->address, value, ADDR_LEN);
      break;
    case EMAIL_S:
      if(strlen(value) > EMAIL_LEN)
        return -1;
      strncpy(elem->email, value, EMAIL_LEN);
      break;
    case HOME_P:
      if(strlen(value) > PHONE_LEN)
        return -1;
      strncpy(elem->home_phone, value, PHONE_LEN);
      break;
    case MOBILE_P:
      if(strlen(value) > PHONE_LEN)
        return -1;
      strncpy(elem->mobile_phone, value, PHONE_LEN);
    case OFFICE_P:
      if(strlen(value) > PHONE_LEN)
        return -1;
      strncpy(elem->office_phone, value, PHONE_LEN);
    default:
      return -1;
  }
  return 0;
}

struct contact_struct* search_by_field(struct contact_list* L, int field, char* value){
  if(L == NULL || L->head_ptr == NULL) return NULL;
  struct contact_struct* tmp_ptr = L->head_ptr;
  do{
    int result;
    switch (field) {
      case NAME_S:
        if(strlen(value) > NAME_LEN)
          continue;
        result = strncmp(tmp_ptr->name, value, NAME_LEN);
        break;
      case ADDRESS_S:
        if(strlen(value) > ADDR_LEN)
          continue;
        result = strncmp(tmp_ptr->address, value, ADDR_LEN);
        break;
      case EMAIL_S:
        if(strlen(value) > EMAIL_LEN)
          continue;
        result = strncmp(tmp_ptr->email, value, EMAIL_LEN);
        break;
      case HOME_P:
        if(strlen(value) > PHONE_LEN)
          continue;
        result = strncmp(tmp_ptr->home_phone, value, PHONE_LEN);
        break;
      case MOBILE_P:
        if(strlen(value) > PHONE_LEN)
          continue;
        result = strncmp(tmp_ptr->mobile_phone, value, PHONE_LEN);
        break;
      case OFFICE_P:
        if(strlen(value) > PHONE_LEN)
          continue;
        result = strncmp(tmp_ptr->office_phone, value, PHONE_LEN);
        break;
    }
    if(result == 0) return tmp_ptr;
  }while((tmp_ptr = tmp_ptr->next_contact) != NULL)
  return NULL;
}

//tra ve 0 neu tim thay, -1 neu khong thay
int search_by_struct(struct contact_list* L, struct contact_struct* S){
  if(L == NULL || L->head_ptr == NULL || S == NULL) return -1;
  struct contact_struct* tmp_struct = L->head_ptr;
  struct contact_list tmp_list;
  tmp_list->head_ptr = L->head_ptr;
  tmp_list->tail_ptr = L->tail_ptr;
  //lap qua tat ca cac truong cua struct
  for(int field = NAME_S; field <= MOBILE_P; field++){
    //tra ve FAIL neu khong tim duoc truong nao khop
    tmp_list->head_ptr = search_by_field(tmp_list, field, get_field_by_index(S, field));
    if(tmp_list->head_ptr == NULL)
      return -1;
  }
  return 0;
}

char* get_field_by_index(struct contact_struct* S, int index){
  if(contact_struct == NULL) return NULL;
  switch (index) {
    case NAME_S:
      return S->name;
    case ADDRESS_S:
      return S->address;
    case EMAIL_S:
      return S->email;
    case HOME_P:
      return S->home_phone;
    case OFFICE_P:
      return S->office_phone;
    case MOBILE_P:
      return S->mobile_phone;
    default:
      return NULL;
  }
}
