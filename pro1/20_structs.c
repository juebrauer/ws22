
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 100

struct address {
   char  name[MAX_STR_LEN];        // member variable #1
   char  firstname[MAX_STR_LEN];   // member variable #2
   char  streetname[MAX_STR_LEN];  // member variable #3
   int   housenumber;              // member variable #4
   int   zipcode;                  // member variable #5
   char  city[MAX_STR_LEN];        // member variable #6   
};

enum pizza_types { Margherita, Salami, Funghi, Hawai };
enum pizza_sizes { S, M, L, XL, XXL, PartySize };

struct pizza_order {
   struct address     delivery_address;
   enum pizza_types   which_pizza;
   enum pizza_sizes   which_size;
};

void set_city_to_kempten(struct pizza_order* o)
{
   strcpy( o->delivery_address.city, "Kempten" );
}

int main() {

   struct pizza_order orderExample =
   {
      {
         "Simpson",
         "Bart",
         "Evergreen Terrace",
         742,
         58008,
         "Springfield"
      },
      Funghi,
      XXL
   };   

   set_city_to_kempten( &orderExample );

   printf("Here is a complete pizza order:\n");
   printf("\tPizza type :%d\n", orderExample.which_pizza);
   printf("\tSize       :%d\n", orderExample.which_size);
   printf("\tDelivery address:\n");
   printf("\t\t%s %s\n", orderExample.delivery_address.firstname,
                         orderExample.delivery_address.name);
   printf("\t\t%d %s\n", orderExample.delivery_address.housenumber,
                         orderExample.delivery_address.streetname);
   printf("\t\t%d %s\n", orderExample.delivery_address.zipcode,
                         orderExample.delivery_address.city);

} // end of main