#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CheckList.h"


int main(void){
  int input_code;
  char buffer[BUFFSIZE];
  struct contact_struct tmp_contact;
  struct contact_struct* contact_ptr, *current_contact;
  struct contact_list list;
  list.head_ptr = NULL;
  list.tail_ptr = NULL;
  while(1){
    clear();
    printf("-----------------------Chon mot trong cac tuy chon-----------------------\n");
    printf("0: them thong tin lien lac\n");
    printf("1: tim kiem lien lac theo truong\n");
    printf("2: kiem tra lien lac co ton tai trong danh sach\n");
    printf("3: liet ke toan bo danh sach\n");
    printf("4: sua thong tin lien lac hien tai!\n");
    printf("5: thoat\n");
    printf("chon: ");
    scanf("%d", &input_code);
    switch (input_code) {
      case 0:
      //over flow...
        clear();
        printf("-----------------Them lien lac vao danh sach KHONG DAU CACH-----------------\n");
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
        printf("So dien thoai di dong: ");
        scanf("%s", tmp_contact.mobile_phone);

        contact_ptr = make_new_contact(tmp_contact.name, tmp_contact.address, tmp_contact.email, tmp_contact.office_phone, tmp_contact.home_phone, tmp_contact.mobile_phone);
        //them lien lac vao list that bai
        if(list_add(&list, contact_ptr) < 0){
          printf("Loi khong the them phan tu vao danh ba\n");
          continue;
        }
        break;
      case 1:
        printf("-----------------Tim kiem lien lac theo truong: -----------------\n");
        int field = get_user_input_field();

        printf("Gia tri tim kiem: ");
        scanf("%s", buffer);
        current_contact = search_by_field(&list, field, buffer);
        if(current_contact == NULL){
          printf("Khong tim thay lien lac nao thoa man\n");
          getchar();
          break;
        }
        else{
        printf("-----------------Ket qua tim kiem: -----------------\n");
        print_struct(current_contact);
        getchar();
        break;
        }
        getchar();
        continue;
      case 2:
        clear();
        printf("-----------------Kiem tra thong tin lien lac KHONG DAU CACH-----------------\n");
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
        printf("So dien thoai di dong: ");
        scanf("%s", tmp_contact.mobile_phone);

        if(search_by_struct(&list, &tmp_contact) == -1)
        {
          printf("Khong tim thay lien lac nhu yeu cau\n");
          getchar();
        }
        else{
          printf("Tim thay lien lac trong danh sasch\n");
          getchar();
        }
        getchar();
        continue;
      case 3:
        printf("------------------Liet ke danh sach lien lac------------------\n");
        contact_ptr = list.head_ptr;
        int index = 0;
        while(contact_ptr  != NULL){
          printf("Lien lac thu: %d\n", ++index);
          print_struct(contact_ptr);
          contact_ptr = contact_ptr->next_contact;
          printf("------------------------------------------------------------\n");
        }
        getchar();
        break;
      case 4:
        printf("--------------------Lien lac hien tai--------------------\n");
        print_struct(current_contact);
        //nhap thong tin muon sua
        field = get_user_input_field();
        printf("Sua voi gia tri: ");
        scanf("%s", buffer);
        if(edit_contact_field(current_contact, field, buffer) < 0){
            printf("Thay doi gia tri truong that bai\n");
            continue;
        }
        printf("Thay doi gia tri thanh cong\n");
        print_struct(current_contact);
        break;
      case 5:
        printf("Tien hanh don dep\n");
        getchar();
        list_destroy(&list);
        return 0;
    }
    getchar();
    continue;
  }
}