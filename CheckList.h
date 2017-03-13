#define NAME_LEN 32
#define ADDR_LEN 128
#define EMAIL_LEN 32
#define PHONE_LEN 10

#define BUFFSIZE 128
#define clear() printf("\033[H\033[J")

struct contact_struct{
  char name[NAME_LEN + 1];
  char address[ADDR_LEN + 1];
  char email[EMAIL_LEN + 1];
  char office_phone[PHONE_LEN + 1];
  char home_phone[PHONE_LEN + 1];
  char mobile_phone[PHONE_LEN + 1];
  struct contact_struct* next_contact;
};

struct contact_list{
  struct contact_struct* head_ptr;
  struct contact_struct* tail_ptr;
};

enum {
  NAME_S, ADDRESS_S, EMAIL_S, OFFICE_P, HOME_P, MOBILE_P
};

struct contact_struct* make_new_contact(char* name, char* address, char* email, char* office_p, char* home_p, char* mobile_p);
int list_add (struct contact_list* L, struct contact_struct* elem);
int edit_contact_field(struct contact_struct* elem, int field, char* value);
struct contact_struct* search_by_field(struct contact_list* L, int field, char* value);
int search_by_struct(struct contact_list* L, struct contact_struct* S);
char* get_field_by_index(struct contact_struct* S, int index);
int print_struct(struct contact_struct*);
int get_user_input_field (void);
int list_destroy(struct contact_list* L);