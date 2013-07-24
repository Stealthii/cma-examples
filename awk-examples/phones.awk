BEGIN {
    printf("Unit name\tCost of Inventory\n");
    }
// { if ($3 != 0) {
        subtotal = $2 * $3;
        total = total + subtotal;
        printf("%s\t\t£%.2f\n",$1,subtotal);
        }
     else {
        empty = empty + 1;
        }
   }
END {
    printf("\nTotal: \t\t£%.2f\n",total);
    if (empty > 0) printf("Phones out of stock: %d\n",empty);
    }
