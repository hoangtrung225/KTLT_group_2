#include <stdio.h>
#include <string.h>

#define NAME_LEN 32
#define ADDR_LEN 128
#define EMAIL_LEN 32
#define PHONE_LEN 10

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

struct contact_struct* make_new_contact(char* name, char* address, char* email, char* office_p, char* home_p, char* mobile_p){
  struct contact_struct* new = (struct contact_struct* ) malloc(sizeof struct contact_struct);

  //mot trong cac truong vuot qua gia tri gioi han
  if(strlen(name) > NAME_LEN || strlen(address) > ADDR_LEN || strlen(email) > EMAIL_LEN ||
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
int list_add (struct contact_struct* elem, struct contact_list* L){
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
}
